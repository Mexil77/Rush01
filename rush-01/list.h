/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 15:30:44 by agogolev          #+#    #+#             */
/*   Updated: 2021/07/04 21:03:39 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_H
#define MY_HEADER_H

void	ft_error(void);
void	ft_valid_input_combo(char *numbers);
void	ft_valid_input_numbers(char *numbers);
void	ft_valid_input(char *argv);
void	ft_ptuchar(char c);
void	ft_print_matrix(int *a, int x, int y);
void	ft_fill_current_input(int index, int *current, int *input);
int	ft_solve(int input[]);
void	ft_cross_match(int *input, int *solved);
int	ft_found_four(int *found_data);
void	ft_found_data(int index, int *found_data, int *solved);
void	ft_fill_found_data(int *a);


#endif
