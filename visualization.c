/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:45:14 by opariy            #+#    #+#             */
/*   Updated: 2018/07/14 12:45:16 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		arrows(int key, t_fr *fr)
{
	double b;

	b = 0.1;
	if (ZOOM > 2 && ZOOM <= 10)
		b = 0.01;
	else if (ZOOM > 10 && ZOOM <= 100)
		b = 0.001;
	else if (ZOOM > 100 && ZOOM <= 1000)
		b = 0.0001;
	else if (ZOOM > 1000 && ZOOM <= 10000)
		b = 0.00001;
	else if (ZOOM > 10000 && ZOOM <= 100000)
		b = 0.000001;
	else if (ZOOM > 100000)
		b = 0.0000001;
	if (key == 126)
		MOVEY += b;
	else if (key == 125)
		MOVEY -= b;
	else if (key == 123)
		MOVEX += b;
	else if (key == 124)
		MOVEX -= b;
}

int				key_hook(int key, t_fr *fr)
{
	if (key == 53)
	{
		mlx_destroy_window(fr->mlx_ptr, fr->win_ptr);
		exit(0);
	}
	else if (key == 78)
		fr->color -= 1000;
	else if (key == 69)
		fr->color += 1000;
	else if (key == 123 || key == 124 || key == 125
			|| key == 126)
		arrows(key, fr);
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	draw_fractol(fr);
	return (0);
}

void			ft_init_window(t_fr *fr)
{
	char *name;

	if (fr->name == 1)
		name = "Mandelbrot";
	else if (fr->name == 2)
		name = "Julia";
	else if (fr->name == 3)
		name = "Burning Ship";
	else if (fr->name == 4)
		name = "Custom Fractol 1";
	else if (fr->name == 5)
		name = "Custom Fractol 2";
	else if (fr->name == 6)
		name = "Custom Fractol 3";
	else if (fr->name == 7)
		name = "Custom Fractol 4";
	else if (fr->name == 8)
		name = "Custom Fractol 5";
	else
		name = "Who knows";
	fr->mlx_ptr = mlx_init();
	fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIDTH, HEIGHT, name);
}

int				mouse_hook(int key, int x, int y, t_fr *fr)
{
	x = 0;
	y = 0;
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	if (key == 4)
		ZOOM *= 1.1;
	else if (key == 5)
		ZOOM *= 0.9;
	draw_fractol(fr);
	return (0);
}

void			ft_draw(t_fr *fr)
{
	draw_fractol(fr);
	mlx_hook(fr->win_ptr, 2, 0, key_hook, fr);
	mlx_mouse_hook(fr->win_ptr, mouse_hook, fr);
	mlx_hook(fr->win_ptr, 6, 0, change_julia, fr);
	mlx_hook(fr->win_ptr, 17, 1L << 17, ft_exit, 0);
	mlx_loop(fr->mlx_ptr);
}
