# List_Contents

Use this function with folders. It does not return anything. Recursive.

The function is `void` type and it requires 2 arguments:
- `std::filesystem::path` - Directory of which contents you want to list
- `std::vector<std::filesystem::path>` - The output is saved to this vector

The Function iterates through the folder, discovering all its subdirectories, and checks each if it is a folder. If it finds any files, they'll be appended to the provided vector. If there's a folder, the function will call itself and iterate through that folder.
