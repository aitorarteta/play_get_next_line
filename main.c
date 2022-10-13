/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarteta <aarteta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:43:12 by aarteta           #+#    #+#             */
/*   Updated: 2022/10/13 22:25:01 by aarteta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "get_next_line.h"

int	main()
{
	int 	fd;
	char *file;
	char *line;

	//Declare file
	file = "text.txt";

	//Open & Read file
	fd = open(file, O_RDONLY);

	//Read & Print 1 line
	line = get_next_line(fd);
	printf("%s", line);

	//Read & Print 2 line
	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
