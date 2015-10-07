#include <stdio.h>
#include "libpower.h"

int main() {
    float x = 2;
    float xx = 2;
    float test = 0;
    test = calc_power_r(x,xx);
    printf("Hello world i'm alive! %f\n", test);
    return 0;
}
