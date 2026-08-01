#include "avl.h"

/*=========================================
            OBTENER ALTURA
=========================================*/

int altura(Viaje *raiz){

    if(raiz==NULL){

        return 0;

    }

    return raiz->altura;

}

/*=========================================
            MAYOR DE DOS
=========================================*/

int mayor(int a,int b){

    if(a>b){

        return a;

    }

    return b;

}

/*=========================================
        FACTOR DE BALANCE
=========================================*/

int factorBalance(Viaje *raiz){

    if(raiz==NULL){

        return 0;

    }

    return altura(raiz->izquierdo)-altura(raiz->derecho);

}

/*=========================================
        CREAR NUEVO VIAJE
=========================================*/

Viaje *crearViaje(int codigo,int capacidad){

    Viaje *nuevo;

    nuevo=(Viaje*)malloc(sizeof(Viaje));

    if(nuevo==NULL){

        printf("\nNo hay memoria disponible.\n");

        return NULL;

    }

    nuevo->codigo=codigo;

    nuevo->capacidad=capacidad;

    nuevo->altura=1;

    nuevo->izquierdo=NULL;

    nuevo->derecho=NULL;

    return nuevo;

}
/*=========================================
        ROTACION DERECHA
=========================================*/

Viaje *rotacionDerecha(Viaje *y){

    Viaje *x;
    Viaje *T2;

    x=y->izquierdo;
    T2=x->derecho;

    x->derecho=y;
    y->izquierdo=T2;

    y->altura=mayor(altura(y->izquierdo),altura(y->derecho))+1;
    x->altura=mayor(altura(x->izquierdo),altura(x->derecho))+1;

    printf("\nRotacion simple a la derecha realizada.\n");

    return x;

}

/*=========================================
        ROTACION IZQUIERDA
=========================================*/

Viaje *rotacionIzquierda(Viaje *x){

    Viaje *y;
    Viaje *T2;

    y=x->derecho;
    T2=y->izquierdo;

    y->izquierdo=x;
    x->derecho=T2;

    x->altura=mayor(altura(x->izquierdo),altura(x->derecho))+1;
    y->altura=mayor(altura(y->izquierdo),altura(y->derecho))+1;

    printf("\nRotacion simple a la izquierda realizada.\n");

    return y;

}

/*=========================================
    ROTACION IZQUIERDA - DERECHA
=========================================*/

Viaje *rotacionIzquierdaDerecha(Viaje *raiz){

    raiz->izquierdo=rotacionIzquierda(raiz->izquierdo);

    printf("\nRotacion doble izquierda-derecha realizada.\n");

    return rotacionDerecha(raiz);

}

/*=========================================
    ROTACION DERECHA - IZQUIERDA
=========================================*/

Viaje *rotacionDerechaIzquierda(Viaje *raiz){

    raiz->derecho=rotacionDerecha(raiz->derecho);

    printf("\nRotacion doble derecha-izquierda realizada.\n");

    return rotacionIzquierda(raiz);

}
/*=========================================
        INSERTAR EN ARBOL AVL
=========================================*/

Viaje *insertarAVL(Viaje *raiz,int codigo,int capacidad){

    int balance;

    if(raiz==NULL){

        return crearViaje(codigo,capacidad);

    }

    if(codigo<raiz->codigo){

        raiz->izquierdo=insertarAVL(raiz->izquierdo,codigo,capacidad);

    }
    else if(codigo>raiz->codigo){

        raiz->derecho=insertarAVL(raiz->derecho,codigo,capacidad);

    }
    else{

        printf("\nEl codigo del viaje ya existe.\n");

        return raiz;

    }

    raiz->altura=1+mayor(altura(raiz->izquierdo),
                         altura(raiz->derecho));

    balance=factorBalance(raiz);

    /*=====================================
            ROTACION SIMPLE DERECHA
    =====================================*/

    if(balance>1 && codigo<raiz->izquierdo->codigo){

        return rotacionDerecha(raiz);

    }

    /*=====================================
            ROTACION SIMPLE IZQUIERDA
    =====================================*/

    if(balance<-1 && codigo>raiz->derecho->codigo){

        return rotacionIzquierda(raiz);

    }

    /*=====================================
        ROTACION DOBLE IZQ-DER
    =====================================*/

    if(balance>1 && codigo>raiz->izquierdo->codigo){

        return rotacionIzquierdaDerecha(raiz);

    }

    /*=====================================
        ROTACION DOBLE DER-IZQ
    =====================================*/

    if(balance<-1 && codigo<raiz->derecho->codigo){

        return rotacionDerechaIzquierda(raiz);

    }

    return raiz;

}
/*=========================================
            BUSCAR VIAJE
=========================================*/

