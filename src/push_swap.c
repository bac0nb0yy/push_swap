/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:24:33 by dtelnov           #+#    #+#             */
/*   Updated: 2023/02/15 09:59:55 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_back(t_node *node, int data)
{
	t_node	*tmp;

	tmp = node;
	node->data = data;
	node = node->next;
	node->prev = tmp;
	node->next = NULL;
}

int	parsing_atoi(char *s)
{
	int	result;
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (s[0] == '-')
	{
		sign = 1;
		++i;
	}
	result = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			(ft_printf("Incorrect numbers given"), exit(EXIT_FAILURE));
		if (result > INT_MAX / 10)
			return (-1 * (sign == 1));
		result = (result * 10) + (s[i++] - 48);
		if (result < 0)
			return (-1 * (sign == 1));
	}
	return (result);
}

void	init_node(t_node *node, int data, t_stack *stack)
{
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	stack->head = *node;
	stack->tail = *node;
}

void	swap_xor(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

int	len_node(t_node *node)
{
	t_node	*tmp;
	int		i;

	tmp = node;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		++i;
	}
	return (i);
}

void	sa(t_node *node)
{
	t_node	*tmp;
	t_node	*before;

	tmp = node;
	before = tmp;
	if (len_node(node) < 2)
		return ;
	while (node->next)
	{
		before = node;
		node = node->next;
	}
	swap_xor(&before->data, &node->data);
	node = tmp;
}

void	sb(t_node *node)
{
	t_node	*tmp;
	t_node	*before;

	tmp = node;
	before = tmp;
	if (len_node(node) < 2)
		return ;
	while (node->next)
	{
		before = node;
		node = node->next;
	}
	swap_xor(&before->data, &node->data);
	node = tmp;
}

void	display_node(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while (node->prev)
	{

	}
}

// void	ss(t_node *node_a, t_node *node_b)
// {
// 	sa(node_a);
// 	sb(node_b);
// }

// void	pa(t_node *node)
// {
// 	t_node	*tmp;
// 	t_node	*before;

	
// }

int	main(int ac, char **av)
{
	t_node	A;
	t_node	B;
	t_node	C;
	int		i;
	int		data;
	t_node	node;
	t_stack	stack;

	A.data = 5;
	A.next = &B;
	B.data = 8;
	B.next = &C;
	C.data = 9;
	C.next = NULL;
	printf("Derniere valeur: %d\nAvant derniere valeur: %d\n", C.data, B.data);
	sa(&A);
	printf("Derniere valeur: %d\nAvant derniere valeur: %d\n", C.data, B.data);
	(void)ac;
	i = 1;
	data = 0;
	ft_printf("Argument 1: %s\n", av[1]);
	while (av[i])
	{
		data = parsing_atoi(av[i]);
		ft_printf("Data -> %d\n", data);
		if (i == 1)
		{
			init_node(&node, data, &stack);
			ft_printf("Addresse memoire de head: %d\nAddresse memoire de tail: %d\n", stack.head, stack.tail);
		}
		else
			push_back(&node, data);
		++i;
	}
}