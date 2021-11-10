/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahale <chahale@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:38:24 by chahale           #+#    #+#             */
/*   Updated: 2021/09/15 18:39:04 by chahale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int		temp;
	char	c;

	temp = 0;
	while (str[temp] != '\0')
	{
		c = str[temp];
		if ((c < 65 || c > 90))
		{
			return (0);
		}
		temp++;
	}
	return (1);
}
