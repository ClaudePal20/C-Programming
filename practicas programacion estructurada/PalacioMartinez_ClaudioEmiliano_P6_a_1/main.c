#include <stdio.h>
#include <stdlib.h>
float suma(float a, float b);
float resta(float a, float b);
float divis(float a, float b);
float mult(float a, float b);
int main()
{
    float a,b,resultado;
    int opc;
    printf("Elige una operacion: \n1. Suma \n2. Resta \n3. Division \n4. Multiplicacion");
    scanf("%d",&opc);
    printf("Dame dos numeros\n");
    scanf("%f %f",&a,&b);
    switch(opc){
        case 1:
            resultado = suma(a,b);
            break;
        case 2:
            resultado = resta(a,b);
            break;
        case 3:
            resultado = divis(a,b);
            break;
        case 4:
            resultado = mult(a,b);
            break;
        default:
            printf("\nOpcion no existente.");
    }
    printf("\nEl resultado de la operacion es: %f",resultado);
    return 0;
}
float resta(float a, float b){
    float res;
    res = a-b;
    return res;
}
float suma(float a, float b){
    float res;
    res = a+b;
    return res;
}
float mult (float a, float b){
    float res;
    res = a*b;
    return res;
}
float divis(float a, float b){
    float res;
    res = a/b;
    return res;
}
