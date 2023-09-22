#include <stdio.h>
#include <stdlib.h>
double sumatoria(double num);
int main(){
    double num,resultado;
    printf("Dame la cantidad de sumas: \n");
    scanf("%lf",&num);
    resultado = sumatoria(num);
    printf("Sumatoria da: %lf",resultado);
    return 0;
}
double sumatoria(double num){
    if(num==0){
        return 0;
    }
    else if(num==1){
        return 1;
    }
    return(1/(3*num))+sumatoria(num-1);
}
