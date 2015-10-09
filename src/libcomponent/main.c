#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"

int main() {
    float *r_pointer;
    float resistors[3];

    r_pointer = resistors;

    float orig_res = 0.0f;
    float newtotal = 0.0f;
    int i;
    

    printf("Ange en resistans: ");
    scanf("%f", &orig_res);
    
    int count = e_resistance(orig_res, r_pointer);
    
    printf("---- Resultat ----\n");
    printf("Resistorer som behövs: %d\n", count);
    printf("Den efterfrågade resistansen: %g\n", orig_res);

    printf("Ersättningsresistanser i E12-serien kopplade i serie:");
    for(i = 0; i < 3; i++) {
        // If array holds a resistor, print it. Print with comma if not last element
        if(resistors[i] > 0) {
            newtotal += resistors[i];
            if(i == (count - 1)) {
                printf(" %g\n", resistors[i]);
            } else {
                printf(" %g,", resistors[i]);
            }
        }
    }

    printf("Ny resistans: %g", newtotal);
    
    return 0;
}
