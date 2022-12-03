/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_perform_radix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:22:10 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/03 07:48:24 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	perform_radix(t_node *stack)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*reference_node;
	int		counter;

	stack_a = stack;
	stack_b = NULL;
	counter = 8;
	while (counter--)
	{
		ft_printf("1");
		reference_node = stack_a->previus;
		while (stack_a != reference_node)
		{
			ft_printf("2");
			if ((stack_a->value >> counter) & 1)
			{
				ft_printf("2.0(%i)", stack_a->value);
				reference_node = stack_a->previus;
				pusw_pb(&stack_a, &stack_b);
			}
			else
			{
				ft_printf("2.1");
				pusw_ra(&stack_a);
			}
		}
		ft_printf("3");
		if ((stack_a->value >> counter) & 1)
			pusw_pb(&stack_a, &stack_b);
		while (stack_b)
			pusw_pa(&stack_a, &stack_b);
		ft_printf("4");
	}
	
}
