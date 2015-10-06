#include <stdio.h>
#include <stdbool.h>

/**
 * Fills res_array with e12 resistors, returns an integer with
 * how many e12 resistors that are needed.
 */
int e_resistance(float orig_resistance, float *res_array) {
    /* Init vars */
    float available_e12[12] = {82.0, 68.0, 56.0, 47.0, 39.0, 33.0, 27.0, 22.0, 18.0, 15.0, 12.0, 10};
    int i;
    int component_count = 0;
    bool is_done = false;

    int multiplier = 1;
    int number = orig_resistance;

    while(number != 0) {
        number = number / 10;
        multiplier *= 10;
    }
    /* Only count zeroes (base ten) */
    multiplier /= 10;
    
    while(!is_done) {
        for(i = 0; i < 12; i++) {
            int resistor_ohm = (available_e12[i] * multiplier);

            if(resistor_ohm <= orig_resistance) {
                res_array[component_count] = resistor_ohm;
                component_count++;
                orig_resistance -= resistor_ohm;
                break;
            }
        }
        
        if(orig_resistance == 0) {
            is_done = true;
        }

        /* If the above for loop does not find a suitable component we need to reduce our multiplier */
        multiplier /= 10;
    }
    


    // Pseudo
    // for e12 series in ohm 
    //   if([] < orig_resistance)
    //     res_array[++] = e12_series[val]
    //     count++
    return component_count;
}

