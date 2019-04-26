/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_free_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshanaha <fshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:18:17 by fshanaha          #+#    #+#             */
/*   Updated: 2018/12/11 17:26:36 by fshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_char_free_arr(char ***arr)
{
	int i;

	i = -1;
	while (arr[0][++i])
	{
		free(**arr);
		**arr = NULL;
	}
	free(*arr);
	*arr = NULL;
}
