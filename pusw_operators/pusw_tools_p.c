/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_tools_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:23:35 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/26 01:41:08 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*stash_node(t_node	**stack)
{
	t_node	*stash_node;

	stash_node = *stack;
	if ((*stack)->next == *stack)
		*stack = NULL;
	else
	{
		(*stack)->previus->next = (*stack)->next;
		(*stack)->next->previus = (*stack)->previus;
		*stack = (*stack)->next;
	}
	return (stash_node);
}

static void	pop_node(t_node **stack_dest, t_node *node)
{
	if (!*stack_dest)
	{
		*stack_dest = node;
		node->next = node;
		node->previus = node;
	}
	else
	{
		node->next = *stack_dest;
		node->previus = (*stack_dest)->previus;
		node->next->previus = node;
		node->previus->next = node;
		*stack_dest = node;
	}
}

static int	pusw_px(t_node **stack_origin, t_node **stack_dest)
{
	t_node	*swap;

	if (!*stack_origin)
		return (1);
	swap = stash_node(stack_origin);
	pop_node(stack_dest, swap);
	return (0);
}

int	pusw_pa(t_node **stack_a, t_node **stack_b, int stack_command)
{
	if (pusw_px(stack_b, stack_a))
		return (1);
	if (stack_command)
		command_stack(PA);
	return (0);
}

int	pusw_pb(t_node **stack_a, t_node **stack_b, int stack_command)
{
	if (pusw_px(stack_a, stack_b))
		return (1);
	if (stack_command)
		command_stack(PB);
	return (0);
}
