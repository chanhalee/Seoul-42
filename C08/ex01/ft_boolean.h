/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chahale@student.42seoul.kr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:17:55 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/25 19:43:49 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_BOOLEAN_H
# define FT_BOOLEAN_H

#include <unistd.h>

typedef int t_bool;

# define TRUE 1
# define FALSE 0
# define EVEN(x) (((x) % 2) == 0)
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0

#endif
