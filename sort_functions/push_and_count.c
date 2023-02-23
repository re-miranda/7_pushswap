/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:12:20 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/23 17:28:47 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	func_a(t_sort_info sort_info, int middle_value, int *push_counter);
static void	func_b(t_sort_info sort_info, int middle_value, int *push_counter);
static void	func_c(t_sort_info sort_info, int middle_value, int *push_counter);
static int	assert_matches(t_sort_info sort_info, int middle_value);

int	push_and_count(t_sort_info sort_info)
{
	int	middle_value;
	int	error_signal;
	int	push_counter;

	if (sort_info.lenght <= 2)
		return (0);
	push_counter = 0;
	middle_value = find_middle_value(sort_info, &error_signal);
	if (error_signal)
		return (-1);
	if (sort_info.main_stack == 'a')
		func_a(sort_info, middle_value, &push_counter);
	else if (sort_info.main_stack == 'b')
		func_b(sort_info, middle_value, &push_counter);
	else
		func_c(sort_info, middle_value, &push_counter);
	return (push_counter);
}

static void	func_a(t_sort_info sort_info, int middle_value, int *push_counter)
{
	int	matches;

	matches = assert_matches(sort_info, middle_value);
	push_counter[0] = matches;
	while (matches)
	{
		while (sort_info.stack_a[0]->value <= middle_value && matches--)
			pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
		while (matches)
		{
			pusw_rra(sort_info.stack_a, OUTPUT_COMMAND);
			if (sort_info.stack_a[0]->value <= middle_value && matches--)
				pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
			else
				break ;
		}
		while (matches)
		{
			while (sort_info.stack_a[0]->value <= middle_value && matches--)
				pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
			pusw_ra(sort_info.stack_a, OUTPUT_COMMAND);
		}
	}
}

static void	func_b(t_sort_info sort_info, int middle_value, int *push_counter)
{
	int	undo_rotate_counter;
	int	matches;

	undo_rotate_counter = 0;
	matches = assert_matches(sort_info, middle_value);
	push_counter[0] = matches;
	while (matches)
	{
		if (sort_info.stack_b[0]->value > middle_value && matches--)
			pusw_pa(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
		else if (++undo_rotate_counter)
			pusw_rb(sort_info.stack_b, OUTPUT_COMMAND);
	}
	while (undo_rotate_counter--)
		pusw_rrb(sort_info.stack_b, OUTPUT_COMMAND);
}

static void	func_c(t_sort_info sort_info, int middle_value, int *push_counter)
{
	int	undo_rotate_counter;
	int	matches;

	undo_rotate_counter = 0;
	matches = assert_matches(sort_info, middle_value);
	push_counter[0] = matches;
	while (matches)
	{
		if (sort_info.stack_a[0]->value <= middle_value && matches--)
			pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
		else if (++undo_rotate_counter)
			pusw_ra(sort_info.stack_a, OUTPUT_COMMAND);
	}
	while (undo_rotate_counter--)
		pusw_rra(sort_info.stack_a, OUTPUT_COMMAND);
}

static int	assert_matches(t_sort_info sort_info, int middle_value)
{
	int		matches;
	t_node	*stack;

	matches = 0;
	if (sort_info.main_stack == 'b')
		stack = sort_info.stack_b[0];
	else
		stack = sort_info.stack_a[0];
	while (sort_info.lenght--)
	{
		if (stack->value > middle_value && sort_info.main_stack == 'b')
			matches++;
		else if (stack->value <= middle_value && sort_info.main_stack != 'b')
			matches++;
		stack = stack->next;
	}
	return (matches);
}
