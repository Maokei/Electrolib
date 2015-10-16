/**
 * @file electrotest.cc
 * @authors Rickard Johansson, Niklas Andersson, Sanel Merdovic
 * @brief Test application for the following libraries libresistance.so, libpower.so and libcomponent.so
 * */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    float resistance = 0;
    float effect = 0;
    

    float volt = 0;
    char coupling = '';
    int num_components = 0;
    //input
    printf("Ange spänningskälla i V: ");
    scanf("%f", &volt);
    getchar();
    printf("Ange koppling [S | P]: ");
    scanf(" %c", &coupling);
    getchar();
    printf("Antal komponenter: ");
    scanf("%d", num_component);
    getchar();
    //libresistance
    
    //libpower
    effect = calc_power_r(volt, resistance);
    //libcomponent (behöver orig_res från libresistance)
    float *r_pointer;
    float resistors[3];
    r_pointer = resistors;

    float orig_res = 957;
    float newtotal = 0.0f;
    int i;
    
    int count = e_resistance(orig_res, r_pointer);
    
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
    printf("Ny ersättningsresistans: %g", newtotal);

    //result are printed out
    printf("Ersättningsresistans: %d ohm\n", resistance);
    printf("Effekt: %d W\n", effect);
    printf("Ersättningsresistanser i E12-serien kopplade i serie: ");

    return 0;
}
