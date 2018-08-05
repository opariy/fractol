/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:08:41 by opariy            #+#    #+#             */
/*   Updated: 2018/07/14 11:08:44 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# define WIDTH 1800
# define HEIGHT 1000
# define ZOOM fr->zoom
# define MOVEX fr->movex
# define MOVEY fr->movey
# define MAXITER fr->maxiter
# define CRE fr->cre
# define CIM fr->cim
# define PR fr->pr
# define PI fr->pi

typedef struct	s_fr
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			name;
	int			maxiter;
	int			depth;
	int			color;
	double		zoom;
	double		movex;
	double		movey;
	double		cre;
	double		cim;
	double		pr;
	double		pi;
}				t_fr;

void			ft_draw(t_fr *fr);
int				key_hook(int key, t_fr *fr);
void			ft_init_window(t_fr *fr);
void			draw_fractol(t_fr *fr);
void			draw_julia(int x, int y, t_fr *fr);
void			draw_mandelbrot(int x, int y, t_fr *fr);
void			draw_custom_1(int x, int y, t_fr *fr);
void			draw_custom_2(int x, int y, t_fr *fr);
void			draw_custom_3(int x, int y, t_fr *fr);
void			draw_custom_4(int x, int y, t_fr *fr);
void			draw_custom_5(int x, int y, t_fr *fr);
void			draw_burninh_ship(int x, int y, t_fr *fr);
int				ft_exit(int keycode);
int				change_julia(int x, int y, t_fr *fr);

#endif
