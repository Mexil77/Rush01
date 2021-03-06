/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:50:06 by agogolev          #+#    #+#             */
/*   Updated: 2021/07/04 21:02:13 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error();
	ft_valid_input(argv[1]);
	ft_solve(argv[1]);
	return (0);
}
