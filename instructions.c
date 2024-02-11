/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:05:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/10 19:27:19 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stacks *stacks, int move)
{
	if (move == 'a')
	{
		write(1, "ra\n", 3);
		ft_rotate_a(stacks);
	}
	else if (move == 'b')
	{
		write(1, "rb\n", 3);
		ft_rotate_b(stacks);
	}
	else
	{
		write(1, "rr\n", 3);
		ft_rotate_a(stacks);
		ft_rotate_b(stacks);
	}
}
void	ft_revrotate(t_stacks *stacks, int move)
{
	if (move == 'a')
	{
		write(1, "rra\n", 4);
		ft_revrotate_a(stacks);
	}
	else if (move == 'b')
	{
		write(1, "rrb\n", 4);
		ft_revrotate_b(stacks);
	}
	else
	{
		write(1, "rrr\n", 4);
		ft_revrotate_a(stacks);
		ft_revrotate_b(stacks);
	}
}

void	ft_swap(t_stacks *stacks, int move)
{
	if (move == 'a')
	{
		write(1, "sa\n", 3);
		ft_swap_a(stacks);
	}
	else if (move == 'b')
	{
		write(1, "sb\n", 3);
		ft_swap_b(stacks);
	}
	else
	{
		write(1, "ss\n", 3);
		ft_swap_a(stacks);
		ft_swap_b(stacks);
	}

}

void    ft_push(t_stacks *stacks, int stack)
{
    if (stack == 'a')
    {
        ft_push_b(stacks);
        write(1, "pa\n", 3);
    }
    else if (stack == 'b')
    {
        ft_push_a(stacks);
        write(1, "pb\n", 3);
    }
}



