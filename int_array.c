/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:13:49 by uahmed            #+#    #+#             */
/*   Updated: 2024/03/13 12:10:44 by uahmed           ###   ########.fr       */
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
	int	ind;

	ind = -1;
	num = malloc(sizeof(int) * tot);
	if (!num)
	{
		ft_free(arg, 0);
		exit(EXIT_FAILURE);
	}
	while (tot--)
		num[++ind] = ft_atoi(arg[tot]);
	return (num);
}
