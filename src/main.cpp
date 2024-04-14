// Licensed under GNU GPL 3.0
// Author Alexander Yell "https://mastodon.nove.team/@NotYourMagicBonkStick"


#include <iostream>
#include <cstring>
#include <vector>

#include "dirCheck.h"
#include "listContents.h"
#include "extractDate.h"
#include "Get_Extension.h"
#include "Conflict_Handler.h"


const std::string version = "v0.9";

int main(int argc, char *argv[]) {

    if (argc < 3 || 0 == strcmp(argv[1], "help") ) {
        std::cout << "Photo-Rename " << version << std::endl;
        std::cout << "Usage: Photo-Rename <ID> <file>" << std::endl;
        std::cout << "Preferred way to provide the files is Drag'n'Drop" << std::endl;
        std::cout << "To create a name with no ID use \"\\!0\"" << std::endl;
        std::cout << "Works with folders" << std::endl;
        std::cout << "To rename multiple individual files use:" << std::endl;
        std::cout << "Photo-Rename <ID> <file1> <file2>" << std::endl;
        return 0;
    }


    std::vector <std::string>listOfElements;

    // Push dirs to list
    for (int i = 2; i < argc; ++i) {
        listOfElements.push_back (argv[i]);
    }

    // set ID
    std::string ID;
    if ( 0 == strcmp(argv[1], "!0") ) {
        ID = "";
    }else{
        ID = argv[1];
    }



    // Directory discovery
    std::vector <std::filesystem::path>listOfFiles;
    for (unsigned int i = 0; i < listOfElements.size (); ++i ) {


        if ( doesExist(listOfElements[i]) ) {

            if ( isFolder (listOfElements[i]) ) {
                listContents (listOfElements[i], listOfFiles);
            }else{
                listOfFiles.push_back ( std::filesystem::path(listOfElements[i]) );
            }

        }else{      // If given dir does not exist
            std::cout << "Omitting inaccessible directory: " << listOfElements[i] << std::endl;
        }


        std::cout << "Discovering files: " << listOfFiles.size () << '\r';

    }
    std::cout << std::endl;


    unsigned int numberOfFiles = listOfFiles.size();


    std::string dateTime[numberOfFiles];
    std::string newName[numberOfFiles];
    std::filesystem::path newDir[numberOfFiles];
    std::string extension;


    for (unsigned int i = 0; i < numberOfFiles; ++i ) {
        dateTime[i] = extractDate (listOfFiles[i]);

        if ("x" == dateTime[i]) {
            std::cout << "No creation time found: " << listOfFiles[i] << std::endl;
            continue;
        }

        extension = Get_Extension(listOfFiles[i]);
        if ("" != ID) {
            newName[i] = dateTime[i] + '_' + ID + extension;
        }else{
            newName[i] = dateTime[i] + extension;
        }

        std::cout << "Fetching time of creation: " << i + 1 << '/' << numberOfFiles << '\r';
    }
    std::cout << std::endl;



    // Rename
    for (unsigned int i = 0; i < numberOfFiles; ++i) {

        // Omit files with no date
        if ("" == newName[i]) {
            std::cout << "Will not be affected: " << listOfFiles[i] << std::endl;
            continue;
        }

        newDir[i] = listOfFiles[i].parent_path() / newName[i];
        newDir[i] = Conflict_Handler (newDir[i], ID);

        std::filesystem::rename(listOfFiles[i], newDir[i]);
        if (!std::filesystem::exists(newDir[i])) {
            std::cout << "Failed to rename: " << listOfFiles[i].string() << std::endl;
            continue;
        }

        std::cout << "Processing: " << i + 1 << '/' << numberOfFiles << '\r';
    }
    std::cout << std::endl << "Done" << std::endl;


return 0;}
