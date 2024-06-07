/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:29:23 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/22 14:03:10 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_zerolimits(t_limits *lims)
{
	lims->max_a = 0;
	lims->max_b = 0;
	lims->min_a = 0;
	lims->min_b = 0;
}

void	ft_zeromoves(t_moves *moves)
{
	moves->cost = 0;
	moves->pa = 0;
	moves->pb = 0;
	moves->sa = 0;
	moves->sb = 0;
	moves->ss = 0;
	moves->ra = 0;
	moves->rb = 0;
	moves->rr = 0;
	moves->rra = 0;
	moves->rrb = 0;
	moves->rrr = 0;
}

void	ft_zerooptimal(t_optimal *optimal)
{
	optimal->cost = 0;
	optimal->pa = 0;
	optimal->pb = 0;
	optimal->sa = 0;
	optimal->sb = 0;
	optimal->ss = 0;
	optimal->ra = 0;
	optimal->rb = 0;
	optimal->rr = 0;
	optimal->rra = 0;
	optimal->rrb = 0;
	optimal->rrr = 0;
}

int	ft_initializestacks(t_stacks *stacks)
{
	t_limits	*lims;
	t_moves		*move;
	t_optimal	*opt;

	lims = (t_limits *)malloc(sizeof(t_limits));
	if (!lims)
		return (0);
	ft_zerolimits(lims);
	move = (t_moves *)malloc(sizeof(t_moves));
	if (!move)
		return (0);
	ft_zeromoves(move);
	opt = (t_optimal *)malloc(sizeof(t_optimal));
	if (!opt)
		return (0);
	ft_zerooptimal(opt);
	stacks->limits = lims;
	stacks->moves = move;
	stacks->optimal = opt;
	return (1);
}
