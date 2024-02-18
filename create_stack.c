/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:11:26 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/10 19:09:02 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stacksize(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	tmp = stack;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
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

int	ft_newstack(t_stack **a, int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->num = num;
	new->next = NULL;
	ft_stackadd_front(a, new);
	return (1);
}

int	ft_createstack(int tot, t_stack **a, int **c)
{
	int	ind;

	ind = -1;
	while (++ind < tot)
	{
		if (!ft_newstack(a, (*c)[ind]))
		{
			ft_freestack(*a);
			free(*c);
			c = NULL;
			return (0);
		}
	}
	free(*c);
	c = NULL;
	return (1);
}

int	ft_stack(int tot, char **argv, t_stack **a)
{
	int	*c;

	if (tot == 1)
		c = ft_fromvar(argv, &tot);
	else
		c = ft_numsarr(tot, &argv[1]);
	if (!c)
		return (0);
	if (ft_checknumdup(c, tot) || ft_sorted(c, tot))
	{
		if (c)
			free(c);
		return (0);
	}
	return (ft_createstack(tot, a, &c));
}
