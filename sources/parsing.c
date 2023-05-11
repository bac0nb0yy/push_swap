/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:16:48 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/11 06:16:21 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_stack(t_stack *stack_a, t_stack *stack_b, char **av, int ac)
{
	int		i;
	int		new_data;

	i = 1;
	while (i < ac)
	{
		new_data = parsing_atoi(av[i], stack_a, stack_b);
		if (check_doublons(new_data, stack_a, stack_b))
			clean_exit_error(ERROR_DOUBLONS, 2, stack_a, stack_b);
		push_back(stack_a, new_data);
		i++;
	}
	rank_nodes(stack_a);
}

bool	overflow_underflow_check(int *n, char *s, int *i)
{
	static int	overflow_detector = INT_MAX / 10;

	if (*n > overflow_detector)
		return (true);
	*n = (*n * 10) + (s[*i] - '0');
	if (*n < 0)
		return (true);
	return (false);
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
			clean_exit_error(ERROR_NOT_DIGITS, 2, stack_a,
				stack_b);
		if (overflow_underflow_check(&result, s, &i))
			clean_exit_error(ERROR_OVER_UNDER, 2, stack_a, stack_b);
		++i;
	}
	return (result * sign);
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