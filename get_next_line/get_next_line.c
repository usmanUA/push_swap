/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:17:23 by uahmed            #+#    #+#             */
/*   Updated: 2024/02/11 16:24:33 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_freebuff(char *lines)
{
	while (*lines)
	{
		*lines = 0;
		lines++;
	}
}

int	ft_movebuff(char *lines)
{
	size_t	tot;
	size_t	ind;
	size_t	nl_pos;

	nl_pos = ft_newline(lines);
	ind = 0;
	tot = 0;
	if (nl_pos)
	{
		tot = ft_strlen(lines);
		while (lines[ind + nl_pos])
		{
			lines[ind] = lines[nl_pos + ind];
			ind++;
		}
		while (ind < tot)
		{
			lines[ind] = 0;
			ind++;
		}
		return (1);
	}
	return (0);
}

int	ft_errorcheck(int fd, char *lines)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		ft_freebuff(lines);
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	lines[BUFFER_SIZE + 1];
	int			bytes;

	if (!ft_errorcheck(fd, lines))
		return (NULL);
	line = NULL;
	bytes = 1;
	while (bytes > 0)
	{
		if (*lines)
			line = ft_writeline(lines, line);
		if (ft_movebuff(lines))
			break ;
		ft_freebuff(lines);
		bytes = read(fd, lines, BUFFER_SIZE);
		if (bytes == -1)
		{
			ft_freebuff(lines);
			return (NULL);
		}
	}
	return (line);
}
