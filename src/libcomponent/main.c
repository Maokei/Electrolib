#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"

int main() {
    /* 3 for now, should be set to numberOfComponents in finished program */
    float resistors[3];
    float orig_res;
    int i;

    orig_res = 8792;

    int count = e_resistance(orig_res, resistors);
    printf("Resistors needed: %d\n", count);

    printf("Targeted resistance in ohm: %g\n", orig_res);
    

    printf("Ersättningsresistancer i E12-serien kopplade i serie:");
    for(i = 0; i < 3; i++) {
        if(resistors[i] != 0) {
            if(i == (count - 1)) {
                printf(" %g", resistors[i]);
            } else {
                printf(" %g,", resistors[i]);
            }
        }
    }
    
    return 0;
}
