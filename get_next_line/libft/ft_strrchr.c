/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:41:11 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/03 16:31:44 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	i;
	char	ch1;

	i = ft_strlen((char*)str);
	ch1 = ch;
	if (ch == '\0')
		return (ft_strchr(str, '\0'));
	while (i--)
		if (*(str + i) == (char)ch1)
			return ((char *)str + i);
	return (NULL);
}
