/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_more_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:25:50 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/11 15:12:36 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_rotate_a(t_stacks *stacks)
{
	t_stack *last;
	t_stack *tmp;
	
	last = stacks->a;
	stacks->a = stacks->a->next;
	tmp = stacks->a;
	last->next = NULL;
	while (stacks->a->next)
		stacks->a = stacks->a->next;
	stacks->a->next = last;
	stacks->a = tmp;
}

void	ft_revrotate_a(t_stacks *stacks)
{
	t_stack *first;
	t_stack *second;
	t_stack *tmp;
	
	second = stacks->a;
	tmp = stacks->a;
	while (tmp->next->next)
		tmp = tmp->next;
	first = tmp->next;
	tmp->next = NULL;
	first->next = second;
	stacks->a = first;
}

void	ft_push_a(t_stacks *stacks)
{
	t_stack *tmp_b;
	
	if (!stacks -> b)
	{
		stacks->b = stacks->a;
		stacks->a = stacks->a->next;
		stacks->b->next = NULL;
		// ft_displaystacks(stacks);
	}
	else
	{
		tmp_b = stacks->b;
		stacks->b = stacks->a;
		stacks->a = stacks->a->next;
		stacks->b->next = tmp_b;
		// ft_displaystacks(stacks);
	}
}

