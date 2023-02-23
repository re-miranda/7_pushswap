/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:43:44 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/22 21:50:16 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_error(int nb)
{
	ft_putendl_fd("Error", 2);
	exit(nb);
}

void	*free_stack(t_node *stack)
{
	if (!stack)
		return (NULL);
	stack->previus->next = NULL;
	while (stack->next)
	{
		stack = stack->next;
		free(stack->previus);
	}
	free(stack);
	return (NULL);
}

void	free_parse(char ***parsed_values)
{
	int	split_index;
	int	counter;

	split_index = 0;
	if (!parsed_values)
		return ;
	while (parsed_values[split_index])
	{
		counter = 0;
		while (parsed_values[split_index][counter])
			free(parsed_values[split_index][counter++]);
		free(parsed_values[split_index][counter]);
		free(parsed_values[split_index]);
		split_index++;
	}
	free(parsed_values);
}

void	exit_sort(t_sort_info sort_info)
{
	free_stack(sort_info.stack_a[0]);
	free_stack(sort_info.stack_b[0]);
	exit_error(-1);
}
