
# Ryan Gittins and Phillip Sime
#
# CS441: Project 3
#
# 2013-11-02
#
#####################################################################
#
# Type "make" or "make scheduler" to compile your code
# 
# Type "make clean" to remove the executable (and any object files)
#
#####################################################################

CC=gcc
CFLAGS=-Wall -g

all: scheduler

scheduler: scheduler.c scheduler.h support.o
	$(CC) -o scheduler $(CFLAGS) scheduler.c support.o

support.o: support.h support.c
	$(CC) -c -o support.o $(CFLAGS) support.c

clean:
	$(RM) scheduler *.o
	$(RM) -rf *.dSYM
