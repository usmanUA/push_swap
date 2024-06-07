/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:47:34 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/22 14:14:23 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_num_a(t_stack *stack_a, int num_b)
{
	int	*nums;
	int	tot;
	int	i;
	int	min;

	tot = ft_num_arr_size(stack_a, num_b, 1);
	nums = ft_next_prev_nums(stack_a, num_b, tot, 1);
	min = nums[0];
	i = -1;
	while (++i < tot)
	{
		if (min > nums[i])
			min = nums[i];
	}
	free(nums);
	return (min);
}

static int	ft_all_smaller(t_stack *stack_a, int num_b)
{
	t_stack	*tmp_a;

	tmp_a = stack_a;
	while (tmp_a)
	{
		if (num_b <= tmp_a->num)
			return (0);
		tmp_a = tmp_a->next;
	}
	return (1);
}

static void	ft_get_num_a(t_stacks *stacks, int num_b)
{
	int		i;
	int		size;
	int		num_a;
	t_stack	*tmp;

	tmp = stacks->a;
	i = 0;
	if (ft_all_smaller(tmp, num_b))
	{
		ft_push(stacks, 'a', 1);
		ft_minup_a(stacks);
		return ;
	}
	num_a = ft_num_a(tmp, num_b);
	i = ft_findindex(tmp, num_a);
	size = ft_stacksize(tmp);
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	ft_getmoves(stacks, size, i, 'a');
}

void	ft_move_a(t_stacks *stacks)
{
	while (stacks->moves->ra)
	{
		ft_rotate(stacks, 'a', 1);
		stacks->moves->ra--;
	}
	while (stacks->moves->rra)
	{
		ft_revrotate(stacks, 'a', 1);
		stacks->moves->rra--;
	}
}

void	ft_move_back(t_stacks *stacks)
{
	int	newmax;

	newmax = 0;
	while (stacks->b)
	{
		ft_minmax(stacks, 'a');
		if (stacks->limits->max_a < stacks->b->num)
		{
			ft_newmax_a(stacks);
			newmax = 1;
		}
		else if (stacks->limits->min_a > stacks->b->num)
			ft_newmin_a(stacks);
		else
			ft_get_num_a(stacks, stacks->b->num);
		ft_move_a(stacks);
		ft_push(stacks, 'a', 1);
		if (newmax)
		{
			ft_rotate(stacks, 'a', 1);
			newmax = 0;
		}
	}
	ft_minmax(stacks, 'a');
	ft_minup_a(stacks);
}
