/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_command_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:23:26 by rmiranda          #+#    #+#             */
/*   Updated: 2023/03/04 20:53:52 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	delete_two_nodes(t_node *stack);

void	filter_stack(t_node **stack)
{
	t_node	*moving_stack;

	moving_stack = *stack;
	if (moving_stack->next == NULL)
		return ;
	while (moving_stack->next->next != NULL)
	{
		if ((moving_stack->value == RA && moving_stack->next->value == RRA)
			|| (moving_stack->value == RRA && moving_stack->next->value == RA))
			delete_two_nodes(moving_stack);
		else if ((moving_stack->value == RB && moving_stack->next->value == RRB)
			|| (moving_stack->value == RRB && moving_stack->next->value == RB))
			delete_two_nodes(moving_stack);
		else
			moving_stack = moving_stack->next;
	}
}

static void	delete_two_nodes(t_node *stack)
{
	t_node	*swap;

	swap = stack->next;
	stack->value = stack->next->next->value;
	stack->next = stack->next->next->next;
	free(swap->next);
	free(swap);
}
