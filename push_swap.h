/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:20:42 by rmiranda          #+#    #+#             */
/*   Updated: 2022/11/28 05:04:32 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft_gnl_printf.h"

typedef struct s_node
{
	int		value;
	struct s_node	*previus;
	struct s_node	*next;
}	t_node;

int		*get_array(int argc, char *argv[]);
t_node	*get_stack(int *int_array, int size);

#endif