#include <stdio.h>
#include <stdlib.h>

struct rectangulo{
    int y;
    int x;
    int ancho;
    int largo;
};
struct rectangulo2{
    int y;
    int x;
    int ancho;
    int largo;
};
int choque(struct rectangulo, struct rectangulo2);
int main(){
    struct rectangulo rect={0,0,10,10};
    struct rectangulo2 rect2={12,12,10,10};;
    int chocan;
    chocan = choque(rect,rect2);
    printf("Chocan? = %d",chocan);
    return 0;
}
int choque(struct rectangulo rect, struct rectangulo2 rect2){
    if(((rect.y>=rect2.y-rect2.largo&&rect.y<=rect2.y)&&(rect.x>=rect2.x-rect2.ancho&&rect.x<=rect2.ancho))||((rect2.y>=rect.y-rect.largo&&rect2.y<=rect.y)&&(rect2.x>=rect.x-rect.ancho&&rect2.x<=rect.ancho))){
        return 1;
    }
}
