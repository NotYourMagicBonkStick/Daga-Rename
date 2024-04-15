# Extract_Date

This function takes a single `std::filesystem::path` type variable as an argument and returns `std::string`.

It creates an `Exiv2::Image::AutoPtr` type object utilizing the provided path. Then it reads the metadata and saves it inside the object.

It creates an `Exiv2::ExifData` object to store exif data fetched from the metadata.

It creates `Exiv2::ExifData::const_iterator` type object to save original time of creating the photo.

If the end of the metadata is reached and there is no date the function will return "x".

If there is an original time of creation it'll be saved to an `std::string` and returned in `YYYY-MM-DD-hh-mm-ss` format.
