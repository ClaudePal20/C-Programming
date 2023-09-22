#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Potencia(int base, int exponente);
int palabra(char cadena[], char*apuntador);
void invertir(char cadena[],int i,int j);
int main(){
 double **aPtr;
 double *bPtr;
 double c[5] = {'A', 'B', 'C', 'D', 'E'};
 int n,longitud,i=0,j=0,l=0;
 char cadenita[]="cadena de palabras revertidas",apuntador;
 printf("%p y %p y %p",&aPtr,&bPtr,c);
 aPtr = &bPtr;
 bPtr = c;
 printf("\n%p y %p",aPtr,bPtr);
 //aPtr esta en 1234.
 //bPtr esta en 4321.
 //c esta en 5678.
 //cual es el contenido de las variables aPtr y bPtr.
 //a. Respuesta: aPtr contiene la direccion de bPtr (4321) y bPtr contiene la direccion de c (5678).
 //b. Respuesta: utilizaria *(aPtr+4)= *contenido* para cambiar el valor.
 *(*aPtr+4)= 'Z';
 printf("\n%lf",c[4]);
 printf("\n%d",n=Potencia(5,4));
 longitud = palabra(cadenita,&apuntador);
 printf("\nLongitud de la segunda palabra: %d y valor contenido dentro del puntero regresado de la segunda palabra (apuntando al inicio): %c",longitud,apuntador);
 l = strlen(cadenita);
 do{
    j++;
    if(cadenita[j]==' '||j==l){
        invertir(cadenita,i,j-1);
        i=j+1;
    }
 }while(j<l);
 printf("\n%s",cadenita);
 return 0;
}
int Potencia(int base, int exponente){
    if (exponente!=0){
        return base*Potencia(base,exponente-1);
    }
    else{
        return 1;
    }
}
int palabra(char cadena[],char*apuntador){
    int i=0,longitud=0,size=strlen(cadena);
    printf("\n%d",size);
    do{
        i++;
    }while(cadena[i]!=' ');
    if(cadena[i]==' '){
        *apuntador = cadena[i+1];
        do{
            ++longitud;
        }while(i+1+longitud<size&&cadena[i+1+longitud]!=' ');
    }
    return longitud;
}
void invertir(char cadena[], int i, int j){
    char temp;
    while(i<j){
        temp=cadena[i];
        cadena[i]=cadena[j];
        cadena[j]=temp;
        i++;
        j--;
    }
}
