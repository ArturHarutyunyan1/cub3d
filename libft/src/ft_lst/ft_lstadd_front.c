/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:49:23 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/25 16:49:57 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// int main()
// {
// 	t_list *lst, *new, *node1, *node2, *node3, *current;

// 	node1 = (t_list *)malloc(sizeof(t_list));
// 	node2 = (t_list *)malloc(sizeof(t_list));
// 	node3 = (t_list *)malloc(sizeof(t_list));
// 	new = (t_list *)malloc(sizeof(t_list));

// 	new->content = "Beginning of the list";
// 	node1->content = "Hello";
// 	node2->content = "Gaspar";
// 	node3->content = "Vaspur";

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;
// 	lst = node1;
// 	ft_lstadd_front(&lst, new);
// 	current = lst;
// 	while (current != NULL)
// 	{
// 		printf ("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	free (new);
// 	free (node1);
// 	free (node2);
// 	free (node3);
// }