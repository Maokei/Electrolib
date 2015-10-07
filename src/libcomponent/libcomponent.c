#include <stdio.h>
#include <stdbool.h>

/**
 * Fills res_array with e12 resistors, returns an integer with
 * how many e12 resistors that are needed to match the original resistance.a
 * return int
 */
int e_resistance(float orig_resistance, float *res_array) {
    /* Init vars */
    int available_e12[12] = { 82, 68, 56, 47, 39, 33, 27, 22, 18, 15, 12, 10 };
    int i; 
    int component_count = 0; /**< Number of filled components */
    bool is_done = false; /**< Boolean switch for the while loop */

    int multiplier = 1;
    int number = orig_resistance;
    
    /* Count number of digits */
    while(number != 0) {
        number = number / 10;
        multiplier *= 10;
    }
    /* Only count zeroes (base ten) */
    multiplier /= 10;
    
    while(!is_done) {
        for(i = 0; i < 12; i++) {
            float resistor_ohm = (available_e12[i] * multiplier);

            if(resistor_ohm <= orig_resistance) {
                res_array[component_count] = resistor_ohm;
                component_count++;
                orig_resistance -= resistor_ohm;
                break;
            }
        }
        
        if(orig_resistance == 0 || component_count == 3) {
            is_done = true;
        }

        /* If the above for loop does not find a suitable component we need to reduce our multiplier */
        multiplier /= 10;
    }
    
    /* Fill slots we don't need with zeroes */
    if(component_count < 3) {

        for(i = component_count; i < 3; i++) {
            res_array[i] = 0.0;
        }
    }

    return component_count;
}

