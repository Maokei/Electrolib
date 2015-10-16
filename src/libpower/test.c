/**
 * @author Rickard Johansson
 * @file test.c
 * @brief Small test application for libpower.so
 * */
#include <stdio.h>
#include "libpower.h"

int main() {
    float x = 2;
    float xx = 5;
    float test = 0;
    test = calc_power_r(x,xx);
    printf("libpower.so test calculations.");
    printf("Calculating power with volt 2 and resistance 5:  %f\n", test);
    xx = 4;
    test = calc_power_i(x, xx);
    printf("Calculating power with volt 2 and current 4: %f\n", test);
    return 0;
}
