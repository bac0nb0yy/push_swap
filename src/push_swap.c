/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:24:33 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/15 22:58:51 by dtelnov          ###   ########.fr       */
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

void	swap_xor(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}

bool	overflow_underflow_check(int *n, char *s, int *i)
{
	static int	overflow_detector = INT_MAX / 10;

	if (*n > overflow_detector)
		return (true);
	*n = (*n * 10) + (s[*i] - 48);
	if (*n < 0)
		return (true);
	return (false);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

char	*ft_longest_array(char *s1, char*s2)
{
	const int	len_a = ft_strlen(s1);
	const int	len_b = ft_strlen(s2);

	if (ft_max(len_a, len_b) == len_a)
		return (s1);
	return (s2);
}

bool	ft_compstr(char *s1, char *s2)
{
	char	*smallest_array;
	char	*longest_array;
	int		i;

	i = 0;
	longest_array = ft_longest_array(s1, s2);
	if (longest_array == s1)
		smallest_array = s2;
	else
		smallest_array = s1;
	while (longest_array[i])
	{
		if (longest_array[i] != smallest_array[i])
			return (false);
		++i;
	}
	return (true);
}

void	clean_exit_error(char *message_error, int fd, t_stack *stack_a,
	t_stack *stack_b)
{
	(ft_putstr_fd(message_error, fd), clear_stack(stack_a),
		clear_stack(stack_b), exit(EXIT_FAILURE));
}

int	parsing_atoi(char *s, t_stack *stack_a, t_stack *stack_b)
{
	int			result;
	int			i;
	int			sign;

	if (ft_compstr(s, "-2147483648"))
		return (INT_MIN);
	i = 0;
	sign = -1 * (s[0] == '-');
	result = 0;
	if (sign == -1)
		++i;
	else
		sign = 1;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			clean_exit_error("Error\nIncorrect numbers given\n", 2, stack_a,
				stack_b);
		if (overflow_underflow_check(&result, s, &i))
			clean_exit_error("Error\nOverflow/Underflow\n", 2, stack_a, stack_b);
		++i;
	}
	return (result * sign);
}

void	display_stack(t_stack *stack_a)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack_a->head;
	while (i < stack_a->len)
	{
		ft_printf("Node %d: %d\n", i + 1, tmp->data);
		tmp = tmp->next;
		++i;
	}
	ft_printf("------------\n");
}

void	sa(t_stack *stack_a)
{
	if (stack_a->len < 3)
		return ;
	swap_xor(&stack_a->head->data, &stack_a->head->next->data);
}

void	sb(t_stack *stack_b)
{
	if (stack_b->len < 3)
		return ;
	swap_xor(&stack_b->head->data, &stack_b->head->next->data);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

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

void	ra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a && stack_a->head && stack_a->len > 1)
	{
		temp = stack_a->head;
		stack_a->head = stack_a->head->next;
		temp->prev = stack_a->tail;
		stack_a->tail->next = temp;
		stack_a->tail = temp;
		link_head_tail(stack_a);
	}
}

void	rb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b && stack_b->head && stack_b->len > 1)
	{
		temp = stack_b->head;
		stack_b->head = stack_b->head->next;
		temp->prev = stack_b->tail;
		stack_b->tail->next = temp;
		stack_b->tail = temp;
		link_head_tail(stack_b);
	}
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack *stack_a)
{
	t_node	*temp;

	if (stack_a && stack_a->head && stack_a->len > 1)
	{
		temp = stack_a->tail;
		stack_a->tail = stack_a->tail->prev;
		temp->next = stack_a->head;
		stack_a->head->prev = temp;
		stack_a->head = temp;
		link_head_tail(stack_a);
	}
}

void	rrb(t_stack *stack_b)
{
	t_node	*temp;

	if (stack_b && stack_b->head && stack_b->len > 1)
	{
		temp = stack_b->tail;
		stack_b->tail = stack_b->tail->prev;
		temp->next = stack_b->head;
		stack_b->head->prev = temp;
		stack_b->head = temp;
		link_head_tail(stack_b);
	}
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}



bool	check_doublons(int data, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = stack_a->head;
	while (i < stack_a->len)
	{
		if (tmp->data == data)
			return (true);
		tmp = tmp->next;
		++i;
	}
	i = 0;
	tmp = stack_b->head;
	while (i < stack_b->len)
	{
		if (tmp->data == data)
			return (true);
		tmp = tmp->next;
		++i;
	}
	return (false);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;
	int		new_data;

	stack_a.len = 0;
	stack_b.len = 0;
	i = 1;
	while (i < ac)
	{
		new_data = parsing_atoi(av[i], &stack_a, &stack_b);
		if (check_doublons(new_data, &stack_a, &stack_b))
			clean_exit_error("Error\nDoublons detected\n", 2, &stack_a, &stack_b);
		push_back(&stack_a, new_data);
		i++;
	}
	display_stack(&stack_a);
	sa(&stack_a);
	display_stack(&stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	display_stack(&stack_a);
	display_stack(&stack_b);
	rr(&stack_a, &stack_b);
	display_stack(&stack_a);
	display_stack(&stack_b);
	rrr(&stack_a, &stack_b);
	display_stack(&stack_a);
	display_stack(&stack_b);
	sa(&stack_a);
	display_stack(&stack_a);
	display_stack(&stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	display_stack(&stack_a);
	display_stack(&stack_b);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}
