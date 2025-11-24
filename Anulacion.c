# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <stdlib.h>
# include <windows.h>

#include "Reprint.h"
# include "Transaccion.h"

extern ttransaccion *inicio;



int Validar_ultimo (){

}

void Anulacion(){
  int refe;
  char numero [5];
  char pan_aux[20];
  ttransaccion *aux = inicio;
  if ( !vacio ()){
      printf ("Me puedes decir el numero de referencia de la transaccion");
      scanf("%d",&refe);
      while (aux->next != NULL){

        if (aux->referncia == refe){

          printf("Dime los ultimos 4 digitos de la tarjeta \n");
          fgets (numero , sizeof(numero ), stdin);
          numero [strcspn (numero, "\n")] = 0;


        }
        aux = aux->next;
      }
      printf("No existe ese numero de referencia\n");
      Sleep(2000);
   }else {
       printf ("No existe ninguna transaccion \n");
       Sleep(1500);
   }

}