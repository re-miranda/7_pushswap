/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:20:38 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/03 03:26:20 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_node *stack);

int	main(int argc, char *argv[])
{
	int		*int_array;
	t_node	*stack;

	int_array = get_array(argc, argv);
	stack = get_stack(int_array, argc - 1);
	// perform_radix(stack);
	// output_stack(stack);
	free(int_array);
	free_stack(stack);
	ft_printf("DONE");
	return (0);
}

static void	free_stack(t_node *stack)
{
	stack->previus->next = NULL;
	while (stack->next)
	{
		stack = stack->next;
		free(stack->previus);
	}
	free(stack);
}
