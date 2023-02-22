/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:51:34 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/22 21:55:32 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_a_size_2(t_sort_info sort_info);
void	sort_b_size_2(t_sort_info sort_info);
void	sort_a_size_3(t_sort_info sort_info);
void	sort_b_size_3(t_sort_info sort_info);

void	sort_a_size_2(t_sort_info sort_info)
{
	t_node	**stack_a;

	stack_a = sort_info.stack_a;
	if (stack_a[0]->value > stack_a[0]->next->value)
		pusw_sa(stack_a, NULL, OUTPUT_COMMAND);
}

void	sort_b_size_2(t_sort_info sort_info)
{
	t_node	**stack_b;

	stack_b = sort_info.stack_b;
	if (stack_b[0]->value < stack_b[0]->next->value)
		pusw_sb(NULL, stack_b, OUTPUT_COMMAND);
}

void	sort_a_size_3(t_sort_info sort_info)
{
	t_node	**stack_a;

	stack_a = sort_info.stack_a;
	sort_a_size_2(sort_info);
	if (stack_a[0]->next->next->value < stack_a[0]->next->value)
	{
		pusw_ra(stack_a, OUTPUT_COMMAND);
		sort_a_size_2(sort_info);
		pusw_rra(stack_a, OUTPUT_COMMAND);
	}
	sort_a_size_2(sort_info);
}

void	sort_b_size_3(t_sort_info sort_info)
{
	t_node	**stack_b;

	stack_b = sort_info.stack_b;
	sort_b_size_2(sort_info);
	if (stack_b[0]->next->next->value > stack_b[0]->next->value)
	{
		pusw_rb(stack_b, OUTPUT_COMMAND);
		pusw_sb(NULL, stack_b, OUTPUT_COMMAND);
		pusw_rrb(stack_b, OUTPUT_COMMAND);
	}
	sort_b_size_2(sort_info);
}