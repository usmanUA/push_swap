/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:40:25 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/22 14:13:44 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_optimize(t_stacks *stacks)
{
	stacks->moves->rr = 0;
	stacks->moves->rrr = 0;
	while (stacks->moves->ra > 0 && stacks->moves->rb > 0)
	{
		stacks->moves->ra--;
		stacks->moves->rb--;
		stacks->moves->rr++;
	}
	while (stacks->moves->rra > 0 && stacks->moves->rrb > 0)
	{
		stacks->moves->rra--;
		stacks->moves->rrb--;
		stacks->moves->rrr++;
	}
}

static void	ft_get_top_a(t_stacks *stacks, t_stack *tmp_a, int size, int ind)
{
	stacks->moves->pb = 1;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (tmp_a->num == stacks->a->num)
		return ;
	ft_getmoves(stacks, size, ind, 'a');
}

static void	ft_get_num_b(t_stacks *stacks, int num)
{
	int		imax_b;
	t_stack	*tmp_b;
	int		size_b;

	tmp_b = stacks->b;
	stacks->moves->rb = 0;
	stacks->moves->rrb = 0;
	if (num > stacks->limits->max_b || num < stacks->limits->min_b)
	{
		if (tmp_b->num == stacks->limits->max_b)
			return ;
		imax_b = ft_findindex(tmp_b, stacks->limits->max_b);
		size_b = ft_stacksize(tmp_b);
		ft_getmoves(stacks, size_b, imax_b, 'b');
	}
	else
		ft_newnum_b(stacks, tmp_b, num);
}

static void	ft_findmoves(t_stacks *stacks)
{
	t_stack	*tmp_a;
	int		size;
	int		ind;

	tmp_a = stacks->a;
	size = ft_stacksize(tmp_a);
	ind = -1;
	while (++ind < size)
	{
		ft_get_top_a(stacks, tmp_a, size, ind);
		ft_get_num_b(stacks, tmp_a->num);
		ft_optimize(stacks);
		ft_optimal(stacks, ind);
		tmp_a = tmp_a->next;
	}
}

void	ft_sort(t_stacks *stacks)
{
	ft_push(stacks, 'b', 1);
	ft_push(stacks, 'b', 1);
	if (!ft_initializestacks(stacks))
		return ;
	while (ft_stacksize(stacks->a) > 3)
	{
		ft_minmax(stacks, 'b');
		ft_findmoves(stacks);
		ft_moveoptimal(stacks);
	}
	ft_sort_three(stacks);
	ft_move_back(stacks);
}
