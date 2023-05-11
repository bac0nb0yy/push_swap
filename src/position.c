/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 04:17:42 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/18 04:17:42 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_lowest_index_position(t_stack *stack)
{
	t_node	*tmp;
	int		lowest_rank;
	int		lowest_position;
	int		i;

	tmp = stack->head;
	lowest_rank = INT_MAX;
	get_position(stack);
	lowest_position = tmp->position;
	i = 0;
	while (i < stack->len)
	{
		if (tmp->rank < lowest_rank)
		{
			lowest_rank = tmp->rank;
			lowest_position = tmp->position;
		}
		tmp = tmp->next;
		++i;
	}
	return (lowest_position);
}

void	assign_index_and_position(t_node *tmp, int *target_idx, int *target_pos)
{
	*target_idx = tmp->rank;
	*target_pos = tmp->position;
}

int	get_target(t_stack *stack_a, int b_idx,
								int target_idx, int target_pos)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack_a->head;
	while (i < stack_a->len)
	{
		if (tmp->rank > b_idx && tmp->rank < target_idx)
		{
			target_idx = tmp->rank;
			target_pos = tmp->position;
		}
		tmp = tmp->next;
		++i;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp = stack_a->head;
	i = 0;
	while (i < stack_a->len)
	{
		if (tmp->rank < target_idx)
		{
			target_idx = tmp->rank;
			target_pos = tmp->position;
		}
		tmp = tmp->next;
		++i;
	}
	return (target_pos);
}

void	get_target_position(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*tmp;
	int		target_pos;
	int		i;

	tmp = stack_b->head;
	get_position(stack_a);
	get_position(stack_b);
	target_pos = 0;
	i = 0;
	while (i < stack_b->len)
	{
		target_pos = get_target(stack_a, tmp->rank, INT_MAX, target_pos);
		tmp->target_pos = target_pos;
		tmp = tmp->next;
		++i;
	}
}
