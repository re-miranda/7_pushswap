/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:23:28 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/17 13:17:33 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_node *stack)
{
	int	stack_size;

	stack_size = count_stack_elems(stack);
	if (stack_size > 1)
		radix_sort(&stack);
}
