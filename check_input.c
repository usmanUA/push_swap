/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:55:13 by uahmed            #+#    #+#             */
/*   Updated: 2024/03/14 11:44:59 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char **str, int free)
{
	write(2, "Error\n", 6);
	if (free)
		ft_free(str, 0);
	exit(EXIT_FAILURE);
}

static void	ft_limit(int argc, char **argv, int free)
{
	int		i;
	long	num;

	i = -1;
	num = 0;
	while (++i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(argv, free);
	}
}

static void	ft_int(int argc, char **argv, int free)
{
	int	i;
	int	j;

	if (argc == 1)
		argc = ft_wordcount(argv);
	ft_limit(argc, argv, free);
	i = -1;
	while (++i < argc)
	{
		j = -1;
		if (argv[i][0] == '\0')
			ft_error(argv, free);
		while (++j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && (argv[i][j] == '-'
					|| (argv[i][j] == '+')))
					continue ;
				ft_error(argv, free);
			}
		}
	}
}

char	**ft_check_input(int argc, char **args)
{
	char	**str;
	int		free;

	free = 0;
	if (argc == 1)
	{
		str = ft_split(args[1], NULL, ' ', 0);
		if (!str || !str[0])
			ft_error(args, free);
		free = 1;
	}
	else
		str = &args[1];
	if (str && str[0])
		ft_int(argc, str, free);
	return (str);
}
