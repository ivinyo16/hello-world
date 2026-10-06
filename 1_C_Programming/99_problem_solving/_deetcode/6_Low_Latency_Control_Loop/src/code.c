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

float pid_step(float set, float meas);

typedef struct
{
    float Kp;                // Proportional gain coeffecient
    float Ki;                // Integral gain coeffecient
    float Kd;                // Derivative gain coeffecient
    float Kaw;               // Anti-windup gain constant
    float T_C;               // Time constant for derivative filtering
    float T;                 // Time step
    float max;               // Max command
    float min;               // Min command
    float max_rate;          // Max rate of change of the command
    float integral;          // Integral term
    float err_prev;          // Previous error
    float deriv_prev;        // Previous Derivative
    float command_sat_prev;  //Previous saturated command
    float command_prev;      // Previous Command
} pid_t;

pid_t pid = {
    .Kp = 1,
    .Ki = 0.1,
    .Kd = 0.01,
    .Kaw = 0.5,
    .T_C = 0.5,
    .T = 0.01, // 10ms
    .max = 100,
    .min = 0,
    .max_rate = 0.05,
    .integral = 0,
    .err_prev = 0,
    .deriv_prev = 0,
    .command_sat_prev = 0,
    .command_prev = 0,
};

float pid_step(float set, float meas)
{
    float command;
    float command_sat;
    /* Error Calculation */
    float err = set - meas;

    /* proportional term */
    float prop = pid.Kp * err;

    /* integral term */
    pid.integral += pid.Ki * err * pid.T;
    /* with anti windup (back calculation) */
    pid.integral += pid.Kaw * (pid.command_sat_prev - pid.command_prev) * pid.T;

    /* Derivative term using filtered derivative method */
    float deriv_filt = ( err - pid.err_prev + (pid.T_C * pid.deriv_prev) ) / (pid.T + pid.T_C);
    pid.err_prev = err;
    pid.deriv_prev = deriv_filt;

    /* sum 3 terms */
    command = (pid.Kp * err) + pid.integral + (deriv_filt * pid.Kd);

    /* Remember command */
    pid.command_prev = command;

    /* Saturate Command */
    if( command > pid.max )
    {
        command_sat = pid.max;
    }
    else if ( command < pid.min )
    {
        command_sat = pid.min;
    }
    else
    {
        command_sat = command;
    }

    /* Apply rate Limiter */
    if( command_sat > (pid.command_sat_prev + (pid.max_rate*pid.T) ))
    {
        command_sat = pid.command_sat_prev + (pid.max_rate*pid.T);
    }
    else if ( command < (pid.command_sat_prev - (pid.max_rate*pid.T) ))
    {
        command_sat = pid.command_sat_prev - (pid.max_rate*pid.T);
    }
    else
    {
        /* do nothing */
    }
    /* remember saturated command for next step */
    pid.command_sat_prev = command_sat;

    return command_sat;


}




int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;


    return 0;
}
