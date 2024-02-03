/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:08:11 by uahmed            #+#    #+#             */
/*   Updated: 2024/01/30 17:29:18 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack	*ft_stacklast(t_stack_a *stack)
// {
// 	while (stack->next)
// 		stack = stack->next;
// 	return (stack);
// }

void	ft_stackadd_back(t_stack_a **stack, t_stack_a *last)
{
	if (!stack)
	{
		*stack = last;
		return ;
	}
	ft_stacklast(*stack)->next = last;
}

void	ft_stackadd_front(t_stack_a **stack, t_stack_a *new)
{
	if (!stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

t_stack	*ft_stacknew(int num)
{
	t_stack	*new;
	int		i;
	int		ind;

	new = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!new)
		return (0);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	ft_stackclear(t_stack_a *stack)
{
	t_stack	*temp;

	if (!stack)
		return ;
	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void	ft_stackdelone(t_stack_a *stack)
{
	t_stack	*temp;

	temp = *stack;
	stack = stack -> next;
	free(temp);
}

int	ft_stacksize(t_stack_a *a)
{
	int	size;

	size = 0;
	while (a)
	{
		size++;
		a = a -> next;
	}
	return (size);
}