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

int		ft_exit(int keycode)
{
    keycode = 0;
    exit(keycode);
}

int			key_hook(int key, t_fr *fr)
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
    mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	draw_fractol(fr);
	return (0);
}

void    ft_init_window(t_fr *fr)
{
    char *name;

    if (fr->name == 1)
        name = "Mandelbrot";
    else if (fr->name == 2)
        name = "Julia";
    else
        name = "Burningship";
    fr->mlx_ptr = mlx_init();
    fr->win_ptr = mlx_new_window(fr->mlx_ptr, WIDTH, HEIGHT, name);
}

int 	mouse_hook(int key, int x, int y, t_fr *fr)
{
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	if (key == 4)
		ZOOM *= 1.1;
	else if (key == 5)
		ZOOM *= 0.9;
	draw_fractol(fr);
	return (0);
}

int 	change_julia(int x, int y, t_fr *fr)
{
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	if (x < WIDTH && y < HEIGHT)
	{
		CRE = -0.7 * x/1000;
		CIM = 0.27015 * y/1000;
	}
	draw_fractol(fr);
	return (0);
}

void    ft_draw(t_fr *fr)
{
	draw_fractol(fr);

    mlx_hook(fr->win_ptr, 2, 0, key_hook, fr);
	mlx_mouse_hook(fr->win_ptr, mouse_hook, fr);
	mlx_hook(fr->win_ptr, 6, 0, change_julia, fr);
    mlx_hook(fr->win_ptr, 17, 1L << 17, ft_exit, 0);
    mlx_loop(fr->mlx_ptr);

}
