/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crow <crow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:48:18 by crow              #+#    #+#             */
/*   Updated: 2021/05/03 23:15:28 by crow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	if (dest == ((void *)0) || src == ((void *)0))
		return (0);
	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}
