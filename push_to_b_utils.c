/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:52:34 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/10 19:11:44 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_optimize(t_stacks *stacks)
{
  while (stacks->optimal->ra > 0 && stacks->optimal->rb > 0)
    {
      stacks->optimal->ra--;
      stacks->optimal->rb--;
      stacks->optimal->rr++;
    }
  while (stacks->optimal->rra > 0 && stacks->optimal->rrb > 0)
    {
      stacks->optimal->rra--;
      stacks->optimal->rrb--;
      stacks->optimal->rrr++;
    }
}

void    ft_optimal(t_stacks *stacks, int ind)
{
    stacks->moves->cost = stacks->moves->pb + stacks->moves->ra + stacks->moves->rra + 
                            stacks->moves->rb + stacks->moves->rrb;
    if (ind == 0 || stacks->optimal->cost > stacks->moves->cost)
      {
	stacks->optimal->cost = stacks->moves->cost;
	stacks->optimal->pb = stacks->moves->pb;
	stacks->optimal->ra = stacks->moves->ra;
	stacks->optimal->rra = stacks->moves->rra;
	stacks->optimal->rb = stacks->moves->rb;
	stacks->optimal->rrb = stacks->moves->rrb;
      }
}

void    ft_newnum_b(t_stacks *stacks, t_stack *tmp_b, int num)
{
    t_stack *tmp_again;
    int num_b;
    int ind_b;
    int size_b;
    
    tmp_again = tmp_b;
    num_b = 0;
    while (tmp_again)
    {
        if (num < tmp_again->num && num > tmp_again->next->num)
            num_b = tmp_again->next->num;
        tmp_again = tmp_again->next;
    }
    ind_b = ft_findindex(tmp_b, num_b);
    size_b = ft_stacksize(tmp_b);
    ft_getmoves(stacks, size_b, ind_b, 'b');
}

void    ft_savemoves(t_stacks *stacks, int r, int rr, int stack)
{
    if (stack == 'a')
    {
        stacks->moves->ra = r;
        stacks->moves->rra = rr;
        return ;
    }
    else if (stack == 'b')
    {    
        stacks->moves->rb = r;
        stacks->moves->rrb = rr;
    }     
}

void    ft_getmoves(t_stacks *stacks, int size, int ind, int stack)
{
    int r;
    int rr;
    
    r = 0;
    rr = 0;
    if (size % 2 == 0)
    {
        if (ind + 1 > size/2)
            rr = size - ind;
        else
            r = ind;
    }
    else
    {
        if (ind > size/2)
            rr = size - ind;
        else
            r = ind;
    }
    ft_savemoves(stacks, r, rr, stack);       
}
