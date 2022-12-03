/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_output_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:21:37 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/03 03:42:57 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	output_stack(t_node *stack)
{
	t_node	*last_stack_node;

	last_stack_node = stack->previus;
	while (stack != last_stack_node)
	{
		ft_printf("%i ", stack->value);
		stack = stack->next;
	}
	ft_printf("%i\n", stack->value);
}
