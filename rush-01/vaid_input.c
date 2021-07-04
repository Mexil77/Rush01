/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agogolev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 12:19:37 by agogolev          #+#    #+#             */
/*   Updated: 2021/07/04 19:49:14 by agogolev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdio.h>
#include <unistd.h>

void	ft_error(void)
{
	write(1,"Error\n", 6);
	return;
}

void	ft_valid_input_combo(char *n)
{
	int	i;

	i = 0;
	while (i < 8 || (i + 8) < 16) //first 8 numbers or last 8 numbers
	{
		
	 	if ((n[i] == 49 && n[i + 3] == 50) || (n[i] == 50 && n[i + 3] == 49))
			i++;
		else if ((n[i] == 49 && n[i + 3] == 51) || (n[i] == 51 && n[i + 3] == 49))
			i++;
		else if ((n[i] == 49 && n[i + 3] == 52) || (n[i] == 52 && n[i + 3] == 49))
			i++;
		else if (n[i] == 50 && n[i + 3] == 50)
			i++;
		else if ((n[i] == 50 && n[i + 3] == 51) || (n[i] == 51 && n[i + 3] == 50))
			i++;
		else
			ft_error();
	}
	//ft_rules(n);
	printf("%s\n", n);
}

void	ft_valid_input_numnbers(char *numbers)
{
	//limit occuarances of each number
	int	i;
	int	n_1;
	int	n_2;
	int	n_3;
	int	n_4;

	i = 0;
	n_1 = 0;
	n_2 = 0;
	n_3 = 0;
	n_4 = 0;
	while (numbers != '\0')
	{
		if (numbers[i] == 49)
			n_1++;
		else if (numbers[i] == 50)
			n_2++;
		else if (numbers[i] == 51)
			n_3++;
		else
			n_4++;
		i++;
	}
	if (n_1 > 4 || n_2 > 8 || n_3 > 8 || n_4 > 4)
		ft_error();
	ft_valid_input_combo(numbers);
}

void	ft_valid_input(char *argv)
{
	int		i;
	int		count;
	char	numbers[16]; //stores numbers without spaces

	i = 0;
	count = 0; //to count 1234
	while (argv[i] != '\0')
	{
		//only space, 1, 2, 3, 4 in ascii
		if (!(argv[i] >= 49 && argv[i] <= 52) && !(argv[i] == 32))
			ft_error();
		else if (argv[i] >= 49 && argv[i] <= 52)
		{
			numbers[count] = argv[i];
			count++;
		}
		if ((i % 2 != 0) && (argv[i] != 32))
			ft_error();
		i++;
	}
	//number of input 1234 = 16
	if (count != 16)
			ft_error();
	ft_valid_input_numbers(numbers);
}
