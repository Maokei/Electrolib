#include <stdio.h>
#include "libcomponent.h"

int main() {
    /* 3 for now, should be set to numberOfComponents in finished program */
    float resistors[3];
    int i;

    int count = e_resistance(1398, resistors);
    printf("Resistors needed: %d\n", count);

    for(i = 0; i < count; i++) {
        printf("Resistor %d needed is e12:%g\n", (i + 1), resistors[i]);
    }
    
    return 0;
}
