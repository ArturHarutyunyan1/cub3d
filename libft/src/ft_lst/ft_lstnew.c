/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:56:38 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/29 11:16:22 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = (t_list *)malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}

// int main()
// {
// 	t_list *lst, *node1, *node2, *node3

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

// 	lst = ft_lstnew("Movses");	
// 	while (lst != NULL)
// 	{
// 		printf("%s", (char *)lst->content);
// 		lst = lst -> next;
// 	}
// }
