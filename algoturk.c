/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoturk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:40:25 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/06 17:27:34 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_moverest(t_stacks *stacks)
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
}

void    ft_movecheapest(t_stacks *stacks)
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

int ft_findindex(t_stack *tmp_b, int num)
{
    int ind;
    t_stack_b *tmp_again;

    tmp_again = tmp_b;
    ind = 0;
    while (tmp_again)
    {
        if (tmp_again->num == num)
            return (ind);
        ind++;
        tmp_again = tmp_again->next;
    }
    return (ind);
}
void	ft_optimize(t_stacks *stacks)
{
  while (stacks->optimal->ra > 0 && stacks->optimal->rb > 0)
    {
      stacks->optimal->ra--;
      stacks->optimal->rb--;
      stacks->optimal->rr++;
    }
  while (stacks->moves->rra > 0 && stacks->moves->rrb > 0)
    {
      stacks->optimal->rra--;
      stacks->optimal->rrb--;
      stacks->optimal->rrr++;
    }
}
void    ft_cheaper(t_stacks *stacks, int ind)
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
    t_stack_b *tmp_again;
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
    if ( size % 2 == 0)
    {
        if (ind - 1 > size/2)
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

void    ft_get_top_a(int ind, t_stacks *stacks, t_stack *tmp_a)
{
    stacks->moves->pb = 1;
    if (tmp_a->num == stacks->a->num)  
        return ;
    size = ft_stacksize(tmp_a);
    ft_getmoves(stacks, size, ind, 'a');
}

void    ft_get_num_b(t_stacks *stacks, int num)
{
    int imax_b;
    t_stack *tmp_b;
    int size_b;
    
    tmp_b = stacks->b;
    if (num > stacks->limits->max_b || num < stacks->limits->min_b)
    {
        if (tmp_b->num == stacks->limits->max_b)
            return ;
        imax_b = ft_findindex(tmp_b, stacks->limits->max_b);
        size_b = ft_stacksize(tmp_b);
        ft_getmoves(stacks, size_b, imax_b, 'b');
     }
    else
        ft_newnum_b(stacks, tmp_b, num);
}

void    ft_findmoves(t_stacks *stacks)
{
    t_stack *tmp_a;
    t_moves *tmp_moves;
    t_optimal *tmp_optimal;
    int size;
    int ind;

    tmp_moves = (t_moves *)malloc(sizeof(t_moves));
    tmp_optimal = (t_optimal *)malloc(sizeof(t_optimal));
    stacks->moves = tmp_moves;
    stacks->optimal = tmp_optimal;
    tmp_a = stacks->a;
    size = ft_stacksize(tmp_a);
    ind = -1;
    while (++ind < size)
    {
        ft_get_top_a(ind, stacks, tmp_a);
        ft_get_num_b(stacks, tmp_a->num);
        ft_cheaper(stacks, ind);
        tmp_a = tmp_a->next;
    }
}

void    ft_minmax_b(t_stacks *stacks)
{
    t_stack *tmp_b;
    t_limits *minmax;

    tmp_b = stacks->b;
    minmax = (t_limits *)malloc(sizeof(t_limits));
    minmax->min_b = tmp_b->num;
    minmax->max_b = tmp_b->num;
    while (tmp_b)
    {
        if (tmp_b->num < minmax->min_b)
            minmax->min_b = tmp_b->num;
        else if (tmp_b->num > minmax->max_b)
            minmax->max_b = tmp_b->num;
        tmp_b = tmp_b->next;
    }
    stacks->limits = minmax;
}

void    ft_push(t_stacks *stacks, int a_b)
{
    t_stack *tmp_b;
    
    if (a_b == 'a')
    {
        
        write(1, "pa\n", 3);
    }
    else
    {
        if (!stacks -> b)
        {
            stacks->b = stacks->a;
            stacks->a = stacks->a->next;
            stacks->b->next = NULL;
        }
        else
        {
            tmp_b = stacks->b;
            stacks->b = stacks->a;
            stacks->a = stacks->a->next;
            stacks->b->next = tmp_b;
        }
        write(1, "pb\n", 3);
    }
}

void    ft_sort(t_stacks *stacks)
{
    int size_a;

    if (ft_stacksize(stacks->a) == 2)
        ft_sort_two(stacks);
    else if (ft_stacksize(stacks->a) == 3)
        ft_sort_three(stacks);
    else if (ft_stacksize(stacks->a) == 4)
        ft_sort_four(stacks);
    else
    {
        ft_push(stacks, 'b');
        ft_push(stacks, 'b');
        while (ft_stacksize(stacks->a) > 3)
        {
            ft_minmax_b(stacks);
            ft_findmoves(stacks);
            ft_optimize(stacks);
            ft_movecheapest(stacks);
        }
    }
}
