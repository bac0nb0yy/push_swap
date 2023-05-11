/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:11:03 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/20 17:11:03 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp_b;
	int		i;

	i = 0;
	tmp_b = stack_b->head;
	while (i < stack_b->len)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > stack_b->len / 2)
			tmp_b->cost_b = (stack_b->len - tmp_b->position) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > stack_a->len / 2)
			tmp_b->cost_a = (stack_a->len - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
		++i;
	}
}

void	do_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	int		i;

	tmp = stack_b->head;
	cheapest = INT_MAX;
	i = 0;
	while (i < stack_b->len)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->cost_b) + ft_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
		++i;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}

void	do_move(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_a, stack_b, 1);
		++cost_a;
		++cost_b;
	}
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b, 1);
		--cost_a;
		--cost_b;
	}
	if (cost_a > 0)
		ra(stack_a, cost_a, 0);
	else
		rra(stack_a, ft_abs(cost_a), 0);
	if (cost_b > 0)
		rb(stack_b, cost_b, 0);
	else
		rrb(stack_b, ft_abs(cost_b), 0);
	pa(stack_a, stack_b, 1);
}
