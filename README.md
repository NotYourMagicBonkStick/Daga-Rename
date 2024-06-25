# Daga-Rename

Simple command line tool to rename photos

The program renames all provided photos to a following format `YYYY-MM-DD_hh-mm-ss_ID.extension`. If there is no creation time in the metadata of the photo, the file will be omitted.

This is a free software licensed under GNU GPL and comes with no warranty. See [LICENSE](./LICENSE).

---

# Usage

The program is launched from the command line. It requires at least one argument which is the directory you want to be changed.

`Daga-Rename '/path/to/photo 1.jpg'`

If you want to add an ID tag at the end of the filename, then specify the ID using `-` character in the first argument. The ID is optional and does not need to be provided.

`Daga-Rename -ID '/path/to/photo 1.jpg'`

The same works with folders and multiple directories specified in the next arguments passed to the program.

`Daga-Rename -ID '/path/to/photo 1.jpg' '/path/to/photo 2.jpg' '/path/to/folder 1' '/path/to/folder 2'`

`Daga-Rename '/path/to/photo 1.jpg' '/path/to/photo 2.jpg' '/path/to/folder 1' '/path/to/folder 2'`

If you are uncertain on how to use this program then run `Daga-Rename help` to see a quick manual.

If there's no date of shooting the photo then the file will be omitted.

### Errors

Generally there aren't any I'm aware of. If you find any, please refer to [Contributing](./contributing.md).

---

# Instalation

You need the following packages installed:
- git
- g++
- libexiv2-dev

To install the program, go to the directory you wish to install it and run the following commands:
```bash
git clone https://github.com/NotYourMagicBonkStick/Daga-Rename
cd Daga-Rename
make install
```

To uninstall simply delete the `Daga-Rename` folder and the alias in the `~/.bash_aliases` file. This program produces no other files and does not clutter your system. The above mentioned are the only directories affected.

---

# Contributing

Feel free to contribute to the project. Please refer to [Contributing](./contributing.md).
