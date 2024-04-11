#include <iostream>
#include <filesystem>


bool isFolder (const std::string& path) {
    std::filesystem::path p(path);
    std::filesystem::file_status status = std::filesystem::status(p);
    return std::filesystem::is_directory(status);
}


bool doesExist (const std::string& path) {
    std::filesystem::path p(path);
    if (!std::filesystem::exists(p)) {
        return false;
    }else{
        return true;
    }
}
