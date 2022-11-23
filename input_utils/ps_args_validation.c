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

static void	check_duplicates(int *stacks, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (stacks[j] == stacks[i])
		{
			free_all(stacks);
			exit_error(5);
		}
		j++;
	}
}

static void	test_intovf(char *str, int *stacks)
{
	while (!ft_isdigit(*str))
		str++;
	while (*str)
	{
		if (*str != '0')
		{
			free_all(stacks);
			exit_error(4);
		}
		str++;
	}
}

void	fill_stacks(int i, char *argv[], int *stacks)
{
	int	j;

	j = 0;
	while (j < i)
	{
		stacks[j] = ft_atoi(argv[j]);
		if (stacks[j] == 0)
			test_intovf(argv[j], stacks);
		check_duplicates(stacks, j);
		j++;
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
