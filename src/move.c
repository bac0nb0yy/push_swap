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

#include "../includes/push_swap.h"

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
		rra(stack_a, nb_abs(cost_a), 0);
	if (cost_b > 0)
		rb(stack_b, cost_b, 0);
	else
		rrb(stack_b, nb_abs(cost_b), 0);
	pa(stack_a, stack_b, 1);
}
