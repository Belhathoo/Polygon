#ifndef GRAPHIC_H
# define GRAPHIC_H

# define WIDTH 800
# define HEIGHT 800

# define ILK_KEY_LEFT 123
# define ILK_KEY_RIGHT 124
# define ILK_KEY_UP 126
# define ILK_KEY_DOWN 125
# define ILK_KEY_ESC 53

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <strings.h>
# include <sys/stat.h>
# include <fcntl.h>
#include "libft/libft.h"

typedef struct s_point
{
   float x;
   float y;
}            t_point;

typedef struct s_ipoint
{
   int x;
   int y;
}            t_ipoint;

typedef struct s_lst
{
    t_point        data;
    float	angle;
    struct s_lst *next;
}                 t_lst;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			i;
	int			xinc;
	int			yinc;
	int			cumul;
	int			x;
	int			y;
}				t_line;

typedef struct		s_graphic
{
	t_lst			*list;
	void			*win;
	void			*img;
	void			*mlx;
	int				*pixels;
	int				bpp;
	int				size_line;
	int				endian;
}					t_graphic;
void calcul_angle(t_lst *list);
void sort_list(t_lst *start);
void    draw_line(t_ipoint p1, t_ipoint p2, t_graphic *p, int color);
void    mlx_putpixel(t_graphic *p, int x, int y, int color);

double		ft_atod(char *c);
void	twodimfree(char ***to);
int	twodimlen(char **twodim);
int	parser(t_graphic *p, char *file, int i);
t_lst          *read_file(char *av);

int					prog_close(t_graphic *p);
int					keys(int k, t_graphic *p);
int					draw(t_graphic *p);

#endif
