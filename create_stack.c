/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:11:26 by uahmed            #+#    #+#             */
/*   Updated: 2023/12/01 16:43:42 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_createstacks(t_stack **stack, int *c, int *sorted, int tot, int b)
{
	int		ind;
	t_stack	*new;

	ind = -1;
	while (++ind < tot)
	{
		new = ft_stacknew(c[ind], tot, sorted);
		if (!new)
		{
			free(c);
			free(sorted);
			return (0);
		}
		ft_stackadd_front(stack, new);
		if (b)
			write(1, "pb\n", 3);
	}
	return (1);
}

int	ft_makestacks(int tot, t_stack **a, t_stack **b, int *c)
{
	int	*sorted;

	sorted = ft_arrcpy(c, tot);
	if (!sorted)
	{
		free(c);
		return (0);
	}
	ft_quicksort(sorted, 0, tot - 1);
	if (!ft_createstacks(a, c, sorted, tot, 0))
		return (0);
	if (!ft_createstacks(b, c, sorted, tot, 1))
		return (0);
	free(c);
	free(sorted);
	return (1);
}

int	ft_stack(int tot, t_stack **a, t_stack **b, char **argv)
{
	int		*c;
	char	**str;

	str = NULL;
	if (tot == 1)
		c = ft_fromvar(argv, &tot);
	else
		c = ft_numsarr(tot, argv, 1);
	if (!c || ft_checknumdup(c, tot))
	{
		if (c)
			free(c);
		return (0);
	}
	return (ft_makestacks(tot, a, b, c));
}
