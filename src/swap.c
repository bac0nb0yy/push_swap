/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:20:09 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/15 23:20:32 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_xor(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

void	sa(t_stack *stack_a)
{
	if (stack_a->len < 3)
		return ;
	swap_xor(&stack_a->head->data, &stack_a->head->next->data);
}

void	sb(t_stack *stack_b)
{
	if (stack_b->len < 3)
		return ;
	swap_xor(&stack_b->head->data, &stack_b->head->next->data);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
