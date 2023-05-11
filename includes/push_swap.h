/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:16:50 by dtelnov           #+#    #+#             */
/*   Updated: 2023/04/20 20:10:47 by dtelnov          ###   ########.fr       */
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
	int					position;
	int					target_pos;
	int					cost_a;
	int					cost_b;
}						t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	int				len;
}		t_stack;

void	swap_xor(int *a, int *b);
void	sa(t_stack *stack_a, int amount, int all);
void	sb(t_stack *stack_b, int amount, int all);
void	ss(t_stack *stack_a, t_stack *stack_b, int amount);
void	rra(t_stack *stack_a, int amount, int all);
void	rrb(t_stack *stack_b, int amount, int all);
void	rrr(t_stack *stack_a, t_stack *stack_b, int amount);
void	ra(t_stack *stack_a, int amount, int all);
void	rb(t_stack *stack_b, int amount, int all);
void	rr(t_stack *stack_a, t_stack *stack_b, int amount);
void	pa(t_stack *stack_a, t_stack *stack_b, int amount);
void	pb(t_stack *stack_a, t_stack *stack_b, int amount);
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
void	sort_five_numbers(t_stack *stack_a, t_stack *stack_b);
bool	is_sorted(t_stack *stack);
void	r_or_rr_amount(t_stack *stack, int pos);
int		find_smallest(t_stack *stack);
int		find_biggest(t_stack *stack);
int		find_pos(t_stack *stack, int to_find);
void	sort_a_big_or_small(t_stack *stack_a, t_stack *stack_b);
int		pos_for_a(t_stack *stack_a, t_stack *stack_b, int pos);
void	parse_stack(t_stack *stack_a, t_stack *stack_b, char **av, int ac);
void	clear_two_stacks(t_stack *stack_a, t_stack *stack_b);
void	get_position(t_stack *stack);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	shift_stack(t_stack *stack_a);
void	push_all_save_three(t_stack *stack_a, t_stack *stack_b);
void	get_target_position(t_stack *stack_a, t_stack *stack_b);
int		get_target(t_stack *stack_a, int b_idx,
								int target_idx, int target_pos);
void	assign_index_and_position(t_node *tmp, int *target_idx, int *target_pos);
int		get_lowest_index_position(t_stack *stack);
int		nb_abs(int nb);
void	get_cost(t_stack *stack_a, t_stack *stack_b);
void	do_cheapest_move(t_stack *stack_a, t_stack *stack_b);
void	do_move(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);
#endif