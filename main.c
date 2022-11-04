/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarteta <aarteta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:43:12 by aarteta           #+#    #+#             */
/*   Updated: 2022/11/04 18:11:51 by aarteta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* int	main()
{
	int 	fd;
	//char *file;
	char *line;

	//Declare file
	//file = "text.txt";
	printf("Inicio main\n");
	//Open & Read file
	fd = open("text.txt", O_RDONLY);
	printf("fd: %i\n", fd);

	//Read & Print 1 line
	line = get_next_line(fd);
	printf("1:%s\n", line);

	//Read & Print 2 line
	line = get_next_line(fd);
	printf("2:%s\n", line);

	//Read & Print 3 line
	line = get_next_line(fd);
	printf("3:%s\n", line);
	return (0);
}*/

int main()
{
	int		fd;
	char	*line;

	printf("Init Main\n");

 	fd = open("text.txt", O_RDONLY);
	printf("Main_fd is:%i\n", fd);
	line = get_next_line(fd);
	printf("1:%s\n", line);
	line = get_next_line(fd);
	printf("2:%s\n", line);
	line = get_next_line(fd);
	printf("3:%s\n", line);
	line = get_next_line(fd);
	printf("4:%s\n", line);
	return (0);
}

