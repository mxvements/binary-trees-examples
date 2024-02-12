/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:59:03 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/12 18:59:04 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static int	ft_treesize_recursive(t_tree **root, int *count)
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
