/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:20:38 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/05 22:07:50 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int		*int_array;
	t_node	*stack;

	int_array = get_array(argc, argv);
	stack = get_stack(int_array, argc - 1);
	perform_radix(&stack, 0);
	free(int_array);
	free_stack(stack);
	return (0);
}
