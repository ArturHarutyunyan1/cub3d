/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:06 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/29 11:15:03 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst->content)
		(del)(lst->content);
	free (lst);
}

/*
void	del(void *a)
{
	free (a);
}*/

/*
int main()
{
	t_list *node1, *node2, *node3;

	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node3 = (t_list *)malloc(sizeof(t_list));

	if (!node1 || !node2 || !node3)
	{
		return (0);
	}

	node1->content = "Gasparcho";
	node2->content = "Vaspurak";
	node3->content = "Agatangexos";

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("nodes before\n
	node1 - %s\n
	node2 - %s\n
	node3 - %s\n",
	(char *)node1->content,
	(char *)node2->content,
	(char *)node3->content);
	ft_lstdelone(node1, &del);
	ft_lstdelone(node2, &del);
	ft_lstdelone(node3, &del);
	return (0);
}*/
