/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 01:29:21 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/01 22:48:29 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_tiny_case_four_five(t_stack *stack_a, t_stack *stack_b);
static void	sort_tiny_case_three(t_stack *stack_a, t_stack *stack_b);
static void	sort_tiny_case_six(t_stack *stack_a, t_stack *stack_b);

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

int	sort_tiny_case(t_stack *stack_a, t_stack *stack_b)
{
	if (check_sorted(stack_a, TYPE_STRAIGHT))
		return (1);
	if (stack_a->quantity < 7)
	{
		if (stack_a->quantity < 3)
		{
			if (stack_a->top->content > stack_a->top->before->content)
				operator(stack_a, stack_b, TYPE_OP_SA);
		}
		else if (stack_a->quantity < 4)
			sort_tiny_case_three(stack_a, stack_b);
		else
		{
			while (stack_a->quantity > 3)
				operator(stack_a, stack_b, TYPE_OP_PB);
			if (stack_b->quantity < 3)
				sort_tiny_case_four_five(stack_a, stack_b);
			else
				sort_tiny_case_six(stack_a, stack_b);
		}
		return (1);
	}
	return (0);
}

static void	sort_tiny_case_three(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->top->content > stack_a->top->before->content)
	{
		if (!(stack_a->top->content > stack_a->bottom->content)
			|| !(stack_a->top->before->content < stack_a->bottom->content))
		{
			operator(stack_a, stack_b, TYPE_OP_SA);
			if (!check_sorted(stack_a, TYPE_STRAIGHT))
				operator(stack_a, stack_b, TYPE_OP_RRA);
			return ;
		}
		operator(stack_a, stack_b, TYPE_OP_RA);
		return ;
	}
	else
	{
		operator(stack_a, stack_b, TYPE_OP_RRA);
		if (stack_a->top->content > stack_a->top->before->content)
			operator(stack_a, stack_b, TYPE_OP_SA);
	}
}

static void	sort_tiny_case_four_five(t_stack *stack_a, t_stack *stack_b)
{
	if (!check_sorted(stack_a, TYPE_STRAIGHT))
		sort_tiny_case_three(stack_a, stack_b);
	if (stack_b->quantity == 3)
	{
		if (stack_b->top->content > stack_b->top->before->content)
			operator(stack_a, stack_b, TYPE_OP_SB);
		merge_seq_a(stack_a, stack_b, 3, 2);
		return ;
	}
	operator(stack_a, stack_b, TYPE_OP_PA);
	if (stack_a->top->content > stack_a->bottom->content)
		operator(stack_a, stack_b, TYPE_OP_RA);
	else
	{
		if (stack_a->top->content > stack_a->top->before->content)
			operator(stack_a, stack_b, TYPE_OP_SA);
		if (!check_sorted(stack_a, TYPE_STRAIGHT))
		{
			operator(stack_a, stack_b, TYPE_OP_RA);
			operator(stack_a, stack_b, TYPE_OP_SA);
			operator(stack_a, stack_b, TYPE_OP_RA);
			operator(stack_a, stack_b, TYPE_OP_RA);
			operator(stack_a, stack_b, TYPE_OP_RA);
		}
	}
}

static void	sort_tiny_case_six(t_stack *stack_a, t_stack *stack_b)
{
	if (!check_sorted(stack_a, TYPE_STRAIGHT))
		sort_tiny_case_three(stack_a, stack_b);
	if (!check_sorted(stack_b, TYPE_STRAIGHT))
	{
		if (stack_b->top->content > stack_b->top->before->content)
		{
			if (!(stack_b->top->content > stack_b->bottom->content)
				|| !(stack_b->top->before->content < stack_b->bottom->content))
			{
				operator(stack_a, stack_b, TYPE_OP_SB);
				if (!check_sorted(stack_b, TYPE_STRAIGHT))
					operator(stack_a, stack_b, TYPE_OP_RRB);
				return ;
			}
			operator(stack_a, stack_b, TYPE_OP_RB);
			return ;
		}
		else
		{
			operator(stack_a, stack_b, TYPE_OP_RRB);
			if (stack_b->top->content > stack_b->top->before->content)
				operator(stack_a, stack_b, TYPE_OP_SB);
		}
	}
	merge_seq_a(stack_a, stack_b, 3, 3);
}
