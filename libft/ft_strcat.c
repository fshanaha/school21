/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:34:41 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/02 12:50:32 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *des, const char *append)
{
	ft_strcpy(des + ft_strlen(des), append);
	return (des);
}
