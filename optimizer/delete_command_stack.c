/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_command_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:23:21 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/25 02:23:22 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*stash_node(t_node	**stack);

void	delete_node(t_node *stack)
{
	t_node	*swap;

	swap = stash_node(&stack);
	free(swap);
}

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
	}
	return (stash_node);
}