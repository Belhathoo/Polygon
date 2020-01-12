
#include <graphic.h>

int				prog_close(t_graphic *p)
{
	mlx_destroy_image(p->mlx, p->img);
	mlx_destroy_window(p->mlx, p->win);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

static void		init(t_graphic *p, char *title)
{
	//if ((p->list = read_file(title)) == NULL)
	//	exit(EXIT_FAILURE);
	if ((parser(p, title, 0) == -1) && write(1, "error: parsing\n", 15))
		exit(EXIT_FAILURE);
	calcul_angle(p->list);
	sort_list(p->list);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, title);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	p->pixels = (int *)mlx_get_data_addr(p->img, &p->bpp, &p->size_line, &p->endian);
}

int				main(int argc, char **argv)
{
	t_graphic p;

	if (argc != 2 && write(1, "usage: ./polygon file\n", 22))
		return (EXIT_FAILURE);
	init(&p, argv[1]);
	draw(&p);
	mlx_hook(p.win, 17, (1L << 17), prog_close, &p);
	mlx_hook(p.win, 2, 0, keys, &p);
	mlx_loop(p.mlx);
	return (EXIT_SUCCESS);
}
