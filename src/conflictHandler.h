#include <filesystem>
#include <string>

#include "getExtension.h"

std::filesystem::path conflictHandler(const std::filesystem::path& inDir, int i = 1) {

    std::filesystem::path outDir = inDir;

    if (std::filesystem::exists(inDir)) {

        std::string procString;
        procString = inDir.string();


        procString.insert(procString.length() - getExtension(inDir).length(), '-' + std::to_string(i));
        outDir = std::filesystem::path(procString);

        if (std::filesystem::exists(outDir)) {
            outDir = conflictHandler(inDir, i + 1);
        }

    }
//yyyy-mm-dd-hh-mm-ss.jpg
    return outDir;
}
