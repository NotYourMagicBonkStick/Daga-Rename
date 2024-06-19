// Licensed under GNU GPL 3.0
// Author Alexander Yell "https://mastodon.nove.team/@NotYourMagicBonkStick"


#include <iostream>
#include <vector>
#include <filesystem>

void List_Contents (const std::filesystem::path inPath, std::vector<std::filesystem::path>& subdirs) {

    for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(inPath) ) {
        if (entry.is_directory()) {
            List_Contents (entry.path(), subdirs);
        }else{
            std::filesystem::path path(entry.path());
            subdirs.push_back(path);
        }

    }

}
