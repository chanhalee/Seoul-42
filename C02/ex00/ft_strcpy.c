/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lch <lch@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:33:35 by lch               #+#    #+#             */
/*   Updated: 2021/09/15 17:18:16 by lch              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length(char	*arr);

char	*ft_strcpy(char	*dest, char	*src)
{
	int	temp;
	int	lena;

	temp = 0;
	lena = length(src);
	while (temp < lena)
	{
		dest[temp] = src[temp];
		temp++;
	}
	dest[temp] = '\0';
	return (dest);
}

int	length(char	*arr)
{
	int	temp;

	temp = 0;
	while (arr[temp] != '\0')
	{
		temp++;
	}
	return (temp);
}
