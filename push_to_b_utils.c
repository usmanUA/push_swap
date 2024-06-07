/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:52:34 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/20 17:01:29 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimal(t_stacks *stacks, int ind)
{
	stacks->moves->cost = stacks->moves->pb + stacks->moves->ra
		+ stacks->moves->rra + stacks->moves->rb + stacks->moves->rrb
		+ stacks->moves->rr + stacks->moves->rrr;
	if (ind == 0 || stacks->optimal->cost > stacks->moves->cost)
	{
		stacks->optimal->cost = stacks->moves->cost;
		stacks->optimal->pb = stacks->moves->pb;
		stacks->optimal->ra = stacks->moves->ra;
		stacks->optimal->rra = stacks->moves->rra;
		stacks->optimal->rb = stacks->moves->rb;
		stacks->optimal->rrb = stacks->moves->rrb;
		stacks->optimal->rr = stacks->moves->rr;
		stacks->optimal->rrr = stacks->moves->rrr;
	}
}

int	ft_num_b(t_stack *stack_b, int num_a)
{
	int	*nums;
	int	tot;
	int	i;
	int	max;

	tot = ft_num_arr_size(stack_b, num_a, 0);
	nums = ft_next_prev_nums(stack_b, num_a, tot, 0);
	max = nums[0];
	i = -1;
	while (++i < tot)
	{
		if (max < nums[i])
			max = nums[i];
	}
	free(nums);
	return (max);
}

void	ft_newnum_b(t_stacks *stacks, t_stack *tmp_b, int num_a)
{
	t_stack	*tmp_again;
	int		num_b;
	int		ind_b;
	int		size_b;

	tmp_again = tmp_b;
	num_b = ft_num_b(tmp_b, num_a);
	ind_b = ft_findindex(tmp_b, num_b);
	size_b = ft_stacksize(tmp_b);
	ft_getmoves(stacks, size_b, ind_b, 'b');
}

static void	ft_savemoves(t_stacks *stacks, int r, int rr, int stack)
{
	if (stack == 'a')
	{
		stacks->moves->ra = r;
		stacks->moves->rra = rr;
		return ;
	}
	else if (stack == 'b')
	{
		stacks->moves->rb = r;
		stacks->moves->rrb = rr;
	}
}

void	ft_getmoves(t_stacks *stacks, int size, int ind, int stack)
{
	int	r;
	int	rr;

	r = 0;
	rr = 0;
	if (size % 2 == 0)
	{
		if (ind + 1 > size / 2)
			rr = size - ind;
		else
			r = ind;
	}
	else
	{
		if (ind > size / 2)
			rr = size - ind;
		else
			r = ind;
	}
	ft_savemoves(stacks, r, rr, stack);
}
