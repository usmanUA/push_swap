/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:08:11 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/11 17:41:43 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestr(char **str)
{
	char **tmp;

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

void    ft_moverest(t_stacks *stacks)
{
    while (stacks->moves->rra)
    {
        ft_revrotate(stacks, 'a');
        stacks->moves->rra--;
    }
    while (stacks->moves->rrr)
    {
        ft_revrotate(stacks, 'c');
        stacks->moves->rrr--;
    }
    ft_push(stacks, 'b');
}

void    ft_movemoves(t_stacks *stacks)
{
    while (stacks->moves->rb)
    {
        ft_rotate(stacks, 'b');
        stacks->moves->rb--;
    }
    while (stacks->moves->ra)
    {
        ft_rotate(stacks, 'a');
        stacks->moves->ra--;
    }
    while (stacks->moves->rr)
    {
        ft_rotate(stacks, 'c');
        stacks->moves->rr--;
    }
    while (stacks->moves->rrb)
    {
        ft_revrotate(stacks, 'b');
        stacks->moves->rrb--;
    }
    ft_moverest(stacks); 
}

int	ft_initializestacks(t_stacks *stacks)
{
	t_moves *moves;
	
	moves = (t_moves *)malloc(sizeof(t_moves));
	if (!moves)
		return (0);
    moves->pa = 0;
    moves->pb = 0;
    moves->ra = 0;
    moves->rb = 0;
    moves->rr = 0;
    moves->rra = 0;
    moves->rrb = 0;
    moves->rrr = 0;
    moves->sa = 0;
    moves->sb = 0;
    moves->ss = 0;
	stacks->moves = moves;
	return (1);
}



