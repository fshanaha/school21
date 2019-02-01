/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrella <sbrella@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 17:03:37 by sbrella           #+#    #+#             */
/*   Updated: 2018/12/24 19:23:50 by sbrella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstcut(t_dlist *prev)
{
	t_dlist	*next;

	if (!prev)
		return ;
	next = (prev->next)->next;
	free((prev->next)->data);
	free(prev->next);
	prev->next = next;
}
