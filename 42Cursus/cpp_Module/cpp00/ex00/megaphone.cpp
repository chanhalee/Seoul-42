/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:21:16 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/01 16:32:33 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	int	index1;
	int index2;

	if (argc < 2)
	{
		cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<endl;
		return (0);
	}
	index1 = 0;
	while (++index1 < argc)
	{
		index2 = -1;
		while (argv[index1][++index2] != '\0')
			cout<<(char)std::toupper(argv[index1][index2]);
	}
	cout<<endl;
	return(0);
}