/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:27:49 by student           #+#    #+#             */
/*   Updated: 2020/08/13 22:27:50 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fractol.h"

t_all		*mlxdel(t_all *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->image != NULL)
		del_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_all		*init(t_fractal *f)
{
	t_all	*mlx;
	char	*title;

	if ((mlx = ft_memalloc(sizeof(t_all))) == NULL)
		return (NULL);
	title = ft_strjoin("Fractal - ", f->name);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->window = mlx_new_window(mlx->mlx, WIN_WIDTH,
			WIN_HEIGHT, title)) == NULL ||
		(mlx->image = new_image(mlx)) == NULL ||
		(mlx->points = ft_memalloc(sizeof(t_point) * WIN_WIDTH
								* WIN_HEIGHT)) == NULL)
		return (mlxdel(mlx));
	mlx->mouse.isdown = 0;
	mlx->fractal = f;
	mlx->mouselock = 1 - f->mouse;
	mlx->palitra = get_palitras();
	mlx->smooth = 1;
	return (mlx);
}

void		data_fit(t_data *v)
{
	double w;
	double h;

	w = v->xmax - v->xmin;
	h = v->ymax - v->ymin;
	if (w / h >= (float)WIN_WIDTH / WIN_HEIGHT)
	{
		v->ymin = -(w * WIN_HEIGHT / WIN_WIDTH / 2);
		v->ymax = w * WIN_HEIGHT / WIN_WIDTH / 2;
	}
	else
	{
		v->xmin = -(h * WIN_WIDTH / WIN_HEIGHT / 2);
		v->xmax = (h * WIN_WIDTH / WIN_HEIGHT / 2);
	}
}

void		reset_data(t_all *mlx)
{
	mlx->data.offx = 0;
	mlx->data.offy = 0;
	mlx->fractal->data(&mlx->data);
	data_fit(&mlx->data);
	mlx->data.max = 32;
	mlx->data.zoom = 1.0f;
}

t_complex	screen_to_complex(int x, int y, t_data *v)
{
	t_complex	p;

	p.r = (((double)x / WIN_WIDTH) * (v->xmax - v->xmin)) * v->zoom
			+ v->xmin + v->offx;
	p.i = (((double)y / WIN_HEIGHT) * (v->ymax - v->ymin)) * v->zoom
			+ v->ymin + v->offy;
	return (p);
}
