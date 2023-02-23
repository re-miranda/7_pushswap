/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:12:20 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/23 05:13:14 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_middle_value(t_sort_info sort_info, int *error);
static void	sort_int_array(int *values_array, int lenght);

int	push_and_count(t_sort_info sort_info)
{
	int	push_counter;
	int	undo_rotate_counter;
	int	middle_value;
	int	error_signal;

	push_counter = 0;
	undo_rotate_counter = 0;
	if (sort_info.lenght <= 2)
		return (0);
	middle_value = find_middle_value(sort_info, &error_signal);
	if (error_signal)
		return (-1);
	if (sort_info.main_stack == 'a')
	{
		while (sort_info.stack_a[0]->value <= middle_value && sort_info.lenght--)
		{
			pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
			push_counter++;
		}
		while (sort_info.lenght--)
		{
			pusw_rra(sort_info.stack_a, OUTPUT_COMMAND);
			if (sort_info.stack_a[0]->value <= middle_value && ++push_counter)
				pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
			else
				break ;
		}
		pusw_ra(sort_info.stack_a, OUTPUT_COMMAND);
		while (sort_info.lenght--)
		{
			pusw_ra(sort_info.stack_a, OUTPUT_COMMAND);
			while (sort_info.stack_a[0]->value <= middle_value && sort_info.lenght--)
			{
				push_counter++;
				pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
			}
		}
	}
	else if (sort_info.main_stack == 'b')
	{
		while (sort_info.lenght--)
		{
			if (sort_info.stack_b[0]->value > middle_value && ++push_counter)
				pusw_pa(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
			else if (++undo_rotate_counter)
				pusw_rb(sort_info.stack_b, OUTPUT_COMMAND);
		}
		while (undo_rotate_counter--)
			pusw_rrb(sort_info.stack_b, OUTPUT_COMMAND);
	}
	else if (sort_info.main_stack == 'c')
	{
		while (sort_info.lenght--)
		{
			if (sort_info.stack_a[0]->value <= middle_value && ++push_counter)
				pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
			else if (++undo_rotate_counter)
				pusw_ra(sort_info.stack_a, OUTPUT_COMMAND);
		}
		while (undo_rotate_counter--)
			pusw_rra(sort_info.stack_a, OUTPUT_COMMAND);
	}
	return (push_counter);
}

static int	find_middle_value(t_sort_info sort_info, int *error)
{
	int	*values_array;
	int	counter;
	int	output;
	t_node	*stack;

	counter = 0;
	*error = -1;
	stack = sort_info.stack_a[0];
	values_array = malloc(sort_info.lenght * sizeof(int));
	if (!values_array)
		return (-1);
	*error = 0;
	if (sort_info.main_stack == 'b')
		stack = sort_info.stack_b[0];
	while (counter < sort_info.lenght)
	{
		values_array[counter] = stack->value;
		stack = stack->next;
		counter++;
	}
	sort_int_array(values_array, sort_info.lenght);
	counter = (int)((sort_info.lenght / 2) - 0.5);
	output = values_array[counter];
	free(values_array);
	return (output);
}

static void	sort_int_array(int *values_array, int lenght)
{
	int	swap;
	int	counter;

	counter = 0;
	while (counter < lenght - 1)
	{
		if (values_array[counter] < values_array[counter + 1])
			counter++;
		else
		{
			swap = values_array[counter];
			values_array[counter] = values_array[counter + 1];
			values_array[counter + 1] = swap;
			counter = 0;
		}
	}
}
