/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:37:51 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/17 22:20:48 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_numbers(t_stack *stack)
{
	const int	first = stack->head->rank;
	const int	second = stack->head->next->rank;
	const int	third = stack->head->next->next->rank;
	static void	(*instructions[])(t_stack *stack, int amount) = {ra, sa, rra};

	if (first > second && second < third && third > first)
		instructions[1](stack, 1);
	else if (first > second && second > third && third < first)
		(instructions[1](stack, 1), instructions[2](stack, 1));
	else if (first > second && second < third && third < first)
		instructions[0](stack, 1);
	else if (first < second && second > third && third > first)
		(instructions[1](stack, 1), instructions[0](stack, 1));
	else if (first < second && second > third && third < first)
		instructions[2](stack, 1);
}
