/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:24:15 by uahmed            #+#    #+#             */
/*   Updated: 2024/03/13 12:30:28 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_freeinstructions(t_list *instructions)
{
	t_list	*tmp;

	while (instructions)
	{
		tmp = instructions->next;
		ft_lstdelone(instructions, &free);
		instructions = tmp;
	}
}

int	ft_exec_instructions(t_stacks *stacks, char *instruction, char **args,
		int free)
{
	if (!ft_strncmp(instruction, "pb\n", 3))
		ft_push(stacks, 'b', 0);
	else if (!ft_strncmp(instruction, "pa\n", 3))
		ft_push(stacks, 'a', 0);
	else if (!ft_strncmp(instruction, "sa\n", 3))
		ft_swap(stacks, 'a', 0);
	else if (!ft_strncmp(instruction, "sb\n", 3))
		ft_swap(stacks, 'b', 0);
	else if (!ft_strncmp(instruction, "ss\n", 3))
		ft_swap(stacks, 'c', 0);
	else if (!ft_strncmp(instruction, "ra\n", 3))
		ft_rotate(stacks, 'a', 0);
	else if (!ft_strncmp(instruction, "rb\n", 3))
		ft_rotate(stacks, 'b', 0);
	else if (!ft_strncmp(instruction, "rr\n", 3))
		ft_rotate(stacks, 'c', 0);
	else if (!ft_strncmp(instruction, "rra\n", 4))
		ft_revrotate(stacks, 'a', 0);
	else if (!ft_strncmp(instruction, "rrb\n", 4))
		ft_revrotate(stacks, 'b', 0);
	else if (!ft_strncmp(instruction, "rrr\n", 4))
		ft_revrotate(stacks, 'c', 0);
	else
		ft_error(args, free);
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

t_list	*ft_saveinstructions(int fd)
{
	char	*line;
	t_list	*instructions;

	instructions = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_lstadd_back(&instructions, ft_lstnew(line));
	}
	return (instructions);
}

void	ft_apply_check(t_stacks *stacks, t_list *instructions, int argc,
		char **args)
{
	t_list	*tmp;
	int		free;

	free = 0;
	if (argc == 2)
		free = 1;
	tmp = instructions;
	while (tmp)
	{
		if (!ft_exec_instructions(stacks, (char *)tmp->content, args, free))
		{
			ft_freestacks(stacks);
			ft_error(args, free);
		}
		tmp = tmp->next;
	}
	if (ft_stacksorted(stacks))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
