/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:49:05 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/12 03:49:05 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stack *stack_a, t_stack *stack_b, char **all, char *msg)
{
	clear_stack(stack_a);
	clear_stack(stack_b);
	if (all && *all)
		free_instructions(all);
	ft_putstr_fd(msg, 2);
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

bool	check_valid_all(char **all)
{
	int	i;

	i = 0;
	while (all[i])
	{
		if (!ft_compstr(all[i], "pa\n") && !ft_compstr(all[i], "pb\n")
			&& !ft_compstr(all[i], "rra\n") && !ft_compstr(all[i], "rrb\n")
			&& !ft_compstr(all[i], "rrr\n") && !ft_compstr(all[i], "ra\n")
			&& !ft_compstr(all[i], "rb\n") && !ft_compstr(all[i], "rr\n")
			&& !ft_compstr(all[i], "sa\n") && !ft_compstr(all[i], "sb\n")
			&& !ft_compstr(all[i], "ss\n"))
			return (false);
		++i;
	}
	return (true);
}
