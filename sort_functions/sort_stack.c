/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 03:23:28 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/22 21:55:22 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack(t_node *stack)
{
	t_sort_info	sort_info;
	t_node	*stack_b;

	sort_info.stack_a = &stack;
	stack_b = NULL;
	sort_info.stack_b = &stack_b;
	sort_info.lenght = count_stack_elems(stack);
	sort_info.main_stack = 'a';
	if (sort_info.lenght <= 2)
		sort_a_size_2(sort_info);
	else if (sort_info.lenght <= 3)
		sort_a_size_3(sort_info);
	else 
		merge_sort(sort_info);
}

// void	radix_sort_leo(t_list **a, t_list **b)
// {
// 	int	l;
// 	int	s;
// 	int	d;

// 	l = 0;
// 	d = digit_lenght(ft_lstsize(*a) - 1);
// 	while (l < d)
// 	{
// 		s = ft_lstsize(*a);
// 		while (s > 0)
// 		{
// 			if ((stkp(*a)->index >> l) & 1)
// 				rotate(a, 'a');
// 			else
// 				push(a, b, 'b');
// 			s--;
// 		}
// 		while (ft_lstsize(*b) > 0)
// 			push(b, a, 'a');
// 		l++;
// 	}
// }

// t_stkp	*stkp(t_list *list)
// {
// 	if (!list)
// 		return (NULL);
// 	return ((t_stkp *)list->content);
// }
