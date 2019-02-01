/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:19:36 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/12 15:37:43 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *sec;
	t_list *buff;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	if (!(sec = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	buff = sec;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(buff->next = ft_lstnew(tmp->content, tmp->content_size)))
		{
			ft_lstdel(&sec, ft_cleancont);
			return (NULL);
		}
		lst = lst->next;
		buff = buff->next;
	}
	return (sec);
}
