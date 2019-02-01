/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:52:18 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/12 15:31:49 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *sour, size_t n)
{
	unsigned int	i;
	char			*to;
	char			*src;

	i = 0;
	if (dest == sour)
		return (dest);
	to = (char*)dest;
	src = (char*)sour;
	if (to <= src)
		while (i < n)
		{
			to[i] = src[i];
			i++;
		}
	else
	{
		i = n;
		while (i > 0)
		{
			to[i - 1] = src[i - 1];
			i--;
		}
	}
	return (to);
}
