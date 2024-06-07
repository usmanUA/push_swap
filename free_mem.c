/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:00:14 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/29 10:37:18 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestack(t_stack *stack)
{
	t_stack	*current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}

void	ft_freestacks(t_stacks *stacks)
{
	if (stacks->moves)
		free(stacks->moves);
	if (stacks->optimal)
		free(stacks->optimal);
	if (stacks->limits)
		free(stacks->limits);
	if (stacks->a)
		ft_freestack(stacks->a);
	if (stacks->b)
		ft_freestack(stacks->b);
}

void	ft_rotate_a(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!stacks->a || !stacks->a->next)
		return ;
	last = stacks->a;
	stacks->a = stacks->a->next;
	tmp = stacks->a;
	last->next = NULL;
	while (stacks->a->next)
		stacks->a = stacks->a->next;
	stacks->a->next = last;
	stacks->a = tmp;
}
