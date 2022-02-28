/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:38:47 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/28 17:02:53 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_iterator	*get_iterator(t_stack *stack, int is_it_reverse)
{
	t_iterator	*ret;

	ret = (t_iterator *)malloc(sizeof(t_iterator));
	if (!ret)
		emergency_exit();
	ret->stack = stack;
	ret->next_index = 0;
	ret->direction = is_it_reverse;
	if (!stack || !stack->quantity)
		ret->next = NULL;
	else
	{
		ret->stack_version = stack->version;
		if (is_it_reverse == TYPE_REVERSE)
			ret->next = stack->bottom;
		else
			ret->next = stack->top;
	}
	return (ret);
}

t_stack	*make_stack(void)
{
	t_stack	*ret;

	ret = (t_stack *)malloc(sizeof(stack_t));
	if (!ret)
		emergency_exit();
	ret->bottom = NULL;
	ret->top = NULL;
	ret->version = 0;
	ret->quantity = 0;
	return (ret);
}

t_content	*make_content(int integer)
{
	t_content	*ret;

	ret = (t_content *)malloc(sizeof(t_content));
	if (!ret)
		emergency_exit();
	ret->before = NULL;
	ret->next = NULL;
	ret->content = integer;
	return (ret);
}

void	free_content(t_content **content)
{
	if (!content || !*content)
		return ;
	free(*content);
	*content = NULL;
}

void	free_stack(t_stack **stack)
{
	t_content	*content;

	if (!stack || !*stack)
		return ;
	while ((*stack)->quantity > 0)
	{
		content = (*stack)->top;
		(*stack)->quantity--;
		(*stack)->top = content->before;
		free_content(&content);
	}
	free(*stack);
	*stack = NULL;
}
