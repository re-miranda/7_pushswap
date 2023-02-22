/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:22:10 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/22 21:48:17 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_n_byte_signed(t_node **stack_a, int byte_position);
static void	sort_n_byte(t_node **stack_a, int byte_position);

void	radix_sort(t_node **stack_a)
{
	static int	counter;

	if (counter < 31)
	{
		sort_n_byte(stack_a, counter++);
		radix_sort(stack_a);
	}
	else
		sort_n_byte_signed(stack_a, counter);
}

static void	sort_n_byte_signed(t_node **stack_a, int byte_position)
{
	t_node	*reference_node;
	t_node	*stack_b;

	stack_b = NULL;
	reference_node = (*stack_a)->previus;
	while (reference_node != (*stack_a))
	{
		if (((*stack_a)->value >> byte_position) & 0b00000001)
			pusw_pb(stack_a, &stack_b, OUTPUT_COMMAND);
		else
			pusw_ra(stack_a, OUTPUT_COMMAND);
	}
	if (((*stack_a)->value >> byte_position) & 0b00000001)
		pusw_pb(stack_a, &stack_b, OUTPUT_COMMAND);
	else
		pusw_ra(stack_a, OUTPUT_COMMAND);
	while (stack_b)
		pusw_pa(stack_a, &stack_b, OUTPUT_COMMAND);
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
			pusw_ra(stack_a, OUTPUT_COMMAND);
		else
			pusw_pb(stack_a, &stack_b, OUTPUT_COMMAND);
	}
	if (((*stack_a)->value >> byte_position) & 0b00000001)
		pusw_ra(stack_a, OUTPUT_COMMAND);
	else
		pusw_pb(stack_a, &stack_b, OUTPUT_COMMAND);
	while (stack_b)
		pusw_pa(stack_a, &stack_b, OUTPUT_COMMAND);
}
