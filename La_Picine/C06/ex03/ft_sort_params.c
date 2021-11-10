/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 03:37:24 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/23 04:14:18 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	tempint1;
	unsigned int	ti2;

	tempint1 = 0;
	ti2 = 0;
	while (s1[tempint1] != '\0')
		tempint1++;
	while (ti2 < tempint1)
	{
		if (s1[ti2] != s2[ti2])
			break ;
		ti2++;
	}
	tempint1 = ((unsigned char *)s1)[ti2] - ((unsigned char *)s2)[ti2];
	return (tempint1);
}

void	sub(int argc, char **argv)
{
	int		ia;
	int		ib;
	char	*c;

	ia = 0;
	while (++ia < argc)
	{
		ib = ia;
		while (++ib < argc)
		{
			if (ft_strcmp(argv[ia], argv[ib]) > 0)
			{	
				c = argv[ia];
				argv[ia] = argv[ib];
				argv[ib] = c;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc;
	i = 0;
	sub(argc, argv);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			write(1, (argv[i] + j), 1);
		write(1, "\n", 1);
	}
	return (0);
}
