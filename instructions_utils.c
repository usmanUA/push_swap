/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:16:51 by uahmed            #+#    #+#             */
/*   Updated: 2024/03/13 12:36:14 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_b(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!stacks->b || !stacks->b->next)
		return ;
	last = stacks->b;
	tmp = stacks->b->next;
	while (stacks->b->next)
		stacks->b = stacks->b->next;
	stacks->b->next = last;
	stacks->b = tmp;
	last->next = NULL;
}

static void	ft_revrotate_b(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tmp;

	if (!stacks->b || !stacks->b->next)
		return ;
	second = stacks->b;
	tmp = stacks->b;
	while (tmp->next->next)
		tmp = tmp->next;
	first = tmp->next;
	tmp->next = NULL;
	first->next = second;
	stacks->b = first;
}

static void	ft_revrotate_a(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tmp;

	if (!stacks->a || !stacks->a->next)
		return ;
	second = stacks->a;
	tmp = stacks->a;
	while (tmp->next->next)
		tmp = tmp->next;
	first = tmp->next;
	tmp->next = NULL;
	first->next = second;
	stacks->a = first;
}

void	ft_rotate(t_stacks *stacks, int move, int print)
{
	if (move == 'a')
	{
		if (print)
			write(1, "ra\n", 3);
		ft_rotate_a(stacks);
	}
	else if (move == 'b')
	{
		if (print)
			write(1, "rb\n", 3);
		ft_rotate_b(stacks);
	}
	else
	{
		if (print)
			write(1, "rr\n", 3);
		ft_rotate_a(stacks);
		ft_rotate_b(stacks);
	}
}

void	ft_revrotate(t_stacks *stacks, int move, int print)
{
	if (move == 'a')
	{
		if (print)
			write(1, "rra\n", 4);
		ft_revrotate_a(stacks);
	}
	else if (move == 'b')
	{
		if (print)
			write(1, "rrb\n", 4);
		ft_revrotate_b(stacks);
	}
	else
	{
		if (print)
			write(1, "rrr\n", 4);
		ft_revrotate_a(stacks);
		ft_revrotate_b(stacks);
	}
}
