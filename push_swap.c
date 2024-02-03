/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/01/31 12:34:47 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **s)
{
	while (*s)
	{
		free(*s);
		s++;
	}
	free(s);
	s = NULL;
}

int	main(int argc, char **argv)
{
	t_stack_a	*a;
	t_stacks stacks;

	if (!ft_stack(argc - 1, argv, &a))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stacks.a = a;
	ft_sort(&stacks);
	return (0);
}
