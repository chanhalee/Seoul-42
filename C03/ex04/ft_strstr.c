/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:42:40 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/19 19:58:05 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	c1;
	unsigned int	c2;
	int				flag;

	flag = 1;
	c1 = -1;
	while (str[++c1] != '\0')
	{
		c2 = -1;
		while (to_find[++c2] != '\0' && str[c1 + c2] != '\0')
			if (to_find[c2] != str[c1 + c2])
				break ;
		if (to_find[c2] == '\0')
			return (str + c1);
	}
	return (0);
}
