/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:00:16 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/12 19:00:17 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

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
