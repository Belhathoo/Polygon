# include "polygone.h"

void swap_lst(t_lst *a, t_lst *b) 
{ 
	t_point temp = a->data;
	float temp2 = a->angle;
	a->angle = b->angle;
	b->angle = temp2;
	a->data = b->data; 
	b->data = temp; 
}

void sort_list(t_lst *head)
{
	t_lst *start = head;
	t_lst *traverse;
	t_lst *min;

	while(start->next)
	{
		min = start;
		traverse = start->next;
		while(traverse)
		{
			/* Find minimum element from array */
			if(min->angle > traverse->angle)
			{
				min = traverse;
			}

			traverse = traverse->next;
		}
		swap_lst(start,min);			// Put minimum element on starting location
		start = start->next;
	}
}