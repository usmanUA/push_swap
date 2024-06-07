/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:50:59 by uahmed            #+#    #+#             */
/*   Updated: 2024/03/13 12:31:09 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "push_swap.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_freestr(char **str);
int		ft_stacksorted(t_stacks *stacks);
void	ft_apply_check(t_stacks *stacks, t_list *instructions, int argc,
			char **args);
t_list	*ft_saveinstructions(int fd);
int		ft_exec_instructions(t_stacks *stacks, char *instruction, char **args,
			int free);
void	ft_freestacks(t_stacks *stacks);
void	ft_freeinstructions(t_list *instructions);

#endif
