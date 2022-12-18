/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_perform_radix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:22:10 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/18 05:52:21 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	perform_radix(t_node **stack_a, const int counter)
{
	t_node	*reference_node;
	t_node	*stack_b;

	stack_b = NULL;
	if (counter == 7)
	{
		ft_printf("bit number %i ---\n", counter);
		output_stack(*stack_a);
		reference_node = (*stack_a)->previus;
		while (reference_node != (*stack_a))
		{
			if (((*stack_a)->value >> counter) & 1)
				pusw_pb(stack_a, &stack_b);
			else
				pusw_ra(stack_a);
		}
		if (((*stack_a)->value >> counter) & 1)
			pusw_pb(stack_a, &stack_b);
		else
			pusw_ra(stack_a);
		ft_printf("<-\n");
		while (stack_b)
			pusw_pa(stack_a, &stack_b);
		return ;
	}
	else
	{
		ft_printf("bit number %i ---\n", counter);
		output_stack(*stack_a);
		reference_node = (*stack_a)->previus;
		while (reference_node != *stack_a)
		{
			if (((*stack_a)->value >> counter) & 1)
				pusw_ra(stack_a);
			else
				pusw_pb(stack_a, &stack_b);
		}
		if (((*stack_a)->value >> counter) & 1)
			pusw_ra(stack_a);
		else
			pusw_pb(stack_a, &stack_b);
		ft_printf("<-\n");
		while (stack_b)
			pusw_pa(stack_a, &stack_b);
		perform_radix(stack_a, counter + 1);
	}
}
