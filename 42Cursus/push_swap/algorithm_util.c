/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:29:21 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/01 01:29:31 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack, int is_it_reverse)
{
	t_iterator	*iter;
	int			former_content;

	if (stack->quantity <= 1)
		return (1);
	if (is_it_reverse == TYPE_STRAIGHT)
		iter = get_iterator(stack, TYPE_STRAIGHT);
	else
		iter = get_iterator(stack, TYPE_REVERSE);
	former_content = iter_next_content(iter)->content;
	while (iter->next)
	{
		if (former_content > iter->next->content)
		{
			free_iterator(&iter);
			return (0);
		}
		former_content = iter_next_content(iter)->content;
	}
	free_iterator(&iter);
	return (1);
}