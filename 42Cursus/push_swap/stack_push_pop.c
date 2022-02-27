/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:41:01 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/27 20:12:29 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_push_content(t_stack *stack, t_content *content)
{
	if (!stack || !content)
		return (stack);
	if (!(stack->bottom))
		stack->bottom = content;
	else
		stack->top->next = content;
	(stack->quantity)++;
	(stack->version)++;
	content->before = stack->top;
	stack->top = content;
	return (stack);
}

t_content	*stack_pop_content(t_stack *stack)
{
	t_content	*ret;

	if (!stack->top)
		return (NULL);
	ret = stack->top;
	stack->top = ret->before;
	ret->before = NULL;
	ret->next = NULL;
	stack->quantity--;
	(stack->version)++;
	if (stack->before == NULL)
		stack->bottom = NULL;
	else
		stack->top->next = NULL;
	return (ret);
}
