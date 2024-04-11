#include <iostream>
#include <string>
#include <filesystem>
#include <exiv2/exiv2.hpp>      // libexiv2-dev
// g++ -std=c++17 -o main.bin src/main.cpp -lexiv2



std::string extractDate(const std::filesystem::path& path) {
    Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(path.string());
    image->readMetadata();

    Exiv2::ExifData& exif_data = image->exifData();

    Exiv2::ExifData::const_iterator it = exif_data.findKey(Exiv2::ExifKey("Exif.Photo.DateTimeOriginal"));
    if (it != exif_data.end()) {
        std::string datetime = it->toString();
        return datetime.substr(0, 4) + '-' + datetime.substr(5, 2) + '-' + datetime.substr(8, 2) + '_' + datetime.substr(11, 2) + '-' + datetime.substr(14, 2) + '-' + datetime.substr(17, 2);
    }

/*
    it = exif_data.findKey(Exiv2::ExifKey("Exif.Photo.DateTimeDigitized"));
    if (it != exif_data.end()) {
        std::string datetime = it->toString();
        return datetime.substr(0, 4) + datetime.substr(5, 2) + datetime.substr(8, 2) + datetime.substr(11, 2) + datetime.substr(14, 2) + datetime.substr(17, 2);
    }
*/


    return "x";
}
