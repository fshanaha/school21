/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:51:48 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/09 21:23:13 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;

	if (!(alst) || !(*alst) || !(del))
		return ;
	while ((nxt = (*alst)->next))
	{
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = nxt;
	}
	(*del)((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = 0;
}
