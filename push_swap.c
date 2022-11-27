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

static int	*get_input(int argc, char *argv[])
{
	int	*output_array;

	check_args(argc, argv);
	output_array = create_array(argc, argv);
	return (output_array);
}

int	main(int argc, char *argv[])
{
	int	*int_array;

	int_array = get_input(argc, argv);
	free(int_array);
	return (0);
}
