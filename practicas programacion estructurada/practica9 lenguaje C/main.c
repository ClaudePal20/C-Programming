#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void divisores(int*num);
void vocalesconsonantes(char array[]);
void flotantes(float*num,float*num2,float*num3);
int main(){
    int numero,opc;
    float num,num2,num3;
    char arr[]="conteo de vocales y consonantes";
    printf("Elige funcion: \n1. Divisores de un numero.\n2. Conteo de vocales y consonantes de una cadena.\n3. El menor de 3 numeros flotantes.\n");
    scanf("%d",&opc);
    switch(opc){
        case 1:
            printf("Dame el numero.\n");
            scanf("%d",&numero);
            divisores(&numero);
            break;
        case 2:
            vocalesconsonantes(arr);
            break;
        case 3:
            printf("\nIntroduce numeros flotantes 1, 2 y 3\n");
            scanf("%f %f %f",&num,&num2,&num3);
            flotantes(&num,&num2,&num3);
            break;
        default:
            printf("\nOpcion inexistente.");
            break;
    }
    return 0;
}
void divisores(int*num){
    printf("Divisores de %d.\n",*num);
    for(int i=1;i<*num;i++){
        if(*num%i==0){
            printf("%d ",i);
        }
    }
}
void vocalesconsonantes(char array[]){
    int longitud = strlen(array), consonantes = 0,vocales = 0;
    for(int i=0;i<longitud;i++){
        if(array[i]=='A'||array[i]=='E'||array[i]=='I'||array[i]=='O'||array[i]=='U'||array[i]=='a'||array[i]=='e'||array[i]=='i'||array[i]=='o'||array[i]=='u'){
            vocales++;
        }
        else if((array[i]>=65&&array[i]<=90)||(array[i]>=97&&array[i]<=122)){
            consonantes++;
        }
    }
    printf("\nCadena: %s\nNumero de vocales: %d\nNumero de consonantes: %d",array,vocales,consonantes);
}
void flotantes(float*num,float*num2,float*num3){
    float menor;
    if(*num<(*num2&&*num3)){
        menor = *num;
    }
    else if(*num2<(*num&&*num3)){
        menor = *num2;
    }
    else if(*num3<(*num&&*num2)){
        menor = *num3;
    }
    printf("\nMenor de los numeros: %f",menor);
}
