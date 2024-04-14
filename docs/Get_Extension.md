# Get Extension

Function `Get_Extension (std::filesystem::path)` returns `std::string`. It contains all characters after the last `.` including. The function takes one argument which is `std::filesystem::path` type. The path is supposed to be the directory of which extension you want to get.

The function converts the `std::filesystem::path` to `std::string`. It then iterates through the string, starting from the back, till it finds the first `.` character.
- `beg` - index of the first character of the extension
- `span` - length of the extension
Both values are used to save the extension using `substr()`

If there is no `.` character, the function will return an empty string.
