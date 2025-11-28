# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <conio.h>
# include <ctype.h>
#include <windows.h>

# include "Transaccion.h"


ttransaccion *inicio = NULL;

int vacio ()
{
  return inicio==NULL;
}

int Cantidad_Transaccion ()
{
  int ref = 1 ;
  ttransaccion *aux = inicio;
  while (aux != NULL)
  {
    ref ++;
    aux = aux->next;
  }
  return ref;
}

void clean ()
{
  ttransaccion *aux = inicio;
  ttransaccion *aux2;
  while (aux != NULL)
  {
    aux2 = aux;
    aux = aux->next;
    free(aux2);
  }
  inicio = NULL;
}

int Validar_pan(const char *pan){
  int par = 0;
  int suma ;
  int len_pan = strlen(pan);

  if (len_pan < 0 || len_pan > 20){
     return 0;
   }
   for ( int i = len_pan - 1; i >= 0; i--){
     if (isdigit(pan[i])){
       int cifra = pan[i] - '0';
       if (par){
          cifra *=2;
          if (cifra > 9){
              cifra-=9;
          }
       }
       suma += cifra;
       par = !par;
     }
   }
   if (suma %10 == 0){
     return 1;
   }
  printf("Error\n");
   return 0;

}
int  Validar_monto(const char *monto)
{
  double numero ;
  int len = strlen(monto);
  for ( int i = 0; i < len; i++)
  {
    if (!isdigit(monto[i]))
    {
      return 0 ;
    }
  }
  if (len <= 0 || len > 12)
  {
    printf("El monto ingresado sobre pasa el tope \n");
    return 0 ;
  }

  numero = atoi(monto);

  if ( numero == 0 )
  {
    printf("El monto ingresado no tiene que ser 0 \n");
    return 0 ;
  }
  return numero /100.0;
}

int Validar_cvv( const char *cvv)
{
  int len = strlen(cvv);
  for ( int i = 0; i < len; i++)
  {
    if (!isdigit(cvv[i]))
    {
      Sleep(3000);
      printf("Ingresaste una letra \n");
      return 0 ;
    }
  }
  if (len <= 0 || len > 4)
  {
    Sleep(3000);
    printf("Ingresaste mas de 4 cifras \n");
    return 0 ;
  }
  return 1;
}
int Validar_fecha( const char *date)
{
  char day[5];
  char year [5];
  int len = strlen(date);

  if (len == 0)
  {
    Sleep(1500);
    printf("No ingresaste nada \n");
    return 0 ;
  }


  if (len ==5)
  {
    if (isdigit(date[0]) && isdigit(date[1]) && isdigit(date[3]) && isdigit(date[4]))
    {
      int dato1, dato2;
      strcat(day, &date[0]);
      strcat(day, &date[1]);

      dato1 = atoi(day);

      strcat(year, &date[3]);
      strcat(year, &date[4]);

      dato2 = atoi(year);

      if ( dato1 > 0 && dato1 < 13 && dato2 > 24)
      {
        return 1 ;
      }

    }else
    {
      Sleep(1500);
      printf("Ingresaste un numero mal \n");

    }
  }else
  {
    Sleep(3000);
    printf("Ingresaste mas de lo permitido \n");

  }
  return 0 ;
}

int FranquiciaEmisora(ttransaccion *aux)
{
  char fra = aux->Pan[0];
  if (fra == '5')
  {
    strcpy(aux->franquicia,"Mastercard");
    return 1;
  }else if (fra == '4')
  {
    strcpy(aux->franquicia,"VISA");
    return 1;
  }else
  {
    return 0;
  }
}



void Flow_Buy (){
  char pan [20] ;
  char monto [30] ;
  char cvv [4+1] ;
  char fecha [5+1] ;

  ttransaccion *aux ;
  aux = malloc (sizeof(ttransaccion));
  aux -> next = NULL;
  aux -> back = NULL;

  printf("-----------BUY----------\n");
  printf("Ingrese el numero del pan: \n ");
  fgets (pan, sizeof(pan), stdin);
  pan[strcspn(pan, "\n")] = 0;
  if (!Validar_pan(pan))
  {
    Sleep(2000);
    printf("Error en la trasnaccion \n" );
    printf("Numero de pan incorrecto \n" );
    return ;
  }
  strcpy(aux->Pan, pan);
  printf("Ingrese el monto en USD: \n ");
  fgets (monto, sizeof(monto), stdin);
  monto[strcspn(monto, "\n")] = 0;
  if (Validar_monto(monto) == 0)
  {
    Sleep(2000);
    printf("Error en la trasnaccion \n" );
    return ;
  }

  if (!FranquiciaEmisora(aux))
  {
    Sleep(11000);
    printf("Franquicia no existe \n" );
    return ;
  }
  aux->Monto = Validar_monto(monto);
  printf("Ingrese el cvv: \n ");
  fgets (cvv, sizeof(cvv), stdin);
  cvv[strcspn(cvv, "\n")] = 0;
  if (!Validar_cvv(cvv))
  {
    Sleep(1000);
    printf("Error en la trasnaccion \n" );
    printf("Numero de cvv mal \n" );
    return ;
  }
  aux->CVV = atoi(cvv);

  printf("Ingrese el fecha de expiracion (MM/YY) : \n ");
  fgets (fecha, sizeof(fecha), stdin);
  fecha[strcspn(fecha, "\n")] = 0;
  if (!Validar_fecha(fecha))
  {
    Sleep(2000);
    printf("Error en la trasnaccion \n" );
    return ;
  }
  strcpy( aux->Expirations_Date , fecha);
  aux->estado = 0;
  aux->referncia = Cantidad_Transaccion();
  aux->next= inicio;
  if (inicio != NULL)
  {
    inicio->back = aux;
  }
  inicio = aux;

  printf("Transaccion correcta  \n ");
  Sleep(1000);


}

