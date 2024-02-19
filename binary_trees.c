/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_trees.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:06:33 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/12 19:06:35 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

/*	LIBFT LIST FUNCTS FOR REFERENCE
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

/*	parent	-> two children (left and right) at most
	root	-> node that has no parent
	leafs	-> nodes that have no children
	BT criteria:
	- at most 2 children per node
	- exactly 1 root
	- exctly
*/

static void	printcontent_nbr(void *content)
{
	printf("%d\n", ((t_content *)content)->nbr);
}

int	main(void)
{

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
	c5->nbr = 9;
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

	/*
	ft_treeadd_left(root, n2);
	ft_treeadd_right(root, n3);
	ft_treeadd_left(&n2, n4);
	ft_treeadd_right(&n2, n5);
	ft_treeadd_left(&n3, n6);*/

	//build binary tree (using nbr on t_content)
	ft_treeadd(root, n2);
	ft_treeadd(root, n4);
	ft_treeadd(root, n3);
	ft_treeadd(root, n6);
	ft_treeadd(root, n5);

	//print tree
	ft_treeprint(root);

	//print size of tree
	printf("size of tree: %d \n", ft_treesize(root));

	//print last
	t_content	*last_content = ft_treelast(root)->content;
	printf("last node %d\n", last_content->nbr);

	//printf depth
	printf("depth last node: %d\n", ft_treedepth(root, ft_treelast(root)));

	//use of ft_treeiter to print nbr on each node
	printf("using treeiter to print nbr on each level/node: \n");
	ft_treeiter(root, printcontent_nbr);

	//tree clear
	ft_treeclear(root, del);
	system("leaks -q binary_trees.out");
	return (0);
}
