/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_leo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:28:54 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/19 03:32:04 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	ell;
	int	ess;
	int	digit_lenght;

	ell = 0;
	digit_lenght = get_digit_lenght(ft_lstsize(*stack_a) - 1);
	while (ell < digit_lenght)
	{
		ess = ft_lstsize(*stack_a);
		while (ess > 0)
		{
			if ((stkp(*stack_a)->index >> ell) & 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			ess--;
		}
		while (ft_lstsize(*stack_b) > 0)
			push(stack_b, stack_a, 'a');
		ell++;
	}
}

int	digit_lenght(int index)
{
	int	are;

	are = 0;
	while (index >> are != 0)
		are++;
	return (are);
}

t_stkp	*stkp(t_node *list)
{
	if (!list)
		return (NULL);
	return ((t_stkp *)list->content);
}
