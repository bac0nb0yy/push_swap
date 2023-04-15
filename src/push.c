/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:18:03 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/15 23:20:15 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*new_node;
	t_node	*tmp;

	if (!stack_b || !stack_b->head || stack_b->len == 0)
		return ;
	new_node = malloc(sizeof(t_node));
	new_node->data = stack_b->head->data;
	new_node->next = stack_a->head;
	if (stack_a->len > 0)
		stack_a->head->prev = new_node;
	else
		stack_a->tail = new_node;
	stack_a->head = new_node;
	link_head_tail(stack_a);
	stack_a->len++;
	tmp = stack_b->head;
	if (stack_b->len > 1)
		stack_b->head = stack_b->head->next;
	else
	{
		stack_b->head = NULL;
		stack_b->tail = stack_b->head;
	}
	stack_b->len--;
	free(tmp);
	link_head_tail(stack_b);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*new_node;
	t_node	*tmp;

	if (!stack_a || !stack_a->head || stack_a->len == 0)
		return ;
	new_node = malloc(sizeof(t_node));
	new_node->data = stack_a->head->data;
	new_node->next = stack_b->head;
	if (stack_b->len > 0)
		stack_b->head->prev = new_node;
	else
		stack_b->tail = new_node;
	stack_b->head = new_node;
	link_head_tail(stack_b);
	stack_b->len++;
	tmp = stack_a->head;
	if (stack_a->len > 1)
		stack_a->head = stack_a->head->next;
	else
	{
		stack_a->head = NULL;
		stack_a->tail = stack_a->head;
	}
	stack_a->len--;
	free(tmp);
	link_head_tail(stack_a);
}
