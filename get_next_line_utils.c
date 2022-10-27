/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarteta <aarteta@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:43:08 by aarteta           #+#    #+#             */
/*   Updated: 2022/10/27 22:27:27 by aarteta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	printf("strlen_str is:%i\n", i);
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	if(!s)
		return (0);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = 0;
	if (dstsize)
	{
		while (src[i] && --dstsize > 0)
		{
			dst [i] = src[i];
			i++;
		}
	dst[i] = '\0';
	}
	return ((int)ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if(dst_len >= dstsize)
	{
		return ( dstsize + src_len);
	}
	dstsize -= dst_len;
	while (*src && dstsize --> 1)
		{
			*(dst++ + dst_len) = *src++;
		}
	*(dst + dst_len) = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	printf("\nstrljoin_i is:%i\n", i);
	printf("strljoin_j is:%i\n", j);
	printf("strljoin_s1 is:%s\n", s1);
	printf("strljoin_s2 is:%s\n", s2);

	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	printf("strljoin_str after malloc is:%s\n", str);

	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	printf("strljoin_str after join is:%s\n", str);
	return (str);
}

char *ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(sizeof(ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}
