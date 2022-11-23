/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:20:38 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/23 02:24:56 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	int	*stacks;

	stacks = NULL;
	check_args(argc, argv);
	stacks = create_stacks(argc);
	fill_stacks(argc - 1, argv + 1, stacks);
	// find_solution();
	free_all(stacks);
	return (0);
}
