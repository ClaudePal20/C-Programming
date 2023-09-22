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
typedef struct Cliente cliente;
typedef struct Cuenta cuentas;
struct Cliente CrearCliente(int id);
void CrearCuenta(struct Cliente clientes[],int id);
void BuscarCliente(struct Cliente clientes[]);
void DepositarDinero(struct Cliente clientes[]);
void RetirarDinero(struct Cliente clientes[]);
void MostrarTodosLosClientes(struct Cliente clientes[],int i,char* direccion);
int main(){
    cliente clientes;
    cliente ArrClientes[100];
    int opc,numeroCliente=1;
    char direccion[]="ArchivoClientes.bin";
    FILE *ArchivoClientes = NULL;
    ArchivoClientes = fopen(direccion,"rb");
    if(ArchivoClientes==NULL){
        ArchivoClientes=fopen(direccion,"wb");
        printf("\nHemos creado un archivo.");
    }
    else{
        while(feof(ArchivoClientes)==0){
            fread(&clientes,sizeof(clientes),1,ArchivoClientes);
            ArrClientes[numeroCliente++]=clientes;
            if(feof(ArchivoClientes)!=0){
                numeroCliente--;//Evitamos que escriba en la siguiente posicion sobreescribiendo en la ultima.
                //El while no se detiene al llegar a la segunda estructura, hace una iteracion mas.
            }
        }
        printf("\nInformacion recuperada con exito.");
        MostrarTodosLosClientes(ArrClientes,numeroCliente,direccion);
    }
    fclose(ArchivoClientes);
    do{
        printf("\nElija la opcion.\n1.Crear nuevo cliente\n2.Crear nueva cuenta\n3.Buscar cliente\n4.Depositar dinero\n5.Retirar dinero\n6.Mostrar todos los clientes\n7.Salir");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                clientes=CrearCliente(numeroCliente);
                ArrClientes[numeroCliente++]=clientes;
                ArchivoClientes = fopen(direccion,"ab");
                fwrite(&clientes, sizeof(clientes), 1, ArchivoClientes);
                fclose(ArchivoClientes);
                break;
            case 2:
                CrearCuenta(ArrClientes,numeroCliente);
                break;
            case 3:
                BuscarCliente(ArrClientes);
                break;
            case 4:
                DepositarDinero(ArrClientes);
                break;
            case 5:
                RetirarDinero(ArrClientes);
                break;
            case 6:
                MostrarTodosLosClientes(ArrClientes,numeroCliente,direccion);
                break;
            case 7:
                printf("Programa terminado. Informacion en el archivo actualizada.");
                ArchivoClientes = fopen(direccion,"wb");
                for(int i=1;i<numeroCliente;i++){
                    clientes = ArrClientes[i];
                    fwrite(&clientes,sizeof(clientes),1,ArchivoClientes);
                }
                fclose(ArchivoClientes);
                break;
                //Aqui buscamos actualizar en el archivo los datos del cliente que
                //representa numero de cliente sin importar que haga el usuario.
            default:
                printf("\nOpcion no existente.");
                break;
        }
    }while(opc!=7);
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
    if(clientes[nroCliente].numCliente!=0){
        clientes[nroCliente].cuentas.cantidadDinero=0;
        clientes[nroCliente].cuentas.numCuenta++;
    }
    else{
        printf("\nCliente no existente.");
    }
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
void MostrarTodosLosClientes(struct Cliente clientes[],int numeroCliente,char*direccion){
    for(int i=1;i<numeroCliente;i++){
        printf("\nNombre: %s \nNumero de cliente: %d \nCURP: %s \nBalance: %f No. de cuenta: %d",&clientes[i].nombre,clientes[i].numCliente,&clientes[i].CURP,clientes[i].cuentas.cantidadDinero,clientes[i].cuentas.numCuenta);
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
