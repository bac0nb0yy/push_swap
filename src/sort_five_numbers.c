/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:14:38 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/18 02:34:34 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_a_big_or_small(t_stack *stack_a, t_stack *stack_b)
{
	const int	b_biggest = find_biggest(stack_b);
	const int	b_smallest = find_smallest(stack_b);
	const int	b_smallest_pos = find_pos(stack_b, b_smallest);

	if (stack_a->head->rank < b_smallest || stack_a->head->rank > b_biggest)
		return (r_or_rr_amount(stack_b, b_smallest_pos));
}

int	pos_for_a(t_stack *stack_a, t_stack *stack_b, int pos)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack_a->head;
	if (stack_b->len > 0)
	{
		if (stack_b->head->rank > find_biggest(stack_a)
			|| stack_b->head->rank < find_smallest(stack_a))
			(sort_a_big_or_small(stack_b, stack_a));
		else
		{
			while (i < stack_a->len && (tmp->next != stack_a->head || ++i))
			{
				pos++;
				if (stack_b->head->rank > tmp->rank
					&& stack_b->head->rank < tmp->next->rank)
					return (pos);
				tmp = tmp->next;
			}
		}
	}
	return (pos);
}

void	sort_five_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int	pos;

	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b, 2);
	sort_three_numbers(stack_a);
	while (stack_b->len > 0)
	{
		pos = 0;
		pos = pos_for_a(stack_a, stack_b, pos);
		r_or_rr_amount(stack_a, pos);
		pa(stack_a, stack_b, 1);
	}
	pos = find_pos(stack_a, find_smallest(stack_a));
	r_or_rr_amount(stack_a, pos);
}
