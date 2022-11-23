/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:20:42 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/23 02:20:35 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft_gnl_printf.h"

void	check_args(int argc, char *argv[]);
int		*create_stacks(int argc);
void	fill_stacks(int i, char *argv[], int *stacks);
void	exit_error(int nb);
void	free_all(int *stacks);

#endif