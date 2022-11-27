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

static void	check_duplicates(int *array, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (array[j] == array[i])
		{
			free(array);
			exit_error(5);
		}
		j++;
	}
}

static int	test_int_overflow(char *str)
{
	while (!ft_isdigit(*str))
		str++;
	while (*str)
	{
		if (*str != '0')
			return (1);
		str++;
	}
	return (0);
}

static void	fill_array(const int size, char *argv[], int *array)
{
	int	j;

	j = 0;
	while (j < size)
	{
		array[j] = ft_atoi(argv[j]);
		if (array[j] == 0 && test_int_overflow(argv[j]))
		{
			free(array);
			exit_error(4);
		}
		check_duplicates(array, j);
		j++;
	}
}

int	*create_array(int argc, char *argv[])
{
	int	*array;

	array = malloc(sizeof(int) * argc - 1);
	if (!array)
		exit(3);
	fill_array(argc - 1, argv + 1, array);
	return (array);
}

void	check_args(int argc, char *argv[])
{
	int	j;

	if (argc < 3)
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
