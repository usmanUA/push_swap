/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:56:34 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/22 14:15:02 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moverest(t_stacks *stacks)
{
	while (stacks->optimal->rra)
	{
		ft_revrotate(stacks, 'a', 1);
		stacks->optimal->rra--;
	}
	while (stacks->optimal->rrr)
	{
		ft_revrotate(stacks, 'c', 1);
		stacks->optimal->rrr--;
	}
	ft_push(stacks, 'b', 1);
}

void	ft_moveoptimal(t_stacks *stacks)
{
	while (stacks->optimal->rb)
	{
		ft_rotate(stacks, 'b', 1);
		stacks->optimal->rb--;
	}
	while (stacks->optimal->ra)
	{
		ft_rotate(stacks, 'a', 1);
		stacks->optimal->ra--;
	}
	while (stacks->optimal->rr)
	{
		ft_rotate(stacks, 'c', 1);
		stacks->optimal->rr--;
	}
	while (stacks->optimal->rrb)
	{
		ft_revrotate(stacks, 'b', 1);
		stacks->optimal->rrb--;
	}
	ft_moverest(stacks);
}

void	ft_minmax(t_stacks *stacks, int stack)
{
	t_stack	*tmp;
	int		min;
	int		max;

	if (stack == 'a')
		tmp = stacks->a;
	else
		tmp = stacks->b;
	min = tmp->num;
	max = tmp->num;
	while (tmp)
	{
		if (min > tmp->num)
			min = tmp->num;
		else if (max < tmp->num)
			max = tmp->num;
		tmp = tmp->next;
	}
	ft_setminmax(stacks, min, max, stack);
}

int	ft_num_arr_size(t_stack *stack, int num, int bigger)
{
	int		tot;
	t_stack	*temp;

	temp = stack;
	tot = 0;
	if (bigger)
	{
		while (temp)
		{
			if (num < temp->num)
				tot++;
			temp = temp->next;
		}
	}
	else
	{
		while (temp)
		{
			if (num > temp->num)
				tot++;
			temp = temp->next;
		}
	}
	return (tot);
}

int	*ft_next_prev_nums(t_stack *stack, int num, int size, int bigger)
{
	int		*nums;
	t_stack	*temp;

	temp = stack;
	nums = (int *)malloc(sizeof(int) * size);
	if (!nums)
		return (0);
	ft_nums(temp, &nums, num, bigger);
	return (nums);
}
