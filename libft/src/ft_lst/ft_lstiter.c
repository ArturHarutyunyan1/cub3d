/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:54:57 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/29 11:15:17 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*val;

	val = lst;
	while (val != NULL)
	{
		f(val->content);
		val = val->next;
	}
}

// void f(void *a)
// {
// 	printf("%s\n", (char *)a);
// }

// int main()
// {
// 	t_list *node1, *node2, *node3, *lst;

// 	node1 = (t_list *)malloc(sizeof(t_list));
// 	node2 = (t_list *)malloc(sizeof(t_list));
// 	node3 = (t_list *)malloc(sizeof(t_list));
// 	lst = (t_list *)malloc(sizeof(t_list));

// 	if (!node1 || !node2 || !node3)
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

// 	ft_lstiter(lst, &f);
// }
