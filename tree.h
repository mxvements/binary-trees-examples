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

//tree new
t_tree	*ft_treenew(void *content);
// tree add
void	ft_treeadd(t_tree **root, t_tree *new); //depends on t_content, uses nbr to behave as binary tree
void	ft_treeadd_right(t_tree **root, t_tree *new);
void	ft_treeadd_left(t_tree **root, t_tree *new);
//tree last (and depth)
t_tree	*ft_treelast(t_tree **root);
int		ft_treedepth(t_tree **root, t_tree *target);
//tree size
int		ft_treesize(t_tree **root);
//tree print
void	ft_treeprint(t_tree **root); //depends on t_content
//tree clear
void	ft_treeclear(t_tree **root, void (*del)(void  *));
void	del(void *content); //depends on t_content
#endif