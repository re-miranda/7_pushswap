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
	char	***parsed_values;
	t_node	*stack;

	parsed_values = parse_arguments(argc, argv);
	stack = get_stack(parsed_values);
	free_parse(parsed_values);
	perform_than_verify_pusw(&stack);
	free_stack(stack);
	ft_printf("OK\n");
	return (0);
}
