/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:24:33 by dtelnov           #+#    #+#             */
/*   Updated: 2023/02/15 08:48:04 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parsing_atoi(char *s)
{
	int	result;

	result = 0;
	while (n[i])
	{
		if (ft_isdigit(n[i]) == 0)
			(ft_printf("Incorrect numbers given"), exit(EXIT_FAILURE));
		if (result > INT_MAX / 10)
			return (-1 * (sign == 1));
		result = (result * 10) + (s[i++] - 48);
		if (result < 0)
			return (-1 * (sign == 1));
	}
	return (result);
}

t_stack	stack_new(int data)
{
	t_stack	stack;

	stack.data = data;
	stack.prev = NULL;
	stack.next = NULL;
	return (stack);
}

void	swap_xor(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}

int	len_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		++i;
	}
	return (i);
}

void	sa(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*before;

	tmp = stack;
	before = tmp;
	if (len_stack(stack) < 2)
		return ;
	while (stack->next)
	{
		before = stack;
		stack = stack->next;
	}
	swap_xor(&before->data, &stack->data);
	stack = tmp;
}

void	sb(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*before;

	tmp = stack;
	before = tmp;
	if (len_stack(stack) < 2)
		return ;
	while (stack->next)
	{
		before = stack;
		stack = stack->next;
	}
	swap_xor(&before->data, &stack->data);
	stack = tmp;
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*before;

	
}

int	main(void)
{
	t_stack	A;
	t_stack	B;
	t_stack	C;

	A.data = 5;
	A.next = &B;
	B.data = 8;
	B.next = &C;
	C.data = 9;
	C.next = NULL;
	printf("Derniere valeur: %d\nAvant derniere valeur: %d\n", C.data, B.data);
	sa(&A);
	printf("Derniere valeur: %d\nAvant derniere valeur: %d\n", C.data, B.data);
}