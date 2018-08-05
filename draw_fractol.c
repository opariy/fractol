/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 13:38:14 by opariy            #+#    #+#             */
/*   Updated: 2018/07/14 13:38:15 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_exit(int keycode)
{
	keycode = 0;
	exit(keycode);
}

int		change_julia(int x, int y, t_fr *fr)
{
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	if (x < WIDTH && y < HEIGHT)
	{
		CRE = -0.7 * x / 1000;
		CIM = 0.27015 * y / 1000;
	}
	draw_fractol(fr);
	return (0);
}

void	choose_fractol(t_fr *fr, int x, int y)
{
	if (fr->name == 1)
		draw_mandelbrot(x, y, fr);
	else if (fr->name == 2)
		draw_julia(x, y, fr);
	else if (fr->name == 3)
		draw_burninh_ship(x, y, fr);
	else if (fr->name == 4)
		draw_custom_1(x, y, fr);
	else if (fr->name == 5)
		draw_custom_2(x, y, fr);
	else if (fr->name == 6)
		draw_custom_3(x, y, fr);
	else if (fr->name == 7)
		draw_custom_4(x, y, fr);
	else if (fr->name == 8)
		draw_custom_5(x, y, fr);
}

void	draw_fractol(t_fr *fr)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			choose_fractol(fr, x, y);
			x++;
		}
		y++;
	}
}
