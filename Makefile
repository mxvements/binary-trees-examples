CC=cc
CFLAGS=-Wall -Wextra -Werror -g3
SRC=	binary_trees.c \
		ft_treenew.c \
		ft_treeadd.c \
		ft_treelast.c \
		ft_treesize.c \
		ft_treeprint.c \
		ft_treeclear.c

all:
	$(CC) $(CFLAGS) $(SRC) -o binary_trees.out

clean:
	rm binary_trees.out 
