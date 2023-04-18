/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:18:59 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/17 19:40:29 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack_a, int amount)
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
			(link_head_tail(stack_a), ft_putstr_fd("ra\n", 1));
		}
	}
}

void	rb(t_stack *stack_b, int amount)
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
			(link_head_tail(stack_b), ft_putstr_fd("rb\n", 1));
		}
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b, int amount)
{
	while (amount--)
		(ra(stack_a, 1), rb(stack_b, 1), ft_putstr_fd("rr\n", 1));
}
