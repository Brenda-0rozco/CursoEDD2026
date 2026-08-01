#include <stdio.h>
#include <stdlib.h>

#include "destino.h"
#include "pasajero.h"
#include "avl.h"
#include "estadisticas.h"

int main(){

    ListaDestinos listaDestinos;

    int opcion;

    inicializarListaDestinos(&listaDestinos);

    do{

        printf("\n");
        printf("====================================================\n");
        printf(" TERMINAL PORTUARIO TURISTICO BUENAVENTURA\n");
        printf("====================================================\n");
        printf("1. Registrar destino\n");
        printf("2. Buscar destino\n");
        printf("3. Mostrar destinos\n");
        printf("4. Modificar destino\n");
        printf("5. Registrar pasajero\n");
        printf("6. Mostrar pasajeros por destino\n");
        printf("7. Registrar viaje programado\n");
        printf("8. Buscar viaje\n");
        printf("9. Mostrar arbol de viajes\n");
        printf("10. Realizar embarque\n");
        printf("11. Consultar pasajero\n");
        printf("12. Mostrar estadisticas\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion){

            case 1:
                registrarDestino(&listaDestinos);
                break;

            case 2:
                buscarDestino(&listaDestinos);
                break;

            case 3:
                mostrarDestinos(&listaDestinos);
                break;

            case 4:
                modificarDestino(&listaDestinos);
                break;

            case 5:
                registrarPasajeroDestino(&listaDestinos);
                break;

            case 6:
                mostrarPasajerosDestino(&listaDestinos);
                break;

            case 7:
                registrarViajeDestino(&listaDestinos);
                break;

            case 8:
                buscarViajeDestino(&listaDestinos);
                break;

            case 9:
                mostrarArbolDestino(&listaDestinos);
                break;

            case 10:
                embarcarPasajeroDestino(&listaDestinos);
                break;

            case 11:
                consultarPasajero(&listaDestinos);
                break;

            case 12:
                mostrarEstadisticas(&listaDestinos);
                break;

            case 0:
                liberarDestinos(&listaDestinos);
                printf("\nPrograma finalizado.\n");
                break;

            default:
                printf("\nOpcion invalida.\n");

        }

    }while(opcion!=0);

    return 0;

}