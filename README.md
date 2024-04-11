# Photo-Rename

Simple command line tool to rename photos

The program renames all provided photos to a following format `YYYY-MM-DD_hh-mm-ss_ID.extension`. If there is no creation time in the metadata of the photo, the file will be omitted.

This is a free software licensed under GNU GPL and comes with no warranty. See [LICENSE](./LICENSE).

---

# Usage

The program is launched from the command line. It requires 2+ arguments. The first argument is always the ID. All the following arguments are files and folders containing files to rename.

`Photo-Rename <ID> '/path/to/photo 1.jpg'`

`Photo-Rename <ID> '/path/to/photo 1.jpg' '/path/to/photo 2.jpg' '/path/to/folder 1' '/path/to/folder 2'`

If you wish to create a filename with no ID, the first argument shall be `!0`. However system terminal may read `!` as a special character which will mess up the argument. This means the program may receive `Photo-Rename` instead of `!0`. To counter that use backslash `\` right before the `!`. This will tell the terminal to not read it as a special character.

So the command to rename the photos without ID will look like this:

`Photo-Rename \!0 '/path/to/photo 1.jpg'`

### Errors

If you provide multiple directories to rename but won't specify any ID the program will return an error starting with: `terminate called after throwing an instance of 'std::filesystem::__cxx11::filesystem_error'`. To avoid this, always make sure that the first provided argument is an ID.

In all other cases the program will print `help`. It can also be displayed by running `Photo-Rename help`.

If you find a bug, please refer to [Contributing](./docs/contributing.md).

---

# Instalation

## Linux

You need the following packages installed:
- git
- g++
- libexiv2-dev

To install the program run the following commands:
```bash
git clone https://github.com/NotYourMagicBonkStick/Photo-Rename
cd Photo-Rename
chmod +x compile.sh
compile.sh
echo "alias Photo-Rename="$(pwd)/Photo-Rename.bin" >> ~/.bash_aliases
```

To uninstall simply delete the `Photo-Rename` folder and the alias at `~/.bash_aliases` file. This program produces no other files and does not clatter your system. The above mentioned are the only directories affected.

## Windows

Not tested or supported

Switch to penguin

---

# Contributing

Feel free to contribute to the project. Please refer to [Contributing](./docs/contributing.md).
