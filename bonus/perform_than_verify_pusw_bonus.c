/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_than_verify_pusw_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:47:19 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/24 21:22:54 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	apply_command(t_node **stack_a, t_node **stack_b, char *buffer);
static int	apply_command_1(t_node **stack_a, t_node **stack_b, char *buffer);
static int	apply_command_2(t_node **stack_a, t_node **stack_b, char *buffer);

void	perform_than_verify_pusw(t_node **stack_a)
{
	char	*buffer;
	t_node	*stack_b;
	int		input_error;

	buffer = get_next_line(0);
	stack_b = NULL;
	input_error = 0;
	while (buffer)
	{
		input_error = apply_command(stack_a, &stack_b, buffer);
		free(buffer);
		buffer = get_next_line(0);
	}
	if (input_error)
		exit_error_and_free_stacks(*stack_a, stack_b);
	verify_and_exit_if_error(*stack_a, stack_b);
}

static int	apply_command(t_node **stack_a, t_node **stack_b, char *buffer)
{
	static int	bypass;

	if (bypass)
		return (bypass);
	if (apply_command_1(stack_a, stack_b, buffer))
	{
		if (apply_command_2(stack_a, stack_b, buffer))
		{
			bypass++;
		}
	}
	return (bypass);
}

static int	apply_command_1(t_node **stack_a, t_node **stack_b, char *buffer)
{
	if (!ft_strncmp(buffer, "rra\n", 4))
		pusw_rra(stack_a, OUTPUT_COMMAND);
	else if (!ft_strncmp(buffer, "rrb\n", 4))
		pusw_rrb(stack_b, OUTPUT_COMMAND);
	else if (!ft_strncmp(buffer, "rrr\n", 4))
		pusw_rrr(stack_a, stack_b, OUTPUT_COMMAND);
	else if (!ft_strncmp(buffer, "ra\n", 3))
		pusw_ra(stack_a, OUTPUT_COMMAND);
	else if (!ft_strncmp(buffer, "rb\n", 3))
		pusw_rb(stack_b, OUTPUT_COMMAND);
	else if (!ft_strncmp(buffer, "rr\n", 3))
		pusw_rr(stack_a, stack_b, OUTPUT_COMMAND);
	else
		return (-1);
	return (0);
}

static int	apply_command_2(t_node **stack_a, t_node **stack_b, char *buffer)
{
	if (!ft_strncmp(buffer, "pa\n", 3))
		pusw_pa(stack_a, stack_b, OUTPUT_COMMAND);
	else if (!ft_strncmp(buffer, "pb\n", 3))
		pusw_pb(stack_a, stack_b, OUTPUT_COMMAND);
	else if (!ft_strncmp(buffer, "sa\n", 3))
		pusw_sa(stack_a, stack_b, OUTPUT_COMMAND);
	else if (!ft_strncmp(buffer, "sb\n", 3))
		pusw_sb(stack_a, stack_b, OUTPUT_COMMAND);
	else if (!ft_strncmp(buffer, "ss\n", 3))
		pusw_ss(stack_a, stack_b, OUTPUT_COMMAND);
	else
		return (-1);
	return (0);
}
