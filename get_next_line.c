/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarteta <aarteta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:43:03 by aarteta           #+#    #+#             */
/*   Updated: 2022/10/14 20:02:17 by aarteta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://www.codequoi.com/en/42-get_next_line-project/

#include "get_next_line.h"
#include <>

int	ft_find_n(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
		if (buf[i++] == '\n')
			return (1);
		//else
	return (0);
}

char	*ft_read(int fd, char *stash, int read_len, char *buf)
{


}

char	*ft_get_line(char **stash, int *end)
{


}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			end;

	end = 0;
	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read(fd, stash, 1, buf);
	if (!stash)
		return (0);
	line = ft_get_line(*stash, end);
	if (line[0] == '\0')
		free (line);
		return (0);
	return (line);
}
