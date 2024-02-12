/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:02:28 by luciama2          #+#    #+#             */
/*   Updated: 2024/02/12 19:02:35 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	del(void *content)
{
	free(content);
}

void	ft_treeclear(t_tree **root, void (*del)(void *))
{
	if (!(*root))
		return ;
	if ((*root)->left)
		ft_treeclear(&((*root)->left), del);
	if ((*root)->right)
		ft_treeclear(&((*root)->right), del);
	del((*root)->content);
	(*root)->content = NULL;
	free(*root);
	(*root) = NULL;
}
