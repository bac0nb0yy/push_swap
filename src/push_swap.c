/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:24:33 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/16 20:57:12 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;
	int		new_data;

	stack_a.len = 0;
	stack_b.len = 0;
	i = 1;
	while (i < ac)
	{
		new_data = parsing_atoi(av[i], &stack_a, &stack_b);
		if (check_doublons(new_data, &stack_a, &stack_b))
			clean_exit_error("Error\nDoublons detected\n", 2, &stack_a, &stack_b);
		push_back(&stack_a, new_data);
		i++;
	}
	// display_stack(&stack_a);
	// sa(&stack_a);
	// display_stack(&stack_a);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// pb(&stack_a, &stack_b);
	// display_stack(&stack_a);
	// display_stack(&stack_b);
	// rr(&stack_a, &stack_b);
	// display_stack(&stack_a);
	// display_stack(&stack_b);
	// rrr(&stack_a, &stack_b);
	// display_stack(&stack_a);
	// display_stack(&stack_b);
	// sa(&stack_a);
	// display_stack(&stack_a);
	// display_stack(&stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// pa(&stack_a, &stack_b);
	// display_stack(&stack_a);
	// display_stack(&stack_b);
	rank_nodes(&stack_a);
	sort_three_numbers(&stack_a);
	rank_nodes(&stack_a);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}
