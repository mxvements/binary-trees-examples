/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:55:09 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/12 18:55:11 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	ft_treeadd_left(t_tree **root, t_tree *new)
{
	t_tree	*node;

	node = *root;
	if (!node)
		return ;
	node->left = new;
}

void	ft_treeadd_right(t_tree **root, t_tree *new)
{
	t_tree	*node;

	node = *root;
	if (!node)
		return ;
	node->right = new;
}

void	ft_treeadd(t_tree **root, t_tree *new)
{
	t_tree		*node;
	t_content	*node_content;
	t_content	*new_content;

	node = *root;
	node_content = node->content;
	new_content = new->content;
	if (node_content->nbr > new_content->nbr)
	{
		if (!node->left)
			ft_treeadd_left(root, new);
		ft_treeadd(&(node->left), new);
	}
	if (node_content->nbr < new_content->nbr)
	{
		if (!node->right)
			ft_treeadd_right(root, new);
		ft_treeadd(&(node->right), new);
	}
}
