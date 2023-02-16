/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_perform_than_verify_pusw_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:47:19 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/06 15:48:57 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	apply_command(t_node **stack_a, t_node **stack_b, char *buffer);
static void	verify_and_exit_if_error(t_node *stack_a, t_node *stack_b);
static void	exit_error_and_free_stacks(t_node *stack_a, t_node *stack_b);
static int	true_if_stack_is_not_sorted(t_node *stack);

void	perform_than_verify_pusw(t_node **stack_a)
{
	char	*buffer;
	t_node	*stack_b;

	buffer = get_next_line(0);
	stack_b = NULL;
	while (buffer)
	{
		apply_command(stack_a, &stack_b, buffer);
		free(buffer);
		buffer = get_next_line(0);
	}
	verify_and_exit_if_error(*stack_a, stack_b);
}

static void	apply_command(t_node **stack_a, t_node **stack_b, char *buffer)
{
	if (!ft_strncmp(buffer, "pa", 2))
		pusw_pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(buffer, "pb", 2))
		pusw_pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(buffer, "ra", 2))
		pusw_ra(stack_a, 0);
	else if (!ft_strncmp(buffer, "rb", 2))
		pusw_rb(stack_b, 0);
	else if (!ft_strncmp(buffer, "rr", 2))
		pusw_rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(buffer, "rra", 3))
		pusw_rra(stack_a, 0);
	else if (!ft_strncmp(buffer, "rrb", 3))
		pusw_rrb(stack_b, 0);
	else if (!ft_strncmp(buffer, "rrr", 3))
		pusw_rrr(stack_a, stack_b, 0);
	else if (!ft_strncmp(buffer, "sa", 2))
		pusw_sa(stack_a, stack_b, 0);
	else if (!ft_strncmp(buffer, "sb", 2))
		pusw_sb(stack_a, stack_b, 0);
	else if (!ft_strncmp(buffer, "ss", 2))
		pusw_ss(stack_a, stack_b, 0);
}

static void	verify_and_exit_if_error(t_node *stack_a, t_node *stack_b)
{
	if (stack_b)
		exit_error_and_free_stacks(stack_a, stack_b);
	if (true_if_stack_is_not_sorted(stack_a))
		exit_error_and_free_stacks(stack_a, NULL);
}

static void	exit_error_and_free_stacks(t_node *stack_a, t_node *stack_b)
{
	ft_putendl_fd("Error", 2);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	exit(14);
}

static int	true_if_stack_is_not_sorted(t_node *stack)
{
	t_node	*reference;
	t_node	*index_node;
	int		x;

	x = 0;
	reference = stack->previus->previus;
	index_node = stack;
	while (reference)
	{
		if (index_node == reference)
			reference = NULL;
		if (index_node->value > index_node->next->value)
			return (-1);
		index_node = index_node->next;
	}
	return (0);
}
