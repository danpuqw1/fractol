/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:27:19 by student           #+#    #+#             */
/*   Updated: 2020/08/13 22:27:24 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include <stdlib.h>

int		draw_hooks(int key, t_all *mlx)
{
	int		doot;

	doot = 0;
	if (key >= K_DIGIT_1 && key <= K_DIGIT_1 + 4)
		mlx->palitra = &get_palitras()[key - K_DIGIT_1];
	else if (key == K_NUM_ENTER)
		mlx->smooth = 1 - mlx->smooth;
	else
		doot = 1;
	if (!doot)
		draw(mlx);
	return (doot);
}

void	move(int key, t_all *mlx)
{
	double w;
	double h;

	w = (mlx->data.xmax - mlx->data.xmin) * mlx->data.zoom;
	h = (mlx->data.ymax - mlx->data.ymin) * mlx->data.zoom;
	if (key == K_UP)
		mlx->data.offy -= h * 0.05f;
	if (key == K_DOWN)
		mlx->data.offy += h * 0.05f;
	if (key == K_LEFT)
		mlx->data.offx -= w * 0.05f;
	if (key == K_RIGHT)
		mlx->data.offx += w * 0.05f;
	if (key == K_L)
		mlx->mouselock = 1 - mlx->mouselock;
}

int		hook_keydown(int key, t_all *mlx)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_NUM_0)
		reset_data(mlx);
	if (key == K_NUM_MULT)
		mlx->data.max *= 2;
	if (key == K_NUM_DIV)
		if (mlx->data.max / 2 >= 2)
			mlx->data.max /= 2;
	if (key == K_NUM_PLUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->data, 1 / ZOOM);
	if (key == K_NUM_MINUS)
		zoom(WIN_WIDTH / 2, WIN_HEIGHT / 2, &mlx->data, ZOOM);
	move(key, mlx);
	if (draw_hooks(key, mlx))
		multithr(mlx);
	return (0);
}
