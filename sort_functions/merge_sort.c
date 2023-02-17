/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:29:15 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/17 13:17:56 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_middle_value(t_node *stack);
static int	*get_array_from_stack(t_node *stack, int stack_size);
static void	sort_array(int *values_array, int stack_size);

void	merge_sort(t_node **stack_a, t_node **stack_b)
{
	int		middle_value;
	t_node	**stack_b;
	int		pushed_amount;

	middle_value = get_middle_value(*stack_a);
	pushed_amount = push_upper_half_to_b(stack_a, stack_b, middle_value);
	if (*stack_a->next->next != *stack_a)
		merge_sort(stack_a, stack_b);
	else if (*stack_a->value > *stack_a->next->value)
		pusw_sa(stack_a, stack_b, OUTPUT_COMMAND);
	if (pushed_amount > 2)
		merge_sort(stack_b, stack_a);
	else if (pushed_amount == 2 && *stack_b->value < *stack_b->next->value)
		pusw_sb(stack_a, stack_b, OUTPUT_COMMAND);
	while (pushed_amount--)
		pusw_pa(stack_a, stack_b, OUTPUT_COMMAND);
}

static int	get_middle_value(t_node *stack, int stack_size)
{
	int	*values_array;
	int	middle_value;

	values_array = get_array_from_stack(stack, stack_size);
	sort_array(values_array, stack_size);
	middle_value = values_array[(int)(stack_size / 2)];
	free(values_array);
	return (middle_value);
}

static int	*get_array_from_stack(t_node *stack, int stack_size)
{
	int	*array;

	array = malloc(sizeof(int), stack_size);
	while (stack_size--)
	{
		stack = stack->previus;
		array[stack_size] = stack->value;
	}
	return (array);
}

static void	sort_array(int *values_array, int stack_size)
{
	int	counter;
	int	swap;

	counter = 0;
	while (counter < stack_size)
	{
		if (values_array[counter] > values_array[counter + 1])
		{
			swap = values_array[counter + 1];
			values_array[counter + 1] = values_array[counter];
			values_array[counter] = swap;
			counter = 0;
			break ;
		}
		counter++;
	}
}
