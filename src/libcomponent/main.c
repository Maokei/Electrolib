#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"

int main() {
    float resistors[3];
    float orig_res = 0.0;
    int i;
    

    printf("Ange en resistans: ");
    scanf("%f", &orig_res);
    
    int count = e_resistance(orig_res, resistors);
    
    printf("---- Resultat ----\n");
    printf("Resistorer som behövs: %d\n", count);
    printf("Den efterfrågade resistansen: %g\n", orig_res);

    printf("Ersättningsresistanser i E12-serien kopplade i serie:");
    for(i = 0; i < 3; i++) {
        // If array holds a resistor, print it. Print with comma if not last element
        if(resistors[i] > 0.0) {
            if(i == (count - 1)) {
                printf(" %g", resistors[i]);
            } else {
                printf(" %g,", resistors[i]);
            }
        }
    }
    
    return 0;
}
