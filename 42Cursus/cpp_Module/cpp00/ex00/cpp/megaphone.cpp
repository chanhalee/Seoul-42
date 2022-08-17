/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:21:16 by chanhale          #+#    #+#             */
/*   Updated: 2022/08/01 23:12:44 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>



int main(int argc, char **argv)
{
	using std::cout;
	using std::endl;
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
			if (argv[index1][index2] <= 'z' && argv[index1][index2] >= 'a')
				argv[index1][index2] -= 32;
		cout<<argv[index1];
	}
	cout<<endl;
	return(0);
}