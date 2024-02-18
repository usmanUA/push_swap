/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:05:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/17 14:25:00 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_rotate(t_stacks *stacks, int move)
{
	if (move == 'a')
		ft_rotate_a(stacks);
	else if (move == 'b')
		ft_rotate_b(stacks);
	else
	{
		ft_rotate_a(stacks);
		ft_rotate_b(stacks);
	}
}

void	ft_revrotate(t_stacks *stacks, int move)
{
	if (move == 'a')
		ft_revrotate_a(stacks);
	else if (move == 'b')
		ft_revrotate_b(stacks);
	else
	{
		ft_revrotate_a(stacks);
		ft_revrotate_b(stacks);
	}
}

void	ft_swap(t_stacks *stacks, int move)
{
	if (move == 'a')
		ft_swap_a(stacks);
	else if (move == 'b')
		ft_swap_b(stacks);
	else
	{
		ft_swap_a(stacks);
		ft_swap_b(stacks);
	}
}

void	ft_push(t_stacks *stacks, int stack)
{
	if (stack == 'a')
		ft_push_b(stacks);
	else if (stack == 'b')
		ft_push_a(stacks);
}
