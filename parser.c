
#include "polygone.h"

static void		twodimfree(char ***to)
{
	char	**to_free;
	int		i;

	i = 0;
	to_free = *to;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

static int		twodimlen(char **twodim)
{
	int		s;

	s = 0;
	while (*twodim++)
		s++;
	return (s);
}



int	parser(t_lst **p, char *file, int i)
{
	t_lst	*tmp;
	t_lst	*tt;
	char	**split;
	char	*line = NULL;
	int	len;
	int	fd;

	if ((fd = open(file, O_RDONLY)) == -1 || read(fd, line, 0) < 0)
		return (-1);
	*p = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		len = twodimlen(split);
		if (2 != len)
			return (-1);
		if (tmp == NULL)
		{
			tmp = create_args();
			tt = tmp;
			tmp->data.x = ft_atod(split[0]);
			tmp->data.y = ft_atod(split[1]);
			i++;
		}
		else
		{
			tmp->next = create_args();
			tmp->data.x = ft_atod(split[0]);
			tmp->data.y = ft_atod(split[1]);
			tmp = tmp->next;
			free(line);
			twodimfree(&split);
			i++;
		}
	}
	*p = tt;
	close(fd);
	return (i > 1 ? 1 : -1);
}
