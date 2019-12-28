# ifndef POLYGONE_H
# define POLYGONE_H

# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include <sys/stat.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

#define PI 3.1415926535897932384626




typedef struct s_point
{
   float x;
   float y;    
}            t_point;

typedef struct s_lst
{
    t_point        data;
    float           angle;
    struct s_lst *next;
}                 t_lst;

typedef struct s_polygone
{
    int size;
    char type;

    float *segments;
    float *tendon;
    t_point *pnts;
    float *angles;




}              t_polygone;

double		ft_atod(char *str);
int         nbr_points(t_lst **l);
void        calcul_module(t_lst *l, t_polygone *polygone);
double      perimetre(t_polygone *polygone);
t_lst		*create_args(void);
t_point		remplissage(char **splitted);
t_lst       *read_file(char *av);
double		ft_atod(char *str);
int        check_forme_triangle(t_polygone *polygone);
double     max_segments(t_polygone *polygone);
int        pi2mi(float seg[3], float max);
void      calcul_tendon(t_polygone *polygone, t_lst *l);
int    check_caree(t_polygone *polygone);

char    check_forme_quadrilatere(t_polygone *polygone);

int  produit_scalaire(t_point p0, t_point p1, t_point p3, t_point p2);


float   surface(t_polygone* polygone);
t_point     *ft_points(int size, t_lst *l);
int    check_regulier(t_polygone *polygone);
void   get_angle(t_polygone *polygone);

void    calcul_angle(t_lst *l);
void    sort_list(t_lst *lst);  


#endif
