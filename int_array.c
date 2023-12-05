/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:13:49 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/01 16:14:10 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_wordcount(char **words)
{
	size_t	count;

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

int	*ft_numsarr(int tot, char **arg, int start)
{
	int	*num;
	int	ind;
	int	n;

	num = malloc(sizeof(int) * tot);
	if (!num)
		return (0);
	ind = -1;
	while (++ind < tot)
	{
		if (!ft_strncmp(arg[ind + start], "0", 1))
			n = 0;
		else
		{
			n = ft_atoi(arg[ind + start]);
			if (!n)
			{
				free(num);
				return (0);
			}
		}
		num[ind] = n;
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
	numarr = ft_numsarr(*tot, str, 0);
	ft_free(str);
	return (numarr);
}

int	*ft_arrcpy(int *c, int tot)
{
	int	ind;
	int	*sorted;

	sorted = malloc(tot * sizeof(int));
	if (!sorted)
		return (0);
	ind = -1;
	while (++ind < tot)
		sorted[ind] = c[ind];
	return (sorted);
}
