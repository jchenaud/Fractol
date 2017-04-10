/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:11:47 by jchenaud          #+#    #+#             */
/*   Updated: 2017/02/22 09:07:17 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2000000000
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

int				get_next_line(const int fd, char **line);

typedef struct	s_struct
{
	char		*buf;
	int			red;
	int			nb;
	int			i;
}				t_struct;

#endif
