/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:18:03 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/11 07:05:34 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int amount, bool display)
{
	t_node	*tmp;

	if (!stack_b || !stack_b->head || stack_b->len == 0)
		return ;
	while (amount--)
	{
		tmp = stack_b->head;
		if (stack_b->len > 1)
		{
			stack_b->head = tmp->next;
			--stack_b->len;
		}
		else
			(initialize_stack(stack_b));
		tmp->next = stack_a->head;
		if (stack_a->len > 0)
			stack_a->head->prev = tmp;
		else
			stack_a->tail = tmp;
		stack_a->head = tmp;
		++stack_a->len;
		(link_head_tail(stack_b), link_head_tail(stack_a));
		if (display)
			ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stack *stack_a, t_stack *stack_b, int amount, bool display)
{
	t_node	*tmp;

	if (!stack_a || !stack_a->head || stack_a->len == 0)
		return ;
	while (amount--)
	{
		tmp = stack_a->head;
		if (stack_a->len > 1)
		{
			stack_a->head = tmp->next;
			--stack_a->len;
		}
		else
			(initialize_stack(stack_a));
		tmp->next = stack_b->head;
		if (stack_b->len > 0)
			stack_b->head->prev = tmp;
		else
			stack_b->tail = tmp;
		stack_b->head = tmp;
		++stack_b->len;
		(link_head_tail(stack_a), link_head_tail(stack_b));
		if (display)
			ft_putstr_fd("pb\n", 1);
	}
}
