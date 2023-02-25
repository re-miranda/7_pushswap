/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:23:28 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/23 05:38:27 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_node *stack)
{
	t_sort_info	sort_info;
	t_node		*stack_b;

	sort_info.stack_a = &stack;
	stack_b = NULL;
	sort_info.stack_b = &stack_b;
	sort_info.lenght = count_stack_elems(stack);
	sort_info.main_stack = 'a';
	if (sort_info.lenght <= 2)
		sort_a_size_2(sort_info);
	else if (sort_info.lenght <= 3)
		sort_a_size_3(sort_info);
	else if (sort_info.lenght <= 5)
		sort_size_5(sort_info);
	else
		merge_sort(sort_info);
	command_stack(OUTPUT_COMMANDS);
}
