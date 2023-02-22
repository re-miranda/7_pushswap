/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:20:42 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/22 21:53:32 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PARSE_EXIT_CODE 1
# define STACK_EXIT_CODE 2
# define OUTPUT_COMMAND 1
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include "libft/libft_gnl_printf.h"

typedef struct s_node
{
	int				value;
	struct s_node	*previus;
	struct s_node	*next;
}	t_node;

typedef struct s_sort_info
{
	t_node	**stack_a;
	t_node	**stack_b;
	int		lenght;
	char	main_stack;
}	t_sort_info;

// PARSE FUNCTOINS
char	***parse_arguments(int argc, char *argv[]);
void	free_parse(char ***parsed_values);

// STACK FUNCTIONS
t_node	*get_stack(char ***parsed_values);
t_node	*get_next_node(t_node *head);
void	*free_stack(t_node *stack);

// SORT FUNCTIONS
int		assert_stack_needs_sorting(t_node *stack);
// void	radix_sort(t_node **stack);
void	sort_stack(t_node *stack_a);
int		count_stack_elems(t_node *stack);
void	merge_sort(t_sort_info sort_info);
void	sort_a_size_2(t_sort_info sort_info);
void	sort_b_size_2(t_sort_info sort_info);
void	sort_a_size_3(t_sort_info sort_info);
void	sort_b_size_3(t_sort_info sort_info);

// PUSH SWAP COMMANDS
int		pusw_pa(t_node **stack_a, t_node **stack_b, int output_command);
int		pusw_pb(t_node **stack_a, t_node **stack_b, int output_command);
int		pusw_ra(t_node **stack, int output_command);
int		pusw_rb(t_node **stack, int output_command);
int		pusw_rr(t_node **stack_a, t_node **stack_b, int output_command);
int		pusw_rra(t_node **stack, int output_command);
int		pusw_rrb(t_node **stack, int output_command);
int		pusw_rrr(t_node **stack_a, t_node **stack_b, int output_command);
int		pusw_sa(t_node **stack_a, t_node **stack_b, int output_command);
int		pusw_sb(t_node **stack_a, t_node **stack_b, int output_command);
int		pusw_ss(t_node **stack_a, t_node **stack_b, int output_command);

// OTHER
void	output_stack(t_node *stack);
void	exit_error(int nb);
void	exit_sort(t_sort_info sort_info);

#endif