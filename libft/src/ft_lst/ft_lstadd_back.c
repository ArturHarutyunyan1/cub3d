/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:48:02 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/25 16:49:08 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}

// int main()
// {
	// t_list *lst, *node1, *node2, *node3, *new, *current;

	// node1 = (t_list *)malloc(sizeof(t_list));
	// node2 = (t_list *)malloc(sizeof(t_list));
	// node3 = (t_list *)malloc(sizeof(t_list));
	// new = (t_list *)malloc(sizeof(t_list));

// 	node1->content = "Hello";
// 	node2->content = "Gaspar";
// 	node3->content = "Vaspur";
// 	new->content = "End of the list";

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;

// 	lst = node1;
// 	ft_lstadd_back(&lst, new);
// 	current = lst;
// 	while (current != NULL)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	free (node1);
// 	free (node2);
// 	free (node3);
// 	free (new);
// }