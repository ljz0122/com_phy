#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<mpfr.h>
#include<gmp.h>

#include"custom_math.h"
#include"pi_calc.h"

void pi_lei_calc(mpfr_t pi,unsigned long int lim){            
    mpfr_t quater_pi,sign,limit,div,div_before,temp;
    mpfr_t mpfr_1,mpfr_2,mpfr_i,mpfr_minus;
    mpfr_t n;
    mpfr_prec_t p=512;  //lim*4+16;
    mpz_t i;
    mpfr_printf("prec is %Pu\n",p);
    mpz_init(i);
    mpfr_inits2(p,quater_pi,sign,limit,div,div_before,NULL);
    mpfr_init2(n,p);
    mpfr_init2(mpfr_i,p);
    mpfr_init_set_si(mpfr_1,1,MPFR_RNDN);
    mpfr_init_set_si(mpfr_2,2,MPFR_RNDN);
    mpfr_init_set_si(mpfr_minus,-1,MPFR_RNDN);
    mpfr_ui_pow_ui(limit,10,lim,MPFR_RNDN);
    mpfr_set(sign,limit,MPFR_RNDN);
    mpfr_si_div(limit,1,limit,MPFR_RNDN);
    mpfr_printf("limit is %.10Rf\n",limit);
    for(mpz_set_d(i,0);mpfr_cmp(sign,limit)>0;mpz_add_ui(i,i,1)){
        //sign = (1/(2*i+1))+(1/(2*i-1));
        mpfr_set_z(mpfr_i,i,MPFR_RNDN);
        mpfr_set(div_before,div,MPFR_RNDN);
        mpfr_fms(div,mpfr_2,mpfr_i,mpfr_1,MPFR_RNDN);
        mpfr_si_div(div,-1,div,MPFR_RNDN);
        mpfr_pow_z(n,mpfr_minus,i,MPFR_RNDN);
        mpfr_mul(div,n,div,MPFR_RNDN);
        mpfr_add(quater_pi,quater_pi,div,MPFR_RNDN);
        mpfr_printf("quater_pi is %.10Rf\n",quater_pi);
        mpfr_sub(sign,div_before,div,MPFR_RNDN);
        mpfr_abs(sign,sign,MPFR_RNDN);
        mpfr_printf("sign is %.10Rf\n",sign);
        //quater_pi=quater_pi+powl((-1),i)*1/(2*i+1);
    }
    mpfr_mul_ui(pi,quater_pi,4,MPFR_RNDN);
    mpfr_clears(quater_pi,sign,limit,div,div_before,n,NULL);
    mpfr_clears(mpfr_1,mpfr_2,mpfr_i,mpfr_minus,NULL);
    gmp_printf("%Zd. ",i);
    mpz_clear(i);
}

/*void pi_euler_clac(mpfr_t pi,unsigned long int lim){
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

void pi_raman_calc(mpfr_t pi,unsigned long int lim){
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
}*/

int main(int argc,char *argv[]){
    int N = atoi(argv[2]);
    int method = atoi(argv[1]);
    mpfr_t pi;
    mpfr_init(pi);
    pi_lei_calc(pi,N);
    mpfr_printf("Pi=%.10Rf\n",pi);
    mpfr_clear(pi);
    return 0;
}