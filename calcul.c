

#include "polygone.h"

int     nbr_points(t_lst **l)
{
    int nbr;
    t_lst *cur;
    nbr = 0;
    cur = *l;

    while (cur)
    {
        nbr++;
        cur = cur->next;
    }
    return (nbr);
}

void     calcul_module(t_lst *l, t_polygone *polygone)
{
    t_lst *tt;
    
    int  i;
    i = 0;

    tt = l;
    if(!(polygone->segments = (float *)malloc(sizeof (float) * polygone->size)))
        return;
    while (i < polygone->size - 1)
    {
        polygone->segments[i] = sqrt(pow((l->data.x - l->next->data.x), 2)
                                    + pow((l->data.y - l->next->data.y), 2));
          i++;
        l = l->next;
    
    }
    polygone->segments[i] = sqrt(pow((tt->data.x - l->data.x), 2) + \
        pow((tt->data.y - l->data.y), 2));
}

double         perimetre(t_polygone *polygone)
{
    double p;
    int i;
    i = 0;
    p = 0;
    while (i < polygone->size)
    {
        p = p + polygone->segments[i];
        i++;
    }
    return (p);
}
