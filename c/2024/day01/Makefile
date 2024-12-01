all: build run clean

build:
	gcc -o main.exe main.c -fsanitize=address -Iinclude
	@echo ""
	@echo ""

run:
	./main.exe input.txt

clean:
	@echo ""
	@echo ""
	rm -rf main.exe
