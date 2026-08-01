#ifndef AVL_H
#define AVL_H

#include <stdio.h>
#include <stdlib.h>

#include "destino.h"

/*=========================================
            ESTRUCTURA VIAJE
=========================================*/

typedef struct Viaje{

    int codigo;
    int capacidad;

    int altura;

    struct Viaje *izquierdo;
    struct Viaje *derecho;

}Viaje;

/*=========================================
        FUNCIONES DEL AVL
=========================================*/

int altura(Viaje *raiz);

int mayor(int a,int b);

int factorBalance(Viaje *raiz);

Viaje *crearViaje(int codigo,int capacidad);

Viaje *rotacionDerecha(Viaje *y);

Viaje *rotacionIzquierda(Viaje *x);

Viaje *insertarAVL(Viaje *raiz,int codigo,int capacidad);

Viaje *buscarViaje(Viaje *raiz,int codigo);

void mostrarInOrden(Viaje *raiz);

void mostrarPreOrden(Viaje *raiz);

void mostrarPostOrden(Viaje *raiz);

void registrarViajeDestino(ListaDestinos *lista);

void buscarViajeDestino(ListaDestinos *lista);

void mostrarArbolDestino(ListaDestinos *lista);

void liberarAVL(Viaje *raiz);

#endif