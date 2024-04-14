# Conflict Handler

The `Conflict_Handler (std::filesystem::path, std::string)` function is recursive and checks if a given directory already exists. It returns a unique `std::filesystem::path` that yet hasn't been created to avoid creating multiple files with the same name.

The function takes three arguments:
- `std::filesystem::path` - directory you want to check
- `std::string` - ID provided by the user
- `int` - number for the additional label (used only by the function itself during recursion)

If the provided directory already exists, the function will create a new `std::string procString` based on the path. It will calculate the length of `ID` and the files' extension in characters. Then it'll use it to find where to insert the additional label to the `procString`. The label is supposed to be placed between `creation time` and `ID`, such as `YYYY-MM-DD_hh-mm-ss-label_ID.extension`.

The label is an `std::string` representation of an `int` type.

Function checks again if the directory exists. If yes, the above will happen again with higher `int` value. Once a unique directory is found, the function returns it as `std::filesystem::type`.
