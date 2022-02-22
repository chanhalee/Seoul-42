/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:23:29 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/22 22:49:24 by chanhale         ###   ########.fr       */
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
	t_content	*top;
	t_content	*bottom;
}	t_stack;

typedef struct s_iterator
{
	int			direction;
	t_content	*now;
}	t_iterator;

#endif