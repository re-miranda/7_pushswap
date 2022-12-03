/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_tools_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:23:35 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/03 07:45:46 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	stash_node(t_node	**stack)
{
	if ((*stack)->next == *stack)
		*stack = NULL;
	else
	{
		(*stack)->previus->next = (*stack)->next;
		(*stack)->next->previus = (*stack)->previus;
	}
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
		(*stack_dest)->previus->next = node;
		(*stack_dest)->previus = node;
		*stack_dest = node;
	}
}

static int	pusw_px(t_node **stack_origin, t_node **stack_dest)
{
	ft_printf("%i", (*stack_dest)->value);
	if (!*stack_dest)
		return (1);
	pop_node(stack_dest, *stack_origin);
	stash_node(stack_origin);
	return (0);
}

int	pusw_pa(t_node **stack_a, t_node **stack_b)
{
	if (pusw_px(stack_b, stack_a))
		return (1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pusw_pb(t_node **stack_a, t_node **stack_b)
{
	if (pusw_px(stack_a, stack_b))
		return (1);
	ft_putendl_fd("pb", 1);
	return (0);
}
