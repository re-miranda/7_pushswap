/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_tools_rrr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:24:53 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/05 22:52:12 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static int	pusw_rrx(t_node **stack)
{
	if (!*stack)
		return (1);
	*stack = (*stack)->previus;
	return (0);
}

int	pusw_rra_bonus(t_node **stack)
{
	if (pusw_rrx(stack))
		return (1);
	return (0);
}

int	pusw_rrb_bonus(t_node **stack)
{
	if (pusw_rrx(stack))
		return (1);
	return (0);
}

int	pusw_rrr_bonus(t_node **stack_a, t_node **stack_b)
{
	if (pusw_rrx(stack_a))
		return (1);
	if (pusw_rrx(stack_b))
		return (1);
	return (0);
}
