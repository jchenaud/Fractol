/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 07:29:21 by jchenaud          #+#    #+#             */
/*   Updated: 2017/04/10 03:57:20 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
//# include <mlx.h>
# include "../minilibx_siera/mlx.h"

# define PTR_MOTION_MASK (1L<<6)
# define MOTION_NOTIFY 6
# define L 1280
# define W 720

struct				s_global
{
	void			*img;
	void			*mlx;
	void			*win;
	char			*buff;
	char			*arg;
	int				r;
	int				v;
	int				b;
	int				r2;
	int				v2;
	int				b2;
	int				first;
	int				pos_x;
	int				pos_y;
	double			fac_zoom;
	int				click;
	int				color;
	int				color_modif;
	int				vib_r;
	int				vib_v;
	int				vib_b;

}					t_glob;

struct				s_fractal
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			ix1;
	double			ix2;
	double			iy1;
	double			iy2;
	int				imax;
	int				i;
	double			image_x;
	double			image_y;
	double			zoom_x;
	double			zoom_y;
	int				x;
	int				y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp_zr;
	double			pos_x;
	double			pos_y;
	double			zx;
	double			zy;
	double			size;
	double			rp_zoom;
	int				fact_z;
	int				litel;
	int				iblock;
	int				lu;
	int				opti;
}					t_f;

struct				s_window
{
	int				l;
	int				w;
}					t_w;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

void				ft_pixel_to_image(int x, int y, char *buf, int need_color);
void				ft_fractol(void);
void				clear_img(void);
int					wheel_mouse(int mcode);
void				ft_gestion(void);
void				ft_window(void);
void				ft_tapis(double x, double y, double sq_size, int i_max);
void				mendel_initial(void);
void				julia_initial(void);
void				init_tapis(void);
void				color_init(void);
#endif
