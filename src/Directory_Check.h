// Licensed under GNU GPL 3.0
// Author Alexander Yell "https://mastodon.nove.team/@NotYourMagicBonkStick"


#include <iostream>
#include <filesystem>


bool is_Folder (const std::string& path) {
    std::filesystem::path p(path);
    std::filesystem::file_status status = std::filesystem::status(p);
    return std::filesystem::is_directory(status);
}


bool does_Exist (const std::string& path) {
    std::filesystem::path p(path);
    if (!std::filesystem::exists(p)) {
        return false;
    }else{
        return true;
    }
}
