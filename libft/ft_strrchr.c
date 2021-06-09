/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:48:28 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 11:48:29 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int symbol)
{
	int		i;
	int		last;
	char	*s;

	s = (char*)str;
	i = 0;
	last = 0;
	while (s[i] != '\0')
	{
		if (s[i] == symbol)
			last = i;
		i++;
	}
	if (symbol == '\0')
		last = i;
	if (last == 0 && s[last] != symbol)
		return (0);
	return (s + last);
}
