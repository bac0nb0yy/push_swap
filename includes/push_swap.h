/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:16:50 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/12 18:29:14 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

# define ERROR_DOUBLONS		"Error\nDoublons detected\n"
# define ERROR_NOT_DIGITS	"Error\nIncorrect numbers given\n"
# define ERROR_OVER_UNDER	"Error\nOverflow/Underflow\n"
# define ERROR_CMD			"Error\nBad instructions found\n"
# define ERROR_MALLOC		"Error\nMalloc() failed\n"

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

// move.c
void	get_cost(t_stack *stack_a, t_stack *stack_b);
void	do_cheapest_move(t_stack *stack_a, t_stack *stack_b);
void	do_move(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);

// parsing.c
void	parse_stack(t_stack *stack_a, t_stack *stack_b, char **av, int ac);
bool	overflow_underflow_check(int *n, char *s, int *i);
int		parsing_atoi(char *s, t_stack *stack_a, t_stack *stack_b);
bool	check_doublons(int data, t_stack *stack_a, t_stack *stack_b);

// position.c
void	assign_index_and_position(t_node *tmp, int *target_idx,
			int *target_pos);
int		get_lowest_index_position(t_stack *stack);
int		get_target(t_stack *stack_a, int b_idx,
			int target_idx, int target_pos);
void	get_target_position(t_stack *stack_a, t_stack *stack_b);

// presort.c
int		*initialize_array(t_stack *stack);
void	gnome_sort(int *array, int len_array);
void	give_rank_to_node_and_free_array(int *sorted_array, t_stack *stack);
void	rank_nodes(t_stack *stack);

// push.c
void	pa(t_stack *stack_a, t_stack *stack_b, int amount, bool display);
void	pb(t_stack *stack_a, t_stack *stack_b, int amount, bool display);

// reverse_rotate.c
void	rra(t_stack *stack_a, int amount, bool display);
void	rrb(t_stack *stack_b, int amount, bool display);
void	rrr(t_stack *stack_a, t_stack *stack_b, int amount, bool display);

// rotate.c
void	ra(t_stack *stack_a, int amount, bool display);
void	rb(t_stack *stack_b, int amount, bool display);
void	rr(t_stack *stack_a, t_stack *stack_b, int amount, bool display);

// swap.c
void	sa(t_stack *stack_a, int amount, bool display);
void	sb(t_stack *stack_b, int amount, bool display);
void	ss(t_stack *stack_a, t_stack *stack_b, int amount, bool display);

// sort.c
void	push_all_save_three(t_stack *stack_a, t_stack *stack_b);
void	shift_stack(t_stack *stack_a);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_three_numbers(t_stack *stack);

// utils_stack.c
void	clear_stack(t_stack *stack);
void	link_head_tail(t_stack *stack);
bool	push_back(t_stack *stack, int data);
void	initialize_stack(t_stack *stack);
void	clean_exit_error(char *message_error, int fd, t_stack *stack_a,
			t_stack *stack_b);

// utils.c
int		find_smallest(t_stack *stack);
int		find_biggest(t_stack *stack);
void	get_position(t_stack *stack);
int		find_pos(t_stack *stack, int to_find);
bool	is_sorted(t_stack *stack);

// checker.c
char	**parse_instructions(char *curr);

// checker_utils.c
bool	check_valid_all(char **all);
char	**ft_realloc(char **old, int old_len, char *to_add);
void	free_instructions(char **to_free);
void	free_all(t_stack *stack_a, t_stack *stack_b, char **all, char *msg);
#endif