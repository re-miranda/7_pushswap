/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:20:38 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/16 03:51:30 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*int_array;
	t_node	*stack;

	check_args(argc, argv);
	int_array = get_array(argc, argv);
	if (!int_array)
		return (0);
	stack = get_stack(int_array, argc - 1);
	sort_stack(&stack, argc - 1);
	free(int_array);
	free_stack(stack);
	return (0);
}
