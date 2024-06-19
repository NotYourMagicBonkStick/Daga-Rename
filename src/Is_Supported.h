// Licensed under GNU GPL 3.0
// Author Alexander Yell "https://mastodon.nove.team/@NotYourMagicBonkStick"


#include <unordered_set>
#include <string>


bool Is_Supported (const std::string& target_ext) {

    if (1 >= target_ext.length()){
        return false;
    }

    std::string target = target_ext.substr(1, 5);

    std::unordered_set<std::string> Supported_Files = {"JPEG", "jpeg", "jpg", "JPG", "TIFF", "tiff", "PNG", "png", "GIF", "gif", "BMP", "bmp", "WebP", "WEBP", "webp", "DNG", "CR2", "NEF", "ARW", "RW2", "ORF", "PEF", "SRF", "MRW", "RAF", "ERF", "SR2", "KDC", "DCR"};

    if ( Supported_Files.find(target) != Supported_Files.end() ){
        return true;
    }else{
        return false;
    }

}
