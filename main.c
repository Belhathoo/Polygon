/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:34:06 by ibel-kha          #+#    #+#             */
/*   Updated: 2019/12/18 16:34:08 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polygone.h"

int		main(int argc, char **argv)
{ 
	int i = 0;
	t_lst *lst;
	t_lst	*tt;
	t_polygone *polygone;

    if (argc == 2)
   { 
	 polygone = (t_polygone *)malloc(sizeof(t_polygone));
	 lst = read_file(argv[1]);
	 tt = lst;
	 polygone->size = nbr_points(&lst);
	 polygone->pnts = ft_points(polygone->size, lst);
	 calcul_module(tt, polygone);
	 get_angle(polygone);
	 lst = tt;
	 while(lst)
	{
		printf("%.2f\t%.2f\n\n", lst->data.x, lst->data.y);
		lst = lst->next;
	}

	while (i < polygone->size)
	{
		printf("%f\n", polygone->segments[i]);
		i++;
	}
	lst = tt;
	if(polygone->size == 3)
		polygone->type = check_forme_triangle(polygone);
	printf("\nPerimetre: %f\n", perimetre(polygone));
	if (polygone->size == 4)
	{
		calcul_tendon(polygone, lst);
		polygone->type = check_forme_quadrilatere(polygone);
   		printf("type: %c\n", polygone->type);
	}
	printf("Surface: %f\n", surface(polygone));
	printf("regulier : %d\n", check_regulier(polygone));
	i = 0;
	while(i < polygone->size)
	{
		printf("angle %d : %f\n", i + 1, (polygone->angles[i] * 180) / PI);
		i++;
	}
   }
	return (0);

}