#include <stdio.h>
#include <stdlib.h>
int stringLength(char*cadena);
int BuscarNum(int array[10],int num,int i);
int main()
{
    char cadena[]="esta es una cadena",*apuntador;
    int array[10]={1,6,4,3,7,8,9,10,11,23},longitud,i=0;
    printf("longitud de la cadena: %d",longitud = stringLength(cadena));
    i = BuscarNam(array,6,i);
    printf("El numero se halla en la posicion",i+1);
    return 0;
}
int stringLength(char*cadena){
    char*ptr=cadena;
    while(*ptr++!='\0');
    int longitud=ptr-cadena-1;
    return longitud;
}
// Desarrolle una función recursiva que permita buscar un número pasado como
// parámetro dentro de un arreglo. Si el número a buscar es encontrado, la función
// retorna la posición de dicho número. En caso contrario, la función retorna -1
int BuscarNum(int array[10],int num,int i){
    if (num==array[i]){
        return i;
    }
    else if(i==sizeof(array)/sizeof(int)-1){
        return -1;
    }
    else{
        BuscarNum(array[10],num,i+1);
    }
}
