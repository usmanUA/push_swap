/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/03/14 11:56:59 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stacks	stacks;
	char		**args;

	if (argc > 1)
	{
		args = ft_check_input(argc - 1, argv);
		a = NULL;
		ft_stack(argc - 1, args, &a, 0);
		stacks.a = a;
		if (!ft_sort_small(&stacks))
			ft_sort(&stacks);
		ft_freestacks(&stacks);
		if (argc == 2)
			ft_free(args, 0);
	}
	return (0);
}
