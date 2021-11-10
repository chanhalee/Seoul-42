/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahale <chahale@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:50:59 by chahale           #+#    #+#             */
/*   Updated: 2021/09/15 18:56:59 by chahale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char	*str)
{
	int		temp;
	char	c;

	temp = 0;
	while (str[temp] != '\0')
	{
		c = str[temp];
		if ((c < 32 || c > 126))
		{
			return (0);
		}
		temp++;
	}
	return (1);
}
