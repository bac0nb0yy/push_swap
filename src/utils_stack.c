/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:12:50 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/18 02:34:10 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	clear_stack(t_stack *stack)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack->head;
	while (stack && i < stack->len)
	{
		stack->head = tmp->next;
		free(tmp);
		tmp = stack->head;
		++i;
	}
	stack = NULL;
}

void	link_head_tail(t_stack *stack)
{
	if (stack->head && stack->tail)
	{
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
	}
}

void	push_back(t_stack *stack, int data)
{
	t_node	*current_node;

	current_node = malloc(sizeof(t_node));
	current_node->data = data;
	current_node->rank = -1;
	if (stack->len == 0)
	{
		stack->head = current_node;
		stack->tail = current_node;
		link_head_tail(stack);
		stack->len++;
		return ;
	}
	current_node->prev = stack->tail;
	stack->tail->next = current_node;
	stack->tail = current_node;
	link_head_tail(stack);
	stack->len++;
}

void	display_stack(t_stack *stack_a)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack_a->head;
	while (i < stack_a->len)
	{
		ft_printf("Node %d: %d and his rank = %d\n", i + 1,
			tmp->data, tmp->rank);
		tmp = tmp->next;
		++i;
	}
	ft_printf("------------\n");
}

bool	is_sorted(t_stack *stack)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = stack->head;
	while (i < stack->len - 1)
	{
		if (tmp->rank > tmp->next->rank)
			return (false);
		tmp = tmp->next;
		++i;
	}
	return (true);
}
