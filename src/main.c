/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 22:28:31 by student           #+#    #+#             */
/*   Updated: 2020/08/13 22:28:33 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "mlx.h"

t_fractal	*get_fractals(void)
{
	static t_fractal array[8] = {
			{"mandelbrot", mandelbrot_data, mandelbrot_point, 0},
			{"julia", julia_data, julia_point, 1},
			{"burningship", burningship_data, burningship_point, 0},
			{NULL, NULL, NULL, 0}
	};

	return (array);
}

t_fractal	*fractal_match(char *str)
{
	t_fractal	*f;
	int			i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}

int			hook_expose(t_all *mlx)
{
	multithr(mlx);
	return (0);
}

int			put_error(char *reason)
{
	ft_putendl(reason);
	return (1);
}

int			main(int argc, char **argv)
{
	t_all		*mlx;
	t_fractal	*f;

	if (argc < 2)
		return (put_error("error: not enough arguments"));
	f = fractal_match(argv[1]);
	if (f->name == NULL)
		return (put_error("error: invalid fractal name\navaible fractals: "
		"julia, mandelbrot, burningship"));
	if ((mlx = init(f)) == NULL)
		return (put_error("error: mlx couldn't initialize properly"));
	reset_data(mlx);
	multithr(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, hook_expose, mlx);
	mlx_hook(mlx->window, 4, 4L, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 8L, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 64L, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
