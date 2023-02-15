/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmiranda <rmiranda@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 05:10:22 by rmiranda          #+#    #+#             */
/*   Updated: 2023/02/14 18:58:55 by rmiranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*get_next_node(t_node *head)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (free_stack(head));
	if (!head)
	{
		head = new_node;
		head->previus = head;
	}
	new_node->previus = head->previus;
	new_node->next = head;
	head->previus->next = new_node;
	head->previus = new_node;
	return (head);
}
