#include <graphic.h>

float distance(t_point a, t_point b)
{
	t_point ab;

	ab.x = b.x - a.x;
	ab.y = b.y - a.y;
	return (sqrt(ab.x * ab.x + ab.y * ab.y));
}

void calcul_angle(t_lst *l) {
    float minX = l->data.x;
    float maxX = l->data.x;
    float minY = l->data.y;
    float maxY = l->data.y;
    t_lst *list = l->next;

    while  (list != NULL) {
        if (list->data.x < minX) minX = list->data.x;
        if (list->data.x > maxX) maxX = list->data.x;
        if (list->data.y < minY) minY = list->data.y;
        if (list->data.y > maxY) maxY = list->data.y;
	list = list->next;
    }
    t_point center = (t_point){minX + (maxX - minX) / 2,minY + (maxY - minY) / 2};
    list = l;
    while (list != NULL) {
        list->angle = acos((list->data.x - center.x) / distance(center, list->data));

        if (list->data.y > center.y) {
            list->angle = M_PI + M_PI - list->angle;
        }
	list = list->next;
    }
}
