#include <stdio.h>
#include <stdlib.h>

typedef struct Cliente{
    int cedula;
    struct Cliente *siguiente;
}Cliente;

typedef struct{
    Cliente *frente;
    Cliente *final;
}Cola;

typedef struct Paquete{
    int codigo;
    int cedula;
    int prioridad;
    struct Paquete *siguiente;
}Paquete;

typedef struct{
    Paquete *tope;
}Pila;

void inicializarCola(Cola *cola){
    cola->frente=NULL;
    cola->final=NULL;
}

void inicializarPila(Pila *pila){
    pila->tope=NULL;
}

int colaVacia(Cola *cola){
    return cola->frente==NULL;
}

int pilaVacia(Pila *pila){
    return pila->tope==NULL;
}

void registrarCliente(Cola *cola){
    Cliente *nuevo=(Cliente*)malloc(sizeof(Cliente));

    if(nuevo==NULL){
        printf("\nNo hay memoria disponible.\n");
        return;
    }

    printf("\nNumero de identidad: ");
    scanf("%d",&nuevo->cedula);

    nuevo->siguiente=NULL;

    if(colaVacia(cola)){
        cola->frente=nuevo;
        cola->final=nuevo;
    }else{
        cola->final->siguiente=nuevo;
        cola->final=nuevo;
    }

    printf("\nCliente registrado correctamente.\n");
}

void mostrarCola(Cola *cola){

    Cliente *aux=cola->frente;

    if(colaVacia(cola)){
        printf("\nLa cola esta vacia.\n");
        return;
    }

    printf("\nCLIENTES EN ESPERA\n\n");

    while(aux!=NULL){
        printf("Cedula: %d\n",aux->cedula);
        aux=aux->siguiente;
    }
}

void liberarCola(Cola *cola){

    Cliente *aux;

    while(cola->frente!=NULL){
        aux=cola->frente;
        cola->frente=cola->frente->siguiente;
        free(aux);
    }

    cola->final=NULL;
}

void liberarPila(Pila *pila){

    Paquete *aux;

    while(pila->tope!=NULL){
        aux=pila->tope;
        pila->tope=pila->tope->siguiente;
        free(aux);
    }
}

int main(){

    Cola colaClientes;
    Pila prioridad1;
    Pila prioridad2;

    int opcion;
    int codigoPaquete=1000;
    inicializarCola(&colaClientes);
    inicializarPila(&prioridad1);
    inicializarPila(&prioridad2);

    do{

        printf("\n");
        printf("=====================================\n");
        printf(" CENTRO DE ENVIO Y DESPACHO\n");
        printf("=====================================\n");
        printf("1. Registrar cliente\n");
        printf("2. Atender cliente\n");
        printf("3. Mostrar pila prioridad 1\n");
        printf("4. Mostrar pila prioridad 2\n");
        printf("5. Despachar paquete\n");
        printf("6. Mostrar cola\n");
        printf("7. Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion){

            case 1:
                registrarCliente(&colaClientes);
                break;

                case 2:
                  atenderCliente(&colaClientes,&prioridad1,&prioridad2,&codigoPaquete);
                   break;

            case 3:
                 mostrarPila(&prioridad1);
                  break;

            case 4:
                mostrarPila(&prioridad2);
                 break;

                   case 5:
                      despacharPaquete(&prioridad1,&prioridad2);
                        break;

            case 6:
                mostrarCola(&colaClientes);
                break;

            case 7:
                liberarCola(&colaClientes);
                liberarPila(&prioridad1);
                liberarPila(&prioridad2);
                printf("\nPrograma finalizado.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    }while(opcion!=7);

    return 0;
}
void apilar(Pila *pila,int codigo,int cedula,int prioridad){

    Paquete *nuevo=(Paquete*)malloc(sizeof(Paquete));

    if(nuevo==NULL){
        printf("\nNo hay memoria disponible.\n");
        return;
    }

    nuevo->codigo=codigo;
    nuevo->cedula=cedula;
    nuevo->prioridad=prioridad;

    nuevo->siguiente=pila->tope;
    pila->tope=nuevo;
}

void atenderCliente(Cola *cola,Pila *prioridad1,Pila *prioridad2,int *codigo){

    Cliente *aux;
    float valor;
    int prioridad;

    if(colaVacia(cola)){
        printf("\nNo hay clientes en espera.\n");
        return;
    }

    aux=cola->frente;
    cola->frente=cola->frente->siguiente;

    if(cola->frente==NULL){
        cola->final=NULL;
    }

    printf("\nCliente atendido: %d\n",aux->cedula);

    printf("Valor pagado: ");
    scanf("%f",&valor);

    if(valor>=50000){
        prioridad=1;
        apilar(prioridad1,*codigo,aux->cedula,prioridad);
    }else{
        prioridad=2;
        apilar(prioridad2,*codigo,aux->cedula,prioridad);
    }

    printf("\nPaquete registrado.\n");
    printf("Codigo: %d\n",*codigo);
    printf("Prioridad: %d\n",prioridad);

    (*codigo)++;

    free(aux);
}

void mostrarPila(Pila *pila){

    Paquete *aux=pila->tope;

    if(pilaVacia(pila)){
        printf("\nLa pila esta vacia.\n");
        return;
    }

    printf("\nPAQUETES\n\n");

    while(aux!=NULL){

        printf("Codigo: %d\n",aux->codigo);
        printf("Cedula: %d\n",aux->cedula);
        printf("Prioridad: %d\n\n",aux->prioridad);

        aux=aux->siguiente;
    }
}
void despacharPaquete(Pila *prioridad1,Pila *prioridad2){

    Paquete *aux;

    if(!pilaVacia(prioridad1)){

        aux=prioridad1->tope;
        prioridad1->tope=aux->siguiente;

        printf("\nPAQUETE DESPACHADO\n");
        printf("Codigo: %d\n",aux->codigo);
        printf("Cedula: %d\n",aux->cedula);
        printf("Prioridad: %d\n",aux->prioridad);

        free(aux);
        return;
    }

    if(!pilaVacia(prioridad2)){

        aux=prioridad2->tope;
        prioridad2->tope=aux->siguiente;

        printf("\nPAQUETE DESPACHADO\n");
        printf("Codigo: %d\n",aux->codigo);
        printf("Cedula: %d\n",aux->cedula);
        printf("Prioridad: %d\n",aux->prioridad);

        free(aux);
        return;
    }

    printf("\nNo existen paquetes para despachar.\n");
}
