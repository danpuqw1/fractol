/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:27:40 by student           #+#    #+#             */
/*   Updated: 2020/08/13 22:27:42 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"
#include "math.h"

t_palitra	*get_palitras(void)
{
	static t_palitra	array[6];

	array[0] =
			(t_palitra){5, 0, {0x501637, 0x047878, 0x33B7FF, 0xF57336,
					0xC22121}};
	array[1] =
			(t_palitra){5, 0, {0x0D1C33, 0xFA373C, 0x682B32, 0x4F0093,
					0xA100D7}};
	array[2] =
			(t_palitra){5, 0, {0x00002F, 0x630480, 0xEFCAEC, 0xA77EA3,
					0xE6E2AF}};
	array[3] =
			(t_palitra){5, 0, {0x002F2F, 0xEFCAEC, 0x630480, 0xE74EE3,
					0x8682EF}};
	array[4] =
			(t_palitra){7, 10, {0x0000FF, 0xFFFF00, 0x00FF00, 0x00FFFF,
					0xFF0000, 0xFF00FF, 0xFF0000}};
	array[5] = (t_palitra){0, 0, {0}};
	return (array);
}

t_color		lin_extr(t_color c1, t_color c2, double p)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}

t_color		linear_color(double i, int max, t_palitra *p)
{
	double		index;
	double		adjust;
	int			c;

	if (p->cycle)
		index = fmod(i, p->cycle - 1) / (p->cycle - 1);
	else
		index = i / max;
	c = p->count - 1;
	adjust = fmod(index, 1.0f / c) * c;
	return (lin_extr((t_color)(p->colors[(int)(index * c) + 1]),
		(t_color)(p->colors[(int)(index * c)]),
		(int)(adjust + 1) - adjust));
}

t_color		smooth_color(t_point p, int max, t_palitra *pal)
{
	double i;
	double zn;
	double nu;

	zn = log(p.c.r * p.c.r + p.c.i * p.c.i) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = p.i + 1 - nu;
	if (i < 0)
		i = 0;
	return (linear_color(i, max, pal));
}

int			get_color(t_point p, t_all *mlx)
{
	if (p.i >= mlx->data.max)
		return (0x000000);
	if (mlx->smooth)
		return (smooth_color(p, mlx->data.max, mlx->palitra).value);
	return (linear_color((double)p.i, mlx->data.max, mlx->palitra).value);
}
