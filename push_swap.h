/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:20:42 by rmiranda          #+#    #+#             */
/*   Updated: 2022/12/03 07:39:53 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft_gnl_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*previus;
	struct s_node	*next;
}	t_node;

int		*get_array(int argc, char *argv[]);
t_node	*get_stack(int *int_array, int size);
void	output_stack(t_node *stack);
void	perform_radix(t_node *stack);
int		pusw_pa(t_node **stack_a, t_node **stack_b);
int		pusw_pb(t_node **stack_a, t_node **stack_b);
int		pusw_ra(t_node *stack[2]);
int		pusw_rb(t_node *stack[2]);
int		pusw_rr(t_node *stack[2]);
int		pusw_rra(t_node *stack[2]);
int		pusw_rrb(t_node *stack[2]);
int		pusw_rrr(t_node *stack[2]);
int		pusw_sa(t_node *stack[2]);
int		pusw_sb(t_node *stack[2]);
int		pusw_ss(t_node *stack[2]);

#endif