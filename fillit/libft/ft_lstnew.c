/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:02:53 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/09 17:47:04 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*cont;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	lst->next = 0;
	if (content == 0)
	{
		lst->content = 0;
		lst->content_size = 0;
	}
	else
	{
		if (!(cont = (void*)malloc(content_size)))
		{
			free(lst);
			return (0);
		}
		lst->content = ft_memcpy(cont, content, content_size);
		lst->content_size = content_size;
	}
	return (lst);
}
