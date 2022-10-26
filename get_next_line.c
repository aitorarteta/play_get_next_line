/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarteta <aarteta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:43:03 by aarteta           #+#    #+#             */
/*   Updated: 2022/10/26 22:03:29 by aarteta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://www.codequoi.com/en/42-get_next_line-project/

#include "get_next_line.h"

/* int	ft_find_n(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
		if (buf[i++] == '\n')
			return (1);
		return (0);
} */

int	ft_find_n(char *buf)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	while (buf[i])
	{
		if (buf[i++] == '\n')
		{
			end = 1;
			break ;
		}
	}
	if (end == 1)
		return (1);
	else
		return (0);
}

char	*ft_read(int fd, char *stash, int read_len, char *buf)
{
	char	*aux;

	while (read_len > 0)
	{
		read_len = read(fd, buf, BUFFER_SIZE);
		printf("\nread len is: %d\n", read_len);
		printf("buf is:\n%s\n", buf);
		if (read_len < 0)
		{
			printf("read_len is less than 0\n");
			return (NULL);
		}
		if (read_len == 0)
		{
			printf("read_len is equal to 0\n");
			break;
		}
		if (!stash)
		{
			printf("stash doesnt exist so create a new one\n");
			stash = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
			stash[0] = 'k';
		}
		printf("stash is %s\n", stash);
		buf[read_len] = '\0';
		printf("buf str is:\n%s\n", buf); // el problema está aquí, que se queda en bucle.
		aux = stash;
		stash = ft_strjoin(aux, buf);
		printf("stash strjoin is %s\n", stash);
		free(aux);
		if (ft_find_n(buf) == 1)
			break;
	}
	printf("stash in ft_read is: %s\n", stash);
	return (stash);
}

char	*ft_get_line(char **stash, int *end)
{
	int		i;
	char	*line;
	char	*aux;

	i = 0;
	while (stash[0][i] && stash[0][i] != '\n')
		i++;
	if (stash[0][i] == '\0')
	{
		*end = 1;
		return (*stash);
	}
	aux = *stash;
	*stash = ft_substr(aux, i + 1, ft_strlen(aux) - i);
	line = ft_substr(aux, 0, i + 1);
	free (aux);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			end;

	end = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read(fd, stash, 1, buf);
	printf("stash is: %s\n", stash);
	if (!stash)
		return (0);
	line = ft_get_line(&stash, &end);
	if (end == 1)
		stash = "NULL";
	if (line[0] == '\0')
	{
		free (line);
		return (0);
	}
	return (line);
}
