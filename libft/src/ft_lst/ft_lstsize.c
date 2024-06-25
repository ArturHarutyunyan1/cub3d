/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:59:15 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/25 17:00:39 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int main()
// {
// 	t_list *lst, *node1, *node2, *node3;
// 	int size = 0;

// 	node1 = (t_list *)malloc(sizeof(t_list));
// 	node2 = (t_list *)malloc(sizeof(t_list));
// 	node3 = (t_list *)malloc(sizeof(t_list));
// 	lst = (t_list *)malloc(sizeof(t_list));

// 	if (!node1 || !node2 || !node3 || !lst)
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
// 	size = ft_lstsize(lst);
// 	printf ("%d", size);
// }