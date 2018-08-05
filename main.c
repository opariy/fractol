/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opariy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 17:51:08 by opariy            #+#    #+#             */
/*   Updated: 2018/08/05 17:51:09 by opariy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putstr("Usage: ./fractol 1 / 2 / 3\n");
	ft_putstr("        1: Mandelbrot\n");
	ft_putstr("        2: Julia\n");
	ft_putstr("        3: Burning Ship\n");
	ft_putstr("        4: Custom Fractol 1\n");
	ft_putstr("        5: Custom Fractol 2\n");
	ft_putstr("        6: Custom Fractol 3\n");
	ft_putstr("        7: Custom Fractol 4\n");
	ft_putstr("        8: Custom Fractol 5\n");
}

void	ft_initialize(t_fr *fr)
{
	fr->depth = 50;
	fr->zoom = 1;
	fr->movex = 0;
	fr->movey = 0;
	fr->color = 0x0f0f0f;
	fr->maxiter = 300;
	fr->cre = -0.7;
	fr->cim = 0.27015;
	fr->pr = 0;
	fr->pi = 0;
}

int		check_input(char c)
{
	int	name;

	if (c == '5')
		name = 5;
	else if (c == '6')
		name = 6;
	else if (c == '7')
		name = 7;
	else if (c == '8')
		name = 8;
	else
	{
		print_usage();
		name = 0;
	}
	return (name);
}

int		ft_validate_input(int argc, char **argv)
{
	int		name;

	name = 0;
	if (argc != 2 || (ft_strlen(argv[1]) != 1))
		print_usage();
	else
	{
		if (argv[1][0] == '1')
			name = 1;
		else if (argv[1][0] == '2')
			name = 2;
		else if (argv[1][0] == '3')
			name = 3;
		else if (argv[1][0] == '4')
			name = 4;
		else
			name = check_input(argv[1][0]);
	}
	return (name);
}

int		main(int argc, char **argv)
{
	t_fr	*fr;

	fr = (t_fr *)malloc(sizeof(t_fr));
	if ((fr->name = ft_validate_input(argc, argv)))
	{
		ft_initialize(fr);
		ft_init_window(fr);
		ft_draw(fr);
	}
	free(fr);
	return (0);
}
