# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <stdlib.h>
# include <windows.h>

#include "Anulacion.h"
# include "Transaccion.h"

extern ttransaccion *inicio;

int Validar_ultimo (const char *pan,  char ultimocuatro){
	int leng = strlen (pan);
  char prueba [5];

     for (int i = leng -5; i < leng; i++){
       strcat (prueba, &pan[i]);
     }

  printf("d%c \n",ultimocuatro);
  printf("d%c \n",prueba);
    if (strcmp (ultimocuatro, prueba) == 0)
    {
      printf("Numeros correctos \n");
      return 1;
    }

     printf("%s",prueba);
 	return 0;
 }

void Anulacion(){
  int refe;
  int numero [5];

  ttransaccion *aux = inicio;
  if ( !vacio ()){
      printf ("Me puedes decir el numero de referencia de la transaccion");
      scanf("%d",&refe);
    while (getchar() != '\n');
      while (aux != NULL){
        printf("%d",refe);
        if (aux->referncia == refe){

          printf("Dime los ultimos 4 digitos de la tarjeta \n");
          fgets (numero , sizeof(numero ), stdin);
          numero [strcspn (numero, "\n")] = 0;
          if (Validar_ultimo (aux->Pan, numero))
          {
            printf("Numeros correctos \n");
          }
          printf("Numeros mal 1 \n");
        }else
        {
          printf("No existe ese numero de referencia\n");
          Sleep(2000);
        }
        aux = aux->next;
      }

   }else {
       printf ("No existe ninguna transaccion \n");
       Sleep(1500);
   }

}