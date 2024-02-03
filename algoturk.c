/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoturk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:40:25 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/03 17:06:51 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_findindex(t_stack_b *tmp_b, int num)
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

void    ft_cheaper(t_stacks *stacks)
{
    stacks->moves->cost = stacks->moves->pb + stacks->moves->ra+stacks->moves->rra + 
                            stacks->moves->rb + stacks->moves->rrb;
    stacks->optimal->cost = stacks->moves->cost;
    
}

void    ft_newnum_b(t_stacks *stacks, t_stack_b *tmp_b, int num)
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

void    ft_get_top_a(int ind, t_stacks *stacks, t_stack_a *tmp_a)
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
    t_stack_b *tmp_b;
    int size_b;
    
    tmp_b = stacks->b;
    if (num > stacks->limits->max_b || num < stacks->limits->min_b)
    {
        imax_b = ft_findindex(tmp_b, stacks->limits->max_b);
        if (tmp_b->num == stacks->limits->max_b)
            return ;
        size_b = ft_stacksize(tmp_b);
        ft_getmoves(stacks, size_b, imax_b, 'b');
     }
    else
        ft_newnum_b(stacks, tmp_b, num);
}

void    ft_findmoves(t_stacks *stacks)
{
    t_stack_a *tmp_a;    
    int size;
    int ind;

    stacks->moves = (t_moves)malloc(sizeof(t_moves));
    stacks->optimal = (t_optimal)malloc(sizeof(t_optimal));
    tmp_a = stacks->a;
    size = ft_stacksize(tmp_a);
    ind = -1;
    while (++ind < size)
    {
        ft_get_top_a(ind, stacks, tmp_a);
        ft_get_num_b(stacks, tmp_a->num);
        ft_cheaper(stacks);
        tmp_a = tmp_a->next;
    }
}

void    ft_minmax_b(t_stacks *stacks)
{
    t_stack_b tmp_b;

    tmp_b = stacks->b;
    stacks->limits->min_b = tmp_b->num;
    stacks->limits->max_b = tmp_b->num;
    while (tmp_b)
    {
        if (tmp_b->num < stacks->limits->min_b)
            stacks->limits->min_b = tmp_b->num;
        else if (tmp_b->num > stacks->limits->max_b)
            stacks->limits->max_b = tmp_b->num;
        tmp_b = tmp_b->next;
    }
}

void    ft_push(t_stacks *stacks, int a_b)
{
    t_stack_b *tmp_b;
    
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
            ft_movecheapest(stacks);
        }
    }
}
