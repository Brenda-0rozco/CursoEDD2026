#ifndef PASAJERO_H
#define PASAJERO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "destino.h"

/*==========================
        PASAJERO
==========================*/

typedef struct Pasajero{

    int documento;
    int tipoDocumento;

    char estado[20];

    struct Pasajero *siguiente;

}Pasajero;

/*==========================
      FUNCIONES FIFO
==========================*/

void inicializarCola(ColaPasajeros *cola);

int colaVacia(ColaPasajeros *cola);

void registrarPasajeroDestino(ListaDestinos *lista);

void registrarPasajero(ColaPasajeros *cola);

void mostrarPasajerosDestino(ListaDestinos *lista);

void mostrarPasajeros(ColaPasajeros *cola);

void embarcarPasajeroDestino(ListaDestinos *lista);

void embarcarPasajero(ColaPasajeros *cola,Destino *destino);

void consultarPrimerPasajero(ColaPasajeros *cola);

int contarPasajeros(ColaPasajeros *cola);

Pasajero *buscarPasajero(ColaPasajeros *cola,int documento);

int pasajeroDuplicado(ListaDestinos *lista,int documento);

void consultarPasajero(ListaDestinos *lista);

void liberarCola(ColaPasajeros *cola);

#endif