/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:24:33 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/18 02:37:43 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_stack(t_stack	*stack)
{
	stack->len = 0;
	stack->head = NULL;
	stack->tail = NULL;
	link_head_tail(stack);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	(initialize_stack(&stack_a), initialize_stack(&stack_b));
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}
