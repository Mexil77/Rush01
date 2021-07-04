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
