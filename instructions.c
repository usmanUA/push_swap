/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:05:03 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/01 16:06:18 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*new_stack;
	t_stack	*last;

	last = *stack;
	*stack = (*stack)->next;
	new_stack = *stack;
	last->next = NULL;
	ft_stackadd_back(&new_stack, last);
	*stack = new_stack;
}

void	ft_revrotate(t_stack **stack)
{
	t_stack	*new_stack;
	t_stack	*last;

	last = ft_stacklast(*stack);
	new_stack = *stack;
	while (new_stack->next->next != NULL)
		new_stack = new_stack->next;
	new_stack->next = NULL;
	ft_stackadd_front(stack, last);
}

void	ft_swap(t_list **stack)
{
	t_list	*frst;
	t_list	*scnd;
	t_list	*new_stack;

	if (!(*stack) && !((*stack)->next))
		return ;
	frst = *stack;
	*stack = (*stack)->next;
	scnd = *stack;
	*stack = (*stack)->next;
	new_stack = *stack;
	frst->next = NULL;
	scnd->next = NULL;
	ft_lstadd_front(&new_stack, frst);
	ft_lstadd_front(&new_stack, scnd);
	*stack = new_stack;
}

void	ft_push(t_stack **a, t_stack **b)
{
	if ((*b)->num)
		(*a)->num = (*b)->num;
}
