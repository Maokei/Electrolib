#include "libpower.h"

float calc_power_r(float volt, float resistance) {
    if(resistance  == 0) {
        return 0;
    }
    return powf(volt,2) / resistance;
}

float calc_power_i(float volt, float current) {
    return volt * current; 
}
