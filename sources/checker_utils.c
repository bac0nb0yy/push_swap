/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelnov <dtelnov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 03:49:05 by dtelnov           #+#    #+#             */
/*   Updated: 2023/05/12 03:49:05 by dtelnov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_valid_cmd(char *cmd)
{
	if (!ft_compstr(cmd, "pa") && !ft_compstr(cmd, "pb")
		&& !ft_compstr(cmd, "rra") && !ft_compstr(cmd, "rrb")
		&& !ft_compstr(cmd, "rrr") && !ft_compstr(cmd, "ra")
		&& !ft_compstr(cmd, "rb") && !ft_compstr(cmd, "rr")
		&& !ft_compstr(cmd, "sa") && !ft_compstr(cmd, "sb")
		&& !ft_compstr(cmd, "ss"))
		return (false);
	return (true);
}
