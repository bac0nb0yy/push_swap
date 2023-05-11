/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 04:13:16 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/18 04:13:16 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_save_three(t_stack *stack_a, t_stack *stack_b)
{
	const int	stack_size = stack_a->len;
	int			pushed;
	int			i;

	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if (stack_a->head->rank <= stack_size / 2)
		{
			pb(stack_a, stack_b, 1, true);
			pushed++;
		}
		else
			ra(stack_a, 1, true);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(stack_a, stack_b, 1, true);
		pushed++;
	}
}

void	shift_stack(t_stack *stack_a)
{
	int	lowest_position;

	lowest_position = get_lowest_index_position(stack_a);
	if (lowest_position > stack_a->len / 2)
		rra(stack_a, stack_a->len - lowest_position, true);
	else
		ra(stack_a, lowest_position, true);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	push_all_save_three(stack_a, stack_b);
	sort_three_numbers(stack_a);
	while (stack_b->len > 0)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		shift_stack(stack_a);
}

void	sort_three_numbers(t_stack *stack)
{
	const int	first = stack->head->rank;
	const int	second = stack->head->next->rank;
	const int	third = stack->head->next->next->rank;
	static void	(*instructions[])(t_stack *stack, int amount, bool display)
		= {ra, sa, rra};

	if (first > second && second < third && third > first)
		instructions[1](stack, 1, true);
	else if (first > second && second > third && third < first)
		(instructions[1](stack, 1, true), instructions[2](stack, 1, true));
	else if (first > second && second < third && third < first)
		instructions[0](stack, 1, true);
	else if (first < second && second > third && third > first)
		(instructions[1](stack, 1, true), instructions[0](stack, 1, true));
	else if (first < second && second > third && third < first)
		instructions[2](stack, 1, true);
}
