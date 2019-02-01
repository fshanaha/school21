/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:03:49 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/24 17:03:52 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstadd(int fd, t_dlist *next)
{
	t_dlist *lst;

	if ((lst = (t_dlist*)malloc(sizeof(t_dlist))))
	{
		lst->data = NULL;
		lst->size = 0;
		lst->label = fd;
		lst->next = next;
	}
	return (lst);
}
