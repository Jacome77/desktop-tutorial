# include <stdio.h>
# include <string.h>
# include <conio.h>
# include <stdlib.h>
# include <windows.h>

#include "Anulacion.h"
# include "Transaccion.h"

extern ttransaccion *inicio;

int Validar_ultimo (const char *pan, int ultimocuatro){
	int leng = strlen (pan);
   char prueba [5];

     for (int i = leng -4; i < leng-3; i++){
       strcat (prueba, &pan[i]);
     }


  printf("%i\n",ultimocuatro);
  int compara = atoi(prueba);
  printf("%i\n",compara);
  Sleep(2000);
    if (compara == ultimocuatro)
    {
      Sleep(1000);
      printf("Numeros correctos \n");
      return 1;
    }else
    {
      printf("Numeros incorrectos \n");
      Sleep(1000);
    }
 	return 0;
 }

void Anulacion(){
  int refe;
  int numero;

  ttransaccion *aux = inicio;
  if ( !vacio ()){
      printf ("Me puedes decir el numero de referencia de la transaccion");
      scanf("%d",&refe);
    while (getchar() != '\n');
      while (aux != NULL){
        printf("%d",refe);
        if (aux->referncia == refe && aux->estado == 0){

          printf("Dime los ultimos 4 digitos de la tarjeta \n");
          scanf("%d",&numero);
          if (Validar_ultimo (aux->Pan, numero))
          {
            aux->estado = 1;
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