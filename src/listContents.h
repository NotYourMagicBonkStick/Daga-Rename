// Licensed under GNU GPL 3.0
// Author Alexander Yell "https://mastodon.nove.team/@NotYourMagicBonkStick"


#include <iostream>
#include <vector>
#include <filesystem>

void listContents (const std::string inPath, std::vector<std::filesystem::path>& subdirs) {

    std::filesystem::path dir(inPath);
    for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(dir) ) {
        if (entry.is_directory()) {
            std::cout << "Omitting inner folder: " << entry.path().string() << std::endl;
        }else{
            std::filesystem::path path(entry.path());
            subdirs.push_back(path);
        }

    }

}
