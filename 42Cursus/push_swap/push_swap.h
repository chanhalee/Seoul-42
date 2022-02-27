/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:23:29 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/27 20:12:32 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define TYPE_REVERSE 1
# define TYPE_STRAIGHT 0

typedef struct s_content
{
	void				*content;
	struct s_content	*before;
	struct s_content	*next;
}	t_content;

typedef struct s_stack
{
	int			quantity;
	int			version;
	t_content	*top;
	t_content	*bottom;
}	t_stack;

typedef struct s_iterator
{
	int			direction;
	int			stack_version;
	int			next_index;
	t_stack		*stack;
	t_content	*next;
}	t_iterator;

void		emergency_exit();
t_iterator	*get_iterator(t_stack *stack, int is_it_reverse);
t_stack		*make_stack(void);
t_content	*make_content(int integer);
t_stack		*stack_push_content(t_stack *stack, t_content *content);
t_content	*stack_pop_content(t_stack *stack);
t_content	*iter_next_content(t_iterator *iterator);
t_content	*iter_retreat_content(t_iterator *iterator);
void		iter_free(t_iterator **iterator);

#endif