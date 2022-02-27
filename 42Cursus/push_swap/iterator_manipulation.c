/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_manipulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 14:48:39 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/27 15:17:52 by chanhale         ###   ########.fr       */
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
		iterator->next = ret->next;
	else
		iterator->next = ret->before;
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
		ret = iterator->next->before;
	else
		ret = iterator->next->next;
	iterator->next = ret;
	return (ret);
}

void	iter_free(t_iterator **iterator)
{
	if (!iterator)
		return (NULL);
	free(*iterator);
	*iterator = NULL;
}
