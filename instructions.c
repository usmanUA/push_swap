/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:05:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/06 18:10:10 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stacks *stacks)
{
	t_stack *last;
	t_stack *tmp;
	
	last = stacks->a;
	tmp = stacks->a->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp = last;
	last->next = NULL;
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

void	ft_rotate_b(t_stacks *stacks)
{
	t_stack *last;
	t_stack *tmp;
	
	last = stacks->b;
	tmp = stacks->b->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp = last;
	last->next = NULL;
	stacks->b = tmp;
}

void	ft_revrotate_b(t_stacks *stacks)
{
	t_stack *first;
	t_stack *second;
	t_stack *tmp;
	
	second = stacks->b;
	tmp = stacks->b;
	while (tmp->next->next)
		tmp = tmp->next;
	first = tmp->next;
	tmp->next = NULL;
	first->next = second;
	stacks->b = first;
}

void	ft_rotate(t_stacks *stacks, int move)
{
	if (move == 'a')
	{
		write(1, "ra\n", 3);
		ft_rotate_a(stacks);
	}
	else if (move == 'b')
	{
		write(1, "rb\n", 3);
		ft_rotate_b(stacks);
	}
	else
	{
		write(1, "rr\n", 3);
		ft_rotate_a(stacks);
		ft_rotate_b(stacks);
	}
}
void	ft_revrotate(t_stacks *stacks, int move)
{
	if (move == 'a')
	{
		write(1, "ra\n", 3);
		ft_revrotate_a(stacks);
	}
	else if (move == 'b')
	{
		write(1, "rb\n", 3);
		ft_revrotate_b(stacks);
	}
	else
	{
		write(1, "rr\n", 3);
		ft_revrotate_a(stacks);
		ft_revrotate_b(stacks);
	}
}

void	ft_swap(t_list *stack)
{
	t_list	*frst;
	t_list	*scnd;
	t_list	*new_stack;

	if (!stack && !(stack->next))
		return ;
	frst = stack;
	stack = stack->next;
	scnd = stack;
	stack = stack->next;
	new_stack = stack;
	frst->next = NULL;
	scnd->next = NULL;
	ft_lstadd_front(new_stack, frst);
	ft_lstadd_front(new_stack, scnd);
	stack = new_stack;
}

