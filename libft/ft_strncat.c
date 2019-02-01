/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 13:11:47 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/02 15:09:38 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *des, const char *append, size_t n)
{
	char	*dst;

	dst = (char*)des;
	while (*dst)
		dst++;
	while (n-- && *append)
		*dst++ = *append++;
	ft_bzero(dst, 1);
	return (des);
}
