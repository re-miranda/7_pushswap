/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_get_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:50:06 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/30 04:22:45 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	array_to_stack(int *int_array, int size, t_node *head)
{
	while (size--)
	{
		head->value = *int_array;
		head = head->next;
		int_array++;
	}
}

static t_node	*get_circular_liked_nodes(int size)
{
	t_node	*head;
	t_node	*current;

	head = malloc(sizeof(t_node));
	head->previus = head;
	head->next = head;
	current = head;
	while (--size)
	{
		current->next = malloc(sizeof(t_node));
		current->next->previus = current;
		current = current->next;
		current->next = head;
		head->previus = current;
	}
	return (head);
}

t_node	*get_stack(int *int_array, int size)
{
	t_node	*stack;

	stack = get_circular_liked_nodes(size);
	array_to_stack(int_array, size, stack);
	return (stack);
}
