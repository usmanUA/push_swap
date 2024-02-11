/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:28:26 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/11 14:18:02 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_setminmax(t_stacks *stacks, int min, int max, int stack)
{
    if (stack == 'a')
    {
        stacks->limits->max_a = max;
        stacks->limits->min_a = min;
    }
    else if (stack == 'b')
    {
        stacks->limits->max_b = max;
        stacks->limits->min_b = min;
    }
}

void    ft_minmax(t_stacks *stacks, int stack)
{
    t_stack *tmp;
    int min;
    int max;

    if (stack == 'a')
        tmp = stacks->a;
    else
        tmp = stacks->b;
    min = tmp->num;
    max = tmp->num;
    while (tmp)
    {
        if (min > tmp->num)
            min = tmp->num;
        else if (max < tmp->num)
            max = tmp->num;
        tmp = tmp->next;
    }
    ft_setminmax(stacks, min, max, stack);
}

void    ft_newmax_a(t_stacks *stacks, t_stack *tmp_a)
{
    int imax_a;
    int size_a;
    t_stack *tmp;

    stacks->moves->ra = 0;
    stacks->moves->rra = 0;
    if (tmp_a->num == stacks->limits->max_a)
        return ;
    tmp = tmp_a;
    imax_a = ft_findindex(tmp_a, stacks->limits->max_a);
    size_a = ft_stacksize(tmp);
    ft_getmoves(stacks, size_a, imax_a, 'a');
}
