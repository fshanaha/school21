/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:03:59 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/21 13:56:01 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*i;

	if (!(i = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		i->content = NULL;
		i->content_size = 0;
	}
	else
	{
		i->content = malloc(content_size * sizeof(content));
		if (i->content == NULL)
		{
			free(i);
			return (NULL);
		}
		ft_memcpy((i->content), content, content_size);
		i->content_size = content_size;
	}
	i->next = NULL;
	return (i);
}
