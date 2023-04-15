/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:16:48 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/15 23:17:23 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
