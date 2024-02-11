/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/11 17:36:01 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"


void	ft_freestack(t_stack *stack)
{
	t_stack *current;
	
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
	if (stacks->a)
		ft_freestack(stacks->a);
	if (stacks->b)
		ft_freestack(stacks->b);
}


int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stacks stacks;
	int flag;
	char *line;
	t_list *instructions;

	a = NULL;
	flag = 1;
	if (!ft_stack(argc - 1, argv, &a) || !ft_initializestacks(&stacks))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stacks.a = a;
	while (flag)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_lstadd_back(&instructions, ft_lstnew(line));
	}
	stacks.instructions = instructions;
	while (stacks.instructions)
	{
		stacks.instructions = stacks.instructions->next;
	}
	
	ft_freestacks(&stacks);
	return (0);
}
