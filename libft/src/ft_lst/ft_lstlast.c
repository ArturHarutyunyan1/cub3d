/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:56:08 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/29 11:15:54 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

// int main()
// {
// 	t_list *node1, *node2, *node3, *lst, *last;

// 	node1 = (t_list *)malloc(sizeof(t_list));
// 	node2 = (t_list *)malloc(sizeof(t_list));
// 	node3 = (t_list *)malloc(sizeof(t_list));
// 	lst = (t_list *)malloc(sizeof(t_list));
// 	last = (t_list *)malloc(sizeof(t_list));

// 	if (!node1 || !node2 || !node3 || !lst || !last)
// 	{
// 		return (0);
// 	}
// 	node1->content = "Gasparcho";
// 	node2->content = "Vaspurak";
// 	node3->content = "Agatangexos";

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;	
// 	lst = node1;
// 	last = ft_lstlast(lst);
// 	printf("%s", (char *)last->content);	
// }
