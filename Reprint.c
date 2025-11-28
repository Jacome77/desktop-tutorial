# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <stdlib.h>
# include <windows.h>

#include "Reprint.h"
# include "Transaccion.h"

extern ttransaccion *inicio;


void Imprimir (){
    char opcion;
    if (!vacio())
    {

        ttransaccion *aux = inicio;
        printf("%-15s %-15s %-20s %-20s %-10s\n", "RFERENCIA", "MONTO", "NUMERO TARJETA", "FRANQUISIA", "ESTADO");
        printf("----------------------------------------------------------------------------------------\n");

        while (inicio != NULL)
        {

            printf("%-15i %-15.2f %-20s %-20s %-10s\n",
                        aux->referncia,
                        aux->Monto,
                        aux->Pan,
                        aux->franquicia,
                        aux->estado == 0 ? "VENTA" : "ANULADA");

            printf("[BUSCAR TRANSACCIONES ANTERIORES A] [BUSCAR TRANSACCIONES MAS RECIENTES B] [SALIR S]");
            scanf(" %c", &opcion);

            if (opcion == 'A'  || opcion == 'a')
            {
                if (aux ->next != NULL)
                {
                   aux = aux->next;
                }
               printf("No existe mas opciones \n");
                Sleep(1000);
            }else if (opcion == 'B'  || opcion  == 'b')
            {

                if (aux ->back != NULL)
                {
                    aux = aux->back ;
                }
                printf("No existe mas opciones \n");

            }else if (opcion == 'S'  || opcion  == 's')
            {
                printf("Tu opcion es incorrecta, vamos a cerrar este apartado \n");
                return;
            }else
            {
                printf("Tu opcion es incorrecta, vamos a cerrar este apartado \n");
                Sleep(1000);
            }


        }

    }else
    {
        printf ("No existe ninguna transaccion \n");
        Sleep(1500);
    }


}

