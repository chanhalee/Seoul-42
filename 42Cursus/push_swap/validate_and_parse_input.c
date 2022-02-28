/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_and_parse_input.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:03:31 by chanhale          #+#    #+#             */
/*   Updated: 2022/02/28 17:38:13 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verify_unique(int num, t_stack *stack)
{
	t_content	*cmp;

	cmp = stack->top;
	while (cmp)
	{
		if (num == cmp->content)
		{
			free_stack(&stack);
			emergency_exit();
		}
		cmp = cmp->before;
	}
	return (1);
}

static void	clear_all_static(char ***arr)
{
	int	index_out;

	if (!arr || !(*arr))
		return ;
	index_out = -1;
	while ((*arr)[++index_out])
		free((*arr)[index_out]);
	free(*arr);
	*arr = NULL;
}

t_stack	*parse_input(int argc, char **argv)
{
	char		**arg_arr_2d;
	int			arr_2d_index;
	long long	parsed_integer;
	t_stack		*ret;

	if (argc < 2)
		exit(1);
	ret = make_stack();
	while (--argc > 0)
	{
		arr_2d_index = -1;
		arg_arr_2d = ft_split(*(++argv), ' ');
		while (arg_arr_2d[++arr_2d_index])
		{
			parsed_integer = ft_atoll(arg_arr_2d[arr_2d_index]);
			if (parsed_integer == TYPE_PARSE_ERROR
				|| !verify_unique(parsed_integer, ret))
				emergency_exit();
			stack_push_back_content(ret, make_content((int)parsed_integer));
		}
		printf("%d\n", ret->bottom->content);
		clear_all_static(&arg_arr_2d);
	}
	return (ret);
}
