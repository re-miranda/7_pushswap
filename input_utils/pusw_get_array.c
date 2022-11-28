/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_get_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:02:42 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/28 02:10:55 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	exit_error(int nb)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Error", 1);
	exit(nb);
}

static int	check_duplicates(int *array, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (array[j] == array[i])
			return (1);
		j++;
	}
	return (0);
}

static void	fill_array(const int size, char *argv[], int *array)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (ft_atoi_safe(argv[j], &array[j]) || check_duplicates(array, j))
		{
			free(array);
			exit_error(4);
		}
		j++;
	}
}

static void	check_args(int argc, char *argv[])
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

int	*get_array(int argc, char *argv[])
{
	int	*array;

	check_args(argc, argv);
	array = malloc(sizeof(int) * argc - 1);
	if (!array)
		exit(3);
	fill_array(argc - 1, argv + 1, array);
	return (array);
}
