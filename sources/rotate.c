/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:18:59 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/11 07:00:24 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a, int amount, bool display)
{
	t_node	*temp;

	while (amount--)
	{
		if (stack_a && stack_a->head && stack_a->len > 1)
		{
			temp = stack_a->head;
			stack_a->head = stack_a->head->next;
			temp->prev = stack_a->tail;
			stack_a->tail->next = temp;
			stack_a->tail = temp;
			link_head_tail(stack_a);
			if (display)
				ft_putstr_fd("ra\n", 1);
		}
	}
}

void	rb(t_stack *stack_b, int amount, bool display)
{
	t_node	*temp;

	while (amount--)
	{
		if (stack_b && stack_b->head && stack_b->len > 1)
		{
			temp = stack_b->head;
			stack_b->head = stack_b->head->next;
			temp->prev = stack_b->tail;
			stack_b->tail->next = temp;
			stack_b->tail = temp;
			link_head_tail(stack_b);
			if (display)
				ft_putstr_fd("rb\n", 1);
		}
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, int amount, bool display)
{
	while (amount--)
	{
		(ra(stack_a, 1, false), rb(stack_b, 1, false));
		if (display)
			ft_putstr_fd("rr\n", 1);
	}
}
