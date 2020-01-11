#include "polygone.h"

void    calcul_tendon(t_polygone *polygone, t_lst *l)
{
	if (polygone->size < 4)
		return;
	if (!(polygone->tendon = (float *)malloc(sizeof(float) * 2)))
		return;
	polygone->tendon[0] = sqrt(pow((l->data.x - l->next->next->data.x), 2)
			+ pow((l->data.y - l->next->next->data.y), 2));
	l = l->next;
	polygone->tendon[1] = sqrt(pow((l->data.x - l->next->next->data.x), 2)
			+ pow((l->data.y - l->next->next->data.y), 2));

}           

int  produit_scalaire(t_point A, t_point B, t_point C, t_point D)
{
	
	float pr_sca;
	t_point AB;
	t_point CD;

	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	CD.x = D.x - C.x;
	CD.y = D.y - C.y;

	pr_sca = (AB.x * CD.x) + (AB.y * CD.y);
	return (pr_sca);


}

float   surface(t_polygone* polygone)
{
	float   s = 0;
	int     i = 0;
	t_point *pnts;

	pnts = polygone->pnts;
	while(i < polygone->size - 1)
	{
		s = s + (pnts[i].x * pnts[i+1].y - pnts[i+1].x * pnts[i].y);
		i++; 
	}
	s = s + (pnts[i].x * pnts[0].y - pnts[0].x * pnts[i].y);
	return (fabs(s / 2));
}

float	kachi(t_point A, t_point B, t_point C)
{
    float   AB, AC, BC;
    float   k;

	AB = powf((B.x - A.x), 2)+ powf((B.y - A.y), 2);
	AC = powf((C.x - A.x), 2)+ powf((C.y - A.y), 2);
	BC = powf((C.x - B.x), 2)+ powf((C.y - B.y), 2);

    k = (AB + BC - AC) / (2 * sqrtf(AB) * sqrtf(BC));
    return (k);
}

void	get_angle(t_polygone *polygone)
{
    float *angle;
    int i = 0;
    t_point *tab;
    float k;

    tab = polygone->pnts;

    angle = (float *)malloc(sizeof(float) * polygone->size);
    polygone->angles = angle;
	while (i < polygone->size - 2)
	{
		k = kachi(tab[i], tab[i+1], tab[i+2]);
        angle[i] = acos(k);

		i++;
    }
	k = kachi(tab[i], tab[i+1], tab[0]);
    angle[i] = acos(k);
	k = kachi(tab[i+1], tab[0], tab[1]);
    angle[i + 1] = acos(k);
}


int   check_regulier(t_polygone *polygone)
{
	int i = 0;
	float  *angle;
    float *t;

	t = polygone->segments;
	while (i < polygone->size - 1)
	{
		if ((int)t[i] != (int)t[i + 1]) 
			return(0);
		i++;
	}
	if ((int)t[i] != (int)t[0])
		return(0);
	i = 0;

     angle = polygone->angles;

	while (i < polygone->size - 1)
	{
		if ((int)angle[i] != (int)angle[i + 1]) 
			return (0);
		i++;
	}
	if ((int)angle[i] != (int)angle[0])
		return(0);
	return (1);   
}
