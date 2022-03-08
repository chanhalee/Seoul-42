/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 22:23:29 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/08 20:58:23 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define TYPE_REVERSE 1
# define TYPE_STRAIGHT 0
# define TYPE_PARSE_ERROR -2147483649
# define TYPE_OP_BIAS_A -1
# define TYPE_OP_BIAS_B 1
# define TYPE_OP_SA 99
# define TYPE_OP_SS 100
# define TYPE_OP_SB 101
# define TYPE_OP_PA 199
# define TYPE_OP_PX 200
# define TYPE_OP_PB 201
# define TYPE_OP_RA 299
# define TYPE_OP_RR 300
# define TYPE_OP_RB 301
# define TYPE_OP_RRA 399
# define TYPE_OP_RRR 400
# define TYPE_OP_RRB 401

typedef struct s_content
{
	int					content;
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

void		emergency_exit(void);
char		**ft_split(char const *s, char c);
long long	ft_atoll(char *str);
t_stack		*parse_input(int argc, char **argv);
void		operator(t_stack *stack_a, t_stack *stack_b, int operation);
t_iterator	*get_iterator(t_stack *stack, int is_it_reverse);
t_stack		*make_stack(void);
t_content	*make_content(int integer);
t_stack		*stack_push_content(t_stack *stack, t_content *content);
t_stack		*stack_push_back_content(t_stack *stack, t_content *content);
t_content	*stack_pop_content(t_stack *stack);
t_content	*stack_pop_back_content(t_stack *stack);
t_content	*iter_next_content(t_iterator *iterator);
t_content	*iter_retreat_content(t_iterator *iterator);
void		free_iterator(t_iterator **iterator);
void		free_content(t_content **content);
void		free_stack(t_stack **stack);
int			check_sorted(t_stack *stack, int is_it_reverse);
int			sort_tiny_case(t_stack *stack_a, t_stack *stack_b);
void		merge_seq_a(t_stack *stack_a, t_stack *stack_b, int n_a, int n_b);
void		sort_tiny_case_three(t_stack *stack_a, t_stack *stack_b);
void		sort_tiny_case_five(t_stack *stack_a, t_stack *stack_b);
void		merge_sort(t_stack *stack_a, t_stack *stack_b);

#endif