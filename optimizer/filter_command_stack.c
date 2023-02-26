/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_command_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 02:23:26 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/25 02:23:27 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	apply_filter_1_ra(t_node **stack_ptr);
static void	apply_filter_1_rb(t_node **stack_ptr);
static void	apply_filter_2_rr(t_node **stack_ptr);
static void	apply_filter_2_ss(t_node **stack_ptr);

void	filter_stack(t_node *stack)
{
	t_node	*last_stack_node;

	last_stack_node = stack;
	stack = stack->next;
	while (stack != last_stack_node)
	{
		if (stack->value == RA || stack->value == RRA)
			apply_filter_1_ra(&stack);
		if (stack->value == RB || stack->value == RRB)
			apply_filter_1_rb(&stack);
		stack = stack->next;
	}
	stack = last_stack_node->next;
	while (stack != last_stack_node)
	{
		if (stack->value == RA || stack->value == RB)
			apply_filter_2_rr(&stack);
		if (stack->value == SA || stack->value == SB)
			apply_filter_2_ss(&stack);
		stack = stack->next;
	}
}

static void	apply_filter_1_ra(t_node **stack_ptr)
{
	t_node	*stack;
	t_node	*moving_node;

	stack = *stack_ptr;
	moving_node = stack->next;
	if (stack->value == RA && moving_node->value == RRA)
	{
		*stack_ptr = stack->previus;
		delete_node(stack);
		delete_node(moving_node);
	}
	else if (stack->value == RRA && moving_node->value == RA)
	{
		*stack_ptr = stack->previus;
		delete_node(stack);
		delete_node(moving_node);
	}
}

static void	apply_filter_1_rb(t_node **stack_ptr)
{
	t_node	*stack;
	t_node	*moving_node;

	stack = *stack_ptr;
	moving_node = stack->next;
	if (stack->value == RB && moving_node->value == RRB)
	{
		*stack_ptr = stack->previus;
		delete_node(stack);
		delete_node(moving_node);
	}
	else if (stack->value == RRB && moving_node->value == RB)
	{
		*stack_ptr = stack->previus;
		delete_node(stack);
		delete_node(moving_node);
	}
}

static void	apply_filter_2_rr(t_node **stack_ptr)
{
	t_node	*stack;
	t_node	*moving_node;

	stack = *stack_ptr;
	moving_node = stack->next;
	if (stack->value == RA)
	{
		while (moving_node->value != PA && moving_node->value != PB
			&& moving_node->value != SB)
		{
			if (moving_node->value == RB)
			{
				stack_ptr[0]->value = RR;
				delete_node(moving_node);
				return ;
			}
			else
				moving_node = moving_node->next;
			if (moving_node == stack)
				return ;
		}
	}
	else
	{
		while (moving_node->value != PA && moving_node->value != PB
			&& moving_node->value != SA)
		{
			if (moving_node->value == RA)
			{
				stack_ptr[0]->value = RR;
				delete_node(moving_node);
				return ;
			}
			else
				moving_node = moving_node->next;
			if (moving_node == stack)
				return ;
		}
	}
}

static void	apply_filter_2_ss(t_node **stack_ptr)
{
	t_node	*stack;
	t_node	*moving_node;

	stack = *stack_ptr;
	moving_node = stack->next;
	if (stack->value == SA)
	{
		while (moving_node->value != PA && moving_node->value != PB
			&& moving_node->value != RB && stack->value == RRB)
		{
			if (moving_node->value == SB)
			{
				stack_ptr[0]->value = SS;
				delete_node(moving_node);
				return ;
			}
			else
				moving_node = moving_node->next;
			if (moving_node == stack)
				return ;
		}
	}
	else
	{
		while (moving_node->value != PA && moving_node->value != PB
			&& moving_node->value != RA && stack->value == RRA)
		{
			if (moving_node->value == SA)
			{
				stack_ptr[0]->value = SS;
				delete_node(moving_node);
				return ;
			}
			else
				moving_node = moving_node->next;
			if (moving_node == stack)
				return ;
		}
	}
}
