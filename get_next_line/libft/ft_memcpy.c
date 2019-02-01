/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:13:28 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/12 15:57:48 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s, const void *c, size_t n)
{
	unsigned int	i;
	char			*src;
	char			*buff;

	i = 0;
	if (s == c)
		return (s);
	src = (char*)s;
	buff = (char*)c;
	while (n--)
	{
		src[i] = buff[i];
		i++;
	}
	return (s);
}
