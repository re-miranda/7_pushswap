/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:20:38 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/23 05:07:40 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	char	***parsed_values;
	t_node	*stack;

	parsed_values = parse_arguments(argc, argv);
	stack = get_stack(parsed_values);
	free_parse(parsed_values);
	if (assert_stack_needs_sorting(stack))
		sort_stack(stack);
	free_stack(stack);
	return (0);
}
