# include <string.h>
# include <stdio.h>
# include <stdlib.h>
#include <windows.h>

#include "Transaccion.h"
#include "Reprint.h"


extern ttransaccion *inicio;


void imprimir (){
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

             aux = aux ->next;
        }
        printf(" Quieres volver al menu principal S/N ");
        scanf("%c", &opcion);
        


    }else
    {
        printf ("No existe ninguna transaccion \n");
        Sleep(1500);
    }


}



void Close(){
    char opcion ;
  if(!vacio()){
      imprimir();
      printf("Quiere realizar el cierre S/N \n");
      scanf("%c",&opcion);
      if (opcion == 's' || opcion == 'S')
      {
          clean();
          printf("Ya se hizo el cierre");
          Sleep(1000);
      }else
      {
          printf("No se realizara cierre \n");
      }
  }else {
    printf("No existe transaccion \n");
  }
}

