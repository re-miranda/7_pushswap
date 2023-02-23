/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:29:15 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/23 05:12:54 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	merge_sort_reversed(t_sort_info sort_info);

void	merge_sort(t_sort_info sort_info)
{
	int	movement_count;

	movement_count = push_and_count(sort_info);
	if (movement_count == -1)
		exit_sort(sort_info);
	sort_info.lenght -= movement_count;
	if (sort_info.lenght < 3)
	{
		sort_b_size_2(sort_info);
		if (sort_info.lenght > 1)
			sort_a_size_2(sort_info);
		while (movement_count--)
			pusw_pa(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
		return ;
	}
	merge_sort(sort_info);
	sort_info.main_stack = 'b';
	sort_info.lenght = movement_count;
	merge_sort_reversed(sort_info);
	while (movement_count--)
		pusw_pa(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
}

static void	merge_sort_reversed(t_sort_info sort_info)
{
	int	movement_count;

	movement_count = push_and_count(sort_info);
	if (movement_count == -1)
		exit_sort(sort_info);
	sort_info.lenght -= movement_count;
	if (sort_info.lenght < 3)
	{
		sort_a_size_2(sort_info);
		if (sort_info.lenght == 2)
			sort_b_size_2(sort_info);
		while (movement_count--)
			pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
		return ;
	}
	merge_sort_reversed(sort_info);
	sort_info.main_stack = 'c';
	sort_info.lenght = movement_count;
	merge_sort(sort_info);
	while (movement_count--)
		pusw_pb(sort_info.stack_a, sort_info.stack_b, OUTPUT_COMMAND);
}
