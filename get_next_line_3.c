/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarteta <aarteta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:09:02 by aarteta           #+#    #+#             */
/*   Updated: 2022/10/27 23:31:17 by aarteta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

 static char	*function_name(int fd, char *buf, char *backup)
{
	int		read_line;
	char	*aux;

	read_line = 1;
	printf("\nfn_fd is:%i\n", fd);
	printf("fn_read_line is:%i\n", read_line);
	printf("fn_buf is:%s\n", buf);
	printf("fn_backup is:%s\n", backup);

	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		printf("\nfn_read_line after read is:%d\n", read_line);
		if (read_line == -1)
			return (0);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		printf("fn_buf after read is:%s\n", buf);
		if (!backup)
			backup = ft_strdup("");
		printf("fn_backup is:%s\n", backup);
		aux = backup;
		printf("fn_aux before strjoin is:%s\n", aux);
		printf("fn_buf before strjoin is:%s\n", buf);
		backup = ft_strjoin(aux, buf);
		printf("fn_backup after strjoin is:%s\n", backup);
		free(aux);
		aux = NULL;
		if (ft_strchr (buf, '\n'))
			break;
	}
	return (backup);
}

	static char	*extract(char *line)
{
	size_t	count;
	char	*backup;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	backup = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	line[count + 1] = '\0';
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buf;
	static char	*backup;

	printf("\ngnl_fd is:%i\n", fd);

 	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	printf("gnl_buf is:%s\n", buf);
	if (!buf)
	{
		printf("gnl_buf doesnt exist");
		return ("nulo");
	}
	printf("gnl_backup is:%s\n", backup);
	line = function_name(fd, buf, backup);
	printf("gnl_line is:%s\n", line);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	backup = extract(line);
	return (line);
}
