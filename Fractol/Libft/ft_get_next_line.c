/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:50:11 by fshanaha          #+#    #+#             */
/*   Updated: 2019/01/25 15:49:48 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_search_list(int fd, t_list *list)
{
	t_list	*buff;

	buff = list;
	while (buff && buff->content_size != (size_t)fd && buff->next != NULL)
		buff = buff->next;
	return (buff);
}

static	int		ft_newline(t_list **bufl, char **line)
{
	char	*buff;
	int		corr;

	corr = 0;
	while (((char *)((*bufl)->content))[corr] != '\n'
	&& ((char *)((*bufl)->content))[corr] != '\0')
		corr++;
	*line = ft_strsub((*bufl)->content, 0, corr);
	buff = (*bufl)->content;
	(*bufl)->content = ft_strsub((*bufl)->content, corr + 1,
	ft_strlen((*bufl)->content) - corr);
	ft_strdel(&buff);
	return (1);
}

static	t_list	*ft_mod_list(int fd, char *buff, t_list **list)
{
	char	*storage;
	t_list	*save;

	(*list == NULL) ? (*list = ft_lstnew(buff, ft_strlen(buff) + 1)) : 0;
	save = ft_search_list(fd, *list);
	if (save->content_size == (size_t)fd)
	{
		storage = save->content;
		save->content = ft_strjoin(save->content, buff);
		ft_strdel(&storage);
	}
	else
	{
		save->next = ft_lstnew(buff, ft_strlen(buff) + 1);
		save = save->next;
		save->content_size = fd;
	}
	return (save);
}

static	void	ft_dellist(t_list **list, int fd)
{
	t_list	*first;
	t_list	*second;

	first = *list;
	second = *list;
	while (second->content_size != (size_t)fd)
	{
		first = second;
		second = second->next;
	}
	if (second == *list)
		*list = second->next;
	first->next = second->next;
	if (second->content != NULL)
		free(second->content);
	free(second);
}

int				ft_get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	t_list			*bufl;
	static t_list	*list = NULL;
	int				corr;

	CHECK(fd < 0 || line == NULL || read(fd, buff, 0) < 0);
	bufl = ft_search_list(fd, list);
	if (bufl && bufl->content_size == (size_t)fd
	&& ft_strchr(bufl->content, '\n'))
		return (ft_newline(&bufl, line));
	while ((corr = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[corr] = '\0';
		bufl = ft_mod_list(fd, buff, &list);
		if (ft_strchr(bufl->content, '\n'))
			break ;
	}
	if (bufl && bufl->content_size == (size_t)fd && *((char*)bufl->content))
		return (ft_newline(&bufl, line));
	else
	{
		if (bufl && bufl->content_size == (size_t)fd)
			ft_dellist(&list, fd);
		return (0);
	}
}
