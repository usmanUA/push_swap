/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/03/13 12:47:21 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stacks	stacks;
	t_list		*instructions;
	char		**args;

	if (argc == 1)
		return (0);
	args = ft_check_input(argc - 1, argv);
	a = NULL;
	ft_stack(argc - 1, args, &a, 1);
	stacks.a = a;
	stacks.b = NULL;
	instructions = ft_saveinstructions(0);
	ft_apply_check(&stacks, instructions, argc, args);
	ft_freestacks(&stacks);
	ft_freeinstructions(instructions);
	if (argc == 2)
		ft_free(args, 0);
	return (0);
}
