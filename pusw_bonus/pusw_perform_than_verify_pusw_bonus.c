/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw_perform_than_verify_pusw_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:47:19 by rmiranda          #+#    #+#             */
/*   Updated: 2023/01/05 22:27:35 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap_bonus.h"

static void	exit_error_and_free_stacks(t_node *stack_a, t_node *stack_b);
static int	true_if_stack_is_not_sorted(t_node *stack);

void	perform_than_verify_pusw(t_node **stack_a)
{
	char	*buffer;
	t_node	*stack_b;

	buffer = get_next_line(0);
	stack_b = NULL;
	while(buffer)
	{
		if (!ft_strncmp(buffer, "pa\n", 3))
			pusw_pa(stack_a, &stack_b);
		else if (!ft_strncmp(buffer, "pb\n", 3))
			pusw_pb(stack_a, &stack_b);
		else if (!ft_strncmp(buffer, "ra\n", 3))
			pusw_ra(stack_a);
		else if (!ft_strncmp(buffer, "rb\n", 3))
			pusw_rb(&stack_b);
		else if (!ft_strncmp(buffer, "rr\n", 3))
			pusw_rr(stack_a, &stack_b);
		else if (!ft_strncmp(buffer, "rra\n", 4))
			pusw_rra(stack_a);
		else if (!ft_strncmp(buffer, "rrb\n", 4))
			pusw_rrb(&stack_b);
		else if (!ft_strncmp(buffer, "rrr\n", 4))
			pusw_rrr(stack_a, &stack_b);
		else if (!ft_strncmp(buffer, "sa\n", 3))
			pusw_sa(stack_a, &stack_b);
		else if (!ft_strncmp(buffer, "sb\n", 3))
			pusw_sb(stack_a, &stack_b);
		else if (!ft_strncmp(buffer, "ss\n", 3))
			pusw_ss(stack_a, &stack_b);
		else
		{
			ft_printf("ERROR NO RULES(%s)\n", buffer);
			exit_error_and_free_stacks(*stack_a, stack_b);
		}
		free(buffer);
		buffer = get_next_line(0);
	}
	if (stack_b)
		exit_error_and_free_stacks(*stack_a, stack_b);
	if (true_if_stack_is_not_sorted(*stack_a))
		exit_error_and_free_stacks(*stack_a, NULL);
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
