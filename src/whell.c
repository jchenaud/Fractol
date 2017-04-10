/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 01:06:13 by jchenaud          #+#    #+#             */
/*   Updated: 2017/04/10 03:36:39 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static void	zoom_in(void)
{
	if (ft_strcmp(t_glob.arg, "Tapis") != 0)
	{
		if (t_f.imax < 200 && t_f.iblock == 0)
			t_f.imax += t_f.imax / 10;
		t_glob.fac_zoom -= t_glob.fac_zoom / 10;
	}
	else
	{
		t_glob.fac_zoom -= t_glob.fac_zoom / 10;
		if (t_f.litel == 0 && t_f.opti != 0)
			t_f.imax++;
	}
	t_f.x2 = t_f.pos_x + t_glob.fac_zoom;
	t_f.y2 = t_f.pos_y + t_glob.fac_zoom;
	t_f.x1 = t_f.pos_x - t_glob.fac_zoom;
	t_f.y1 = t_f.pos_y - t_glob.fac_zoom;
	ft_fractol();
}

static void	zoom_out(void)
{
	if (ft_strcmp(t_glob.arg, "Tapis") != 0)
	{
		if (t_f.imax > 50 && t_f.iblock == 0)
			t_f.imax -= 5;
		t_glob.fac_zoom += t_glob.fac_zoom / 10;
	}
	else
	{
		t_glob.fac_zoom += t_glob.fac_zoom / 10;
		if (t_f.litel == 1 && t_f.opti > 9)
			t_f.imax--;
	}
	t_f.x2 = t_f.pos_x + t_glob.fac_zoom;
	t_f.y2 = t_f.pos_y + t_glob.fac_zoom;
	t_f.x1 = t_f.pos_x - t_glob.fac_zoom;
	t_f.y1 = t_f.pos_y - t_glob.fac_zoom;
	ft_fractol();
}

int			wheel_mouse(int mcode)
{
	if (mcode == 4)
		zoom_in();
	else if (mcode == 5)
		zoom_out();
	else if (mcode == 1)
		t_glob.click = (t_glob.click == 0) ? 1 : 0;
	return (0);
}
