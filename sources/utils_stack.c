/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:12:50 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/11 07:04:43 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	initialize_stack(t_stack *stack)
{
	stack->len = 0;
	stack->head = NULL;
	stack->tail = NULL;
	link_head_tail(stack);
}

void	clean_exit_error(char *message_error, int fd, t_stack *stack_a,
							t_stack *stack_b)
{
	(ft_putstr_fd(message_error, fd), clear_stack(stack_a),
		clear_stack(stack_b), exit(EXIT_FAILURE));
}
