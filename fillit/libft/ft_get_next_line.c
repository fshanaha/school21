/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:22:29 by sbrella           #+#    #+#             */
/*   Updated: 2019/01/03 18:17:41 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					del(t_dlist *begin, char **a, int fd)
{
	t_dlist	*me;
	t_dlist *prev;

	me = begin->next;
	if (a == 0)
	{
		while ((me))
		{
			free(me->data);
			begin = me;
			me = begin->next;
			free(begin);
		}
		return (-1);
	}
	free(*a);
	prev = me;
	while (me)
	{
		prev = me;
		me = me->next;
		if (me && me->label == fd)
			ft_dlstcut(prev);
	}
	return (0);
}

int					cut(t_dlist *begin, char *str, int i, int fd)
{
	void			*a;

	while (begin->label != fd && begin)
		begin = begin->next;
	free(begin->data);
	a = ft_memchr((void*)str, (int)('\n'), (size_t)i);
	i = i - (int)((char*)a - str) - 1;
	if (i != 0)
	{
		str = (char*)(a + 1);
		if (!(a = malloc(i)))
			return (del(begin, 0, fd));
		ft_memmove(a, (void*)str, i);
		begin->data = a;
		begin->size = i;
	}
	else
	{
		begin->data = NULL;
		begin->size = 0;
	}
	return (1);
}

void				*manage_line(char **line, int *c, char *str, int i)
{
	void			*a;
	char			*ln;

	a = ft_memchr((void*)str, (int)('\n'), (size_t)i);
	if (a == NULL)
	{
		if (!(ln = (char*)malloc(*c + i)))
			return ((*c = -1) == -1 ? (void*)str : (void*)str);
		ft_memmove((void*)ln, (void*)(*line), *c);
		ft_memmove((void*)(ln + *c), (void*)str, i);
		*c = *c + i;
	}
	else
	{
		str[(char*)a - str] = '\0';
		if (!(ln = (char*)malloc(*c + ((char*)a - str) + 1)))
			return ((*c = -1) == -1 ? (void*)str : (void*)str);
		ft_memmove((void*)ln, (void*)(*line), *c);
		ft_memmove((void*)(ln + *c), str, ((char*)a - str) + 1);
		str[(char*)a - str] = '\n';
	}
	free(*line);
	*line = ln;
	return (a);
}

int					do_something(int fd, char **line, t_dlist *begin)
{
	t_dlist			*me;
	size_t			n;

	n = 0;
	me = begin;
	while ((me = me->next))
		if (me->label == fd)
		{
			while (n < me->size && ((char*)(me->data))[n] != '\n')
				n++;
			if ((n != me->size) && ((char*)(me->data))[n] == '\n')
			{
				ft_smemmove((void*)(*line = ft_strnew(n)), (void*)me->data, n);
				ft_memmove(me->data, &((me->data)[n + 1]), me->size - n - 1);
				me->size = me->size - n - 1;
				return (*line == NULL ? del(begin, 0, fd) : -2);
			}
			ft_smemmove(*line = ft_strnew(n), me->data, n == 0 ? 0 : n + 1);
			me->size = 0;
			return (*line == NULL ? del(begin, 0, fd) : n);
		}
	while (begin->next)
		begin = begin->next;
	begin->next = ft_dlstadd(fd, NULL);
	return (0);
}

int					ft_get_next_line(const int fd, char **line)
{
	int				i;
	char			str[BUFF_SIZE];
	int				c;
	static t_dlist	lst = {-1, NULL, 0, NULL};
	void			*a;

	i = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if ((c = do_something(fd, line, &lst)) >= 0)
	{
		while ((i = read(fd, str, BUFF_SIZE)) > 0)
			if ((a = manage_line(line, &c, str, i)) != 0)
				return (c == -1 ? del(&lst, 0, fd) : cut(&lst, str, i, fd));
		if (i == 0 && c == 0)
			return (del(&lst, line, fd));
		if (i == 0)
			manage_line(line, &c, "\0", 1);
	}
	if (i == -1 || c == -1)
		return (-1);
	return (1);
}
