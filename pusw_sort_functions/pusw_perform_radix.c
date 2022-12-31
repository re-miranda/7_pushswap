/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_perform_radix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:22:10 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/31 17:24:02 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_n_byte_signed(t_node **stack_a, int byte_position)
{
	t_node	*reference_node;
	t_node	*stack_b;

	stack_b = NULL;
	reference_node = (*stack_a)->previus;
	while (reference_node != (*stack_a))
	{
		if (((*stack_a)->value >> byte_position) & 0b00000001)
			pusw_pb(stack_a, &stack_b);
		else
			pusw_ra(stack_a);
	}
	if (((*stack_a)->value >> byte_position) & 0b00000001)
		pusw_pb(stack_a, &stack_b);
	else
		pusw_ra(stack_a);
	while (stack_b)
		pusw_pa(stack_a, &stack_b);
}

static void	sort_n_byte(t_node **stack_a, int byte_position)
{
	t_node	*reference_node;
	t_node	*stack_b;

	stack_b = NULL;
	reference_node = (*stack_a)->previus;
	while (reference_node != *stack_a)
	{
		if (((*stack_a)->value >> byte_position) & 0b00000001)
			pusw_ra(stack_a);
		else
			pusw_pb(stack_a, &stack_b);
	}
	if (((*stack_a)->value >> byte_position) & 0b00000001)
		pusw_ra(stack_a);
	else
		pusw_pb(stack_a, &stack_b);
	while (stack_b)
		pusw_pa(stack_a, &stack_b);
}

void	perform_radix(t_node **stack_a, const int counter)
{
	if (counter < 31)
	{
		sort_n_byte(stack_a, counter);
		perform_radix(stack_a, counter + 1);
	}
	else
		sort_n_byte_signed(stack_a, counter);
}
