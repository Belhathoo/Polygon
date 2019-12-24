/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nombre_de_mot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 22:26:09 by erahimi           #+#    #+#             */
/*   Updated: 2019/04/20 22:26:12 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nombre_de_mot(const char *s, char x)
{
	int nbr;

	nbr = 0;
	while (*s)
	{
		if (*s != x && (*(s + 1) == x || !(*(s + 1))))
			nbr++;
		s++;
	}
	return (nbr);
}
