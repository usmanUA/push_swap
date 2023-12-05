/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:03 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/01 16:14:21 by uahmed           ###   ########.fr       */
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
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;

	a = NULL;
	b = NULL;
	if (!ft_stack(argc - 1, &a, &b, argv))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	// ft_rotate(&a);
	temp = a;
	while (temp)
	{
		printf("num in stack: %d and it's index: %d\n", temp->num, temp->ind);
		temp = temp->next;
	}
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}
