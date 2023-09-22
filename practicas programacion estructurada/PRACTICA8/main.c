#include <stdio.h>
#include <stdlib.h>
void capturarDatos(char**etiquetas,char*nombre,char *nacionalidad, int*edad,char*color);
void imprimirDatos(char *nombre, char *nacionalidad, int *edad,char *color);
int stringLength(char *nombre);
double* maximum(double* a, int size);
double* minimum(double* a, int size);
void cambioPosicion(double*maximum, double *minimum);
void swapPointers(char*ptr1,char*ptr2);
int main(){
    double arreglo[10]={10.23,4.246,5.982,-12.324,6.5885,9.56443,7.564,8.8678,10.235,111.2465};
    char *etiquetas[] = {"Nombre","Nacionalidad","Edad","Color favorito"};
    char *s1 = "Debo imprimirme despues",*s2 = "Debo imprimirme antes";
    char nombre[20];
    int edad,longitud;
    double *menor,*mayor;
    char nacionalidad[10];
    char color[10];
    char genmusical[10];
    capturarDatos(etiquetas,nombre,nacionalidad,&edad,color);
    longitud = stringLength(nombre);
    printf("\nLongitud del arreglo 'nombre': %d\n",longitud);
    printf("\nArreglo de doubles ejercicio 3: [");
    for(int i =0;i<10;i++){
        printf("%lf ",arreglo[i]);
    }
    printf("]");
    menor = minimum(arreglo,10);
    mayor = maximum(arreglo,10);
    printf("\nMenor del arreglo de doubles: %lf\nMayor del arreglo de doubles: %lf\n",*menor,*mayor);
    cambioPosicion(mayor,menor);
    printf("\nCambio de posiciones arreglo de doubles ejercicio 3: [");
    for(int i =0;i<10;i++){
        printf("%lf ",arreglo[i]);
    }
    swapPointers(s1,s2);
    printf("]");
    printf("\ns1 es %s\n", s1);
    printf("\ns2 es %s\n", s2);
    return 0;
}
void capturarDatos(char**etiquetas, char* nombre,char* nacionalidad, int* edad, char* color){
    //char**etiquetas se puede leer de esta forma
    //primer asterisco * (0x8000): tiene guardado 0x4000
    //segundo asterisco * (0x4000): tiene guardado 0x2000 de etiquetas
    //0x2000: tiene guardado el valor del arreglo
    printf("%s: ",*etiquetas++);//0x4000++
                                //0x2001
    scanf("%s",nombre);
    fflush(stdin);
    printf("%s: ",*etiquetas++);//0x4000++ (ya lleva dentro 0x2001)
                                //0x2002
    gets(nacionalidad);
    printf("%s: ",*etiquetas++);//0x4000++
                                //0x2003
    scanf("%d",&edad);
    printf("%s: ",*etiquetas++);//0x4000++
                                //0x2004
    scanf("%s",color);
    imprimirDatos(nombre, nacionalidad,edad,color);
}
void imprimirDatos(char *nombre, char *nacionalidad, int *edad, char *color){
    printf("\nNombre: %s\nNacionalidad: %s\nEdad: %d\nColor: %s",nombre,nacionalidad,edad,color);
}
int stringLength(char *nombre){
    char *Puntero = nombre;
    while(*Puntero++!='\0');
    int len = nombre - Puntero;
    return len*(-1);
}
double* minimum(double* a,int size){
    double *puntero;
    puntero = &a[0];
    for(int i =0;i<size;i++){
        if (a[i]<*puntero){
            puntero =&a[i];
        }
    }
    return puntero;
}
double* maximum(double* a,int size){
    double *puntero;
    puntero = &a[0];
    for(int i =0;i<size;i++){
        if (a[i]>*puntero){
            puntero = &a[i];
        }
    }
    return puntero;
}
void cambioPosicion(double *maximum, double* minimum){
    double temporal = *minimum;
    *minimum = *maximum;
    *maximum = temporal;
}
void swapPointers(char*ptr1,char*ptr2){
    char a=*ptr1;
    *ptr1 = *ptr2;
    *ptr2 = a;
}
