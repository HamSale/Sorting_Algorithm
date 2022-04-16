#
# makefile
#
CC=gcc -g
LIBS= -L C:/sd/MinGW/lib/gcc-lib/mingw32/3.2.3/ -lstdc++

all: sorting

sorting: main.o sort.o arr.o
	$(CC) -o sorting main.o sort.o arr.o

arr.o: arr.c arr.h
	$(CC) -c arr.c -o arr.o  $(LIB)

sort.o: sort.c sort.h
	$(CC) -c sort.c -o sort.o  $(LIB)

main.o: main.c
	$(CC) -c main.c -o main.o $(LIB)

clean:
	del -f sorting.exe
	del -f *.o