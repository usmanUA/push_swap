/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:16:51 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/11 14:41:23 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_rotate_b(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*tmp;

	last = stacks->b;
	tmp = stacks->b->next;
	while (stacks->b->next)
		stacks->b = stacks->b->next;
	stacks->b->next = last;
	stacks->b = tmp;
	last->next = NULL;
}

void	ft_revrotate_b(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tmp;

	second = stacks->b;
	tmp = stacks->b;
	while (tmp->next->next)
		tmp = tmp->next;
	first = tmp->next;
	tmp->next = NULL;
	first->next = second;
	stacks->b = first;
}

void	ft_push_b(t_stacks *stacks)
{
	t_stack	*tmp_a;

	tmp_a = stacks->a;
	stacks->a = stacks->b;
	stacks->b = stacks->b->next;
	stacks->a->next = tmp_a;
}

void	ft_swap_a(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->a->num;
	stacks->a->num = stacks->a->next->num;
	stacks->a->next->num = tmp;
}

void	ft_swap_b(t_stacks *stacks)
{
	int	tmp;

	tmp = stacks->b->num;
	stacks->b->num = stacks->b->next->num;
	stacks->b->next->num = tmp;
}
