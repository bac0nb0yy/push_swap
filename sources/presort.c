/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:05:51 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/23 10:52:37 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*initialize_array(t_stack *stack)
{
	int		*array;
	int		i;
	t_node	*curr;

	array = malloc(sizeof(int) * stack->len);
	curr = stack->head;
	i = 0;
	while (i < stack->len)
	{
		array[i] = curr->data;
		curr = curr->next;
		++i;
	}
	return (array);
}

void	gnome_sort(int *array, int len_array)
{
	int	i;

	i = 0;
	while (i < len_array)
	{
		if (i == 0)
			++i;
		else if (array[i] >= array[i - 1])
			++i;
		else
		{
			swap_xor(&array[i], &array[i - 1]);
			--i;
		}
	}
}

void	give_rank_to_node_and_free_array(int *sorted_array, t_stack *stack)
{
	t_node	*curr;
	t_node	*tmp;
	int		i;

	curr = stack->head;
	i = 0;
	while (i < stack->len)
	{
		tmp = curr;
		while (sorted_array[i] != tmp->data)
			tmp = tmp->next;
		tmp->rank = i + 1;
		curr = curr->next;
		++i;
	}
	free(sorted_array);
}

void	rank_nodes(t_stack *stack)
{
	int	*array;

	array = initialize_array(stack);
	gnome_sort(array, stack->len);
	give_rank_to_node_and_free_array(array, stack);
}
