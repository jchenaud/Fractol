/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tapis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 10:11:48 by jchenaud          #+#    #+#             */
/*   Updated: 2017/04/10 03:41:17 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	ft_line(t_point a, t_point b, int color)
{
	int		x;
	int		y;
	double	cof;
	double	ord;

	cof = (double)(b.y - a.y) / (b.x - a.x);
	ord = a.y - cof * (a.x);
	x = a.x;
	if (x != b.x)
		while (x < b.x)
		{
			y = (cof * x + ord);
			ft_pixel_to_image(x, y, t_glob.buff, color);
			x++;
		}
	else
	{
		y = a.y;
		while (y < b.y)
		{
			ft_pixel_to_image(x, y, t_glob.buff, color);
			y++;
		}
	}
}

static void	ft_square(double x, double y, double size, int color)
{
	t_point a;
	t_point b;
	int		i;

	if (x <= t_f.x2 && y <= t_f.y2)
	{
		x = (x - t_f.x1) * t_f.zoom_x;
		y = (y - t_f.y1) * t_f.zoom_y;
		size = size * t_f.zoom_x;
		if (size > 6)
		{
			a.x = x;
			b.x = (x + size);
			i = 0;
			while (i <= size)
			{
				a.y = y;
				b.y = y;
				ft_line(a, b, color);
				y++;
				i++;
			}
		}
		t_f.litel = (size <= 6 || t_f.opti < 9 || t_f.opti > 10000) ? 1 : 0;
	}
}

static int	condition(double x, double y, double sq_size)
{
	if ((x <= t_f.x1 && x <= t_f.x2 && y <= t_f.y1
				&& y <= t_f.y2 && x + sq_size >= t_f.x1
				&& y + sq_size >= t_f.y1)
			|| (x >= t_f.x1 && x <= t_f.x2 && y <= t_f.y1 && y <= t_f.y2)
			|| (x <= t_f.x1 && x <= t_f.x2 && y >= t_f.y1 && y <= t_f.y2)
			|| (x >= t_f.x1 && x <= t_f.x2 && y >= t_f.y1 && y <= t_f.y2))
		return (0);
	return (1);
}

static void	recur_anex(double x, double y, double sq_size, int i_max)
{
	t_f.opti++;
	ft_square((x + sq_size / 3), (y + sq_size / 3), (sq_size / 3), 1);
	ft_tapis(x, y, sq_size / 3, i_max - 1);
	ft_tapis(x + (sq_size / 3), y, sq_size / 3, i_max - 1);
	ft_tapis(x + 2 * (sq_size / 3), y, sq_size / 3, i_max - 1);
	ft_tapis(x, (y + sq_size / 3), sq_size / 3, i_max - 1);
	ft_tapis(x + 2 * (sq_size / 3), (y + sq_size / 3),
			sq_size / 3, i_max - 1);
	ft_tapis(x, y + 2 * (sq_size / 3),
			sq_size / 3, i_max - 1);
	ft_tapis(x + (sq_size / 3), y + 2 * (sq_size / 3),
			sq_size / 3, i_max - 1);
	ft_tapis(x + 2 * (sq_size / 3), y + 2 * (sq_size / 3),
			sq_size / 3, i_max - 1);
}

void		ft_tapis(double x, double y, double sq_size, int i_max)
{
	if (t_glob.first == 1)
	{
		init_tapis();
		x = 0;
		y = 0;
		sq_size = t_w.w;
		t_glob.first = 2;
	}
	t_f.zoom_x = t_w.w / (t_f.x2 - t_f.x1);
	t_f.zoom_y = t_w.w / (t_f.y2 - t_f.y1);
	if (t_glob.first == 2)
	{
		i_max = t_f.imax;
		t_glob.first = 0;
		x *= t_f.zoom_x;
		y *= t_f.zoom_x;
		t_f.litel = 0;
	}
	if ((i_max > 0) && (condition(x, y, sq_size) == 0))
		recur_anex(x, y, sq_size, i_max);
	else
		return ;
	t_f.size = sq_size;
}
