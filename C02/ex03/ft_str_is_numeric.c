/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahale <chahale@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:23:46 by chahale           #+#    #+#             */
/*   Updated: 2021/09/16 17:46:50 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char	*str)
{
	int		temp;
	char	c;

	temp = 0;
	while (str[temp] != '\0')
	{
		c = str[temp];
		if ((c < 48 || c > 57))
		{
			return (0);
		}
		temp++;
	}
	return (1);
}
