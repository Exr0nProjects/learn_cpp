CC=g++
CFLAGS=-std=gnu++11

debug: main_[!meta:pid!].cpp
	$(CC) main_[!meta:pid!].cpp -o auto $(CFLAGS) && clear && ./auto && cat [!meta:pid!].out 2>/dev/null
