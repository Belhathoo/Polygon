/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibel-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:41:40 by ibel-kha          #+#    #+#             */
/*   Updated: 2019/12/18 16:41:43 by ibel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "polygone.h"

double		ft_atod(char *str)
{
	double		nbr;
	int			i;
	double		chfr;
	static int	signe;

	nbr = (double)ft_atoi(str);
	i = 0;
	chfr = 10;
	while ((str[i] == '\n') || (str[i] == ' ') || (str[i] == '\t')
			|| (str[i] == '\f') || (str[i] == '\v') || (str[i] == '\r'))
		i++;
	signe = str[i] == '-' ? 1 : 0;
	i = ((str[i] == '-') || (str[i] == '+')) ? i + 1 : i;
	while (str[i] && str[i++] != '.')
		i = i + 0;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		nbr = nbr >= 0 && !signe ? nbr + (double)(str[i++] - 48) / chfr :
			nbr - (double)(str[i++] - 48) / chfr;
		chfr *= 10;
	}
	return (nbr);
}
void    ft_alloc(t_lst **l, t_lst **curr, t_lst **tt)
{
	if ((*l) == NULL)
	{
		(*l) = create_args();
		(*l)->data = (*curr)->data;
        (*tt) = (*l);
	}
    else 
    {
		(*l)->next = create_args();
		(*l)->next->data = (*curr)->data;
		(*l) = (*l)->next;
	}
}



t_lst         *check_points(t_lst **lst, t_polygone *polygone)
{
	t_lst *tete;
	t_lst *curr;
	t_lst  *lista;

    t_lst   *l;
	
    int i = 0;
    
    l = *lst;
    lista = NULL;
    
    curr = create_args();
	if((int)(polygone->angles[polygone->size - 1] * 180/PI) == 180)
		l = l->next;
	else
	{
		curr->data = l->data;
		ft_alloc(&lista, &curr, &tete);
		l = l->next;
	}
	while(i < polygone->size - 1)
	{
		if ((int)(polygone->angles[i] * 180/PI) == 180)
		{
			i++;
			l = l->next;
		}
		else
        {
			curr->data = l->data;
			ft_alloc(&lista, &curr, &tete);
			l = l->next;
			i++;
		}
	}
    free(curr);
    lista = tete; 
    polygone->size = nbr_points(&lista);
    lista = tete;    

    free(polygone->pnts);
	polygone->pnts = ft_points(polygone->size, lista);

    free(polygone->angles);
	get_angle(polygone);

    calcul_module(lista, polygone);
   	lista = tete;

	return (lista);
}

