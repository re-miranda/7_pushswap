/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_tools_rr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:24:13 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/26 01:41:05 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	pusw_rx(t_node **stack)
{
	if (!*stack)
		return (1);
	*stack = (*stack)->next;
	return (0);
}

int	pusw_ra(t_node **stack, int stack_command)
{
	if (pusw_rx(stack))
		return (1);
	if (stack_command)
		command_stack(RA);
	return (0);
}

int	pusw_rb(t_node **stack, int stack_command)
{
	if (pusw_rx(stack))
		return (1);
	if (stack_command)
		command_stack(RB);
	return (0);
}

int	pusw_rr(t_node **stack_a, t_node **stack_b, int stack_command)
{
	if (pusw_rx(stack_a))
		return (1);
	if (pusw_rx(stack_b))
		return (1);
	if (stack_command)
		command_stack(RR);
	return (0);
}
