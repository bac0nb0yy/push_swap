/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:16:50 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/17 01:25:57 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_node
{
	int					data;
	struct s_node		*prev;
	struct s_node		*next;
	int					rank;
}						t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				len;
}		t_stack;

void	swap_xor(int *a, int *b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
bool	overflow_underflow_check(int *n, char *s, int *i);
int		parsing_atoi(char *s, t_stack *stack_a, t_stack *stack_b);
bool	check_doublons(int data, t_stack *stack_a, t_stack *stack_b);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*ft_longest_array(char *s1, char*s2);
bool	ft_compstr(char *s1, char *s2);
void	clean_exit_error(char *message_error, int fd, t_stack *stack_a,
			t_stack *stack_b);
void	clear_stack(t_stack *stack);
void	link_head_tail(t_stack *stack);
void	push_back(t_stack *stack, int data);
void	display_stack(t_stack *stack_a);
int		*initialize_array(t_stack *stack);
void	display_array(int *array, t_stack *stack);
void	rank_nodes(t_stack *stack);
void	gnome_sort(int *array, int len_array);
void	give_rank_to_node(int *sorted_array, t_stack *stack);
void	sort_three_numbers(t_stack *stack);
#endif