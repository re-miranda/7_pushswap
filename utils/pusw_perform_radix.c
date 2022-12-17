/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_perform_radix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:22:10 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/17 06:22:33 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	perform_radix(t_node **stack)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*reference_node;
	int		counter;

	stack_a = *stack;
	stack_b = NULL;
	counter = 0;
	while (counter < 8)
	{
		ft_printf("bit number %i ---\n", counter);
		reference_node = stack_a->previus;
		while (reference_node != stack_a)
		{
			if ((stack_a->value >> counter) & 1)
				pusw_ra(&stack_a);
			else
				pusw_pb(&stack_a, &stack_b);
		}
		if ((stack_a->value >> counter) & 1)
			pusw_ra(&stack_a);
		else
			pusw_pb(&stack_a, &stack_b);
		ft_printf("<-\n");
		while (stack_b)
		{
			pusw_rrb(&stack_b);
			pusw_pa(&stack_a, &stack_b);
		}
		counter++;
	}
	*stack = stack_a;
}
