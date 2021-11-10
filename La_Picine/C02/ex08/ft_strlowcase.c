/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahale <chahale@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:05:41 by chahale           #+#    #+#             */
/*   Updated: 2021/09/15 19:07:00 by chahale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char	*str)
{
	int		temp;
	char	c;

	temp = 0;
	while (str[temp] != '\0')
	{
		c = str[temp];
		if ((c >= 65 && c <= 90))
		{
			str[temp] += 32;
		}
		temp++;
	}
	return (str);
}
