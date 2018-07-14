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


void		draw_mandelbrot(int x, int y, t_fr *fr)
{
	double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	int 	i;

	PR = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MOVEX;
	PI = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MOVEY;
	newRe = 0;
	newIm = 0;
	i = -1;
	while (++i < MAXITER)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + PR;
		newIm = 2 * oldRe * oldIm + PI;
		if((newRe * newRe + newIm * newIm) > 4)
			break;
	}
	if (i == MAXITER)
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr,
					  x, y, 0);
	else
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr, x, y, fr->color * i);
}



void	 draw_julia(int x, int y, t_fr *fr)
{
    double	newRe;
	double	newIm;
	double	oldRe;
	double	oldIm;
	int 	i;

	newRe = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MOVEX;
	newIm = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MOVEY;
	i = 0;
	while (i < MAXITER)
	{
		oldRe = newRe;
		oldIm = newIm;
		newRe = oldRe * oldRe - oldIm * oldIm + CRE;
		newIm = 2 * oldRe * oldIm + CIM;
		if((newRe * newRe + newIm * newIm) > 4)
			break;
		i++;
	}
	if (i == MAXITER)
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr,
					  x, y, 0);
	else
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr, x, y, fr->color * i);
}

void	choose_fractol(t_fr *fr, int x, int y)
{
	if (fr->name == 1)
		draw_mandelbrot(x, y, fr);
	else if (fr->name == 2)
		draw_julia(x, y, fr);
}

void	draw_fractol(t_fr *fr)
{
	int 	y;
	int 	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH) {
			choose_fractol(fr, x, y);
			x++;
		}
		y++;
	}
}