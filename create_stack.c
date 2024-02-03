/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:11:26 by uahmed            #+#    #+#             */
/*   Updated: 2024/01/30 16:50:28 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_newstack(t_stack **a, int num)
{
	t_stack	*new;
	
	new = ft_stacknew(num);
	if (!new)
		return (0);
	ft_stackadd_front(a, new);
	return (1);
}

int	ft_createstack(int tot, t_stack **a, int *c)
{
	int		ind;
	

	ind = -1;
	while (++ind < tot)
	{
		if (!ft_newstack(a, c[ind]))
		{
			free(c);  // is freeing c here valid?
			return (0);
		}
		
	}
	return (1);
}

int	ft_stack(int tot, char **argv, t_stack_a **a)
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
	return (ft_createstack(tot, a, c));
}
