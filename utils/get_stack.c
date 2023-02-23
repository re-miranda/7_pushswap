/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:50:06 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/23 21:53:20 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*create_stack(char ***parsed_values);
static int		detect_duplicates(t_node *stack);
static int		detect_duplicates_2(t_node *stack);
static void		abort_stack(t_node *stack);

t_node	*get_stack(char ***parsed_values)
{
	t_node	*stack;

	stack = create_stack(parsed_values);
	if (detect_duplicates(stack))
	{
		free_parse(parsed_values);
		abort_stack(stack);
	}
	return (stack);
}

static t_node	*create_stack(char ***parsed_values)
{
	t_node	*stack;
	int		split_index;
	int		counter;

	counter = 0;
	split_index = 0;
	stack = NULL;
	while (parsed_values[split_index])
	{
		if (!parsed_values[split_index][counter])
		{
			counter = 0;
			split_index++;
			continue ;
		}
		stack = get_next_node(stack);
		if (!stack)
			return (NULL);
		stack->previus->value = ft_atoi(parsed_values[split_index][counter]);
		counter++;
	}
	return (stack);
}

static int	detect_duplicates(t_node *stack)
{
	t_node	*last_node;

	last_node = stack->previus;
	while (stack != last_node)
	{
		if (detect_duplicates_2(stack))
			return (1);
		stack = stack->next;
	}
	if (detect_duplicates_2(stack))
		return (1);
	return (0);
}

static int	detect_duplicates_2(t_node *stack)
{
	t_node	*stop_node;

	stop_node = stack->previus;
	while (stack != stop_node)
	{
		if (stop_node->value == stack->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	abort_stack(t_node *stack)
{
	free_stack(stack);
	exit_error(STACK_EXIT_CODE);
}
