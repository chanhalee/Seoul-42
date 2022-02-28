/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_manipulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:48:39 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/28 17:08:01 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_content	*iter_next_content(t_iterator *iterator)
{
	t_content	*ret;

	if (!iterator || iterator->stack_version != iterator->stack->version
		|| iterator->next_index >= iterator->stack->quantity)
		return (NULL);
	ret = iterator->next;
	(iterator->next_index)++;
	if (iterator->direction == TYPE_STRAIGHT)
		iterator->next = ret->before;
	else
		iterator->next = ret->next;
	return (ret);
}

t_content	*iter_retreat_content(t_iterator *iterator)
{
	t_content	*ret;

	if (!iterator || iterator->stack_version != iterator->stack->version
		|| iterator->next_index <= 0)
		return (NULL);
	(iterator->next_index)--;
	if (iterator->direction == TYPE_STRAIGHT)
		ret = iterator->next->next;
	else
		ret = iterator->next->before;
	iterator->next = ret;
	return (ret);
}

void	free_iterator(t_iterator **iterator)
{
	if (!iterator)
		return ;
	free(*iterator);
	*iterator = NULL;
}
