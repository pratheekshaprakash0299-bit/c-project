CC = gcc
CFLAGS = -Wall -Wextra -O2

all: big3.exe fact.exe pal.exe

big3.exe: dev1/big3.c
	$(CC) $(CFLAGS) dev1/big3.c -o big3.exe

fact.exe: fact.c
	$(CC) $(CFLAGS) fact.c -o fact.exe

pal.exe: pal.c
	$(CC) $(CFLAGS) pal.c -o pal.exe

clean:
	rm -f *.o *.exe

