/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_rr_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 02:03:58 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/30 04:21:08 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	pusw_rx(t_node *stack[2], int i)
{
	if (!stack[i])
		return (1);
	stack[i] = stack[i]->next;
	return (0);
}

int	pusw_ra(t_node *stack[2])
{
	if (pusw_rx(stack, 0))
		return (1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	pusw_rb(t_node *stack[2])
{
	if (pusw_rx(stack, 1))
		return (1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	pusw_rr(t_node *stack[2])
{
	if (pusw_rx(stack, 0))
		return (1);
	if (pusw_rx(stack, 1))
		return (1);
	ft_putendl_fd("rr", 1);
	return (0);
}
