/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:16:17 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/16 14:15:20 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
