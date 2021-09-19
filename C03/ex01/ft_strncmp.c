/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 14:08:45 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/19 19:54:40 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	tempint1;
	unsigned int	t2;

	tempint1 = 0;
	t2 = 0;
	while (s1[tempint1] != '\0')
		tempint1++;
	while (t2 < tempint1 && t2 < n - 1)
	{
		if (s1[t2] != s2[t2])
			break ;
		t2++;
	}
	tempint1 = ((unsigned char *)s1)[t2] - ((unsigned char *)s2)[t2];
	return (tempint1);
}
