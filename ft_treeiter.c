/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:04:50 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/17 16:04:52 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"


/*
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst-> content);
		lst = lst-> next;
	}
}
*/

static void	printtabs(int numtabs)
{
	int	i;

	i = 0;
	while (i < numtabs)
	{
		printf("\t");
		i++;
	}
}

static void	ft_treeiter_recursive(t_tree **root, void (*f)(void*), int level)
{
	t_tree *node;

	node = *root;
	printtabs(level);
	f(node->content);
	if (node->left)
		ft_treeiter_recursive(&(node->left), f, level + 1);
	if (node->right)
		ft_treeiter_recursive(&(node->right), f, level + 1);
}

void	ft_treeiter(t_tree **root, void (*f)(void *))
{
	ft_treeiter_recursive(root, f, 0);
}
