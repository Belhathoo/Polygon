
#include <graphic.h>

void	mlx_putpixel(t_graphic *p, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH
			&& y >= 0 && y < HEIGHT)
	{
		p->pixels[y * WIDTH + x] = color;
	}
}

static void			draw_points(t_graphic *p)
{
	t_lst	*l = p->list;
	int x, y, t = 0;
	t_ipoint p1, p2, p_initial;

	if (l != NULL)
		p_initial = (t_ipoint){WIDTH/2 + (int)(l->data.x * 20.0),
				HEIGHT - (HEIGHT/2 + (int)(l->data.y * 20.0))
			};
	while (l != NULL)
	{
		if (++t == 1)
			p1 = (t_ipoint){WIDTH/2 + (int)(l->data.x * 20.0),
				HEIGHT - (HEIGHT/2 + (int)(l->data.y * 20.0))
			};
		if (t > 1)
		{
			p2 = (t_ipoint){WIDTH/2 + (int)(l->data.x * 20.0),
				HEIGHT - (HEIGHT/2 + (int)(l->data.y * 20.0))
			};
			draw_line(p1, p2, p, 0xFF00FC);
			p1 = p2;
		}
		l = l->next;
	}
	draw_line(p_initial, p1, p, 0xFF00FC);
}

int				draw(t_graphic *p)
{
	bzero(p->pixels, WIDTH * HEIGHT * 4);
	draw_line((t_ipoint){WIDTH/2, 0}, (t_ipoint){WIDTH/2, HEIGHT}, p, 0xFFFFFF);
	draw_line((t_ipoint){0, HEIGHT/2}, (t_ipoint){WIDTH, HEIGHT/2}, p, 0xFFFFFF);
	for (int i = 20; i < WIDTH; i+=20) {
		draw_line((t_ipoint){i, HEIGHT/2 - 2}, (t_ipoint){i, HEIGHT/2 + 2}, p, 0xFFFFFF);
	}
	for (int i = 20; i < HEIGHT; i+=20) {
		draw_line((t_ipoint){WIDTH/2 - 2, i}, (t_ipoint){WIDTH/2 + 2, i}, p, 0xFFFFFF);
	}
	draw_points(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (1);
}
