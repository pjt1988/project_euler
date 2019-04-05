OBJS=main.o
CC=g++
DEBG=-g
CFLAG=-c $(DEBUG)
LFLAGS=-WALL $(DEBUG)

all: $(OBJS)
	$(CC) -o "pe_run" $(LFLAGS) $(OBJS) 

main.o: main.cpp
	$(CC) -c -g main.cpp


clean: 
	\rm -f *.o pe_run
