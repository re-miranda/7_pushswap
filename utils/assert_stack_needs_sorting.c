/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_stack_needs_sorting.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 06:44:21 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/15 14:11:06 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	assert_stack_needs_sorting(t_node *stack)
{
	t_node	*reference;
	t_node	*index_node;

	reference = stack->previus->previus;
	index_node = stack;
	while (reference)
	{
		if (index_node == reference)
			reference = NULL;
		if (index_node->value > index_node->next->value)
			return (-1);
		index_node = index_node->next;
	}
	return (0);
}
