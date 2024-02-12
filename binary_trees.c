#include "tree.h"

/*	libft list functions for reference
	t_list	*ft_lstnew(void *content);
	void	ft_lstadd_front(t_list **lst, t_list *new);
	void	ft_lstadd_back(t_list **lst, t_list *new);
	int		ft_lstsize(t_list *lst);
	t_list	*ft_lstlast(t_list *lst);
	void	ft_lstclear(t_list **lst, void (*del)(void *));

	void	ft_lstdelone(t_list *lst, void (*del)(void *));
	void	ft_lstiter(t_list *lst, void (*f)(void *));
	t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
*/

/* TREE NEW NODE */
t_tree	*ft_treenew(void *content)
{
	t_tree	*treenode;

	treenode = (t_tree *)malloc(sizeof(t_tree));
	if (!treenode)
		return (NULL);
	treenode->content = content;
	treenode->left = NULL;
	treenode->right = NULL;
	return (treenode);
}
/* TREE ADD */

void	ft_treeadd_left(t_tree **tree, t_tree *new)
{
	t_tree	*node;

	node = *tree;
	if (!node)
		return ; //empty tree
	node->left = new;
}

void	ft_treeadd_right(t_tree **root, t_tree *new)
{
	t_tree	*node;

	node = *root;
	if (!node)
		return ; //empty tree
	node->right = new;
}

/* TREE LEAF (LAST) && TREE DEPTH */
int		ft_treedepth_recursive(t_tree **root, t_tree *target, int depth)
{
	int	depth_left;
	int	depth_right;

	if (*root == target)
		return (depth);
	if (!(*root))
		return (-1);
	depth++;
	depth_left = ft_treedepth_recursive(&((*root)->left), target, depth);
	depth_right = ft_treedepth_recursive(&((*root)->right), target, depth);
	if (depth_left > 0)
		return (depth_left);
	return (depth_right);
}
int		ft_treedepth(t_tree **root, t_tree *target)
{
	return (ft_treedepth_recursive(root, target, 0));
}

t_tree	*ft_treelast(t_tree **root)
{
	t_tree	*node;
	t_tree 	*last_left;
	t_tree	*last_right;
	int		last_left_depth;
	int		last_right_depth;

	node = *root;
	last_left_depth = 0;
	last_right_depth = 0;
	if (!node->left && !node->right)
		return (node);
	if (node->left)
	{
		last_left = ft_treelast(&(node->left));
		last_left_depth = ft_treedepth(root, last_left);
	}
	if (node->right)
	{
		last_right = ft_treelast(&(node->right));
		last_right_depth = ft_treedepth(root, last_right);
	}
	if (last_left_depth >= last_right_depth)
		return (last_left);
	return (last_right);
}

/* TREE SIZE RECURSIVE */

int	ft_treesize_recursive(t_tree **root, int *count)
{
	t_tree	*node;

	node = *root;
	if (!node)
		return (*count);
	(*count)++;
	ft_treesize_recursive(&(node->left), count);
	ft_treesize_recursive(&(node->right), count);
	return (*count);
}
int	ft_treesize(t_tree **root)
{
	int	count;

	count = 0;
	return (ft_treesize_recursive(root, &count));
}

/* PRINT TREE RECURSIVE */

static void	printtabs(int numtabs)
{
	for (int i = 0; i < numtabs; i++)
	{
		printf("\t");
	}
}
void	ft_treeprint_recursive(t_tree **root, int level)
{
	t_tree		*node;
	t_content	*content;

	/*	preorder traversal order
		we print out the data in the node first
		followed by the left subtree
		followed by the right subtree

		trees work really well with recursion (we can benefit from it)
		everything we do for the root, we do for all subtrees
	*/
	node = *root;
	if (!node)
	{
		printtabs(level);
		printf("---<empty>---\n");
		return;
	}
	content = node->content;

	printtabs(level);
	printf("value: %d\n", (int)content->nbr);
	printtabs(level);
	printf("left: \n");

	ft_treeprint_recursive(&(node->left), level+1);

	printtabs(level);
	printf("right: \n");

	ft_treeprint_recursive(&(node->right), level+1);

	printtabs(level);
	printf("done\n");
	return ;
}
void	ft_treeprint(t_tree **root)
{
	return ft_treeprint_recursive(root, 0);
}

/* TREE CLEAR */
//void	ft_lstclear(t_list **lst, void (*del)(void *));

void	del(void *content)
{
	free(content);
}

void	ft_treeclear(t_tree **root, void (*del)(void  *))
{
	if (!(*root))
		return;
	if ((*root)->left)
		ft_treeclear(&((*root)->left), del);
	if ((*root)->right)
		ft_treeclear(&((*root)->right), del);
	del((*root)->content);
	(*root)->content = NULL;
	free(*root);
	(*root) = NULL;
}

int	main(void)
{
	//https://www.youtube.com/watch?v=fAAZixBzIAI in js
	//https://www.youtube.com/watch?v=UbhlOk7vjVY in C
	/*	parent	-> two children (left and right) at most
		root	-> node that has no parent
		leafs	-> nodes that have no children

		BT criteria:
		- at most 2 children per node
		- exactly 1 root
		- exctly
	*/

	//content
	t_content		*c1 = malloc(sizeof(t_content));
	c1->nbr = 10;
	t_content		*c2 = malloc(sizeof(t_content));
	c2->nbr = 11;
	t_content		*c3 = malloc(sizeof(t_content));
	c3->nbr = 12;
	t_content		*c4 = malloc(sizeof(t_content));
	c4->nbr = 13;
	t_content		*c5 = malloc(sizeof(t_content));
	c5->nbr = 14;
	t_content		*c6 = malloc(sizeof(t_content));
	c6->nbr = 15;
	//nodes
	t_tree	*n1 = ft_treenew((void *)c1);
	t_tree	*n2 = ft_treenew((void *)c2);
	t_tree	*n3 = ft_treenew((void *)c3);
	t_tree	*n4 = ft_treenew((void *)c4);
	t_tree	*n5 = ft_treenew((void *)c5);
	t_tree	*n6 = ft_treenew((void *)c6);

	//define root
	t_tree **root = &n1; 

	//connect them up into a BT
	ft_treeadd_left(root, n2);
	ft_treeadd_right(root, n3);
	ft_treeadd_left(&n2, n4);
	ft_treeadd_right(&n2, n5);
	ft_treeadd_left(&n3, n6);

	//print tree
	ft_treeprint(root);

	//print size of tree
	printf("size of tree: %d \n", ft_treesize(root));

	//print last
	t_content	*last_content = ft_treelast(root)->content;
	printf("last node %d\n", last_content->nbr);

	//printf depth
	printf("depth last node: %d\n", ft_treedepth(root, ft_treelast(root)));

	/*
	//free
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);*/

	//tree clear
	ft_treeclear(root, del);
	return (0);
}