/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:59:40 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/01 14:56:04 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	const unsigned char		*ar;
	unsigned char			w;

	w = (unsigned char)c;
	ar = (const unsigned char*)arr;
	while (n--)
	{
		if (*ar == w)
		{
			return ((void *)ar);
		}
		ar++;
	}
	return (NULL);
}
