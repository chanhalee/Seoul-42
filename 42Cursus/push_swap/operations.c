/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:41:09 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/01 17:36:53 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	op_check(t_stack *stack_a, t_stack *stack_b, int reqire_quantity)
{
	if (stack_a->quantity >= reqire_quantity
		&& stack_b->quantity >= reqire_quantity)
		return (1);
	return (0);
}

static int	op_swap(t_stack *stack)
{
	t_content	*content_first;
	t_content	*content_second;

	if (stack->quantity < 2)
		return (0);
	content_first = stack_pop_content(stack);
	content_second = stack_pop_content(stack);
	stack_push_content(stack, content_first);
	stack_push_content(stack, content_second);
	return (1);
}

static int	op_push(t_stack *stack_from, t_stack *stack_to)
{
	t_content	*content;

	if (stack_from->quantity < 1)
		return (0);
	content = stack_pop_content(stack_from);
	stack_push_content(stack_to, content);
	return (1);
}

static int	op_rotate(t_stack *stack, int is_it_reverse)
{
	t_content	*content;

	if (stack->quantity < 1)
		return (0);
	if (is_it_reverse == TYPE_REVERSE)
	{
		content = stack_pop_back_content(stack);
		stack_push_content(stack, content);
	}
	else
	{
		content = stack_pop_content(stack);
		stack_push_back_content(stack, content);
	}
	return (1);
}

void	operator(t_stack *stack_a, t_stack *stack_b, int operation)
{
	if (operation == TYPE_OP_SA && op_swap(stack_a))
		write(1, "sa\n", 3);
	else if (operation == TYPE_OP_SB && op_swap(stack_b))
		write(1, "sb\n", 3);
	else if (operation == TYPE_OP_SS && op_check(stack_a, stack_b, 2)
		&& op_swap(stack_a) && op_swap(stack_b))
		write(1, "ss\n", 3);
	else if (operation == TYPE_OP_PA && op_push(stack_b, stack_a))
		write(1, "pa\n", 3);
	else if (operation == TYPE_OP_PB && op_push(stack_a, stack_b))
		write(1, "pb\n", 3);
	else if (operation == TYPE_OP_RA && op_rotate(stack_a, TYPE_STRAIGHT))
		write(1, "ra\n", 3);
	else if (operation == TYPE_OP_RB && op_rotate(stack_b, TYPE_STRAIGHT))
		write(1, "rb\n", 3);
	else if (operation == TYPE_OP_RR && op_check(stack_a, stack_b, 1)
		&& op_rotate(stack_a, 0) && op_rotate(stack_b, TYPE_STRAIGHT))
		write(1, "rr\n", 3);
	else if (operation == TYPE_OP_RRA && op_rotate(stack_a, TYPE_REVERSE))
		write(1, "rra\n", 4);
	else if (operation == TYPE_OP_RRB && op_rotate(stack_b, TYPE_REVERSE))
		write(1, "rrb\n", 4);
	else if (operation == TYPE_OP_RRR && op_check(stack_a, stack_b, 1)
		&& op_rotate(stack_a, TYPE_REVERSE) && op_rotate(stack_b, TYPE_REVERSE))
		write(1, "rrr\n", 4);
}
