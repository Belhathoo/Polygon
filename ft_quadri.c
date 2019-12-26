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


/*char   check_forme_quadrilatere(t_polygone *polygone)
{
	t_point *pnts;
	float ps;
	float ps1;
	float ps_td;

	pnts = polygone->pnts;
	ps = abs(produit_scalaire(pnts[0], pnts[1], pnts[2], pnts[3]));
	ps1 = abs(produit_scalaire(pnts[1], pnts[2], pnts[0], pnts[3]));
	ps_td = abs(produit_scalaire(pnts[0], pnts[2], pnts[1], pnts[3]));

	if ((ps == polygone->segments[0] * polygone->segments[2])
			&& (ps1 == polygone->segments[1] * polygone->segments[3]))
	{
		if ((polygone->segments[0] == polygone->segments[2]) 
				&& (polygone->segments[1] == polygone->segments[3]))
		{
			if (ps_td == 0)
			{    
				if(polygone->tendon[0] == polygone->tendon[1])
					return('c'); 
				else
					return ('l');
			}
			else if (polygone->tendon[0] == polygone->tendon[1])
				return ('r');
			else
				return('p');
		}
		else
			return ('x');
	}
	else if ((ps == polygone->segments[0] * polygone->segments[2])
			|| (ps1 == polygone->segments[1] * polygone->segments[3]))
		return ('t');
	else
		return ('x');
}*/