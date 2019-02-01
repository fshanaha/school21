/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:05:32 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/10 20:36:28 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	slen;

	slen = ft_strlen((char*)little);
	if (*little == '\0')
		return ((char*)big);
	if (*big == '\0')
		return (NULL);
	while (len-- >= slen && *big)
	{
		if ((!(ft_memcmp(big, little, slen))) && *big == *little)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
