/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 05:49:29 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/24 01:41:43 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../push_swap.h"

# undef OUTPUT_COMMAND
# define OUTPUT_COMMAND 0

void	perform_than_verify_pusw(t_node **stack_a);
void	exit_error_and_free_stacks(t_node *stack_a, t_node *stack_b);
void	exit_ko_and_free_stacks(t_node *stack_a, t_node *stack_b);
void	verify_and_exit_if_error(t_node *stack_a, t_node *stack_b);

#endif