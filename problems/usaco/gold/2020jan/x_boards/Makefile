CC=g++
CFLAGS=-std=gnu++11 

debug: main_boards.cpp
	$(CC) main_boards.cpp -o auto $(CFLAGS) && ./auto && cat boards.out 2>/dev/null
