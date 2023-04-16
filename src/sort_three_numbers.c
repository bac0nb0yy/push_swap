/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:37:51 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/16 23:38:05 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_numbers(t_stack *stack)
{
	const int	first = stack->head->rank;
	const int	second = stack->head->next->rank;
	const int	third = stack->head->next->next->rank;
	static void	(*instructions[])(t_stack *stack) = {ra, sa, rra};

	if (first < second && second < third)
		return ;
	else if (first == second - 2 && second == third + 1)
		(instructions[1](stack), instructions[0](stack));
	else if (first == second + 1 && second == third - 2)
		instructions[1](stack);
	else if (first == second - 1 && second == third + 2)
		instructions[2](stack);
	else if (first == second + 2 && second == third - 1)
		instructions[0](stack);
	else
		(instructions[1](stack), instructions[2](stack));
}
