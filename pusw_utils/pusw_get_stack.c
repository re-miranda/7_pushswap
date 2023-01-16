/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_get_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:50:06 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/16 05:57:51 by rmiranda         ###   ########.fr       */
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
	t_node	*swap;
	t_node	*head;
	t_node	*current;

	head = malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->previus = head;
	head->next = head;
	current = head;
	while (--size)
	{
		swap = malloc(sizeof(t_node));
		if (!swap)
		{
			free_stack(current);
			return (NULL);
		}
		current->next = swap;
		current->next->previus = current;
		current = current->next;
		current->next = head;
		head->previus = current;
	}
	return (head);
}

t_node	*get_stack(int argc, char *argv[])
{
	int *int_array;
	int	size;
	t_node	*stack;

	size = argc - 1;
	check_args(argc, argv);
	int_array = get_array(argc, argv);
	if (!int_array)
		exit_error(-1);
	stack = get_circular_liked_nodes(size);
	if (!stack)
	{
		free(int_array);
		exit_error(-1);
	}
	array_to_stack(int_array, size, stack);
	free(int_array);
	return (stack);
}
