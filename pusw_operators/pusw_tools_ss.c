/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_tools_ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 03:25:13 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/05 22:24:08 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	pusw_sx(t_node **stack[2], int i)
{
	int	swap;

	if (!(*stack[i]))
		return (1);
	if ((*stack[i])->next == (*stack[i]))
		return (1);
	swap = (*stack[i])->value;
	(*stack[i])->value = (*stack[i])->next->value;
	(*stack[i])->next->value = swap;
	return (0);
}

int	pusw_sa(t_node **stack_a, t_node **stack_b, int output_command)
{
	t_node	**stacks_in_array[2];

	stacks_in_array[0] = stack_a;
	stacks_in_array[1] = stack_b;
	if (pusw_sx(stacks_in_array, 0))
		return (1);
	if (output_command)
		ft_putendl_fd("sa", 1);
	return (0);
}

int	pusw_sb(t_node **stack_a, t_node **stack_b, int output_command)
{
	t_node	**stacks_in_array[2];

	stacks_in_array[0] = stack_a;
	stacks_in_array[1] = stack_b;
	if (pusw_sx(stacks_in_array, 1))
		return (1);
	if (output_command)
		ft_putendl_fd("sb", 1);
	return (0);
}

int	pusw_ss(t_node **stack_a, t_node **stack_b, int output_command)
{
	t_node	**stacks_in_array[2];

	stacks_in_array[0] = stack_a;
	stacks_in_array[1] = stack_b;
	if (pusw_sx(stacks_in_array, 0))
		return (1);
	if (pusw_sx(stacks_in_array, 1))
		return (1);
	if (output_command)
		ft_putendl_fd("ss", 1);
	return (0);
}
