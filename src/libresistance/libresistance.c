#include "libresistance.h"

/**
* count - amount of components in the chosen conection type
* conn - connection type, serial or parallel [ S|P ]
* array - holds component values, as many as 'count' variable says
*/

float calc_resistance(int count, char conn, float *array)
{

 /* Initiating variables */
  int i;
  float totalResistance = 0.0;
  float temp = 0.0;

 /* Library will not chrash if a null-pointer is passed. */
 if(array == 0)
 {
  printf("\nNull-pointer exception!\n");
  exit(1);
 }

 /* We need at least one component, or we do not have a connection! */
 if(count <= 0)
 {
  printf("\nNeed at least 1 component!\n");
  return -1;

 }

 /* Check that all supplied values are > 0 (can't have negative resistance). */
 
 for(i = 0; i < count; i++) {
	if(array[i] < 0.0) {
	 printf("\nNegative resistance is not valid!\n");
	 return -1;
 	}

 }

 /* Compute total resistance based on chosen connection type. */
 if(conn == 'P' || conn == 'p')
 {
	for(i = 0; i < count; i++)
	{
		if(array[i] == 0.0)
		{
			totalResistance = 0;
			return totalResistance;
		}

		temp += 1/array[i];
	}
	
	totalResistance = 1/temp;
 }

 else if(conn == 'S' || conn == 's')
 { 
	for(i = 0; i < count; i++)
	{
		totalResistance += array[i];
	} 
 }
 
 /* Only serial or parallel connections are supprted. */
 else
 {
	printf("\nUnsupported connection type!\n");
	return -1;
 }

  return totalResistance;

}
