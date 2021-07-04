/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:38:10 by emgarcia          #+#    #+#             */
/*   Updated: 2021/07/04 21:04:13 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_fill_found_data(int *a)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		*a = 0;
		i++;
	}
	a -= 4;
}

void	ft_found_data(int index, int *found_data, int *solved)
{
	int	i;

	i = 0;
	solved += index;
	while (i < 4)
	{
		if (*solved != 0)
		{
			*found_data = *solved;
		}
		found_data++;
		solved += 4;
		i++;
	}
	found_data -= 8;
	solved -= 16;
}

int	ft_found_four(int *found_data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (found_data[i] == 4)
		{
			return (1);
		}
	}
	return (0);
}

void	ft_cross_match(int *input, int *solved)
{
	int	i;
	int	*found_data;
	int	*current_input_values;

	found_data = (int *)malloc(4 * 4);
	current_input_values = (int *)malloc(15 * 4);
	i = 0;
	ft_fill_found_data(found_data);
	ft_found_data(i, found_data, solved);
	ft_fill_current_input(i, current_input_values, input);
	ft_print_matrix(found_data, 4, 1);
	ft_print_matrix(current_input_values, 5, 2);
	ft_print_matrix(solved, 4, 4);
	ft_print_matrix(input, 4, 4);
}

int	ft_solve(char input[])
{
	int	solved[16] = {0, 4, 0, 0, 0, 0, 4, 0, 4, 0, 0, 0, 0, 0, 0, 4};

	ft_cross_match(input, solved);
	return (0);
}
