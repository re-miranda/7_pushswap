/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_tools_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:24:53 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/03 03:24:54 by rmiranda         ###   ########.fr       */
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
