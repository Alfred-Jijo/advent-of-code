all: build run clean

build:
	gcc -o main.exe main.c -fsanitize=address -Iinclude
	clear

run:
	./main.exe input.txt

clean:
	clear
	rm -rf main.exe
