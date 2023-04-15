/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:19:42 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/15 23:19:53 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a && stack_a->head && stack_a->len > 1)
	{
		temp = stack_a->tail;
		stack_a->tail = stack_a->tail->prev;
		temp->next = stack_a->head;
		stack_a->head->prev = temp;
		stack_a->head = temp;
		link_head_tail(stack_a);
	}
}

void	rrb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b && stack_b->head && stack_b->len > 1)
	{
		temp = stack_b->tail;
		stack_b->tail = stack_b->tail->prev;
		temp->next = stack_b->head;
		stack_b->head->prev = temp;
		stack_b->head = temp;
		link_head_tail(stack_b);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
