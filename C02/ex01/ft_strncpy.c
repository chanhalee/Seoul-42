/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lch <lch@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:19:38 by lch               #+#    #+#             */
/*   Updated: 2021/09/15 17:42:00 by lch              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char	*dest, char	*src, unsigned int n)
{
	unsigned int	temp;

	temp = 0;
	while (src[temp] != '\0' && temp < n)
	{
		dest[temp] = src[temp];
		temp++;
	}
	while (temp < n)
	{
		dest[temp] = '\0';
		temp++;
	}
	return (dest);
}
