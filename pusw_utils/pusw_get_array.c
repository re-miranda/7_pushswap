/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_get_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:02:42 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/16 03:47:00 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	detect_duplicates(int *array, int i)
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

static void	fill_array_and_detect_duplicates(const int size, char *argv[], int *array)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (ft_atoi_safe(argv[j], &array[j]) || detect_duplicates(array, j))
		{
			free(array);
			exit_error(4);
		}
		j++;
	}
}

int	*get_array(int argc, char *argv[])
{
	int	*array;

	array = malloc(sizeof(int) * argc - 1);
	if (!array)
		exit(3);
	fill_array_and_detect_duplicates(argc - 1, argv + 1, array);
	return (array);
}
