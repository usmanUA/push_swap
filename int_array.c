/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:13:49 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/16 13:39:18 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(int *c, int tot)
{
	int	ind;

	ind = -1;
	tot--;
	while (++ind < tot)
	{
		if (c[ind] < c[ind + 1])
			return (0);
	}
	return (1);
}

int	ft_wordcount(char **words)
{
	int	count;

	count = 0;
	while (words[count])
		count++;
	return (count);
}

int	ft_checknumdup(int *arr, int tot)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tot)
	{
		j = -1;
		while (++j < tot)
		{
			if (i != j)
			{
				if (arr[i] == arr[j])
					return (1);
			}
		}
	}
	return (0);
}

int	*ft_numsarr(int tot, char **arg)
{
	int	*num;
	int	n;
	int	ind;

	num = malloc(sizeof(int) * tot);
	if (!num)
		return (0);
	ind = -1;
	while (tot--)
	{
		if (!ft_strncmp(arg[tot], "0", 1))
			n = 0;
		else
		{
			n = ft_atoi(arg[tot]);
			if (!n)
			{
				free(num);
				return (0);
			}
		}
		num[++ind] = n;
	}
	return (num);
}

int	*ft_fromvar(char **argv, int *tot)
{
	char	**str;
	int		*numarr;

	str = ft_split(argv[1], ' ');
	if (!str)
		return (0);
	*tot = ft_wordcount(str);
	numarr = ft_numsarr(*tot, str);
	ft_freestr(str);
	return (numarr);
}
