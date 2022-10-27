/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarteta <aarteta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:10:59 by aarteta           #+#    #+#             */
/*   Updated: 2022/10/27 21:03:25 by aarteta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int ft_find_n(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
		if (buf[i++] == '\n')
			return (1);
		return (0);
}
*/

static char *function_name(int fd, char *buf, char *backup)
{
	//int		read_line;
	//char	*aux;

	//read_line = 1;
	printf("Inicio function_name -> fd is %i, buf is %s, backup is %s\n", fd, buf, backup);
	/* while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		printf("Hey");
		if (read_line < 0)
			return ("NULL");
		else if (read_line == 0)
			break;
		buf[read_line] = '\0';
		if (!backup)
			backup = ft_strdup("");
		aux = backup;
		backup = ft_strjoin(aux, buf);
		if (ft_find_n(buf))
			break;
	} */
	//return (backup);
	return ("Okay");
}

/* static char *extract(char *line)
{
	size_t	i;
	char	*backup;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
				i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[i + 1] = '\0';
	return (backup);
} */

char *get_next_line(int fd)
{
	char	*line;
	char	*buf;
	static char	*backup;
	printf("Inicio get_next_line -> fd is %i\n", fd);
 	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	printf("gnl_buf is %s\n", buf);
	if (!buf)
		printf("gnl_buf doesn't exist");
		return (NULL);
	line = function_name(fd, buf, backup);
	printf("gnl_line is: %s\n", line);
/*	free(buf);
	if (!line)
		return (NULL);
	backup = extract(line) */;
	return (line);
}
