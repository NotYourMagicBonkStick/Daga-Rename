// Licensed under GNU GPL 3.0
// Author Alexander Yell "https://mastodon.nove.team/@NotYourMagicBonkStick"


#include <filesystem>
#include <string>

#include "getExtension.h"

std::filesystem::path conflictHandler(const std::filesystem::path& inDir, const std::string& ID, int i = 1) {

    std::filesystem::path outDir = inDir;

    if (std::filesystem::exists(inDir)) {

        std::string procString;
        procString = inDir.string();


        procString.insert(procString.length() - getExtension(inDir).length() - ID.length() - 1, '-' + std::to_string(i));
        outDir = std::filesystem::path(procString);

        if (std::filesystem::exists(outDir)) {
            outDir = conflictHandler(inDir, ID, i + 1);
        }

    }

    return outDir;
}
