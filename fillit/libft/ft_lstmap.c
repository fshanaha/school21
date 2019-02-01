/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:52:50 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/09 21:39:36 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		do_nothing(void *lst, size_t size)
{
	size = 0;
	free(lst);
	return ;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *newlst;
	t_list *newlstdbl;

	if (!(newlst = (f)(lst)))
		return (NULL);
	newlstdbl = newlst;
	while ((lst = lst->next))
	{
		if (!(newlst->next = (f)(lst)))
		{
			ft_lstdel(&newlstdbl, do_nothing);
			return (0);
		}
		newlst = newlst->next;
	}
	return (newlstdbl);
}
