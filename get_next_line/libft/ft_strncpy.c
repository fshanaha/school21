/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:49:58 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/03 18:07:10 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *des, const char *sour, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	src = (unsigned char*)sour;
	dst = (unsigned char*)des;
	while (n > 0)
	{
		if (*src == '\0' && n > 0)
			ft_bzero(dst, n);
		else
			*dst++ = *src++;
		n--;
	}
	return (des);
}
