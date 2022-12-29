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

static void	command_pass_str(char *str)
{
	if (!ft_strncmp("sa", str, 2) || !ft_strncmp("sb", str, 2))
		return ;
	if (!ft_strncmp("ss", str, 2))
		return ;
	if (!ft_strncmp("pb", str, 2) || !ft_strncmp("pa", str, 2))
		return ;
	if (!ft_strncmp("ra", str, 2) || !ft_strncmp("rb", str, 2))
		return ;
	if (!ft_strncmp("rra", str, 3) || !ft_strncmp("rrb", str, 3))
		return ;
	if (!ft_strncmp("rr", str, 2) || !ft_strncmp("rrr", str, 3))
		return ;
	exit_error(3);
}

static int	digit_pass_str(char *str)
{
	int	iterator;

	iterator = 0;
	while (str[iterator])
	{
		if (!ft_isdigit(argv[argc][iterator]) && argv[argc][iterator] != '-')
			return (0);
		iterator++;
	}
	return (1);
}

static int	check_args(int argc, char *argv[])
{
	int	number_amount;
	int	iterator;

	number_amount = 0;
	iterator = 0;
	if (argc < 4)
		exit_error(1);
	if (!ft_isdigit(argv[argc][0]))
		exit_error(2);
	while (iterator < argc)
	{
		if (number_amount == iterator && digit_pass_str(argv[++iterator]))
			number_amount++;
		else
			command_pass_str(argv[iterator]);
	}
	return (number_amount);
}

int	*get_array_bonus(int argc, char *argv[])
{
	int	*array;
	int	size;

	size = check_args_(argc, argv);
	array = malloc(sizeof(int) * size);
	if (!array)
		exit(3);
	fill_array(size, argv + 1, array);
	return (array);
}
