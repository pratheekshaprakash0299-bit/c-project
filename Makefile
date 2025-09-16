# Usage: make F1=big3.c F2=fact.c F3=pal.c

F1 ?= f1.c
F2 ?= f2.c
F3 ?= f3.c

ABC.exe: f1.o f2.o f3.o
	gcc -o ABC.exe f1.o f2.o f3.o

f1.o: $(F1)
	gcc -c $(F1) -o f1.o

f2.o: $(F2)
	gcc -c $(F2) -o f2.o

f3.o: $(F3)
	gcc -c $(F3) -o f3.o

