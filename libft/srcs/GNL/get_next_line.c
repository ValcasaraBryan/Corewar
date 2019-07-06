/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <brvalcas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 18:57:52 by brvalcas          #+#    #+#             */
/*   Updated: 2019/07/06 12:25:49 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (line && (read(fd, buf, 0) != (-1)))
	{
		tmp = ft_check_link(&list, fd);
		if (!tmp->content || !(ft_strchr((char *)tmp->content, '\n')))
			if (ft_add_line((char **)&(tmp->content), buf, fd) == (-1))
				return (-1);
		ret = ft_add_line_next((char **)&(tmp->content), &(*line));
		if (ret == 0)
		{
			ft_free_list(&list, fd);
			return (0);
		}
		else
			return (1);
	}
	ft_free_list(&list, fd);
	return (-1);
}

int					ft_add_line(char **rest, char *buf, const int fd)
{
	int				ret;
	char			*tmp;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!*rest)
			*rest = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(*rest, buf);
			free(*rest);
			*rest = tmp;
		}
		if ((ft_strnchr(buf, '\n') >= 0))
			return (ret);
	}
	return (ret);
}

int					ft_add_line_next(char **rest, char **line)
{
	int				index;
	char			*tmp;

	if (*rest != NULL)
		index = ft_strnchr(*rest, '\n');
	if (*rest != NULL && index >= 0)
	{
		*line = ft_strndup(*rest, index);
		tmp = ft_strdup(ft_strchr(*rest, '\n') + 1);
		free(*rest);
		*rest = tmp;
		return (1);
	}
	else if ((*rest != NULL && index == (-1)) && (*rest[0] != 0))
	{
		*line = *rest;
		*rest = NULL;
		return (1);
	}
	*line = NULL;
	return (0);
}

t_list				*ft_check_link(t_list **list, const int fd)
{
	t_list			*tmp;

	if (*list)
	{
		tmp = *list;
		while (tmp)
		{
			if (fd == (int)tmp->content_size)
				return (tmp);
			tmp = tmp->next;
		}
		tmp = ft_lstnew(NULL, 0);
		tmp->content_size = (size_t)fd;
		tmp->next = *list;
		*list = tmp;
		return (tmp);
	}
	*list = ft_lstnew(NULL, 0);
	(*list)->content_size = (size_t)fd;
	return (*list);
}

void				ft_free_list(t_list **list, const int fd)
{
	t_list	*tmp;
	t_list	*too_free;

	tmp = *list;
	if (!tmp)
		return ;
	if (fd == (int)tmp->content_size)
	{
		*list = (*list)->next;
		free(tmp->content);
		free(tmp);
	}
	else
	{
		while ((int)tmp->next->content_size != fd)
			tmp = tmp->next;
		too_free = tmp->next;
		tmp->next = tmp->next->next;
		free(too_free);
	}
}
