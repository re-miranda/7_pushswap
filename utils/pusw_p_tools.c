/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_p_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 02:03:58 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/30 04:12:06 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	stash_node(t_node	**stack)
{
	if (*stack->next == *stack)
		*stack = NULL;
	else
	{
		*stack->previus->next = *stack->next;
		*stack->next->previus = *stack->previus;
	}
}

static void	pop_node(t_node	**stack, t_node *node)
{
	if (!*stack)
	{
		*stack = node;
		node->next = node;
		node->previus = node;
	}
	else
	{
		node->next = *stack;
		node->previus = *stack->previus;
		*stack->previus->next = node;
		*stack->previus = node;
		*stack = node;
	}
}

static int	pusw_px(t_node *stack[2], int i)
{
	if (!stack[0 + i])
		return (1);
	pop_node(&stack[0 + i], stack[1 - i]);
	stash_node(&stack[1 - i]);
	return (0);
}

int	pusw_pa(t_node *stack[2])
{
	if (pusw_px(stack, 0))
		return (1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pusw_pb(t_node *stack[2])
{
	if (pusw_px(stack, 1))
		return (1);
	ft_putendl_fd("pb", 1);
	return (0);
}
