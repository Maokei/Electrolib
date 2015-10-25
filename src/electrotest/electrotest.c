/**
 * @file electrotest.cc
 * @authors Rickard Johansson, Niklas Andersson, Sanel Merdovic
 * @brief Test application for the following libraries libresistance.so, libpower.so and libcomponent.so
 * @brief 2015-10-24
 * *       ▄▄▄▀▀▀▄▄███▄
 * ░░░░░▄▀▀░░░░░░░▐░▀██▌
 * ░░░▄▀░░░░▄▄███░▌▀▀░▀█
 * ░░▄█░░▄▀▀▒▒▒▒▒▄▐░░░░█▌
 * ░▐█▀▄▀▄▄▄▄▀▀▀▀▌░░░░░▐█▄
 * ░▌▄▄▀▀░░░░░░░░▌░░░░▄███████▄
 * ░░░░░░░░░░░░░▐░░░░▐███████████▄
 * ░le code░░░░░░▐░░░░▐█████████████▄
 * ░░░░tucan░░░░░░▀▄░░░▐██████████████▄
 * ░░░░░░has░░░░░░░░▀▄▄████████████████▄
 * ░░░░░arrived░░░░░░░░░░░░█▀██████
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../libresistance/libresistance.h"
#include "../libcomponent/libcomponent.h"
#include "../libpower/libpower.h"


float* new_array(int);

int main(int argc, char *argv[]) {
    float *r_pointer;
    float resistors[3];
    float new_resistance = 0.0f;
    float effect = 0;
    float orig_res;    
    float volt = 0;
    char coupling;
    int num_components = 0;
    float *array;
    int count;
    int i;

    printf("\n-- Electrotest --\n\n");

    // User input
    printf("Enter the voltage in V: ");
    scanf("%f", &volt);
    getchar();
    printf("Enter the coupling [S | P]: ");
    scanf("%c", &coupling);
    getchar();
    printf("Enter the number of components: ");
    scanf("%d", &num_components);
    getchar();
    
    //libresistance
   
    array = new_array(num_components);
   
    for(i = 0; i < num_components; i++) {
        printf("Component %d (ohm): ", i+1);
        scanf("%f", &array[i]);
        getchar();
    }

    orig_res = calc_resistance(num_components, coupling, array);
    
    free((void*)array);

    if(orig_res != -1) {
        printf("Total Resistance is: %6.2f Ohm\n", orig_res);
    }
    else {
	printf("Bad input values! Exiting...\n");
	exit(1);
}

    //libpower
    effect = calc_power_r(volt, orig_res);
    
    //libcomponent
    r_pointer = resistors;

    count = e_resistance(orig_res, r_pointer);
    
    //results
    //print effect
    effect = ceilf(effect * 100) / 100; //round up 2 dec points
    printf("\nEffect: %f W\n", effect);

    printf("Resistors needed: %d\n", count);

    printf("E12 Resistors connected in a series: ");

    for(i = 0; i < 3; i++) {
        // If array holds a resistor, print it. Print with comma if not last element
        if(resistors[i] > 0) {
            new_resistance += resistors[i];
            if(i == (count - 1)) {
                printf(" %g\n", resistors[i]);
            } else {
                printf(" %g,", resistors[i]);
            }
        }
    }
    printf("New resistance: %g\n", new_resistance);

    return 0;
}


float* new_array(int n) {
    float *array = (float*)malloc(n*sizeof(float));

    if(array == NULL) {
        printf("\nAllocating memory failed!\n"
	    "Exiting...\n");
        exit(1);
    }
    return array;
}
