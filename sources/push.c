/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:18:03 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/11 05:46:16 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int amount)
{
	t_node	*tmp;

	if (!stack_b || !stack_b->head || stack_b->len == 0)
		return ;
	while (amount--)
	{
		tmp = stack_b->head;
		if (stack_b->len > 1)
			stack_b->head = tmp->next;
		else
		{
			stack_b->head = NULL;
			stack_b->tail = stack_b->head;
		}
		--stack_b->len;
		tmp->next = stack_a->head;
		if (stack_a->len > 0)
			stack_a->head->prev = tmp;
		else
			stack_a->tail = tmp;
		stack_a->head = tmp;
		++stack_a->len;
		(link_head_tail(stack_b),
			link_head_tail(stack_a), ft_putstr_fd("pa\n", 1));
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b, int amount)
{
	t_node	*tmp;

	if (!stack_a || !stack_a->head || stack_a->len == 0)
		return ;
	while (amount--)
	{
		tmp = stack_a->head;
		if (stack_a->len > 1)
			stack_a->head = tmp->next;
		else
		{
			stack_a->head = NULL;
			stack_a->tail = stack_a->head;
		}
		--stack_a->len;
		tmp->next = stack_b->head;
		if (stack_b->len > 0)
			stack_b->head->prev = tmp;
		else
			stack_b->tail = tmp;
		stack_b->head = tmp;
		++stack_b->len;
		(link_head_tail(stack_a),
			link_head_tail(stack_b), ft_putstr_fd("pb\n", 1));
	}
}
