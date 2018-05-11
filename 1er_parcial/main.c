#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_Prop 20


int main()
{
    int Error=-9;
    char seguir='s';
    int opcion;
    EPropietario Propietario[TAM_Prop];
    Error=inicializaVector(Propietario,TAM_Prop);

        do
        {
            menu("1- Alta de propietario\n"
                 "2- Modificación de propietario\n"
                 "3- Baja de propietario\n");

            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    Error=Alta(Propietario,TAM_Prop);
                    break;
                case 0:
                    seguir = 'n';
                    Error=0;
                    break;
                default:
                    Error=-1;
                    opcion=-2;
                    break;
            }//FIN switch(opcion)
            if(Error!=0)
            {
                sms_error(opcion,Error);
                Error=0;
            }
        }while(seguir=='s');

    return Error;
}
