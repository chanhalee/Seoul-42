/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:38:47 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/22 22:52:22 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_iterator	*get_iterator_mind_null(t_stack *stack, int is_it_reverse)
{
	t_iterator	*ret;

	ret = (t_iterator*)malloc(sizeof(t_iterator));
	if (!ret)
		return (NULL);
	if (is_it_reverse == TYPE_REVERSE)
	{
		ret->direction = TYPE_REVERSE;
		ret->now = stack->bottom;	// can be null
	}
	else
	{
		ret->direction = TYPE_STRAIGHT;
		ret->now = stack->top;	// can be null
	}
	return(ret);
}