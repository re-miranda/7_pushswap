/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:23:28 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/16 01:32:35 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_stack_elems(t_node *stack);

void	sort_stack(t_node *stack)
{
	int stack_size;

	stack_size = count_stack_elems(stack);
	if (stack_size > 1)
		perform_radix(&stack);
	// else
	// 	perform_quicksort(stack);
}

int	count_stack_elems(t_node *stack)
{
	t_node	*last_elem;
	int		counter;

	last_elem = stack->previus;
	counter = 0;
	while (stack != last_elem)
	{
		counter++;
		stack = stack->next;
	}
	return (counter + 1);
}
