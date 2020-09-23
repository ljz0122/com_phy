#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include"pi_calc.h"

int main(int argc,char *argv[]){
    long double pi;
    int N = atoi(argv[2]);
    int method = atoi(argv[1]);
    char * str_pi;
    switch (method)
    {
    case 1 :
        pi = pi_lei_calc(N);
        break;
    case 2 :
        pi = pi_euler_clac(N);
        break;
    case 3 :
        pi = pi_raman_calc(N);
        break;
    default:
        printf("Unrecognized Argument\n");
    }
    printf("Pi=%s \n",gcvt(pi,N+1,&str_pi));
    return 0;
}