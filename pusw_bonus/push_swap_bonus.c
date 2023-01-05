/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:52:33 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/05 22:14:18 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This program is a checker that assumes:
// The numbers have already been cleared from duplicates and value overflows.
// The pipe input is consistent with a functioning push_swap output.

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	int		*int_array;
	t_node	*stack;

	int_array = get_array(argc, argv);
	stack = get_stack(int_array, argc - 1);
	perform_than_verify_pusw(&stack);
	free(int_array);
	free_stack(stack);
	ft_printf("OK\n");
	return (0);
}
