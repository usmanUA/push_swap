/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/16 13:30:07 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestack(t_stack *stack)
{
	t_stack	*current;

	while (stack)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}

void	ft_freestacks(t_stacks *stacks)
{
	if (stacks->moves)
		free(stacks->moves);
	if (stacks->optimal)
		free(stacks->optimal);
	if (stacks->limits)
		free(stacks->limits);
	if (stacks->a)
		ft_freestack(stacks->a);
	if (stacks->b)
		ft_freestack(stacks->b);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stacks	stacks;

	a = NULL;
	if (!ft_stack(argc - 1, argv, &a) || !ft_initializestacks(&stacks))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stacks.a = a;
	if (!ft_sort_small(&stacks))
		ft_sort(&stacks);
	ft_freestacks(&stacks);
	return (0);
}
