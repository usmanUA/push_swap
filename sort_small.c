/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:26:39 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/22 14:13:27 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_two(t_stacks *stacks)
{
	ft_swap(stacks, 'a', 1);
}

void	ft_sort_three(t_stacks *stacks)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = stacks->a->num;
	n2 = stacks->a->next->num;
	n3 = stacks->a->next->next->num;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		ft_swap(stacks, 'a', 1);
	else if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		ft_swap(stacks, 'a', 1);
		ft_revrotate(stacks, 'a', 1);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ft_rotate(stacks, 'a', 1);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		ft_swap(stacks, 'a', 1);
		ft_rotate(stacks, 'a', 1);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		ft_revrotate(stacks, 'a', 1);
}

static void	ft_sort_four(t_stacks *stacks)
{
	ft_push(stacks, 'b', 1);
	ft_sort_three(stacks);
	ft_move_back(stacks);
}

int	ft_sort_small(t_stacks *stacks)
{
	if (ft_stacksize(stacks->a) == 2)
	{
		ft_sort_two(stacks);
		return (1);
	}
	else if (ft_stacksize(stacks->a) == 3)
	{
		ft_sort_three(stacks);
		return (1);
	}
	else if (ft_stacksize(stacks->a) == 4)
	{
		if (!ft_initializestacks(stacks))
			return (1);
		ft_sort_four(stacks);
		return (1);
	}
	return (0);
}
