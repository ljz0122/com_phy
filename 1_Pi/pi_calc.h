#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>
#include<gmp.h>

#ifndef _PI_CALC_H
#define _PI_CALC_H

#endif

long double pi_lei_calc(long double pi,int lim);

long double pi_euler_calc(long double pi,int lim);

void pi_raman_calc(mpfr_t pi,int lim);