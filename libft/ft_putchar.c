/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:19:08 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/07 15:19:09 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar(char c)
{
	char	ch[2];

	if ((unsigned char)c < 128)
		write(1, &c, 1);
	else
	{
		ch[0] = ((3 << 6) + ((unsigned char)c >> 6));
		ch[1] = ((1 << 7) + ((unsigned char)c & 63));
		write(1, ch, 2);
	}
}
