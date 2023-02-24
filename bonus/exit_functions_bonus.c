/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:31:11 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/24 01:41:18 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	true_if_stack_is_not_sorted(t_node *stack);

void	exit_error_and_free_stacks(t_node *stack_a, t_node *stack_b)
{
	ft_putendl_fd("Error", 2);
	if (stack_b)
		free_stack(stack_b);
	if (stack_a)
		free_stack(stack_a);
	exit(14);
}

void	exit_ko_and_free_stacks(t_node *stack_a, t_node *stack_b)
{
	ft_putendl_fd("KO", 2);
	if (stack_b)
		free_stack(stack_b);
	if (stack_a)
		free_stack(stack_a);
	exit(14);
}

void	verify_and_exit_if_error(t_node *stack_a, t_node *stack_b)
{
	if (stack_b)
		exit_ko_and_free_stacks(stack_a, stack_b);
	if (true_if_stack_is_not_sorted(stack_a))
		exit_ko_and_free_stacks(stack_a, NULL);
}

static int	true_if_stack_is_not_sorted(t_node *stack)
{
	t_node	*reference;
	t_node	*index_node;

	reference = stack->previus;
	index_node = stack;
	while (reference)
	{
		if (index_node->value > index_node->next->value)
			return (-1);
		index_node = index_node->next;
		if (index_node == reference)
			reference = NULL;
	}
	return (0);
}
