/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:50:01 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/29 11:11:03 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*val;

	if (*lst)
	{
		while (*lst != NULL)
		{
			val = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = val;
		}
		*lst = NULL;
	}
}
/*
void del(char *a)
{
	free (a);
}

int main()
{
	t_list *node1, *node2, *node3, **lst;

	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node3 = (t_list *)malloc(sizeof(t_list));
	lst = (t_list **)malloc(sizeof(t_list));
	if (!node1 || !node2 || !node3 || !lst)
	{
		return (0);
	}

	node1->content = "Gasparcho";
	node2->content = "Vaspurak";
	node3->content = "Agatangexos";

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	*lst = node1;
	printf("nodes before\n
	node1 - %s\n
	nnode2 - %s\n
	nnode3 - %s\n
	", (char *)node1->content,
	(char *)node2->content,
	(char *)node3->content);
	ft_lstclear(lst, &del);
}*/