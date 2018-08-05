/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractols.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 13:12:51 by opariy            #+#    #+#             */
/*   Updated: 2018/08/05 13:12:53 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_burninh_ship(int x, int y, t_fr *fr)
{
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	int		i;

	PR = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MOVEX;
	PI = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MOVEY;
	newre = 0;
	newim = 0;
	i = -1;
	while (++i < MAXITER)
	{
		oldre = newre;
		oldim = newim;
		newre = oldre * oldre - oldim * oldim + PR;
		newim = 2 * fabs(oldre * oldim) + PI;
		if ((newre * newre + newim * newim) > 4)
			break ;
	}
	if (i == MAXITER)
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr,
					x, y, 0);
	else
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr, x, y, fr->color * i);
}

void	draw_custom_5(int x, int y, t_fr *fr)
{
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	int		i;

	newre = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MOVEX;
	newim = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MOVEY;
	i = 0;
	while (i < MAXITER)
	{
		oldre = newre;
		oldim = newim;
		newre = (oldre * oldre) - 3 * atan(oldim * oldim);
		newim = 2 * oldre * oldim;
		if ((newre * newre + newim * newim) > 4)
			break ;
		i++;
	}
	if (i == MAXITER)
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr,
					x, y, 0);
	else
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr, x, y, fr->color * i);
}

void	draw_custom_4(int x, int y, t_fr *fr)
{
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	int		i;

	newre = 1.5 * (x - WIDTH / 2) / (0.5 * ZOOM * WIDTH) + MOVEX;
	newim = (y - HEIGHT / 2) / (0.5 * ZOOM * HEIGHT) + MOVEY;
	i = 0;
	while (i < MAXITER)
	{
		oldre = newre;
		oldim = newim;
		newre = tan(oldre * oldre) - oldim * oldim + CRE;
		newim = 2 * oldre * oldim + CIM;
		if ((newre * newre + newim * newim) > 4)
			break ;
		i++;
	}
	if (i == MAXITER)
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr,
					x, y, 0);
	else
		mlx_pixel_put(fr->mlx_ptr, fr->win_ptr, x, y, fr->color * i);
}
