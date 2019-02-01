/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:33:24 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/03 18:04:45 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t i;

	i = ft_strlen((char*)str2);
	if (!*str2)
		return ((char*)str1);
	while (*str1)
		if (!ft_memcmp(str1++, str2, i))
			return ((char*)str1 - 1);
	return (0);
}
