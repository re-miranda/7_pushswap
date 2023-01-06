/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_tools_rr_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:24:13 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/05 22:52:01 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static int	pusw_rx(t_node **stack)
{
	if (!*stack)
		return (1);
	*stack = (*stack)->next;
	return (0);
}

int	pusw_ra_bonus(t_node **stack)
{
	if (pusw_rx(stack))
		return (1);
	return (0);
}

int	pusw_rb_bonus(t_node **stack)
{
	if (pusw_rx(stack))
		return (1);
	return (0);
}

int	pusw_rr_bonus(t_node **stack_a, t_node **stack_b)
{
	if (pusw_rx(stack_a))
		return (1);
	if (pusw_rx(stack_b))
		return (1);
	return (0);
}
