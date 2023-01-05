/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_tools_ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:25:13 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/05 22:06:32 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	pusw_sx(t_node *stack[2], int i)
{
	int	swap;

	if (!stack[i])
		return (1);
	if (stack[i]->next == stack[i])
		return (1);
	swap = stack[i]->value;
	stack[i]->value = stack[i]->next->value;
	stack[i]->next->value = swap;
	return (0);
}

int	pusw_sa(t_node *stack[2])
{
	if (pusw_sx(stack, 0))
		return (1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	pusw_sb(t_node *stack[2])
{
	if (pusw_sx(stack, 1))
		return (1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	pusw_ss(t_node *stack[2])
{
	if (pusw_sx(stack, 0))
		return (1);
	if (pusw_sx(stack, 1))
		return (1);
	ft_putendl_fd("ss", 1);
	return (0);
}
