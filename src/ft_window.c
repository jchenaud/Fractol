/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 07:31:28 by jchenaud          #+#    #+#             */
/*   Updated: 2017/04/10 01:20:12 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	my_key_anex(int keycode)
{
	if (keycode == 69 && ft_strcmp(t_glob.arg, "Tapis") != 0)
		t_f.imax += 5;
	else if (keycode == 78 && ft_strcmp(t_glob.arg, "Tapis") != 0)
		t_f.imax -= 5;
	else if (keycode == 126)
		t_f.lu += 5;
	else if (keycode == 125)
		t_f.lu -= 5;
	else if (keycode == 67)
	{
		if (t_f.iblock == 0)
			t_f.iblock++;
		else
			t_f.iblock--;
	}
	else if (keycode == 81)
		ft_fractol();
	else if (keycode == 15)
	{
		t_glob.first = 1;
		ft_fractol();
	}
}

int			my_keyf(int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_image(t_glob.mlx, t_glob.img);
		mlx_destroy_window(t_glob.mlx, t_glob.win);
		exit(0);
	}
	else if (keycode == 8)
	{
		if (t_glob.color == 0)
			t_glob.color++;
		else
			t_glob.color--;
	}
	else if (keycode >= 83 && keycode <= 88)
		t_glob.color_modif = keycode - 82;
	else if (keycode == 69 || keycode == 78 || keycode == 67
			|| keycode == 81 || keycode == 125 || keycode == 126
			|| keycode == 15)
		my_key_anex(keycode);
	return (0);
}

static void	color_mouse(void)
{
	double pos_x;

	pos_x = (t_glob.pos_x / (t_w.l / 255));
	if (t_glob.color_modif == 1)
		t_glob.r2 = pos_x;
	else if (t_glob.color_modif == 2)
		t_glob.v2 = pos_x;
	else if (t_glob.color_modif == 3)
		t_glob.b2 = pos_x;
	else if (t_glob.color_modif == 4)
		t_glob.vib_r = pos_x;
	else if (t_glob.color_modif == 5)
		t_glob.vib_v = pos_x;
	else if (t_glob.color_modif == 6)
		t_glob.vib_b = pos_x;
	ft_fractol();
}

int			pos_mouse(int x, int y)
{
	if (x > 0 && y > 0 && x < t_w.l && y < t_w.w)
	{
		t_glob.pos_x = x;
		t_glob.pos_y = y;
		t_f.pos_x = (t_glob.pos_x / t_f.zoom_x) + t_f.x1;
		t_f.pos_y = (t_glob.pos_y / t_f.zoom_y) + t_f.y1;
		if (ft_strcmp(t_glob.arg, "Julia") == 0 && t_glob.click == 0)
		{
			t_f.c_r = t_f.pos_x;
			t_f.c_i = t_f.pos_y;
			ft_fractol();
		}
		if (t_glob.color == 1)
			color_mouse();
	}
	return (0);
}

void		ft_window(void)
{
	int endian;
	int bpp;
	int size;

	size = t_w.l * t_w.w;
	t_glob.color = 0;
	t_glob.mlx = mlx_init();
	t_glob.img = mlx_new_image(t_glob.mlx, t_w.l, t_w.w);
	if (ft_strcmp(t_glob.arg, "Tapis") != 0)
		t_glob.win = mlx_new_window(t_glob.mlx, t_w.l, t_w.w, t_glob.arg);
	else
	{
		size = t_w.w * t_w.w;
		t_glob.win = mlx_new_window(t_glob.mlx, t_w.w, t_w.w, t_glob.arg);
	}
	t_glob.buff = mlx_get_data_addr(t_glob.img, (&bpp), (&size), (&endian));
	mlx_mouse_hook(t_glob.win, wheel_mouse, 0);
	t_glob.first = 1;
	ft_fractol();
	mlx_hook(t_glob.win, MOTION_NOTIFY, PTR_MOTION_MASK, pos_mouse, 0);
	mlx_key_hook(t_glob.win, my_keyf, 0);
	mlx_loop(t_glob.mlx);
	return ;
}
