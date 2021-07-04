/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 13:38:10 by emgarcia          #+#    #+#             */
/*   Updated: 2021/07/04 16:40:36 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_ptuchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_matrix(int *a, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < y)
	{
		while (j < x)
		{
			ft_ptuchar(*a + 48);
			if (j < x - 1)
			{
				ft_ptuchar(',');
				ft_ptuchar(' ');
			}
			j++;
			a++;
		}
		j = 0;
		printf("\n");
		i++;
	}
}

void	ft_fill_current_input(int index, int *current, int *input)
{
	int	i;

	i = 0;
	input += index;
	*current = *input;
	current++;
	input += 8 - index;
	while (i < 4)
	{
		*current = *input;
		i++;
		input++;
		current++;
	}
	i = 0;
	input -= 8 + index;
	*current = *input;
	current++;
	input += 8 - index;
	while (i < 4)
	{
		*current = *input;
		i++;
		input++;
		current++;
	}
	input -= 16;
	current -= 10;
}

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

int	ft_count_cross_table(int *current)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i < 5)
	{
		if (current[i] + current[i + 5] == 4 && current[i] == 2)
			count += 6;
		else if (current[i] + current[i + 5] == 3)
			count += 2;
		else
			count += 3;
		i++;
	}
	return ((count + 4) * 3);
}

int	ft_count_posibilities(int *current)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < 5)
	{
		if (current[i] + current[i + 5] == 4 && current[i] == 2)
		{
			if (i == 0)
				count += 6;
			else
				count += 3;
		}
		else if (current[i] + current[i + 5] == 3)
			count += 2;
		else
			count += 3;
		i++;
	}
	return (count * 4);
}

void	ft_fill_cross_table(int *current, int *cross, int size)
{
	int	i;
	int	*posibilities;

	i = 1;
	posibilities = (int *)malloc(ft_count_posibilities(current) * 4);
}

void	ft_cross_match_OL(int index, int *found_data, int *current, int *solved)
{
	int	*cross_match_table;
	int	size;

	if (ft_found_four(found_data) == 1)
	{
		size = ft_count_cross_table(current);
		cross_match_table = (int *)malloc(size * 4);
		ft_fill_cross_table(current, cross_match_table, size);
	}
}

void	ft_cross_match(int *input, int *solved)
{
	int	i;
	int	*found_data;
	int	*current_input_values;

	found_data = (int *)malloc(4 * 4);
	current_input_values = (int *)malloc(10 * 4);
	i = 0;
	ft_fill_found_data(found_data);
	ft_found_data(i, found_data, solved);
	ft_fill_current_input(i, current_input_values, input);
	ft_cross_match_one_line(i, found_data, current_input_values, solved);
	ft_print_matrix(found_data, 4, 1);
	ft_print_matrix(current_input_values, 5, 2);
	ft_print_matrix(solved, 4, 4);
	ft_print_matrix(input, 4, 4);
}

int main(void)
{
	int input[16] = {2,1,2,3,2,3,2,1,2,3,1,3,3,2,3,1};
	int solved[16] = {0,4,0,0,0,0,4,0,4,0,0,0,0,0,0,4};
	ft_cross_match(input, solved);
	return 0;
}