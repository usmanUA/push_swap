/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:47:34 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/18 17:53:49 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_newmin_a(t_stacks *stacks, t_stack *tmp_a)
{
	int		imin_a;
	int		size_a;
	t_stack	*tmp;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (tmp_a->num == stacks->limits->min_a)
		return ;
	tmp = tmp_a;
	imin_a = ft_findindex(tmp_a, stacks->limits->min_a);
	size_a = ft_stacksize(tmp);
	ft_getmoves(stacks, size_a, imin_a, 'a');
}

void	ft_get_num_a(t_stacks *stacks, t_stack *stack, int num)
{
	int		i;
	int		size;
	int		num_a;
	t_stack	*tmp;

	tmp = stack;
	num_a = tmp->num;
	i = 0;
	while (tmp->next)
	{
		if (num > tmp->num && num < tmp->next->num)
			num_a = tmp->next->num;
		i++;
		tmp = tmp->next;
	}
	i = ft_findindex(stack, num_a);
	size = ft_stacksize(stack);
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stack->num == num_a)
		return ;
	ft_getmoves(stacks, size, i, 'a');
}

void	ft_bringup_a(t_stacks *stacks)
{
	while (stacks->moves->ra)
	{
		ft_rotate(stacks, 'a');
		stacks->moves->ra--;
	}
	while (stacks->moves->rra)
	{
		ft_revrotate(stacks, 'a');
		stacks->moves->rra--;
	}
}

void	ft_minup_a(t_stacks *stacks)
{
	int		i;
	int		size;
	t_stack	*tmp_a;

	tmp_a = stacks->a;
	ft_minmax(stacks, 'a');
	if (stacks->limits->min_a != tmp_a->num)
	{
		i = ft_findindex(tmp_a, stacks->limits->min_a);
		size = ft_stacksize(tmp_a);
		ft_getmoves(stacks, size, i, 'a');
		ft_bringup_a(stacks);
	}
}

void	ft_move_back(t_stacks *stacks)
{
	t_stack	*tmp_a;

	tmp_a = stacks->a;
	while (stacks->b)
	{
		ft_minmax(stacks, 'a');
		if (stacks->limits->max_a < tmp_a->num)
			ft_newmax_a(stacks, tmp_a);
		else if (stacks->limits->min_a > tmp_a->num)
			ft_newmin_a(stacks, tmp_a);
		else
			ft_get_num_a(stacks, tmp_a, stacks->b->num);
		ft_bringup_a(stacks);
		ft_push(stacks, 'a');
	}
	ft_minup_a(stacks);
}
