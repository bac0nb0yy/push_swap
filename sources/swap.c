/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:20:09 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/11 06:09:22 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, int amount, int all)
{
	if (stack_a->len < 3)
		return ;
	while (amount--)
	{
		swap_xor(&stack_a->head->data, &stack_a->head->next->data);
		swap_xor(&stack_a->head->rank, &stack_a->head->next->rank);
		if (all == 0)
			ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_stack *stack_b, int amount, int all)
{
	if (stack_b->len < 3)
		return ;
	while (amount--)
	{
		swap_xor(&stack_b->head->data, &stack_b->head->next->data);
		swap_xor(&stack_b->head->rank, &stack_b->head->next->rank);
		if (all == 0)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, int amount)
{
	while (amount--)
		(sa(stack_a, 1, 1), sb(stack_b, 1, 1), ft_putstr_fd("ss\n", 1));
}
