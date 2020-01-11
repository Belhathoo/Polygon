#include "polygone.h"

double     max_segments(t_polygone *polygone)
{
    double max;
    int i;
     i = 1;
 max = polygone->segments[0];
  
  while (i < polygone->size)
  {
      if (polygone->segments[i] > max)
        max = polygone->segments[i];
     else
     i++;
  }
  return (max);
}

int     pi2mi(float segments[3], float max)
{
  float i;
  float j;
  float k;
  i = segments[0];
  j = segments[1];
  k = segments[2];
    if((i == max) && (ceil(i*i) == ceil(j*j + k*k)))
      return (1);
    if ((j == max) && (j*j == i*i + k*k))
      return (1);
    if ((k == max) && (k*k == i*i + j*j))
      return (1);
    
return (0);  
    
}

int     type_triangle(t_polygone *polygone)
{
  int i;
  int j;
  int k;

  i = (int)polygone->angles[0];
  j = (int)polygone->angles[1];
  k = (int)polygone->angles[2];

   if(i == j && j == k && k == i)
      return (2);
   if ((i == j && i != k) || (i == k && i != j) ||(i != j && j == k))
      return (1);

    
    return (0);
}

char      *check_forme_triangle(t_polygone *polygone)
{

    float max;
    max = 0;

    max = max_segments(polygone);
    printf("Type(Triangle):");
    if (pi2mi(polygone->segments, max) == 1 && type_triangle(polygone) == 1 )
        printf("\tIsocele Rectangle\n");
    else if (pi2mi(polygone->segments, max) == 1)
        printf("\tRectangle\n" );
    else if (type_triangle(polygone) == 1)
       printf("\tIsocele\n");
    else if (type_triangle(polygone) == 2)
        printf("\tEquilaterale\n");
    else
        printf("\tXX \n");
  return ("XX");
}