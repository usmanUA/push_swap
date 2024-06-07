/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:28:26 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/21 17:09:28 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ft_move_a(stacks);
	}
}

void	ft_nums(t_stack *stack, int **nums, int num, int bigger)
{
	int	i;

	i = 0;
	if (bigger)
	{
		while (stack)
		{
			if (num < stack->num)
				(*nums)[i++] = stack->num;
			stack = stack->next;
		}
	}
	else
	{
		while (stack)
		{
			if (num > stack->num)
				(*nums)[i++] = stack->num;
			stack = stack->next;
		}
	}
}

void	ft_setminmax(t_stacks *stacks, int min, int max, int stack)
{
	if (stack == 'a')
	{
		stacks->limits->max_a = max;
		stacks->limits->min_a = min;
	}
	else if (stack == 'b')
	{
		stacks->limits->max_b = max;
		stacks->limits->min_b = min;
	}
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_newmax_a(t_stacks *stacks)
{
	t_stack	*tmp;
	int		i;
	int		size;

	tmp = stacks->a;
	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (ft_stacklast(tmp)->num == stacks->limits->max_a)
		return ;
	i = ft_findindex(tmp, stacks->limits->max_a);
	size = ft_stacksize(tmp);
	if (size % 2 == 0)
	{
		if (i + 1 > size / 2)
			stacks->moves->rra = (size - i) - 1;
		else
			stacks->moves->ra = i + 1;
	}
	else
	{
		if (i > size / 2)
			stacks->moves->rra = (size - i) - 1;
		else
			stacks->moves->ra = i + 1;
	}
}
