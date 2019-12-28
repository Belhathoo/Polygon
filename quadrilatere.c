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
//	float AB, AC, BC;
	t_point AB;
	t_point CD;

	AB.x = B.x - A.x;
	AB.y = B.y - A.y;
	CD.x = D.x - C.x;
	CD.y = D.y - C.y;

	pr_sca = (AB.x * CD.x) + (AB.y * CD.y);
/*
(void)D;
	AB = pow((B.x - A.x), 2)+ pow((B.y - A.y), 2);
	AC = pow((C.x - A.x), 2)+ pow((C.y - A.y), 2);
	BC = pow((C.x - B.x), 2)+ pow((C.y - B.y), 2);
	pr_sca = (AB +AC - BC) / 2;
*/
	return (pr_sca);


}

/*

   float   calcul_angle(t_point b, t_point a, t_point c)
   {

   float angle;
   float dAB;
   float dAC;
   float pr_sca;
   t_point AB;
   t_point AC;

   AC.x = c.x - a.x;
   AC.y = c.y - a.y;
   AB.x = b.x - a.x;
   AB.y = b.y - a.y;

   pr_sca = (AB.x * AC.x) + (AB.y * AB.y);
   dAB = sqrt(pow(AB.x, 2) + pow(AB.x, 2));
   dAC = sqrt(pow(AC.x, 2) + pow(AC.x, 2));
   angle = acos(pr_sca / (dAB * dAC))
   return(angle * (180 / PI))

   }

   int  check_angle(t_polygone *polygone)
   {
   float tab[3]; 
   float tab1[3];

   tab[0] = polygone->tendon[0];
   tab[1] = polygone->segments[0];
   tab[2] = polygone->segments[1];

   tab1[0] = polygone->tendon[1];
   tab1[1] = polygone->segments[2];
   tab1[2] = polygone->segments[3];
   if ((pi2mi(tab, tab[0]) == 1) && (pi2mi(tab1, tab1[0]) == 1))
   return (1);

   return (0);
   }

   int  check_rectangle(t_polygone *polygone)
   {

   int i;
   int tmp;
   i = 0;
   tmp = 0;

   if (check_angle(polygone) == 1)
   {
   for(i = 0; i < 2;i++)
   {
   if (polygone->segments[i] == polygone->segments[i+2])
   {
   tmp++;
   }
   }
   if (tmp == 2)
   return(1);
   }
   return(0);
   }
   */

float   surface(t_polygone* polygone)
{
	float   s = 0;
	int     i = 0;
	t_point *pnts;

	pnts = polygone->pnts;
	while(i < polygone->size)
	{
		s = s + (pnts[i].x * pnts[i+1].y - pnts[i+1].x * pnts[i].y);
		i++; 
	}
	s = s + (pnts[i].x * pnts[0].y - pnts[0].x * pnts[i].y);
	return (fabs(s / 2));

}
float kachi(t_point A, t_point B, t_point C)
{
    float   AB, AC, BC;
    float   k;

	AB = powf((B.x - A.x), 2)+ powf((B.y - A.y), 2);
	AC = powf((C.x - A.x), 2)+ powf((C.y - A.y), 2);
	BC = powf((C.x - B.x), 2)+ powf((C.y - B.y), 2);

    k = (AB + BC - AC) / (2 * sqrtf(AB) * sqrtf(BC));
    return (k);
}

void get_angle(t_polygone *polygone)
{
    float *angle;
//    float pr_sca;
    int i = 0;
 //   float *t;
    t_point *tab;
    float k;

    tab = polygone->pnts;
//    t = polygone->segments;

    angle = (float *)malloc(sizeof(float) * polygone->size);
    polygone->angles = angle;
	while (i < polygone->size - 2)
	{
//		pr_sca = produit_scalaire(tab[i], tab[i+1], tab[i+1], tab[i+2]); 
        //B=BABC   C=CBCD   D=DCDA   A=ADAB
		k = kachi(tab[i], tab[i+1], tab[i+2]);
        angle[i] = acos(k);

		i++;
	}
//	pr_sca = produit_scalaire(tab[0], tab[i], tab[i], tab[i-1]);
//	angle[i] = acos(pr_sca /(t[i] * t[i - 1]));
//	pr_sca = produit_scalaire(tab[i], tab[0], tab[0], tab[1]);
//	angle[i + 1] = acos(pr_sca /(t[i] * t[0]));
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
		if (t[i] != t[i + 1]) 
			return(0);
		i++;
	}
	if (t[i] != t[0])
		return(0);
	i = 0;

     angle = polygone->angles;

	while (i < polygone->size - 1)
	{
		if (angle[i] != angle[i + 1]) 
			return (0);
		i++;
	}
	if (angle[i] != angle[0])
		return(0);
	return (1);   
}
