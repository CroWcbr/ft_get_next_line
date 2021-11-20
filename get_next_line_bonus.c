/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarrell <cdarrell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:59:20 by cdarrell          #+#    #+#             */
/*   Updated: 2021/10/22 17:50:07 by cdarrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_remainder(char **rem, char *p_n)
{
	char		*line;
	char		*tmp_rem;

	if (*rem)
	{
		p_n = ft_strchr(*rem, '\n');
		if (p_n)
		{
			tmp_rem = *rem;
			*rem = ft_strdup(p_n + 1);
			p_n = ft_memcpy(p_n, "\n\0", 2);
			line = ft_strdup(tmp_rem);
			free(tmp_rem);
		}
		else
		{
			line = *rem;
			*rem = ((void *)0);
		}
	}
	else
		line = ft_strdup("");
	return (line);
}

static char	*gnl_read(int fd, char *line, char **rem, char *p_n)
{
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];
	int		r;

	r = 1;
	while (!p_n && r && line && !(*rem))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == 0 && *line == '\0')
		{
			free(line);
			return ((void *)0);
		}
		buf[r] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{	
			*rem = ft_strdup(p_n + 1);
			p_n = ft_memcpy(p_n, "\n\0", 2);
		}
		tmp = line;
		line = ft_strjoin(line, buf);
		free(tmp);
	}
	return (line);
}

static t_gnl_list	*ft_gnl_lstnew(int fd)
{
	t_gnl_list	*tmp;

	tmp = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (tmp == ((void *)0))
		return ((void *)0);
	tmp->fd = fd;
	tmp->remainder = ((void *)0);
	tmp->next = ((void *)0);
	return (tmp);
}

static void	ft_gnl_lstdelone(t_gnl_list **head, int fd)
{
	t_gnl_list	*tmp_head;
	t_gnl_list	*ttt;

	tmp_head = *head;
	if (tmp_head->fd == fd)
	{
		*head = (*head)->next;
		free(tmp_head);
	}
	else
	{
		while (tmp_head)
		{
			if (tmp_head->next->fd == fd)
				break ;
			tmp_head = tmp_head->next;
		}
		ttt = tmp_head->next;
		tmp_head->next = ttt->next;
		free(ttt);
	}	
}

char	*get_next_line(int fd)
{
	static t_gnl_list	*head;
	t_gnl_list			*tmp;
	char				test_buff[1];
	char				*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, test_buff, 0) != 0)
		return ((void *)0);
	if (!head)
		head = ft_gnl_lstnew(fd);
	if (!head)
		return ((void *)0);
	tmp = head;
	while (tmp && tmp->fd != fd)
	{
		if (!tmp->next)
			tmp->next = ft_gnl_lstnew(fd);
		tmp = tmp->next;
	}
	if (!tmp)
		return ((void *)0);
	line = gnl_remainder(&tmp->remainder, ((void *)0));
	line = gnl_read(tmp->fd, line, &tmp->remainder, ((void *)0));
	if (!(tmp->remainder))
		ft_gnl_lstdelone(&head, tmp->fd);
	return (line);
}
