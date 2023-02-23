/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_stack_elems.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 06:54:33 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/17 06:55:21 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
