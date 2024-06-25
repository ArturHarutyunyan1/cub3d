/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:17:04 by arturhar          #+#    #+#             */
/*   Updated: 2024/01/29 11:16:09 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;
	t_list	*val;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	while (lst != NULL)
	{
		val = f(lst->content);
		node = ft_lstnew(val);
		if (!node)
		{
			del(val);
			ft_lstclear(&result, (*del));
			return (result);
		}
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}

// void *f(void *a)
// {
// 	char *dup;

// 	dup = ft_strdup((char *)a);
// 	return ((char *)dup);
// }

// void del(void *a)
// {
// 	free (a);
// }

// int main()
// {
// 	t_list *node1, *node2, *node3, *lst, *result;

// 	node1 = (t_list *)malloc(sizeof(t_list));
// 	node2 = (t_list *)malloc(sizeof(t_list));
// 	node3 = (t_list *)malloc(sizeof(t_list));
// 	lst = (t_list *)malloc(sizeof(t_list));
// 	result = (t_list *)malloc(sizeof(t_list));

// 	if (!node1 || !node2 || !node3 || !result || !lst)
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
// 	result = ft_lstmap(lst, f, &del);

// 	while (result)
// 	{
// 		printf ("%s\n", (char *)result->content);
// 		result = result->next;
// 	}
// }
