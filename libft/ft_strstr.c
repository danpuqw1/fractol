/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:48:37 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/06 11:48:38 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	int		j;
	int		res;
	char	*s1;

	s1 = (char*)str1;
	i = 0;
	if (*s1 == '\0' && *str2 == '\0')
		return (s1);
	while (s1[i] != '\0')
	{
		res = i;
		j = 0;
		while (s1[i + j] != '\0' && str2[j] != '\0')
		{
			if (s1[i + j] != str2[j])
				res = -1;
			j++;
		}
		if (res != -1 && str2[j] == '\0')
			return (s1 + res);
		i++;
	}
	return (NULL);
}
