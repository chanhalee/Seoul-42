/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 00:16:35 by chanhale          #+#    #+#             */
/*   Updated: 2021/12/29 00:35:06 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_ptr;

	if (lst == NULL || *lst == NULL || new == NULL)
		return ;
	lst_ptr = *lst;
	while (lst_ptr->next != NULL)
		lst_ptr = lst_ptr->next;
	lst_ptr->next = new;
}
