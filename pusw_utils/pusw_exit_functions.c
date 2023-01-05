/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_exit_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:43:44 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/04 08:48:00 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_node *stack)
{
	stack->previus->next = NULL;
	while (stack->next)
	{
		stack = stack->next;
		free(stack->previus);
	}
	free(stack);
}
