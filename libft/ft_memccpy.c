/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:58:20 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/11 17:39:47 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s, const void *c, int j, size_t n)
{
	char			*src;
	const char		*buff;

	src = (char*)s;
	buff = (const char*)c;
	if (n == 0)
		return (NULL);
	while (n-- > 0)
		if ((*src++ = *buff++) == (char)j)
			return (src);
	return (NULL);
}
