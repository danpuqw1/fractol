/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:42:29 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 12:42:30 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char		*dest_tmp;
	const char	*src_tmp;

	dest_tmp = dest;
	src_tmp = src;
	while (count-- > 0)
		*dest_tmp++ = *src_tmp++;
	return (dest);
}
