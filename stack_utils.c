/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:08:11 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/01 16:31:16 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *last)
{
	if (!stack)
	{
		*stack = last;
		return ;
	}
	ft_stacklast(*stack)->next = last;
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (!stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_stacknew(int num, int tot, int *sorted)
{
	t_stack	*new;
	int		i;
	int		ind;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	i = -1;
	ind = 0;
	while (++i < tot)
	{
		if (sorted[i] == num)
			ind = i;
	}
	new->num = num;
	new->ind = ind + 1;
	new->next = NULL;
	return (new);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
