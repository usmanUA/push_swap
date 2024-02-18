/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:03 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/17 14:24:02 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_exec_instructions(t_stacks *stacks, char *instruction)
{
	if (!ft_strncmp(instruction, "pb\n", 3))
		ft_push(stacks, 'b');
	else if (!ft_strncmp(instruction, "pa\n", 3))
		ft_push(stacks, 'a');
	else if (!ft_strncmp(instruction, "sa\n", 3))
		ft_swap(stacks, 'a');
	else if (!ft_strncmp(instruction, "sb\n", 3))
		ft_swap(stacks, 'b');
	else if (!ft_strncmp(instruction, "ss\n", 3))
		ft_swap(stacks, 'c');
	else if (!ft_strncmp(instruction, "ra\n", 3))
		ft_rotate(stacks, 'a');
	else if (!ft_strncmp(instruction, "rb\n", 3))
		ft_rotate(stacks, 'b');
	else if (!ft_strncmp(instruction, "rr\n", 3))
		ft_rotate(stacks, 'c');
	else if (!ft_strncmp(instruction, "rra\n", 4))
		ft_revrotate(stacks, 'a');
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		ft_revrotate(stacks, 'b');
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		ft_revrotate(stacks, 'c');
	else
		return (0);
	return (1);
}

int	ft_stacksorted(t_stacks *stacks)
{
	t_stack	*tmp_a;

	tmp_a = stacks->a;
	if (stacks->b)
		return (0);
	while (tmp_a->next)
	{
		if (tmp_a->num > tmp_a->next->num)
			return (0);
		tmp_a = tmp_a->next;
	}
	return (1);
}

void	ft_saveinstructions(t_stacks *stacks)
{
	char	*line;
	t_list	*instructions;

	instructions = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_lstadd_back(&instructions, ft_lstnew(line));
	}
	stacks->instructions = instructions;
}

int	ft_applymoves(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->instructions;
	while (tmp)
	{
		if (!ft_exec_instructions(stacks, (char *)tmp->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	a = NULL;
	if (!ft_stack(argc - 1, argv, &a) || !ft_initializestacks(&stacks))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stacks.a = a;
	ft_saveinstructions(&stacks);
	if (!ft_applymoves(&stacks))
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (ft_stacksorted(&stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_freestacks(&stacks);
	return (0);
}
