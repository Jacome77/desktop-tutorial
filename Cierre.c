# include <string.h>
# include <stdio.h>
# include <stdlib.h>
#include <windows.h>

#include "Transaccion.h"
#include "Reprint.h"


extern ttransaccion *inicio;

void Close(){
    char opcion ;
  if(!vacio()){
      Imprimir();
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