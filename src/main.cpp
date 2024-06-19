// Licensed under GNU GPL 3.0
// Author Alexander Yell "https://mastodon.nove.team/@NotYourMagicBonkStick"


#include <iostream>
#include <cstring>
#include <vector>

#include "Directory_Check.h"
#include "List_Contents.h"
#include "Extract_Date.h"
#include "Get_Extension.h"
#include "Conflict_Handler.h"


const std::string version = "v1.0.1";

int main(int argc, char *argv[]) {


    // print messages

    if (argc < 2 || 0 == strcmp(argv[1], "help") ) {
        std::cout << "Daga-Rename " << version << std::endl;
        std::cout << "Usage: Daga-Rename <ID> <file>" << std::endl;
        std::cout << "Preferred way to provide the files is Drag'n'Drop" << std::endl;
        std::cout << "To create a name with ID use \"-ID\" before any file" << std::endl;
        std::cout << "ID argument is optional and can be omitted if you don't want an ID" << std::endl;
        std::cout << "Works with folders" << std::endl;
        std::cout << "To rename multiple individual files use:" << std::endl;
        std::cout << "Daga-Rename <ID> <file1> <file2>" << std::endl;
        return 1;
    }

    if (argc == 2 && argv[1][0] == '-') {
        std::cout << "Daga-Rename" << version << std::endl;
        std::cout << "Missing arguments: no directory specified" << std::endl;
        return 2;
    }


    std::vector <std::string>listOfElements;


    // set ID
    std::string ID;
    if (argv[1][0] == '-') {
        ID = std::string(argv[1] + 1);
    }else{
        ID = "";
        listOfElements.push_back(argv[1]); // if first argument is not ID then it is a dir
    }


    // Push dirs to list
    for (int i = 2; i < argc; ++i) {
        listOfElements.push_back (argv[i]);
    }



    // Directory discovery
    std::vector <std::filesystem::path>listOfFiles;
    for (unsigned int i = 0; i < listOfElements.size (); ++i ) {

        if ( false == does_Exist (listOfElements[i]) ) {
            std::cout << "Omitting inaccessible directory: " << listOfElements[i] << std::endl;
            continue;
        }


        // File formats that are not media and crash the program
        if ( ".zip" == Get_Extension (listOfElements[i]) ) {
            std::cout << "Omitting unsupported file format: " << listOfElements[i] << std::endl;
            continue;
        }


        // Directory iterator
        if (is_Folder (listOfElements[i]) ) {
            List_Contents (std::filesystem::path (listOfElements[i]), listOfFiles);
        }else{
            listOfFiles.push_back ( std::filesystem::path (listOfElements[i]) );
        }


        std::cout << "Discovering files: " << listOfFiles.size () << '\r';

    }
    std::cout << std::endl;


    unsigned int numberOfFiles = listOfFiles.size();


    std::string dateTime[numberOfFiles];
    std::string newName[numberOfFiles];
    std::filesystem::path newDir[numberOfFiles];
    std::string extension;


    // Build new filenames
    for (unsigned int i = 0; i < numberOfFiles; ++i ) {
        dateTime[i] = Extract_Date (listOfFiles[i]);

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
