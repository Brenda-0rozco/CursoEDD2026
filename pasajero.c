#include "pasajero.h"

/*=========================================
        INICIALIZAR COLA
=========================================*/

void inicializarCola(ColaPasajeros *cola){

    cola->frente=NULL;
    cola->final=NULL;

}

/*=========================================
            COLA VACIA
=========================================*/

int colaVacia(ColaPasajeros *cola){

    return cola->frente==NULL;

}

/*=========================================
      CONTAR PASAJEROS EN ESPERA
=========================================*/

int contarPasajeros(ColaPasajeros *cola){

    Pasajero *aux;

    int contador=0;

    aux=cola->frente;

    while(aux!=NULL){

        contador++;

        aux=aux->siguiente;

    }

    return contador;

}

/*=========================================
      BUSCAR PASAJERO EN UNA COLA
=========================================*/

Pasajero *buscarPasajero(ColaPasajeros *cola,int documento){

    Pasajero *aux;

    aux=cola->frente;

    while(aux!=NULL){

        if(aux->documento==documento){

            return aux;

        }

        aux=aux->siguiente;

    }

    return NULL;

}

/*=========================================
    VERIFICAR PASAJERO DUPLICADO
=========================================*/

int pasajeroDuplicado(ListaDestinos *lista,int documento){

    Destino *destino;

    Pasajero *aux;

    destino=lista->frente;

    while(destino!=NULL){

        aux=destino->cola.frente;

        while(aux!=NULL){

            if(aux->documento==documento){

                return 1;

            }

            aux=aux->siguiente;

        }

        destino=destino->siguiente;

    }

    return 0;

}

/*=========================================
        REGISTRAR PASAJERO
=========================================*/

void registrarPasajero(ColaPasajeros *cola){

    Pasajero *nuevo;

    nuevo=(Pasajero*)malloc(sizeof(Pasajero));

    if(nuevo==NULL){

        printf("\nNo hay memoria disponible.\n");
        return;

    }

    printf("\nNumero de documento: ");
    scanf("%d",&nuevo->documento);

    printf("\nTipo de documento\n");
    printf("1. Cedula de Ciudadania\n");
    printf("2. Pasaporte\n");
    printf("3. Tarjeta de Identidad\n");
    printf("Seleccione: ");
    scanf("%d",&nuevo->tipoDocumento);

    if(nuevo->tipoDocumento<1 || nuevo->tipoDocumento>3){

        printf("\nTipo de documento invalido.\n");

        free(nuevo);

        return;

    }

    strcpy(nuevo->estado,"En espera");

    nuevo->siguiente=NULL;

    if(colaVacia(cola)){

        cola->frente=nuevo;
        cola->final=nuevo;

    }else{

        cola->final->siguiente=nuevo;
        cola->final=nuevo;

    }

    printf("\nPasajero registrado correctamente.\n");

}

/*=========================================
    REGISTRAR PASAJERO A DESTINO
=========================================*/

void registrarPasajeroDestino(ListaDestinos *lista){

    Destino *destino;

    int codigoDestino;

    int documento;

    if(listaVacia(lista)){

        printf("\nNo existen destinos registrados.\n");

        return;

    }

    printf("\nCodigo del destino: ");
    scanf("%d",&codigoDestino);

    destino=buscarDestinoCodigo(lista,codigoDestino);

    if(destino==NULL){

        printf("\nDestino no encontrado.\n");

        return;

    }

    printf("\nNumero de documento: ");
    scanf("%d",&documento);

    if(pasajeroDuplicado(lista,documento)){

        printf("\nEl pasajero ya esta registrado.\n");

        return;

    }

    Pasajero *nuevo;

    nuevo=(Pasajero*)malloc(sizeof(Pasajero));

    if(nuevo==NULL){

        printf("\nNo hay memoria disponible.\n");

        return;

    }

    nuevo->documento=documento;

    printf("\nTipo de documento\n");
    printf("1. Cedula de Ciudadania\n");
    printf("2. Pasaporte\n");
    printf("3. Tarjeta de Identidad\n");
    printf("Seleccione: ");
    scanf("%d",&nuevo->tipoDocumento);

    if(nuevo->tipoDocumento<1 || nuevo->tipoDocumento>3){

        printf("\nTipo de documento invalido.\n");

        free(nuevo);

        return;

    }

    strcpy(nuevo->estado,"En espera");

    nuevo->siguiente=NULL;

    if(colaVacia(&destino->cola)){

        destino->cola.frente=nuevo;
        destino->cola.final=nuevo;

    }else{

        destino->cola.final->siguiente=nuevo;
        destino->cola.final=nuevo;

    }

    printf("\nPasajero registrado correctamente.\n");
    printf("Destino: %s\n",destino->nombre);

}
/*=========================================
        MOSTRAR PASAJEROS
=========================================*/

