#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Cuenta{
    float cantidadDinero;
    int numCuenta;
};
struct Cliente{
    char nombre[20];
    int numCliente;
    char CURP[20];
    struct Cuenta cuentas;
};
typedef struct Cliente clientes;
typedef struct Cuenta cuentas;
struct Cliente CrearCliente(int id);
void CrearCuenta(struct Cliente clientes[],int id);
void BuscarCliente(struct Cliente clientes[]);
void DepositarDinero(struct Cliente clientes[]);
void RetirarDinero(struct Cliente clientes[]);
void MostrarTodosLosClientes(struct Cliente clientes[],int i);
int main(){
    clientes clientes[100];
    int opc,numeroCliente=0;
    do{
        printf("\nElija la opcion.\n1.Crear nuevo cliente\n2.Crear nueva cuenta\n3.Buscar cliente\n4.Depositar dinero\n5.Retirar dinero\n6.Mostrar todos los clientes\n7.Salir\n");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                clientes[numeroCliente]=CrearCliente(numeroCliente++);
                break;
            case 2:
                CrearCuenta(clientes,numeroCliente);
                break;
            case 3:
                BuscarCliente(clientes);
                break;
            case 4:
                DepositarDinero(clientes);
                break;
            case 5:
                RetirarDinero(clientes);
                break;
            case 6:
                MostrarTodosLosClientes(clientes,numeroCliente);
                break;
            case 7:
                printf("Programa terminado.");
                break;
            default:
                printf("\nOpcion no existente.");
                break;
        }
    }while(opc!=7);
    FILE *ArchivoClientes = NULL;
    ArchivoClientes = fopen ("ArchivoClientes.txt", "w");
    fwrite(clientes, sizeof(struct Cliente), numeroCliente+1, ArchivoClientes);
    return 0;
}
struct Cliente CrearCliente(int id){
    struct Cliente cliente;
    fflush(stdin);
    printf("\nIntroduce tu nombre: ");
    gets(cliente.nombre);//Nombre
    fflush(stdin);
    printf("\nDame tu CURP: ");
    scanf("%s",cliente.CURP);//CURP
    cliente.numCliente=id;//ID
    cliente.cuentas.numCuenta=0;//Cuenta
    return cliente;
}
void CrearCuenta(struct Cliente clientes[],int id){
    int nroCliente;
    printf("Cliente a crear una cuenta");
    scanf("%d",&nroCliente);
    clientes[nroCliente].cuentas.cantidadDinero=0;
    clientes[nroCliente].cuentas.numCuenta++;
}
void BuscarCliente(struct Cliente clientes[]){
    int id;
    printf("\nNumero de cliente a buscar.");
    scanf("%d",&id);
    if(clientes[id].cuentas.numCuenta==0){
        printf("\nEl cliente no tiene una cuenta creada.");
    }
    else{
        printf("\nNombre: %s \nNumero de cliente: %d \nCURP: %s \nBalance: %f No. de cuenta: %d",&clientes[id].nombre,clientes[id].numCliente,&clientes[id].CURP,clientes[id].cuentas.cantidadDinero,clientes[id].cuentas.numCuenta);
    }
}
void MostrarTodosLosClientes(struct Cliente clientes[],int numeroCliente){
    for(int id=1;id<=numeroCliente;id++){
        printf("\nNombre: %s \nNumero de cliente: %d \nCURP: %s \nBalance: %f No. de cuenta: %d",&clientes[id].nombre,clientes[id].numCliente,&clientes[id].CURP,clientes[id].cuentas.cantidadDinero,clientes[id].cuentas.numCuenta);
    }
}
void DepositarDinero(struct Cliente clientes[]){
    int id;
    float monto;
    printf("\nNumero de cliente a depositar: ");
    scanf("%d",&id);
    printf("\nIntroduce el monto: ");
    scanf("%f",&monto);
    clientes[id].cuentas.cantidadDinero=clientes[id].cuentas.cantidadDinero+monto;
}
void RetirarDinero(struct Cliente clientes[]){
    int id;
    float monto;
    printf("\nIntroduce tu numero de cliente para realizar el retiro: ");
    scanf("%d",&id);
    printf("\nIntroduce el monto a retirar: ");
    do{
        scanf("%f",&monto);
        if(clientes[id].cuentas.cantidadDinero<monto){
            printf("\nEl monto a retirar es mayor a la cantidad de dinero en el balance.");
        }
    }while(clientes[id].cuentas.cantidadDinero<monto);
    clientes[id].cuentas.cantidadDinero-=monto;
}
