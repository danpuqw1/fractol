/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:51:42 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/07 10:51:45 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*result;
	size_t			i;
	unsigned char	*tmp;

	result = malloc(size);
	if (!(result))
		return (NULL);
	tmp = result;
	i = 0;
	while (i < size)
		tmp[i++] = 0;
	return (result);
}
