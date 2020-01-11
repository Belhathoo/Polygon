#include "polygone.h"

t_point     *ft_points(int size, t_lst *l)
{

	t_lst *head;
	t_point *tab;
	int i = 0;
	head = l; 
	tab = (t_point *)malloc(sizeof(t_point) * size);
	while(head != NULL)
	{
		tab[i].x = head->data.x ;
		tab[i].y = head->data.y; 
		i++;
		head = head->next;
	}
	return (tab);
}


char   *check_forme_quadrilatere(t_polygone *polygone)
{
	t_point *pnts;
	float ps;
	float ps1;
	float ps_td;

	pnts = polygone->pnts;
	ps = abs(produit_scalaire(pnts[0], pnts[1], pnts[2], pnts[3]));
	ps1 = abs(produit_scalaire(pnts[1], pnts[2], pnts[0], pnts[3]));
	ps_td = abs(produit_scalaire(pnts[0], pnts[2], pnts[1], pnts[3]));
	/************
		ps et ps1 sont les produits scalaires des cote face a face
		ps_td est le produit scalaire des tendons 
											*****************/
	if ((ps == polygone->segments[0] * polygone->segments[2])
			&& (ps1 == polygone->segments[1] * polygone->segments[3]))
	{
		if ((polygone->segments[0] == polygone->segments[2]) 
				&& (polygone->segments[1] == polygone->segments[3]))
		{
			if (ps_td == 0)
			{    
				if(polygone->tendon[0] == polygone->tendon[1])
					return("Carre."); 
				else
					return ("Losange.");
			}
			else if (polygone->tendon[0] == polygone->tendon[1])
				return ("Rectangle.");
			else
				return("Parallélogramme.");
		}
		else
			return ("XX");
	}
	else if ((ps == polygone->segments[0] * polygone->segments[2])
			|| (ps1 == polygone->segments[1] * polygone->segments[3]))
		return ("Trapeze.");
	else
		return ("XX");
}

