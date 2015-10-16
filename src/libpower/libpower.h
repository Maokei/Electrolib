/**
 * @author Rickard Johansson
 * @file libpower.h
 * @brief libpower is used to calculate the power(P) current heating effect.
 * */

#include <math.h>

#ifndef LIBPOWER_H
#define LIBPOWER_H

/**
 * @name calc_power_r
 * @param float as curcuit voltage.
 * @param float as curcuit resistance.
 * @return flaot curcuit power.
 * */
extern float calc_power_r(float volt, float resistance);

/**
 * @name calc_power_i
 * @param float as curcuit voltage.
 * @param float as circuit current.
 * @return float circuit power.
 * */
extern float calc_power_i(float volt, float current);

#endif //LIBPOWER_H
