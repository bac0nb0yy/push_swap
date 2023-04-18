/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:19:42 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/18 01:54:13 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack_a, int amount)
{
	t_node	*temp;

	while (amount--)
	{
		if (stack_a && stack_a->head && stack_a->len > 1)
		{
			temp = stack_a->tail;
			stack_a->tail = stack_a->tail->prev;
			temp->next = stack_a->head;
			stack_a->head->prev = temp;
			stack_a->head = temp;
			(link_head_tail(stack_a), ft_putstr_fd("rra\n", 1));
		}
	}
}

void	rrb(t_stack *stack_b, int amount)
{
	t_node	*temp;

	while (amount--)
	{
		if (stack_b && stack_b->head && stack_b->len > 1)
		{
			temp = stack_b->tail;
			stack_b->tail = stack_b->tail->prev;
			temp->next = stack_b->head;
			stack_b->head->prev = temp;
			stack_b->head = temp;
			(link_head_tail(stack_b), ft_putstr_fd("rrb\n", 1));
		}
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int amount)
{
	while (amount--)
		(rra(stack_a, 1), rrb(stack_b, 1), ft_putstr_fd("rrr\n", 1));
}

void	r_or_rr_amount(t_stack *stack, int pos)
{
	if (pos < stack->len / 2)
		return (ra(stack, pos));
	if (pos >= stack->len / 2)
		return (rra(stack, stack->len - pos));
}
