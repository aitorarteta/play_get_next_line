/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarteta <aarteta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:43:06 by aarteta           #+#    #+#             */
/*   Updated: 2022/10/27 22:42:03 by aarteta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>// for size_t
# include <stdlib.h> // for malloc
# include <stdio.h> //for printf --> delete before delivery
# include <fcntl.h> // for O_RDONLY
# include <string.h>

//#include <stdlib.h> and <unistd.h> for *malloc(), free(), & read()*.

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 10

# endif

char	*get_next_line(int fd);
int		ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int i);

#endif
