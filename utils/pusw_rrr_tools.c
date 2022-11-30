/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_rrr_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 02:03:58 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/30 04:21:12 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	pusw_rrx(t_node *stack[2], int i)
{
	if (!stack[i])
		return (1);
	stack[i] = stack[i]->previus;
	return (0);
}

int	pusw_rra(t_node *stack[2])
{
	if (pusw_rrx(stack, 0))
		return (1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	pusw_rrb(t_node *stack[2])
{
	if (pusw_rrx(stack, 1))
		return (1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	pusw_rrr(t_node *stack[2])
{
	if (pusw_rrx(stack, 0))
		return (1);
	if (pusw_rrx(stack, 1))
		return (1);
	ft_putendl_fd("rrr", 1);
	return (0);
}
