#include <stdio.h>
#include <stdlib.h>
#include "resistance.h"

float* new_array(int);

int main()
{

 int count, i;
 char conn;
 float *array;
 float totalResistance;

 printf("\n-- Electrotest --\n\n");
 
 printf("\nType of connection [S | P]: ");
 scanf ("%s", &conn);
 printf("\nAmount of components: ");
 scanf("%d", &count);
 
 array = new_array(count);

 for(i = 0; i < count; i++)
 {
  printf("\nComponent %d (ohm): ", i+1);
  scanf("%f", &array[i]);
 }
 
 totalResistance = calc_resistance(count, conn, array);
 
 free((void*)array);

 if(totalResistance != -1)
	 printf("\nTotal Resistance is: %6.2f Ohm\n\n", totalResistance);

 return 0;

}

float* new_array(int n)
{
 float *array = (float*)malloc(n*sizeof(int));

 if(array == NULL)
 {
  printf("\nAllocating memory failed!\n"
	 "Exiting...\n");
  exit(1);

 }
 return array;

}
