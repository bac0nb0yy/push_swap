/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 23:14:23 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/15 23:16:32 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
