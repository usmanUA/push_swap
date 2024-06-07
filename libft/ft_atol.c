/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:49:58 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/19 16:04:34 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atol(const char *s)
{
	long int	num;
	int			sign;

	sign = 1;
	num = 0;
	while (ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*(s++) == '-')
			sign *= -1;
	}
	while (ft_isdigit(*s))
		num = num * 10 + (*(s++) - '0');
	return (num * sign);
}
