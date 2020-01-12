
#include <graphic.h>

int		twodimlen(char **twodim)
{
	int		s;

	s = 0;
	while (*twodim++)
		s++;
	return (s);
}
