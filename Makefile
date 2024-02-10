CC=cc
CFLAGS=-Wall -Wextra -Werror -g3
SRC=binary_trees.c

all:
	$(CC) $(CFLAGS) $(SRC) -o binary_trees.out

clean:
	rm binary_trees.out 
