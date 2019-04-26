/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:33:29 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/21 13:58:30 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	b;
	unsigned char	*str;

	b = (unsigned char)c;
	str = (unsigned char*)s;
	while (n--)
	{
		*str++ = b;
	}
	return (s);
}
