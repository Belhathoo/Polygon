
#include <graphic.h>

t_lst				*create_args(void)
{
	t_lst			*args;

	if (!(args = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	  args->next = NULL;
	return (args);
}

t_point		remplissage(char **splitted)
{
	t_point	data;

	data.x = ft_atod(splitted[0]);
	data.y = ft_atod(splitted[1]);
	return (data);
}


t_lst          *read_file(char *av)
{
    t_lst   *l;
	t_lst	*tt;
	t_lst	*curr;
	int     fd;
    char   *line;
    char   **splitted;

	l = NULL;
	tt = NULL;
	curr = NULL;
    if ((fd = open(av, O_RDONLY)) < 0)
       return (NULL);
	
	curr = create_args();
	while (get_next_line(fd, &line) > 0)
    {
		splitted = ft_strsplit(line, ' ');
		curr->data = remplissage(splitted);
		if (l == NULL)
		{
			l = create_args();
			tt = l;
			l->data = curr->data;
		}
		else
		{
			l->next = create_args();
			l->next->data = curr->data;
			l = l->next;
		}
   }
   l = tt;
   return (l);
}
