/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 12:41:01 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/01 17:42:11 by chanhale         ###   ########.fr       */
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

t_stack	*stack_push_back_content(t_stack *stack, t_content *content)
{
	if (!stack || !content)
		return (stack);
	if (!(stack->top))
		stack->top = content;
	else
		stack->bottom->before = content;
	(stack->quantity)++;
	(stack->version)++;
	content->next = stack->bottom;
	stack->bottom = content;
	return (stack);
}

t_content	*stack_pop_content(t_stack *stack)
{
	t_content	*ret;

	if (!stack->top)
		return (NULL);
	ret = stack->top;
	(stack->quantity)--;
	(stack->version)++;
	stack->top = ret->before;
	if (stack->top == NULL)
		stack->bottom = NULL;
	else
		stack->top->next = NULL;
	ret->before = NULL;
	return (ret);
}

t_content	*stack_pop_back_content(t_stack *stack)
{
	t_content	*ret;

	if (!stack->bottom)
		return (NULL);
	ret = stack->bottom;
	stack->quantity--;
	(stack->version)++;
	stack->bottom = ret->next;
	if (stack->bottom == NULL)
		stack->top = NULL;
	else
		stack->bottom->before = NULL;
	ret->next = NULL;
	return (ret);
}
