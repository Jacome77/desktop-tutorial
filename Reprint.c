# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <stdlib.h>
# include <windows.h>

#include "Reprint.h"
# include "Transaccion.h"

extern ttransaccion *inicio;


void Imprimir (){
    if (!vacio())
    {
        ttransaccion *aux = inicio;
        printf("%-15s %-15s %-20s %-20s %-10s\n", "RFERENCIA", "MONTO", "NUMERO TARJETA", "FRANQUISIA", "ESTADO");
        printf("----------------------------------------------------------------------------------------\n");
        while (aux != NULL){

            printf("%-15i %-15.2f %-20s  %-10s\n",
                    aux->referncia,
                    aux->Monto,
                    aux->Pan,
                    //aux->franquicia,
                    aux->estado == 0 ? "VENTA" : "ANULADA");

            aux = aux->next;
        }
    }else
    {
        printf ("No existe ninguna transaccion \n");
        Sleep(1500);
    }


}

