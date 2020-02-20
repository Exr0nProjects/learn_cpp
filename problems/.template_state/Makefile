CC=g++
CFLAGS=-std=gnu++11 -I

debug: main_[!meta:pid!].cpp
	$(CC) main_[!meta:pid!].cpp -o auto_[!meta:pid!] $(CFLAGS) && clear && ./auto_[!meta:pid!] && cat [!meta:pid!].out 2>/dev/null
