#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int buscadorDePalabras(char *ptr,char *ptr2);
int main(){
    char cadena[30]="Esta es una frase con palabras";
    char palabra[10]="palabras";
    char *ptr = cadena,*ptr2=palabra;
    printf("%d",buscadorDePalabras(ptr,ptr2));
    return 0;
}
int buscadorDePalabras(char *ptr, char *ptr2){
    int i=0,j=0,exito,longitud = strlen(ptr),longitud2=strlen(ptr2);
    do{//Checamos hasta llegar a la inicial de la primera palabra
        if(*ptr==*ptr2){
            do{//Una vez que se cumple la condicion recorremos
                if(*ptr==*ptr2){
                    exito=1;
                    *ptr++;
                    *ptr2++;
                    j++;
                }
                else{
                    exito=0;
                }
            }while(j<longitud2&&exito==1);
            return exito;
        }
        *ptr++;
        i++;
    }while(i<longitud&&exito==0);
    return 0;
}
