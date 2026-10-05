/**
 * @file template.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-06-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/* Standard libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdatomic.h>
#include <stdint.h>

#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(...) do{ fprintf( stderr, __VA_ARGS__ ); } while( false )
#else
#define DEBUG_PRINT(...) do{ } while ( false )
#endif

#ifndef PID_KP
#define PID_KP 1.0f
#endif
#ifndef PID_KI
#define PID_KI 0.1f
#endif
#ifndef PID_KD
#define PID_KD 0.01f
#endif
#ifndef PID_DT
#define PID_DT 0.001f
#endif
#ifndef PID_OUTPUT_MIN
#define PID_OUTPUT_MIN -100.0f
#endif
#ifndef PID_OUTPUT_MAX
#define PID_OUTPUT_MAX 100.0f
#endif

float pid(float set, float meas)
{
    static float integral = 0.0f;
    static float previous_error = 0.0f;
    static bool initialized = false;

    const float error = set - meas;
    const float derivative = initialized
        ? (error - previous_error) / PID_DT
        : 0.0f;
    const float candidate_integral = integral + error * PID_DT;
    const float candidate_output = PID_KP * error
        + PID_KI * candidate_integral
        + PID_KD * derivative;
    const bool above_max = candidate_output > PID_OUTPUT_MAX;
    const bool below_min = candidate_output < PID_OUTPUT_MIN;

    if ((!above_max && !below_min)
        || (above_max && PID_KI * error < 0.0f)
        || (below_min && PID_KI * error > 0.0f)) {
        integral = candidate_integral;
    }

    float output = PID_KP * error + PID_KI * integral + PID_KD * derivative;
    if (output > PID_OUTPUT_MAX) {
        output = PID_OUTPUT_MAX;
    } else if (output < PID_OUTPUT_MIN) {
        output = PID_OUTPUT_MIN;
    }

    previous_error = error;
    initialized = true;
    return output;
}




int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;


    return 0;
}
