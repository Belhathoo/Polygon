
#include <graphic.h>

int	parser(t_graphic *p, char *file, int i)
{
	t_lst	*tmp;
	char	**split;
	char	*line;
	int	len;
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1 || read(fd, line, 0) < 0)
		return (-1);
	p->list = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		len = twodimlen(split);
		if (2 != len)
			return (-1);
		if (!(tmp = (struct s_lst *)malloc(sizeof(struct s_lst))))
			return (-1);
		tmp->data.x = ft_atod(split[0]);
		tmp->data.y = ft_atod(split[1]);
		tmp->next = p->list;
		p->list = tmp;
		free(line);
		twodimfree(&split);
		i++;
	}
	close(fd);
	return (i > 1 ? 1 : -1);
}
