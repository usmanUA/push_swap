/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:08:11 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/16 13:40:14 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestr(char **str)
{
	char	**tmp;

	tmp = str;
	if (str)
	{
		while (*str)
		{
			free(*str);
			str++;
		}
		str = tmp;
		free(str);
		str = NULL;
	}
}

void	ft_moverest(t_stacks *stacks)
{
	while (stacks->optimal->rra)
	{
		ft_revrotate(stacks, 'a');
		stacks->optimal->rra--;
	}
	while (stacks->optimal->rrr)
	{
		ft_revrotate(stacks, 'c');
		stacks->optimal->rrr--;
	}
	ft_push(stacks, 'b');
}

void	ft_moveoptimal(t_stacks *stacks)
{
	while (stacks->optimal->rb)
	{
		ft_rotate(stacks, 'b');
		stacks->optimal->rb--;
	}
	while (stacks->optimal->ra)
	{
		ft_rotate(stacks, 'a');
		stacks->optimal->ra--;
	}
	while (stacks->optimal->rr)
	{
		ft_rotate(stacks, 'c');
		stacks->optimal->rr--;
	}
	while (stacks->optimal->rrb)
	{
		ft_revrotate(stacks, 'b');
		stacks->optimal->rrb--;
	}
	ft_moverest(stacks);
}

int	ft_findindex(t_stack *stack, int num)
{
	int		ind;
	t_stack	*tmp;

	tmp = stack;
	ind = 0;
	while (tmp)
	{
		if (tmp->num == num)
			break ;
		ind++;
		tmp = tmp->next;
	}
	return (ind);
}
