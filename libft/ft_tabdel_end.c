/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 08:58:54 by jchenaud          #+#    #+#             */
/*   Updated: 2016/12/14 09:16:26 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tabdel_end(char *tab, int len)
{
	int i;

	i = 0;
	while (i < len && tab[i])
		i++;
	while (tab[i])
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
