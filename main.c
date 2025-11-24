#include <ctype.h>
# include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "Transaccion.h"
#include "Reprint.h"


void menu();
void Clean();

int Validar_numero(const char *op)
{
    int log = strlen(op);
    if (log < 0 || log > 9)
    {
        return 0;
    }
    if (isdigit(op[0]))
    {
        return 1;
    }
    return 0;
}


int main ()
{
    char Opcion_respuesta [2+1];
    int respuesta;

    while (1)
    {
        Clean();
        menu();
        fgets(Opcion_respuesta, sizeof(Opcion_respuesta), stdin);
        Opcion_respuesta[strcspn(Opcion_respuesta, "\n")] = 0;
        if (Validar_numero(Opcion_respuesta))
        {
            int respuesta = atoi(Opcion_respuesta);
            switch (respuesta)
            {
            case 1:
                Clean();
                Flow_Buy();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                Clean();
                char Repu [3];
                do
                {
                    Imprimir();
                    Sleep(3000);
                    printf("Quieres volver al menu principal S o N \n");
                    scanf("%c", &Repu );

                }while (strcmp(Repu, "S") == 0 || strcmp(Repu, "s") == 0);

                break;
            case 5:
                break;

            default:

            printf("No es la opcion correcta ");
            Clean();

            }
        }

    }

}



void menu ()
{
    printf("-------------------------------\n");
    printf("---------------MENU------------\n");
    printf("1) Buy \n");
    printf("2) Annular \n");
    printf("3) Closing \n");
    printf("4) Reprint \n");
    printf("5) Total reports \n");
    printf("-------------------------------\n");
}

void Clean()
{
    system("cls");
}