Viaje *buscarViaje(Viaje *raiz,int codigo){

    if(raiz==NULL){

        return NULL;

    }

    if(codigo==raiz->codigo){

        return raiz;

    }

    if(codigo<raiz->codigo){

        return buscarViaje(raiz->izquierdo,codigo);

    }

    return buscarViaje(raiz->derecho,codigo);

}

/*=========================================
        RECORRIDO INORDEN
=========================================*/

void mostrarInOrden(Viaje *raiz){

    if(raiz==NULL){

        return;

    }

    mostrarInOrden(raiz->izquierdo);

    printf("\n=====================================\n");
    printf("Codigo del viaje : %d\n",raiz->codigo);
    printf("Capacidad        : %d\n",raiz->capacidad);
    printf("Altura           : %d\n",raiz->altura);

    mostrarInOrden(raiz->derecho);

}

/*=========================================
        RECORRIDO PREORDEN
=========================================*/

void mostrarPreOrden(Viaje *raiz){

    if(raiz==NULL){

        return;

    }

    printf("\n=====================================\n");
    printf("Codigo del viaje : %d\n",raiz->codigo);
    printf("Capacidad        : %d\n",raiz->capacidad);
    printf("Altura           : %d\n",raiz->altura);

    mostrarPreOrden(raiz->izquierdo);

    mostrarPreOrden(raiz->derecho);

}

/*=========================================
        RECORRIDO POSTORDEN
=========================================*/

void mostrarPostOrden(Viaje *raiz){

    if(raiz==NULL){

        return;

    }

    mostrarPostOrden(raiz->izquierdo);

    mostrarPostOrden(raiz->derecho);

    printf("\n=====================================\n");
    printf("Codigo del viaje : %d\n",raiz->codigo);
    printf("Capacidad        : %d\n",raiz->capacidad);
    printf("Altura           : %d\n",raiz->altura);

}
/*=========================================
        REGISTRAR VIAJE
=========================================*/

void registrarViajeDestino(ListaDestinos *lista){

    Destino *destino;

    int codigoDestino;
    int codigoViaje;
    int capacidad;

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

    printf("\nCodigo del viaje: ");
    scanf("%d",&codigoViaje);

    printf("Capacidad maxima: ");
    scanf("%d",&capacidad);

    destino->raizAVL=insertarAVL(destino->raizAVL,
                                 codigoViaje,
                                 capacidad);

    printf("\nViaje registrado correctamente.\n");

}

/*=========================================
        BUSCAR VIAJE
=========================================*/

void buscarViajeDestino(ListaDestinos *lista){

    Destino *destino;

    Viaje *viaje;

    int codigoDestino;
    int codigoViaje;

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

    printf("Codigo del viaje: ");
    scanf("%d",&codigoViaje);

    viaje=buscarViaje(destino->raizAVL,codigoViaje);

    if(viaje==NULL){

        printf("\nViaje no encontrado.\n");

        return;

    }

    printf("\n=====================================\n");
    printf("VIAJE ENCONTRADO\n");
    printf("=====================================\n");

    printf("Codigo: %d\n",viaje->codigo);
    printf("Capacidad: %d\n",viaje->capacidad);

}

/*=========================================
        MOSTRAR ARBOL
=========================================*/

void mostrarArbolDestino(ListaDestinos *lista){

    Destino *destino;

    int codigoDestino;
    int opcion;

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

    printf("\n");
    printf("1. InOrden\n");
    printf("2. PreOrden\n");
    printf("3. PostOrden\n");
    printf("Opcion: ");
    scanf("%d",&opcion);

    switch(opcion){

        case 1:

            mostrarInOrden(destino->raizAVL);

            break;

        case 2:

            mostrarPreOrden(destino->raizAVL);

            break;

        case 3:

            mostrarPostOrden(destino->raizAVL);

            break;

        default:

            printf("\nOpcion invalida.\n");

    }

}

/*=========================================
        LIBERAR AVL
=========================================*/

void liberarAVL(Viaje *raiz){

    if(raiz==NULL){

        return;

    }

    liberarAVL(raiz->izquierdo);

    liberarAVL(raiz->derecho);

    free(raiz);

}