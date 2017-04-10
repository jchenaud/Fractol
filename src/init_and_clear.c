/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 01:27:35 by jchenaud          #+#    #+#             */
/*   Updated: 2017/04/10 03:12:28 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	mendel_initial(void)
{
	t_glob.fac_zoom = 1;
	t_f.x1 = -2.1;
	t_f.x2 = 0.6;
	t_f.y1 = -1.2;
	t_f.y2 = 1.2;
	t_f.imax = 50;
	t_glob.vib_r = 255;
	t_glob.vib_v = 255;
	t_glob.first = 0;
	return ;
}

void	julia_initial(void)
{
	t_glob.fac_zoom = 1;
	t_f.x1 = -1.5;
	t_f.x2 = 1.5;
	t_f.y1 = -1.5;
	t_f.y2 = 1.5;
	t_f.imax = 50;
	t_glob.first = 0;
	t_glob.click = 0;
	t_glob.vib_v = 255;
	t_glob.vib_r = 255;
	t_f.c_r = 0.285;
	t_f.c_i = 0.01;
	return ;
}

void	color_init(void)
{
	t_glob.r = 0;
	t_glob.b = 0;
	t_glob.v = 0;
	t_f.lu = 0;
}

void	clear_img(void)
{
	mlx_destroy_image(t_glob.mlx, t_glob.img);
	t_glob.img = mlx_new_image(t_glob.mlx, t_w.l, t_w.w);
	mlx_put_image_to_window(t_glob.mlx, t_glob.win, t_glob.img, 0, 0);
}

void	init_tapis(void)
{
	t_glob.fac_zoom = t_w.w;
	t_f.x1 = 0;
	t_f.x2 = t_w.w;
	t_f.y1 = 0;
	t_f.y2 = t_w.w;
	t_f.imax = 4;
	t_glob.r = 255;
	t_glob.v = 255;
	t_glob.b = 255;
	t_glob.vib_r = 255;
	t_glob.vib_v = 255;
	t_glob.vib_b = 255;
	return ;
}
