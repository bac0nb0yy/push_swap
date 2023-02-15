/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 06:16:50 by dtelnov           #+#    #+#             */
/*   Updated: 2023/02/15 07:45:00 by dtelnov          ###   ########.fr       */
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

typedef struct s_stack
{
	int					data;
	struct s_stack		*prev;
	struct s_stack		*next;	
}						t_stack;

#endif