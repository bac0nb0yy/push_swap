/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:18:59 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/15 23:19:27 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a && stack_a->head && stack_a->len > 1)
	{
		temp = stack_a->head;
		stack_a->head = stack_a->head->next;
		temp->prev = stack_a->tail;
		stack_a->tail->next = temp;
		stack_a->tail = temp;
		link_head_tail(stack_a);
	}
}

void	rb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b && stack_b->head && stack_b->len > 1)
	{
		temp = stack_b->head;
		stack_b->head = stack_b->head->next;
		temp->prev = stack_b->tail;
		stack_b->tail->next = temp;
		stack_b->tail = temp;
		link_head_tail(stack_b);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
