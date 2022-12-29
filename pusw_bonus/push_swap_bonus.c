/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:52:33 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/21 05:52:41 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	int		*int_array;
	int		**char_array;
	t_node	*stack;

	int_array = get_array_bonus(argc, argv);
	stack = get_stack(int_array, argc - 1);
}