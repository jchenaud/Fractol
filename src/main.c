/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 07:22:02 by jchenaud          #+#    #+#             */
/*   Updated: 2017/04/10 03:22:48 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void		ft_gestion(void)
{
	if (t_glob.color == 1)
	{
		t_glob.r = t_glob.vib_r;
		t_glob.v = t_glob.vib_v;
		t_glob.b = t_glob.vib_b;
	}
	t_f.opti = 0;
	ft_tapis(0, 0, t_f.size, 0);
	return ;
}

static void	ft_help(void)
{
	ft_putstr("if you want to make a widow with different size you just");
	ft_putstr(" have to use arg (Mandelbrot or Julia) size (for example:");
	ft_putstr("640 , 720) take care size can't be < 500\n if you make f");
	ft_putstr("or ex : Julia 640 300 the real size of widows is 640,500");
	ft_putstr(" max size is 3000 1500");
	ft_putstr("\n______________________________________________________\n");
	ft_putstr("for chage colors you need to press [c] and color key   \n");
	ft_putstr("colors keys on Julia and Mandelbrot are :\n [4][5][6] fo");
	ft_putstr("r first game colors and [1][2][3] for second \n after pr");
	ft_putstr("ess [c] agen \n same on Tapis but only first game colors");
	ft_putstr("\n______________________________________________________\n");
	ft_putstr("\n_______________________key_list_______________________\n");
	ft_putstr("+ for add point\n- opposit of '+'\n * block auto add point");
	ft_putstr(" / or reactive\nhup arrow ->  more britness");
	ft_putstr("\nlow arrow ->  down a britness");
	ft_putstr("\n = refrech window");
	ft_putstr("\nR reset window\n");
}

static void	size_w(char **argv)
{
	t_w.l = (ft_atoi(argv[2]) >= 500) ? ft_atoi(argv[2]) : 500;
	t_w.w = (ft_atoi(argv[3]) >= 500) ? ft_atoi(argv[3]) : 500;
	if (t_w.l > 3000)
		t_w.l = 3000;
	if (t_w.w > 1500)
		t_w.w = 1500;
}

int			main(int argc, char **argv)
{
	if ((argc >= 2) && (ft_strcmp(argv[1], "Mandelbrot") == 0
				|| ft_strcmp(argv[1], "Julia") == 0
				|| (ft_strcmp(argv[1], "Tapis") == 0 && argc == 2)))
	{
		if ((argc != 2) && (argc == 4) && (ft_strcmp(argv[1], "Mandelbrot") == 0
					|| ft_strcmp(argv[1], "Julia") == 0))
			size_w(argv);
		else
		{
			t_w.l = L;
			t_w.w = W;
		}
		t_glob.arg = argv[1];
		ft_window();
		return (0);
	}
	write(1, "Argument are : Mandelbrot , Julia , Tapis \n", 43);
	write(1, "For more info use Help\n", 24);
	if (argc == 2 && ft_strcmp(argv[1], "Help") == 0)
		ft_help();
	return (1);
}
