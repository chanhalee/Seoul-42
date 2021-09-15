/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahale <chahale@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:09:12 by chahale           #+#    #+#             */
/*   Updated: 2021/09/15 19:42:46 by chahale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	makelow(char	*str, int index);
void	makeup(char	*str, int index);

char	*ft_strcapitalize(char *str)
{
	int		flag;
	int		temp;

	flag = 1;
	temp = 0;
	while (str[temp] != '\0')
	{
		if (flag)
		{
			makeup (str, temp);
			temp++;
			flag = 0;
			continue ;
		}
		if (str[temp] == 32)
		{
			flag = 1;
			temp++;
			continue ;
		}
		makelow (str, temp);
		temp++;
	}
	return (str);
}

void	makelow(char	*str, int index)
{
	if ((str[index] >= 65 && str[index] <= 90))
	{
		str[index] += 32;
	}
}

void	makeup(char	*str, int index)
{
	if ((str[index] >= 97 && str[index] <= 122))
	{
		str[index] -= 32;
	}
}
