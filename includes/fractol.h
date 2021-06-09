/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dteemo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:37:37 by student           #+#    #+#             */
/*   Updated: 2020/08/12 19:37:39 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdint.h>
# include <pthread.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define ZOOM 1.1f
# define THREADS 8

typedef struct		s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}					t_rgba;

typedef union		u_color
{
	int			value;
	t_rgba		rgba;
}					t_color;

typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;

typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;

typedef struct		s_complex
{
	double		r;
	double		i;
}					t_complex;

typedef struct		s_data
{
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
	double		zoom;
	double		offx;
	double		offy;
	long		max;
	t_complex	mouse;
}					t_data;

typedef struct		s_point
{
	t_complex	c;
	long		i;
}					t_point;

typedef struct		s_palitra
{
	uint8_t		count;
	int			cycle;
	int			colors[16];
}					t_palitra;
typedef struct s_all	t_all;

typedef void		(*t_func_d)(t_data *v);
typedef t_point		(*t_func_p)(int x, int y, t_data *v, t_all *mlx);
typedef struct		s_fractal
{
	char		*name;
	t_func_d	data;
	t_func_p	point;
	int			mouse;
}					t_fractal;

typedef struct		s_thread
{
	int				id;
	t_all			*mlx;
}					t_thread;

typedef struct		s_multithr
{
	pthread_t		threads[THREADS];
	t_thread		args[THREADS];
}					t_multithr;

struct				s_all
{
	void		*mlx;
	void		*window;
	t_fractal	*fractal;
	t_point		*points;
	t_image		*image;
	t_mouse		mouse;
	t_data		data;
	t_palitra	*palitra;
	t_multithr	multithr;
	int			smooth;
	int			mouselock;
};

t_all				*mlxdel(t_all *mlx);
t_all				*init(t_fractal *f);
void				multithr(t_all *mlx);
void				draw(t_all *mlx);
int					hook_mousedown(int button, int x, int y, t_all *mlx);
int					hook_mouseup(int button, int x, int y, t_all *mlx);
int					hook_mousemove(int x, int y, t_all *mlx);
int					hook_keydown(int key, t_all *mlx);
int					hook_expose(t_all *mlx);
t_image				*del_image(t_all *mlx, t_image *img);
t_image				*new_image(t_all *mlx);
void				clear_image(t_image *img);
void				image_set_point(t_image *image, int x, int y, int color);
t_fractal			*fractal_match(char *str);
int					get_color(t_point p, t_all *mlx);
t_palitra			*get_palitras();
void				zoom(int x, int y, t_data *v, double z);
void				data_fit(t_data *v);
void				reset_data(t_all *mlx);
t_complex			screen_to_complex(int x, int y, t_data *v);
t_point				mandelbrot_point(int x, int y, t_data *v, t_all *mlx);
void				mandelbrot_data(t_data *v);
t_point				burningship_point(int x, int y, t_data *v, t_all *mlx);
void				burningship_data(t_data *v);
t_point				julia_point(int x, int y, t_data *v, t_all *mlx);
void				julia_data(t_data *v);

#endif
