/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:05:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/22 15:57:01 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_a(t_stacks *stacks)
{
	int	tmp;

	if (!stacks->a || !stacks->a->next)
		return ;
	tmp = stacks->a->num;
	stacks->a->num = stacks->a->next->num;
	stacks->a->next->num = tmp;
}

static void	ft_swap_b(t_stacks *stacks)
{
	int	tmp;

	if (!stacks->b || !stacks->b->next)
		return ;
	tmp = stacks->b->num;
	stacks->b->num = stacks->b->next->num;
	stacks->b->next->num = tmp;
}

void	ft_swap(t_stacks *stacks, int move, int print)
{
	if (move == 'a')
	{
		if (print)
			write(1, "sa\n", 3);
		ft_swap_a(stacks);
	}
	else if (move == 'b')
	{
		if (print)
			write(1, "sb\n", 3);
		ft_swap_b(stacks);
	}
	else
	{
		if (print)
			write(1, "ss\n", 3);
		ft_swap_a(stacks);
		ft_swap_b(stacks);
	}
}

static void	ft_push_a(t_stacks *stacks)
{
	t_stack	*tmp_b;

	if (!stacks->a)
		return ;
	if (!stacks->b)
	{
		stacks->b = stacks->a;
		stacks->a = stacks->a->next;
		stacks->b->next = NULL;
	}
	else
	{
		tmp_b = stacks->b;
		stacks->b = stacks->a;
		stacks->a = stacks->a->next;
		stacks->b->next = tmp_b;
	}
}

void	ft_push(t_stacks *stacks, int stack, int print)
{
	t_stack	*tmp_a;

	if (stack == 'a')
	{
		if (!stacks->b)
			return ;
		tmp_a = stacks->a;
		stacks->a = stacks->b;
		stacks->b = stacks->b->next;
		stacks->a->next = tmp_a;
		if (print)
			write(1, "pa\n", 3);
	}
	else if (stack == 'b')
	{
		ft_push_a(stacks);
		if (print)
			write(1, "pb\n", 3);
	}
}
