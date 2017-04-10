/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 08:51:32 by jchenaud          #+#    #+#             */
/*   Updated: 2017/04/10 03:06:36 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		ft_pixel_to_image(int x, int y, char *buffer, int need_color)
{
	if ((x >= 0 && y >= 0) && (x < t_w.l && y < t_w.w))
	{
		buffer[(x * 4) + (y * t_w.l * 4)] = (need_color == 0) ?
			t_glob.b2 : t_glob.b;
		buffer[(x * 4) + (y * t_w.l * 4) + 1] = (need_color == 0) ?
			t_glob.v2 : t_glob.v;
		buffer[(x * 4) + (y * t_w.l * 4) + 2] = (need_color == 0) ?
			t_glob.r2 : t_glob.r;
	}
}

static void	anex_1(void)
{
	t_f.image_x = t_w.l;
	t_f.image_y = t_w.w;
	if (t_glob.first == 1)
	{
		if (ft_strcmp(t_glob.arg, "Mandelbrot") == 0)
			mendel_initial();
		else if (ft_strcmp(t_glob.arg, "Julia") == 0)
			julia_initial();
		color_init();
	}
	t_f.zoom_x = t_f.image_x / (t_f.x2 - t_f.x1);
	t_f.zoom_y = t_f.image_y / (t_f.y2 - t_f.y1);
	t_f.x = 0;
	t_f.z_r = 0;
	t_f.z_i = 0;
	t_f.i = 0;
	t_f.tmp_zr = 0;
	if (ft_strcmp(t_glob.arg, "Mandelbrot") == 0)
	{
		t_f.c_r = 0;
		t_f.c_i = 0;
	}
}

static void	anex_2(void)
{
	if (ft_strcmp(t_glob.arg, "Mandelbrot") == 0)
	{
		t_f.c_r = t_f.x / t_f.zoom_x + t_f.x1;
		t_f.c_i = t_f.y / t_f.zoom_y + t_f.y1;
		t_f.z_r = 0;
		t_f.z_i = 0;
	}
	else if (ft_strcmp(t_glob.arg, "Julia") == 0)
	{
		t_f.z_r = t_f.x / t_f.zoom_x + t_f.x1;
		t_f.z_i = t_f.y / t_f.zoom_y + t_f.y1;
	}
	t_f.i = 0;
}

static void	anex_3(void)
{
	t_f.tmp_zr = t_f.z_r;
	t_f.z_r = t_f.z_r * t_f.z_r - t_f.z_i * t_f.z_i + t_f.c_r;
	t_f.z_i = 2 * t_f.z_i * t_f.tmp_zr + t_f.c_i;
	t_f.i++;
	if (t_f.i == t_f.imax)
		ft_pixel_to_image(t_f.x, t_f.y, t_glob.buff, 0);
	else
	{
		if (t_f.lu == t_f.imax)
			t_f.lu--;
		t_glob.r = t_f.i * t_glob.vib_r / (t_f.imax - t_f.lu);
		t_glob.v = t_f.i * t_glob.vib_v / (t_f.imax - t_f.lu);
		t_glob.b = t_f.i * t_glob.vib_b / (t_f.imax - t_f.lu);
		ft_pixel_to_image(t_f.x, t_f.y, t_glob.buff, 1);
	}
}

void		ft_fractol(void)
{
	clear_img();
	if (ft_strcmp(t_glob.arg, "Mandelbrot") == 0
			|| ft_strcmp(t_glob.arg, "Julia") == 0)
	{
		anex_1();
		while (t_f.x < t_f.image_x)
		{
			t_f.y = 0;
			while (t_f.y < t_f.image_y)
			{
				anex_2();
				while (t_f.z_r * t_f.z_r + t_f.z_i * t_f.z_i < 4
						&& t_f.i < t_f.imax)
					anex_3();
				t_f.y++;
			}
			t_f.x++;
		}
	}
	else
		ft_gestion();
	t_glob.first = 2;
	mlx_put_image_to_window(t_glob.mlx, t_glob.win, t_glob.img, 0, 0);
}
