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

void		init(t_lst **p, char *title)
{
	if (parser(p, title, 0) == -1 && write(1, "error: parsing\n", 15))
		exit(EXIT_FAILURE);
//	calcul_angle(p);
//	sort_list(p);
}

int		main(int argc, char **argv)
{
	int i = 0;
	t_lst *lst = NULL;
	t_lst	*tt = NULL;
	t_lst  *aux;
	t_polygone *polygone;

	if (argc != 2 && write(1, "usage: ./polygon file\n", 22))
		return (0);
	polygone = (t_polygone *)malloc(sizeof(t_polygone));

//	lst = read_file(argv[1]);
	init(&lst, argv[1]);
	tt = lst;
	polygone->size = nbr_points(&lst);
	lst = tt;
	polygone->pnts = ft_points(polygone->size, lst);
	get_angle(polygone);
	lst = tt;
	aux = check_points(&lst, polygone);
	tt = aux;
	//aux = tt;
	while(aux)
	{
		printf("x.%.2f\ty.%.2f\n", aux->data.x, aux->data.y);
		aux = aux->next;
	}
	aux = tt;
	while (i < polygone->size)
	{
		printf("seg %d = %f\n", i+1, polygone->segments[i]);
		i++;
	}
	if(polygone->size == 3)
		polygone->type = check_forme_triangle(polygone);
	printf("Size: %d\nPerimetre: %f\n",polygone->size, perimetre(polygone));
	if (polygone->size == 4)
	{
		calcul_tendon(polygone, aux);
		polygone->type = check_forme_quadrilatere(polygone);
		printf("type: %c\n", polygone->type);
	}
	printf("Surface: %f\n", surface(polygone));
	printf("regulier? %d\n", check_regulier(polygone));
	i = 0;
	while(i < polygone->size)
	{
		printf("angle %d : %f\n", i + 1, (polygone->angles[i] * 180) / PI);
		aux = aux->next;
		i++;
	}
	aux = tt;
	return (0);

}
