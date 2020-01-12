#include <graphic.h>

void	ft_draw_horiz(t_line *l, t_ipoint p1, t_ipoint p2, t_graphic *p, int color)
{
	l->cumul = l->dx / 2;
	l->i = 0;
	while (++l->i <= l->dx)
	{
		l->x += l->xinc;
		l->cumul += l->dy;
		if (l->cumul >= l->dx)
		{
			l->cumul -= l->dx;
			l->y += l->yinc;
		}
		mlx_putpixel(p, l->x, l->y, color);
	}
}

void	ft_draw_verti(t_line *l, t_ipoint p1, t_ipoint p2, t_graphic *p, int color)
{
	l->cumul = l->dy / 2;
	l->i = 0;
	while (++l->i <= l->dy)
	{
		l->y += l->yinc;
		l->cumul += l->dx;
		if (l->cumul >= l->dy)
		{
			l->cumul -= l->dy;
			l->x += l->xinc;
		}
		mlx_putpixel(p, l->x, l->y, color);
	}
}

void	draw_line(t_ipoint p1, t_ipoint p2, t_graphic *p, int color)
{
	t_line	*l;

	l = (struct s_line *)malloc(sizeof(struct s_line));
	l->x = p1.x;
	l->y = p1.y;
	l->dx = p2.x - p1.x;
	l->dy = p2.y - p1.y;
	l->xinc = (l->dx > 0) ? 1 : -1;
	l->yinc = (l->dy > 0) ? 1 : -1;
	l->dx = abs(l->dx);
	l->dy = abs(l->dy);
	mlx_putpixel(p, l->x, l->y, color);
	if (l->dx > l->dy)
		ft_draw_horiz(l, p1, p2, p, color);
	else
		ft_draw_verti(l, p1, p2, p, color);
	free(l);
}
