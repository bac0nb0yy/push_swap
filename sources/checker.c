/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 07:24:41 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/12 01:06:01 by dtelnov          ###   ########.fr       */
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

void	display_instructions(char **all_instructions)
{
	int	i;

	i = 0;
	while (all_instructions && all_instructions[i])
	{
		ft_printf("Instruction %d : %s\n", i, all_instructions[i]);
		++i;
	}
}

char	**ft_realloc(char **old, int old_len, char *to_add)
{
	char	**new;
	int		i;
	int		j;

	new = malloc(sizeof(char *) * (old_len + 2));
	i = 0;
	while (i < old_len)
	{
		j = 0;
		new[i] = malloc(ft_strlen(old[i]) + 1);
		while (j < (int)ft_strlen(old[i]))
		{
			new[i][j] = old[i][j];
			++j;
		}
		new[i][j] = 0;
		++i;
	}
	j = 0;
	new[i] = malloc(ft_strlen(to_add) + 1);
	while (j < (int)ft_strlen(to_add))
	{
		new[i][j] = to_add[j];
		++j;
	}
	new[i][j] = 0;
	new[i + 1] = 0;
	free_instructions(old);
	return (new);
}

int	main(int ac, char **av)
{
	char	**instructions;
	char	*curr_instruction;
	int		curr_len;

	(void) ac;
	(void) av;
	curr_instruction = get_next_line(0);
	if (curr_instruction && !ft_compstr(curr_instruction, "\n"))
	{
		instructions = malloc(sizeof(char *) * 2);
		instructions[0] = malloc(ft_strlen(curr_instruction) + 1);
		int k = 0;
		while (k < (int)ft_strlen(curr_instruction))
		{
			instructions[0][k] = curr_instruction[k];
			++k;
		}
		instructions[0][k] = 0;
		instructions[1] = 0;
		curr_len = 1;
		free(curr_instruction);
		curr_instruction = get_next_line(0);
		while (!ft_compstr(curr_instruction, "\n"))
		{
			instructions = ft_realloc(instructions, curr_len, curr_instruction);
			free(curr_instruction);
			curr_instruction = get_next_line(0);
			++curr_len;
		}
		display_instructions(instructions);
		free(curr_instruction);
		free_instructions(instructions);
	}
}
