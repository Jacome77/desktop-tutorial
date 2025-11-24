# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <stdlib.h>
# include <windows.h>

#include "Anulacion.h"
# include "Transaccion.h"

extern ttransaccion *inicio;

int Validar_ultimo (const char *pan){
	int leng = strlen (pan);
    char ultimo [5];
    char prueba [5];
    printf ("Me puedes regalar los ultimos 4 numeros del pan \n");
    scanf ("%s",ultimo);

     for (int i = leng -5; i <= leng; i++){
       strcat (prueba, &pan[i]);
     }

     printf("%s",prueba);
 	return 0;
 }

void Anulacion(){
  int refe;
  char numero [5];

  ttransaccion *aux = inicio;
  if ( !vacio ()){
      printf ("Me puedes decir el numero de referencia de la transaccion");
      scanf("%d",&refe);
      while (aux->next != NULL){

        if (aux->referncia == refe){

          printf("Dime los ultimos 4 digitos de la tarjeta \n");
          fgets (numero , sizeof(numero ), stdin);
          numero [strcspn (numero, "\n")] = 0;

         if ( !Validar_ultimo (aux->Pan)) {

         }
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