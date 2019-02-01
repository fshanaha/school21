/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:04:38 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/07 14:31:41 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *des, const char *sour)
{
	unsigned char			*src;
	unsigned char			*dst;

	src = (unsigned char*)sour;
	dst = (unsigned char*)des;
	while (*src)
	{
		*dst++ = *src++;
	}
	*dst = '\0';
	return (des);
}
