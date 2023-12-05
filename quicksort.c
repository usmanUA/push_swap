/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:40:08 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/01 12:09:48 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_intswap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_partition(int *c, int i, int pivot)
{
	int	j;

	j = i - 1;
	while (++j < pivot)
	{
		if ((c[j]) < (c[pivot]))
		{
			ft_intswap(&c[i], &c[j]);
			++i;
		}
	}
	ft_intswap(&c[i], &c[pivot]);
	return (i);
}

void	ft_quicksort(int *c, int start, int end)
{
	int	pivotpos;

	pivotpos = 0;
	if (start < end)
	{
		pivotpos = ft_partition(c, start, end);
		ft_quicksort(c, start, pivotpos - 1);
		ft_quicksort(c, pivotpos + 1, end);
	}
}
