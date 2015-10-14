/**
 * @file electrotest.cc
 * @authors Rickard Johansson, Niklas Andersson, Sanel Merdovic
 * @brief Test application for the following libraries libresistance.so, libpower.so and libcomponent.so
 * */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    float current = 0;
    char coupling = '';
    int num_components = 0;
    //input
    printf("Ange spänningskälla i V: ");
    scanf("%f", &current);
    getchar();
    printf("Ange koppling [S | P]: ");
    scanf(" %c", &coupling);
    getchar();
    printf("Antal komponenter: ");
    scanf("%d", num_component);
    getchar();
    //libresistance
    
    //libpower
    
    //libcomponent

    return 0;
}
