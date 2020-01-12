
#include <graphic.h>

int		keys(int key, t_graphic *p)
{
	t_lst *l = p->list;
	
	if (key == ILK_KEY_ESC)
		prog_close(p);
	if (key == ILK_KEY_UP)
		while (l != NULL){
			l->data.y += 0.1;
			l = l->next;
		}
	if (key == ILK_KEY_DOWN)
		while (l != NULL){
			l->data.y -= 0.1;
			l = l->next;
		}
	if (key == ILK_KEY_LEFT)
		while (l != NULL){
			l->data.x -= 0.1;
			l = l->next;
		}
	if (key == ILK_KEY_RIGHT)
		while (l != NULL){
			l->data.x += 0.1;
			l = l->next;
		}
	if (key == ILK_KEY_UP || key == ILK_KEY_DOWN || key == ILK_KEY_LEFT || key == ILK_KEY_RIGHT)
		draw(p);
	return (1);
}
