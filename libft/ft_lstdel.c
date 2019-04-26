/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:14:26 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/10 13:43:21 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*i;

	while (alst && del && *alst)
	{
		i = (*alst)->next;
		(*del)(((*alst)->content), (*alst)->content_size);
		free(*alst);
		(*alst) = i;
	}
	*alst = NULL;
}
