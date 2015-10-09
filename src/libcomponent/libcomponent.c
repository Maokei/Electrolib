#include <math.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Fills res_array with e12 resistors, returns an integer with
 * how many e12 resistors that are needed to match the original resistance
 * return int
 */
int e_resistance(float orig_resistance, float *res_array) {
    /* Init vars */
    float available_e12[12] = { 8.2, 6.8, 5.6, 4.7, 3.9, 3.3, 2.7, 2.2, 1.8, 1.5, 1.2, 1.0 };
    bool is_done = false; /**< Boolean switch for the while loop */

    int component_count = 0; /**< Number of filled components */
    int zeroes = log10(orig_resistance);
    int multiplier = pow(10, zeroes);
    int current_iteration = 0;
    int i;

    while(!is_done) {
        for(i = 0; i < 12; i++) {
            float resistor_ohm = (available_e12[i] * multiplier);
            
            if(resistor_ohm <= orig_resistance) {
                res_array[component_count] = resistor_ohm;
                orig_resistance -= resistor_ohm;
                component_count++;
                break;
            }
        }
        
        /* Smallest possible e12 resistor here is 1, also finish while loop if we have 3 resistors */
        if(orig_resistance < 1 || component_count == 3) {
            is_done = true;
        }
        
        /* Try each level of multiplication max 3 times */
        current_iteration++;
        if(current_iteration == 3) {
            /* Go to next multiplication level and reset the iteration count */
            multiplier /= 10;
            current_iteration = 0;
        }    
    }
    
    /* Fill slots we don't need with zeroes */
    if(component_count < 3) {
        for(i = component_count; i < 3; i++) {
            res_array[i] = 0.0f;
        }
    }

    return component_count;
}

