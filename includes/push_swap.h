/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:16:50 by dtelnov           #+#    #+#             */
/*   Updated: 2023/02/15 09:09:18 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_sorted
{
	int	data;
	int	indice;
}		t_sorted;

typedef struct s_node
{
	int					data;
	struct s_node		*prev;
	struct s_node		*next;
}						t_node;

typedef struct s_stack
{
	struct s_node	head;
	struct s_node	tail;
}		t_stack;

#endif