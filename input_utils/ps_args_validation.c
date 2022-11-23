/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:02:42 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/23 02:23:40 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fill_stacks(int i, char *argv[], int *stacks)
{
	while (i--)
	{
		stacks[i] = ft_atoi(argv[i]);
		if (stacks[i] == 0 && argv[i][0] != '0')
		{
			free_all(stacks);
			exit_error(4);
		}
	}
}

int	*create_stacks(int argc)
{
	int	*int_array;

	int_array = malloc(sizeof(int) * argc - 1);
	if (!int_array)
		exit(3);
	return (int_array);
}

void	check_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = argc;
	if (argc < 3)
		exit_error(1);
	while (--i)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-')
				exit_error(2);
			j++;
		}
	}
}