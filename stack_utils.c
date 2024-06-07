/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:08:11 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/22 14:00:59 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_newmin_a(t_stacks *stacks)
{
	int		imin_a;
	int		size_a;
	t_stack	*tmp;

	stacks->moves->ra = 0;
	stacks->moves->rra = 0;
	if (stacks->a->num == stacks->limits->min_a)
		return ;
	tmp = stacks->a;
	imin_a = ft_findindex(tmp, stacks->limits->min_a);
	size_a = ft_stacksize(tmp);
	ft_getmoves(stacks, size_a, imin_a, 'a');
}

int	ft_findindex(t_stack *stack, int num)
{
	int		ind;
	t_stack	*tmp;

	tmp = stack;
	ind = 0;
	while (tmp)
	{
		if (tmp->num == num)
			break ;
		ind++;
		tmp = tmp->next;
	}
	return (ind);
}
