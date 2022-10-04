CC = gcc
CFLAGS = -ansi -pedantic -Wall -Werror -std=c89
OBJ = lasertank.o newSleep.o
EXEC = lasertank
.PHONY: all test clean

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

lasertank.o : lasertank.c
	$(CC) $(CFLAGS) lasertank.c -c

newSleep.o : newSleep.c
	$(CC)  $(CFLAGS) newSleep.c -c

clean:
	rm -f $(EXEC) $(OBJ)
