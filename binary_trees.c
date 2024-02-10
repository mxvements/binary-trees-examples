#include "tree.h"

/*	libft list functions for reference
	t_list	*ft_lstnew(void *content);
	void	ft_lstadd_front(t_list **lst, t_list *new);
	void	ft_lstadd_back(t_list **lst, t_list *new);
	int		ft_lstsize(t_list *lst);
	t_list	*ft_lstlast(t_list *lst);
	void	ft_lstdelone(t_list *lst, void (*del)(void *));
	void	ft_lstclear(t_list **lst, void (*del)(void *));
	void	ft_lstiter(t_list *lst, void (*f)(void *));
	t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
*/

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
	t_content		c1;
	c1.nbr = 10;
	t_content		c2;
	c2.nbr = 11;
	t_content		c3;
	c3.nbr = 12;
	t_content		c4;
	c4.nbr = 13;
	t_content		c5;
	c5.nbr = 14;
	t_content		c6;
	c6.nbr = 15;
	//nodes
	t_tree	*n1 = ft_treenew((void *)&c1);
	t_tree	*n2 = ft_treenew((void *)&c2);
	t_tree	*n3 = ft_treenew((void *)&c3);
	t_tree	*n4 = ft_treenew((void *)&c4);
	t_tree	*n5 = ft_treenew((void *)&c5);
	t_tree	*n6 = ft_treenew((void *)&c6);

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

	//free
	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);
	return (0);
}