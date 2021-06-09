/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:32:07 by dteemo            #+#    #+#             */
/*   Updated: 2019/04/07 15:32:08 by dteemo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	char	ch[2];

	if ((unsigned char)c < 128)
		write(fd, &c, 1);
	else
	{
		ch[0] = ((3 << 6) + ((unsigned char)c >> 6));
		ch[1] = ((1 << 7) + ((unsigned char)c & 63));
		write(fd, ch, 2);
	}
}
