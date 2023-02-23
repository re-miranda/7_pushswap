/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_middle_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:56:46 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/23 05:57:47 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_int_array(int *values_array, int lenght);

int	find_middle_value(t_sort_info sort_info, int *error)
{
	int		*values_array;
	int		counter;
	int		output;
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
