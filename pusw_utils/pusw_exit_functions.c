/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_exit_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 08:43:44 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/08 20:52:27 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_error(int nb)
{
	ft_putendl_fd("Error", 2);
	exit(nb);
}

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

void	check_args(int argc, char *argv[])
{
	int	j;

	if (argc < 2)
		exit_error(1);
	while (--argc)
	{
		j = 0;
		while (argv[argc][j])
		{
			if (!ft_isdigit(argv[argc][j]) && argv[argc][j] != '-')
				exit_error(2);
			j++;
		}
	}
}
