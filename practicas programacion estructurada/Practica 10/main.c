#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct cancion{
    char titulo[20];
    char artista[20];//    #1
    char genero[20];//     #2
    char album[20];//      #3
    int duracion;//  #4
    int anio;//        #5
};
void CapturarCanciones(struct cancion[],int tam);
void MostrarPlaylist(struct cancion[],int tam);
void MostrarCancion(struct cancion[],int tam);
void ReproducirAleatorio(struct cancion[],int tam);
int Duracion(struct cancion[],int tam);
void MostrarCancionesPorGenero(struct cancion[],int tam);
int Comparar(char genero1[], char genero2[]);
int main(){
    struct cancion canciones[100];
    int tam,opc,b,opc2,duracion;
    do{
        printf("Rockola\n1. Capturar canciones \n2. Mostrar playlist\n3. Mostrar cancion\n4. Reproducir aleatorio\n5. Duracion del playlist\n6. Mostrar canciones por genero\n");
        scanf("%d",&opc);
        if(opc==1||((opc<=6&&opc>=2)&&b==0)){
            if((opc<=6&&opc>=2)&&b==0){
                printf("Debes capturar primero una o mas canciones para usar el resto de opciones.");
            }
            printf("\nIntroduce la cantidad de canciones:");
            scanf("%d",&tam);
            CapturarCanciones(canciones,tam);
            b=1;
        }
        else if(opc==2&&b==1){
            MostrarPlaylist(canciones,tam);
        }
        else if(opc==3&&b==1){
            MostrarCancion(canciones,tam);
        }
        else if(opc==4&&b==1){
            ReproducirAleatorio(canciones,tam);
        }
        else if(opc==5&&b==1){
            printf("Duracion de la playlist: %d",duracion = Duracion(canciones,tam));
        }
        else if(opc==6&&b==1){
            MostrarCancionesPorGenero(canciones,tam);
        }
        else{
            printf("\nOpcion no reconocida.");
        }
        printf("\nDeseas utilizar otra opcion?\n1: Si.\nCualquier otra tecla: No.");
        scanf("%d",&opc2);
    }while(opc2==1);
    return 0;
}
void CapturarCanciones(struct cancion canciones[], int tam){
    int opc,b;
    for(int i=0;i<tam;i++){
        printf("Nombre de la cancion [%d]: ",i+1);
        fflush(stdin);
        gets(canciones[i].titulo);
        fflush(stdin);
        printf("Nombre del artista: ");
        gets(canciones[i].artista);
        fflush(stdin);
        printf("Genero \n1. Rock:\n2. Hip-Hop\n3. Jazz\n4. Reggaeton\n5. Trap\n6. Cumbia\n7. Electronica\n8. R&B\n9. Blues\n10. Metal\n");
        do{
            scanf("%d",&opc);
            switch(opc){
                case 1:
                    strcpy(&canciones[i].genero,"Rock");
                    break;
                case 2:
                    strcpy(&canciones[i].genero,"Hip-Hop");
                    break;
                case 3:
                    strcpy(&canciones[i].genero,"Jazz");
                    break;
                case 4:
                    strcpy(&canciones[i].genero,"Reggaeton");
                    break;
                case 5:
                    strcpy(&canciones[i].genero,"Trap");
                    break;
                case 6:
                    strcpy(&canciones[i].genero,"Cumbia");
                    break;
                case 7:
                    strcpy(&canciones[i].genero,"Electronica");
                    break;
                case 8:
                    strcpy(&canciones[i].genero,"R&B");
                    break;
                case 9:
                    strcpy(&canciones[i].genero,"Blues");
                    break;
                case 10:
                    strcpy(&canciones[i].genero,"Metal");
                    break;
                default:
                    printf("Genero musical no reconocido. Vuelve a elegir uno de los mostrados.");
                    b=1;
                    break;
            }
        }while(b==1);
        printf("Album: ");
        fflush(stdin);
        gets(canciones[i].album);
        fflush(stdin);
        printf("Duracion: ");
        do{
            scanf("%d",&canciones[i].duracion);
            if(canciones[i].duracion<=0){
                printf("\nIntroduciste una duracion no valida. Vuelve a introducirla.");
            }
        }while(canciones[i].duracion<=0);
        printf("Anio de lanzamiento: ");
        do{
            scanf("%d",&canciones[i].anio);
            if(canciones[i].anio<=1880||canciones[i].anio>2022){
                printf("Introduciste un anio de lanzamiento no valido. Vuelve a introducirlo.");
            }
        }while(canciones[i].anio<=1880||canciones[i].anio>2022);
    }
}
void MostrarPlaylist(struct cancion canciones[], int tam){
    for(int i=0;i<tam;i++){
        printf("\nCancion %d. Titulo: '%s'. Artista: '%s'. Genero: '%s'. Album: '%s'. Duracion: %d segundos. Anio: %d.",i+1,&canciones[i].titulo, &canciones[i].artista, &canciones[i].genero, &canciones[i].album, canciones[i].duracion, canciones[i].anio);
    }
}
void MostrarCancion(struct cancion canciones[],int tam){
    int i;
    printf("Dame el numero de cancion");
    scanf("%d",&i);
    if(i<=0){
        printf("La cancion buscada no existe.");
    }
    else{
        printf("\nCancion %d. Titulo: '%s'. Artista: '%s'. Genero: '%s'. Album: '%s'. Duracion: %d segundos. Anio: %d.",i,&canciones[i-1].titulo,&canciones[i-1].artista,&canciones[i-1].genero,&canciones[i-1].album,canciones[i-1].duracion,canciones[i-1].anio);
    }
}
void ReproducirAleatorio(struct cancion canciones[],int tam){
    int i=rand()%tam;
    if (i<=0){
        i+=1;
    }
    printf("\nCancion %d. Titulo: '%s'. Artista: '%s'. Genero: '%s'. Album: '%s'. Duracion: %d segundos. Anio: %d.",i,&canciones[i-1].titulo,&canciones[i-1].artista,&canciones[i-1].genero,&canciones[i-1].album, canciones[i-1].duracion, canciones[i-1].anio);
}
int Duracion(struct cancion canciones[],int tam){
    int sum = 0;
    for(int i = 0;i<tam;i++){
      sum+=(canciones[i].duracion);
    }
    return sum;
}
void MostrarCancionesPorGenero(struct cancion canciones[],int tam){
    char genero[10][15]={"Rock","Hip-Hop","Jazz","Reggaeton","Trap","Cumbia","Electronica","R&B","Blues","Metal"};
    int opc;
    printf("Generos:\n1. Rock:\n2. Hip-Hop\n3. Jazz\n4. Reggaeton\n5. Trap\n6. Cumbia\n7. Electronica\n8. R&B\n9. Blues\n10. Metal");
    do{
        scanf("%d",&opc);
        if(opc<=0||opc>=10){
            printf("\nElegiste una opcion no reconocida.");
        }
    }while(opc<=0||opc>=10);
    printf("Canciones de %s",genero[opc-1]);
    for(int i=0;i<tam;i++){
        if(Comparar(genero[opc-1],&canciones[i].genero)==1){
            printf("\nCancion %d. Titulo: '%s'. Artista: '%s'. Album: '%s'. Duracion: %d segundos. Anio: %d.\n",i+1,&canciones[i].titulo,&canciones[i].artista,&canciones[i].album,canciones[i].duracion,canciones[i].anio);
        }
    }
}
int Comparar(char genero1[], char genero2[]){
    int contador=0;
    while(genero1[contador]==genero2[contador]){
        if(genero1[contador]=='\0'||genero2[contador]=='\0')
            break;
        contador++;
    }
    if(genero1[contador]=='\0' && genero2[contador]=='\0')
        return 1;
    else
        return 0;
}
