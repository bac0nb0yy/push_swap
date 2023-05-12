/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:24:41 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/12 03:49:01 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_instructions(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		++i;
	}
	free(to_free);
	to_free = NULL;
}

char	**ft_realloc(char **old, int old_len, char *to_add)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (old_len + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i < old_len)
	{
		new[i] = malloc(ft_strlen(old[i]) + 1);
		if (!new[i])
			return (NULL);
		ft_memmove(new[i], old[i], ft_strlen(old[i]) + 1);
		++i;
	}
	new[i] = malloc(ft_strlen(to_add) + 1);
	if (!new[i])
		return (NULL);
	ft_memmove(new[i], to_add, ft_strlen(to_add) + 1);
	new[i + 1] = 0;
	free_instructions(old);
	return (new);
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
		return (NULL);
	ft_memmove(instructions[0], curr, ft_strlen(curr) + 1);
	instructions[1] = 0;
	curr_len = 1;
	free(curr);
	curr = get_next_line(0);
	while (!ft_compstr(curr, "\n"))
	{
		instructions = ft_realloc(instructions, curr_len, curr);
		if (!instructions)
			return (free(curr), free_instructions(instructions), NULL);
		free(curr);
		curr = get_next_line(0);
		++curr_len;
	}
	free(curr);
	return (instructions);
}

int	main(int ac, char **av)
{
	char	**all;
	char	*curr;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 3)
		return (EXIT_FAILURE);
	(initialize_stack(&stack_a), initialize_stack(&stack_b));
	parse_stack(&stack_a, &stack_b, av, ac);
	curr = get_next_line(0);
	if (curr && !ft_compstr(curr, "\n"))
	{
		all = parse_instructions(curr);
		if (!all)
			return (clear_stack(&stack_a), clear_stack(&stack_b),
				free_instructions(all), EXIT_FAILURE);
	}
	(clear_stack(&stack_a), clear_stack(&stack_b));
	free_instructions(all);
}
