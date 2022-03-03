/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_special_for_five.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:49:00 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/03 13:27:49 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sf_find_second_min(t_stack *stack)
{
	int			min;
	int			ret;
	t_content	*now;

	now = stack->top;
	min = now->content;
	while (now->before)
	{
		if (min > now->before->content)
			min = now->before->content;
		now = now->before;
	}
	now = stack->top;
	ret = now->content;
	if (ret == min)
		ret = now->before->content;
	while (now->before)
	{
		if (ret > now->before->content && min < now->before->content)
			ret = now->before->content;
		now = now->before;
	}
	return (ret);
}

void	sort_tiny_case_five(t_stack *stack_a, t_stack *stack_b)
{
	int	pivot;

	pivot = sf_find_second_min(stack_a);
	while (stack_a->quantity > 3)
	{
		if (stack_a->top->content <= pivot)
		{
			operator(stack_a, stack_b, TYPE_OP_PB);
		}
		else
			operator(stack_a, stack_b, TYPE_OP_RA);
	}
	if (stack_b->top->content < stack_b->top->before->content)
		operator(stack_a, stack_b, TYPE_OP_SB);
	if (!check_sorted(stack_a, TYPE_STRAIGHT))
		sort_tiny_case_three(stack_a, stack_b);
	operator(stack_a, stack_b, TYPE_OP_PA);
	operator(stack_a, stack_b, TYPE_OP_PA);
}
