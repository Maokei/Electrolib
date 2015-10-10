#include <stdio.h>
#include <stdlib.h>

// count - antal komponenter
// conn - kopplingstyp, seriell eller parallell [ S|P ]
// array - array av komponentvärden, lika stor som count

float calc_resistance(int count, char conn, float *array)
{

  int i;
  float totalResistance = 0.0;
  float temp = 0.0;

 if(array == 0)
 {
  printf("\nNull-pointer exeption!\n");
  exit(1);
 }

 if(count <= 0)
 {
  printf("\nNeed at least 1 component!\n");
  return -1;

 }

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
 else
 {
	printf("\nUnsupported connection type!\n");
	return -1;
 }

  return totalResistance;

}
