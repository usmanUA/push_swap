/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:40:25 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/05 18:26:51 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_biggest(int num, t_stack *stack)
{
    while (stack)
    {
        if (num < stack -> num)
            return (0);
        stack = stack -> next;
    }
    return (1);
}

int ft_smallest(int num, t_stack *stack)
{
    while (stack)
    {
        if (num > stack -> num)
            return (0);
        stack = stack -> next;
    }
    return (1);
}

int ft_ismax(t_stack *stack)
{
    int first;

    first = stack -> num;
    while (stack)
    {
        if (stack -> num > first)
            return (1);
        stack = stack -> next;
    }
    return (0);
}

int ft_ismax(t_stack *stack)
{
    int first;

    first = stack -> num;
    while (stack)
    {
        if (stack -> num < first)
            return (1);
        stack = stack -> next;
    }
    return (0);
}

void    ft_findprice(t_stack **a, t_stack *b)
{
    t_stack **temp;
    int     moves;
    int     check;

    temp = a;
    moves = 1;
    check = -1;
    while (*a)
    {
        if (ft_biggest((*a)->num, b) || ft_smallest((*a)->num, b))
        {
            if (b -> num < (b -> next) -> num)
            {
                (*a)->steps++;
                if (moves > 1)
                {
                    moves--;
                    check++;
                }
            }
            if (check > 0)
                moves += check;
            (*a)->steps = moves;
        }
        *a = (*a)->next;
        moves++;
    }
    a = temp;
}

void    ft_pushdel(t_stack **a, t_stack **b)
{
    t_stack **temp;

    temp = a;
    (*b) -> num = (*temp) -> num;
    *a = (*a) -> next;
    free(*temp);
}

void    ft_pushtob(t_stack **a, t_stack **b)
{
    t_stack **tempb;

    tempb = b;
    ft_pushdel(a, b);
    ft_pushdel(a, &((*b)->next));
    ft_findprice(a, b);
    
    
}