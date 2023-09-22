#include <stdio.h>
#include <stdlib.h>
#define N 3
struct cancion{
    char titulo[25];
    char artista[20];
    float duracion;
}
canciones[N];
;
int main(){
    int i;
    //Capturar arreglo
    for(i=0;i<N;i++){
        printf("\n\n cancion %d",i+1);
        printf("\nCaptura Ttulo ");
        gets(canciones[i].titulo);
        printf("Capturar Duracion ");;
        scanf("%f", &canciones[i].duracion);
        printf("Captura Artista");
        fflush(stdin);
        gets(canciones[i].artista);
        }
    for(i=0;i<N;i++){
        printf("\n\n cancion %d",i+1);
        printf("\n Titulo: %s",canciones[i].titulo);
        printf("\nDuracion: %s",canciones[i].duracion);
        printf("\n Artista: %s",canciones[i].artista);
    }
    return 0;
}
