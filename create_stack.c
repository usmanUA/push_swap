/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:11:26 by uahmed            #+#    #+#             */
/*   Updated: 2024/03/13 12:12:58 by uahmed           ###   ########.fr       */
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

static void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (!stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

static int	ft_newstack(t_stack **a, int num)
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

static void	ft_createstack(int tot, t_stack **a, int **c)
{
	int	ind;

	ind = -1;
	while (++ind < tot)
	{
		if (!ft_newstack(a, (*c)[ind]))
		{
			ft_freestack(*a);
			free(*c);
		}
	}
	free(*c);
}

void	ft_stack(int tot, char **argv, t_stack **a, int bonus)
{
	int	*c;
	int	fre;

	fre = 0;
	if (tot == 1)
		fre = 1;
	if (tot == 1)
		tot = ft_wordcount(argv);
	c = ft_numsarr(tot, argv);
	if (ft_checknumdup(c, tot))
	{
		free(c);
		ft_error(argv, fre);
	}
	if ((!bonus && ft_sorted(c, tot)))
	{
		if (c)
			free(c);
		if (fre)
			ft_free(argv, 0);
		exit(0);
	}
	ft_createstack(tot, a, &c);
}
