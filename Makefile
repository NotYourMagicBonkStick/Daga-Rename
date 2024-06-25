build:
	g++ -std=c++17 -o Daga-Rename.bin src/main.cpp -lexiv2 -Wall

install: build
	echo "alias Daga-Rename=\"$(PWD)/Daga-Rename.bin\"" >> $(HOME)/.bash_aliases
