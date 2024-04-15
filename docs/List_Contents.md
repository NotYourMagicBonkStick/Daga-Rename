# List_Contents

Use this function with folders. It does not return anything.

The function and it requires 2 arguments:
- `std::string` - Directory of which contents you want to list
- `std::vector<std::filesystem::path>` - The output is saved to the vector

The `std::string` is converted to `std::filesystem::path`. Function iterates through the folder, discovering all its subdirectories, and checks each if it is a folder. If it is a folder it prints a message and skips it. If no it adds it to the provided vector.
