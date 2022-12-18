/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_tools_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:24:53 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/17 03:48:15 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	pusw_rrx(t_node **stack)
{
	if (!*stack)
		return (1);
	*stack = (*stack)->previus;
	return (0);
}

int	pusw_rra(t_node **stack)
{
	if (pusw_rrx(stack))
		return (1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	pusw_rrb(t_node **stack)
{
	if (pusw_rrx(stack))
		return (1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	pusw_rrr(t_node **stack_a, t_node **stack_b)
{
	if (pusw_rrx(stack_a))
		return (1);
	if (pusw_rrx(stack_b))
		return (1);
	ft_putendl_fd("rrr", 1);
	return (0);
}
