/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:55:14 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/18 01:55:14 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest(t_stack *stack)
{
	int		mini;
	int		i;
	t_node	*tmp;

	tmp = stack->head;
	mini = tmp->rank;
	i = 0;
	while (i < stack->len)
	{
		mini = ft_min(mini, tmp->rank);
		++i;
		tmp = tmp->next;
	}
	return (mini);
}

int	find_biggest(t_stack *stack)
{
	int		maxi;
	int		i;
	t_node	*tmp;

	tmp = stack->head;
	maxi = tmp->rank;
	i = 0;
	while (i < stack->len)
	{
		maxi = ft_max(maxi, tmp->rank);
		++i;
		tmp = tmp->next;
	}
	return (maxi);
}

void	get_position(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack->head;
	i = 0;
	while (i < stack->len)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	find_pos(t_stack *stack, int to_find)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->head;
	while (i < stack->len)
	{
		if (tmp->rank == to_find)
			return (i);
		++i;
		tmp = tmp->next;
	}
	return (-1);
}

void	clear_two_stacks(t_stack *stack_a, t_stack *stack_b)
{
	(clear_stack(stack_a), clear_stack(stack_b));
}
