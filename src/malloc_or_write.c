/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_or_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 01:27:55 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/17 01:57:49 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_op
{
	char		data;
	struct s_op	*next;
}						t_op;

size_t	ft_strlen(const char *s)
{
	register const char	*str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	print_op(t_op *all_operations)
{
	t_op	*tmp;
	char	*buffer;
	int		i;

	tmp = all_operations;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		++i;
	}
	buffer = malloc(i + 1);
	i = 0;
	while (all_operations)
	{
		buffer[i] = all_operations->data;
		all_operations = all_operations->next;
		++i;
	}
	buffer[i] = 0;
	ft_putstr_fd(buffer, 1);
	free(buffer);
}

void	clear_list(t_op **all_operations)
{
	t_op	*tmp;

	while (all_operations && *all_operations)
	{
		tmp = (*all_operations)->next;
		free(*all_operations);
		*all_operations = tmp;
	}
	*all_operations = NULL;
}

void	add_op_list(t_op **all_operations, char operation)
{
	t_op	*new;
	t_op	*tmp;

	new = malloc(sizeof(t_op));
	tmp = *all_operations;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*all_operations = new;
	new->data = operation;
	new->next = NULL;
}

void	malloc_and_write(t_op *all_operations)
{
	int		i;
	char	*actual_op;

	i = 0;
	while (i < 40000)
	{
		add_op_list(&all_operations, 'r');
		++i;
	}
	print_op(all_operations);
}

void	only_write(char op)
{
	int	i;

	i = 0;
	while (i < 40000)
	{
		write(1, &op, 1);
		++i;
	}
}

int	main(void)
{
	clock_t	start;
	clock_t	end;
	double	duration;
	t_op	all_op;

	start = clock();
	malloc_and_write(&all_op);
	end = clock();
	duration = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Time taken to execute in seconds : %f\n", duration);

	start = clock();
	only_write('r');
	end = clock();
	duration = ((double)end - start) / CLOCKS_PER_SEC;
	printf("Time taken to execute in seconds : %f", duration);
	return (0);
}
