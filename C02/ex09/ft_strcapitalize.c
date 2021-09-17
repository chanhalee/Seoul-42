/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahale <chahale@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:09:12 by chahale           #+#    #+#             */
/*   Updated: 2021/09/16 20:21:59 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	makelow(char	*str, int index);
void	makeup(char	*str, int index);
int		checkalphanum(char c);

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
			flag = 0;
			if (checkalphanum(str[temp++]))
				flag = 1;
			continue ;
		}
		if (checkalphanum(str[temp++]))
		{
			flag = 1;
			continue ;
		}
		makelow (str, --temp);
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

int	checkalphanum(char c)
{
	if (c < 'a' || c > 'z')
		if (c < 'A' || c > 'Z')
			if (c < '0' || c > '9')
				return (1);
	return (0);
}