void mostrarPasajeros(ColaPasajeros *cola){

    Pasajero *aux;

    aux=cola->frente;

    if(colaVacia(cola)){

        printf("\nNo existen pasajeros en espera.\n");

        return;

    }

    printf("\n=====================================\n");
    printf("PASAJEROS EN ESPERA\n");
    printf("=====================================\n");

    while(aux!=NULL){

        printf("\nDocumento: %d\n",aux->documento);

        switch(aux->tipoDocumento){

            case 1:
                printf("Tipo: Cedula de Ciudadania\n");
                break;

            case 2:
                printf("Tipo: Pasaporte\n");
                break;

            case 3:
                printf("Tipo: Tarjeta de Identidad\n");
                break;

        }

        printf("Estado: %s\n",aux->estado);

        aux=aux->siguiente;

    }

}

/*=========================================
    MOSTRAR PASAJEROS POR DESTINO
=========================================*/

void mostrarPasajerosDestino(ListaDestinos *lista){

    Destino *destino;

    int codigo;

    if(listaVacia(lista)){

        printf("\nNo existen destinos registrados.\n");

        return;

    }

    printf("\nCodigo del destino: ");
    scanf("%d",&codigo);

    destino=buscarDestinoCodigo(lista,codigo);

    if(destino==NULL){

        printf("\nDestino no encontrado.\n");

        return;

    }

    printf("\nDestino: %s\n",destino->nombre);
    printf("Empresa: %s\n",destino->empresa);

    mostrarPasajeros(&destino->cola);

}

/*=========================================
    CONSULTAR PRIMER PASAJERO
=========================================*/

void consultarPrimerPasajero(ColaPasajeros *cola){

    if(colaVacia(cola)){

        printf("\nLa cola esta vacia.\n");

        return;

    }

    printf("\n=====================================\n");
    printf("PRIMER PASAJERO EN ESPERA\n");
    printf("=====================================\n");

    printf("\nDocumento: %d\n",cola->frente->documento);

    switch(cola->frente->tipoDocumento){

        case 1:
            printf("Tipo: Cedula de Ciudadania\n");
            break;

        case 2:
            printf("Tipo: Pasaporte\n");
            break;

        case 3:
            printf("Tipo: Tarjeta de Identidad\n");
            break;

    }

    printf("Estado: %s\n",cola->frente->estado);

}
/*=========================================
        EMBARCAR PASAJERO
=========================================*/

void embarcarPasajero(ColaPasajeros *cola,Destino *destino){

    Pasajero *aux;

    if(colaVacia(cola)){

        printf("\nNo existen pasajeros en espera.\n");

        return;

    }

    aux=cola->frente;

    strcpy(aux->estado,"Embarcado");

    cola->frente=cola->frente->siguiente;

    if(cola->frente==NULL){

        cola->final=NULL;

    }

    printf("\n=====================================\n");
    printf("PASAJERO EMBARCADO\n");
    printf("=====================================\n");

    printf("Documento: %d\n",aux->documento);
    printf("Destino: %s\n",destino->nombre);

    destino->pasajerosEmbarcados++;

    free(aux);

}

/*=========================================
    EMBARCAR PASAJERO POR DESTINO
=========================================*/

void embarcarPasajeroDestino(ListaDestinos *lista){

    Destino *destino;

    int codigo;

    if(listaVacia(lista)){

        printf("\nNo existen destinos registrados.\n");

        return;

    }

    printf("\nCodigo del destino: ");
    scanf("%d",&codigo);

    destino=buscarDestinoCodigo(lista,codigo);

    if(destino==NULL){

        printf("\nDestino no encontrado.\n");

        return;

    }

    embarcarPasajero(&destino->cola,destino);

}

/*=========================================
        CONSULTAR PASAJERO
=========================================*/

void consultarPasajero(ListaDestinos *lista){

    Destino *destino;

    Pasajero *aux;

    int documento;

    printf("\nNumero de documento: ");
    scanf("%d",&documento);

    destino=lista->frente;

    while(destino!=NULL){

        aux=buscarPasajero(&destino->cola,documento);

        if(aux!=NULL){

            printf("\n=====================================\n");
            printf("PASAJERO ENCONTRADO\n");
            printf("=====================================\n");

            printf("Documento: %d\n",aux->documento);
            printf("Destino: %s\n",destino->nombre);
            printf("Empresa: %s\n",destino->empresa);
            printf("Estado: %s\n",aux->estado);

            return;

        }

        destino=destino->siguiente;

    }

    printf("\nEl pasajero no se encuentra registrado.\n");

}

/*=========================================
        LIBERAR COLA
=========================================*/

void liberarCola(ColaPasajeros *cola){

    Pasajero *aux;

    while(cola->frente!=NULL){

        aux=cola->frente;

        cola->frente=cola->frente->siguiente;

        free(aux);

    }

    cola->final=NULL;

}