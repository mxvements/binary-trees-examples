#ifndef TREE_H
# define TREE_H
# include <stdlib.h>
# include <stdio.h>

typedef struct s_tree
{
	void			*content;
	struct s_tree	*right;
	struct s_tree	*left;
}	t_tree;

typedef struct s_content
{
	int	nbr;
}	t_content;

#endif