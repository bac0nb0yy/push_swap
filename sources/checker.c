/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:24:41 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/23 10:51:34 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_cmd(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	if (ft_compstr(cmd, "pa\n"))
		pa(stack_a, stack_b, 1, false);
	else if (ft_compstr(cmd, "pb\n"))
		pb(stack_a, stack_b, 1, false);
	else if (ft_compstr(cmd, "rra\n"))
		rra(stack_a, 1, false);
	else if (ft_compstr(cmd, "rrb\n"))
		rrb(stack_b, 1, false);
	else if (ft_compstr(cmd, "rrr\n"))
		rrr(stack_a, stack_b, 1, false);
	else if (ft_compstr(cmd, "ra\n"))
		ra(stack_a, 1, false);
	else if (ft_compstr(cmd, "rb\n"))
		rb(stack_b, 1, false);
	else if (ft_compstr(cmd, "rr\n"))
		rr(stack_a, stack_b, 1, false);
	else if (ft_compstr(cmd, "sa\n"))
		sa(stack_a, 1, false);
	else if (ft_compstr(cmd, "sb\n"))
		sb(stack_b, 1, false);
	else if (ft_compstr(cmd, "ss\n"))
		ss(stack_a, stack_b, 1, false);
}

void	do_cmds(t_stack *stack_a, t_stack *stack_b, char **all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		do_cmd(stack_a, stack_b, all[i]);
		++i;
	}
}

char	**parse_instructions(char *curr)
{
	char	**instructions;
	int		curr_len;

	instructions = malloc(sizeof(char *) * 2);
	if (!instructions)
		return (NULL);
	instructions[0] = malloc(ft_strlen(curr) + 1);
	if (!instructions[0])
		return (free(instructions), NULL);
	ft_memmove(instructions[0], curr, ft_strlen(curr) + 1);
	instructions[1] = 0;
	curr_len = 1;
	free(curr);
	curr = get_next_line(0);
	while (curr)
	{
		instructions = ft_realloc(instructions, curr_len, curr);
		if (!instructions)
			return (free(curr), NULL);
		free(curr);
		curr = get_next_line(0);
		++curr_len;
	}
	free(curr);
	return (instructions);
}

bool	is_valid(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a) && stack_b->len == 0)
	{
		(clear_stack(stack_a), clear_stack(stack_b));
		return (ft_printf("OK\n"), EXIT_SUCCESS);
	}
	(clear_stack(stack_a), clear_stack(stack_b));
	return (ft_printf("KO\n"), EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	char	**all;
	char	*curr;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	(initialize_stack(&stack_a), initialize_stack(&stack_b));
	parse_stack(&stack_a, &stack_b, av, ac);
	curr = get_next_line(0);
	if (curr)
	{
		all = parse_instructions(curr);
		if (!all || !check_valid_all(all))
			return (free_all(&stack_a, &stack_b, all, ERROR_CMD), 1);
		do_cmds(&stack_a, &stack_b, all);
		free_instructions(all);
	}
	return (is_valid(&stack_a, &stack_b));
}
