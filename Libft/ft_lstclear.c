/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:28:24 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 00:34:36 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		lst = &next;
	}
}
