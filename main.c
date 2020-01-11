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
	t_lst *lst = NULL;
	t_lst	*tt = NULL;
	t_lst  *aux;
	t_polygone *polygone;

	if (argc != 2 && write(1, "usage: ./polygon file\n", 22))
		return (0);
	polygone = (t_polygone *)malloc(sizeof(t_polygone));

	lst = read_file(argv[1]);
	tt = lst;
	polygone->size = nbr_points(&lst);
	lst = tt;
	polygone->pnts = ft_points(polygone->size, lst);
	get_angle(polygone);
	lst = tt;
	aux = check_points(&lst, polygone);


	tt = aux;
	printf("\n*****Les Points:*****\n");
	printf("Size: %d\n",polygone->size);
		aux = tt;
	if(polygone->size == 3)
		polygone->type = check_forme_triangle(polygone);
	else if (polygone->size == 4)
	{
		calcul_tendon(polygone, aux); //tendon!!!
		polygone->type = check_forme_quadrilatere(polygone);
		printf("Type: (Quadrilatere)\t%s\n", polygone->type);
	}
	else
		printf("Type:\tXX\n");
	printf("\n");
	while(aux)
	{
		printf("%c (x.%.2f; y.%.2f)\n",aux->name, aux->data.x, aux->data.y);
		aux = aux->next;
	}
	aux = tt;
	printf("\n*****Les Segements(cotes):*****\n");
	while (i < polygone->size)
	{
		if (i == polygone->size - 1)
				printf("%c%c = %f\n", aux->name, tt->name , polygone->segments[i]);
		else
		{
			printf("%c%c = %f\n", aux->name, aux->name + 1, polygone->segments[i]);
			aux = aux->next;
		}
		i++;
	}
	aux = tt;
	i = 0;
	printf("\n*****Les Angles:*****\n");
	while(i < polygone->size)
	{
		if (i == polygone->size - 1)
			printf(" %c = %.2f\n", tt->name, (polygone->angles[i] * 180) / PI);
		else
		{
			printf(" %c = %.2f\n", aux->name + 1, (polygone->angles[i] * 180) / PI);
			aux = aux->next;
		}
		i++;
	}
	aux = tt;
	printf("\n*****Les Caracteristiques::*****\n");
	printf("\nPerimetre:\t%.2f\n", perimetre(polygone));
	printf("Surface:\t%.2f\n", surface(polygone));
	printf("Regulier?\t%d\n", check_regulier(polygone));

	printf("\n******************************\n\n");
	return (0);

}
