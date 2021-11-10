/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahale <chahale@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:30:46 by chahale           #+#    #+#             */
/*   Updated: 2021/09/15 18:35:16 by chahale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int		temp;
	char	c;

	temp = 0;
	while (str[temp] != '\0')
	{
		c = str[temp];
		if ((c < 97 || c > 122))
		{
			return (0);
		}
		temp++;
	}
	return (1);
}
