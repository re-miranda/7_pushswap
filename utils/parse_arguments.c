/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 04:38:07 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/16 00:38:58 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	abort_parse(char ***parsed_values);
static int	detect_illigal_values(char ***parsed_values);
static int	contains_illigal_characters(char *argument);

char	***parse_arguments(int argc, char *argv[])
{
	int		c_index;
	char	***parsed_values;

	if (argc < 2)
		exit(0);
	c_index = 0;
	parsed_values = ft_calloc(argc, sizeof(char **));
	if (!parsed_values)
		exit_error(PARSE_EXIT_CODE);
	while (c_index < argc - 1)
	{
		parsed_values[c_index] = ft_split(argv[c_index + 1], ' ');
		if (!parsed_values[c_index])
			abort_parse(parsed_values);
		c_index++;
	}
	if (detect_illigal_values(parsed_values))
		abort_parse(parsed_values);
	return (parsed_values);
}

static void	abort_parse(char ***parsed_values)
{
	free_parse(parsed_values);
	exit_error(PARSE_EXIT_CODE);
}

static int	detect_illigal_values(char ***parsed_values)
{
	int	split_i;
	int	counter;

	split_i = 0;
	while (parsed_values[split_i])
	{
		counter = 0;
		while (parsed_values[split_i][counter])
		{
			if (contains_illigal_characters(parsed_values[split_i][counter]))
				break ;
			if (ft_atoi_safe(parsed_values[split_i][counter], NULL))
				break ;
			counter++;
		}
		if (parsed_values[split_i][counter])
			return (1);
		split_i++;
	}
	return (0);
}

static int	contains_illigal_characters(char *value)
{
	int	counter;

	counter = 0;
	while (value[counter])
	{
		if (ft_isdigit(value[counter]))
			counter++;
		else if (value[counter] == '-' || value[counter] == '+')
			counter++;
		else if (ft_iswhitespace(value[counter]))
			counter++;
		else
			return (1);
	}
	return (0);
}
