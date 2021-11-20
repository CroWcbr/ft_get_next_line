/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:48:18 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/11 20:22:49 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*tmp;
	int		len;
	int		i;

	len = ft_strlen(s);
	tmp = (char *)malloc((len + 1) * sizeof(char));
	if (tmp == ((void *)0))
		return ((void *)0);
	i = -1;
	while (++i < len)
		*(tmp + i) = *(s + i);
	*(tmp + i) = '\0';
	return (tmp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*tmp;
	unsigned int	i;

	if (s1 == ((void *)0) || s2 == ((void *)0))
		return ((void *)0);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (tmp == ((void *)0))
		return ((void *)0);
	i = 0;
	while (*s1)
	{
		*(tmp + i++) = *s1;
		s1++;
	}
	while (*s2)
	{
		*(tmp + i++) = *s2;
		s2++;
	}
	*(tmp + i) = '\0';
	return (tmp);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return ((void *)0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;
	size_t			i;

	if (src == dst || n == 0)
		return (dst);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned char *)src;
	i = -1;
	while (++i < n)
		*(tmp_dst + i) = *(tmp_src + i);
	return (dst);
}
