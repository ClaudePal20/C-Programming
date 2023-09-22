#include <stdio.h>
#include <stdlib.h>
struct Pelicula{
    char nombre[20];
    int *anioDePublicacion;
    char actores[20][30];
    char descripcion[30];
};
int main(){
    struct Pelicula peliculas[5];
    for (int i =0;i<5;i++){
        printf("%s",peliculas[i].nombre);
        printf("%d",peliculas[i].anioDePublicacion);
        printf("%s",peliculas[i].actores);
        printf("%s",peliculas[i].descripcion);
    }
    return 0;
}
