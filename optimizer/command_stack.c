/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:23:24 by rmiranda          #+#    #+#             */
/*   Updated: 2023/03/04 20:51:47 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	output_stack(t_node *stack);
static void	output_command(int command);
static void	free_command_stack(t_node *stack);

int	command_stack(int command)
{
	static t_node	*stack;

	if (command == OUTPUT_COMMANDS)
	{
		stack->previus->next = NULL;
		stack->previus = NULL;
		filter_stack(&stack);
		output_stack(stack);
		free_command_stack(stack);
		return (0);
	}
	if (command == DESTROY_COMMANDS)
	{
		free_command_stack(stack);
		return (0);
	}
	stack = get_next_node(stack);
	if (!stack)
		return (-1);
	stack->previus->value = command;
	return (0);
}

static void	output_stack(t_node *stack)
{
	while (stack->next != NULL)
	{
		output_command(stack->value);
		stack = stack->next;
	}
	output_command(stack->value);
}

static void	output_command(int command)
{
	if (command == PA)
		ft_putendl_fd("pa", 1);
	if (command == PB)
		ft_putendl_fd("pb", 1);
	if (command == RA)
		ft_putendl_fd("ra", 1);
	if (command == RB)
		ft_putendl_fd("rb", 1);
	if (command == RR)
		ft_putendl_fd("rr", 1);
	if (command == RRA)
		ft_putendl_fd("rra", 1);
	if (command == RRB)
		ft_putendl_fd("rrb", 1);
	if (command == RRR)
		ft_putendl_fd("rrr", 1);
	if (command == SA)
		ft_putendl_fd("sa", 1);
	if (command == SB)
		ft_putendl_fd("sb", 1);
	if (command == SS)
		ft_putendl_fd("ss", 1);
}

static void	free_command_stack(t_node *stack)
{
	t_node	*free_node;

	while (stack->next != NULL)
	{
		free_node = stack;
		stack = stack->next;
		free(free_node);
	}
	free(stack);
}
