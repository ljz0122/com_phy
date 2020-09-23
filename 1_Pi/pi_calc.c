#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>
#include<gmp.h>

#include"custom_math.h"
#include"pi_calc.h"

void pi_lei_calc(mpfr_t pi,mpfr_t lim){            
    mpfr_t quater_pi,sign;
    mpfr_inits2(512,quater_pi,sign);
    int i = 0;
    for(int i = 0;mpfr_cmp(sign,lim)<0;i++){
        
        sign = (1/(2*i+1))+(1/(2*i-1));
        quater_pi=quater_pi+powl((-1),i)*1/(2*i+1);
        if((1/sign)>powl(10,lim))
    }
    printf("sign=%.12Lf num=%d\n",sign,i);
    return quater_pi*4;
}

long double pi_euler_clac(int lim){
    long double euler_pi=0;
    int i;
    for(i = 1;1;i++){
        euler_pi=euler_pi+1/powl(i,2);
        if((1/(sqrtl((euler_pi=euler_pi+1/pow(i,2))*6)-sqrt(euler_pi*6)))>powl(10,lim)){
            break;
        }
    }
    printf("num=%d ",i);
    return sqrtl(euler_pi*6);
}

long double pi_raman_calc(int lim){
    long double pi_1 = 0;
    int i;
    long double sign;   
    for(i = 0 ;1;i++){
        sign = ((pi_1+(fact(4*i)*(1103+26390*i))/(powl(fact(i),4)*powl(396,4*i)))*sqrtl(8)/(99*99))-(pi_1*sqrtl(8)/(99*99));
        pi_1=pi_1+(fact(4*i)*(1103+26390*i))/(powl(fact(i),4)*pow(396,4*i));
        if((1/sign)>powl(10,lim)){
            break;
        }
    }
    printf("num=%d ",i);
    pi_1=pi_1*sqrtl(8)/(99*99);
    return 1/pi_1;
}