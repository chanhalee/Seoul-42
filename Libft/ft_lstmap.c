/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:38:22 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 01:20:40 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_new_t_list(t_list **new);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*result_iter;
	t_list	*new_item;

	if (lst == NULL || f == NULL || alloc_new_t_list(&result))
		return (NULL);
	result_iter = result;
	result_iter->content = f(lst->content);
	del(lst->content);
	result_iter->next = lst->next;
	free(lst);
	while (result_iter->next != NULL)
	{
		if (alloc_new_t_list(&new_item))
			return (NULL);
		new_item->content = f(result_iter->next->content);
		del(result_iter->next->content);
		new_item->next = result_iter->next->next;
		free(result_iter->next);
		result_iter->next = new_item;
		result_iter = result_iter->next;
	}
	return (result);
}

static int	alloc_new_t_list(t_list **new)
{
	if (new == NULL)
		return (1);
	*new = (t_list *)malloc(sizeof (t_list));
	if (*new == NULL)
		return (1);
	return (0);
}
