#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_Prop 20
#define TAM_Autos 20


int main()
{
    int Error=-9;
    char seguir='s';
    int flag=0;

    int opcion;
    EPropietario Propietario[TAM_Prop];
    eAutomovil Autos[TAM_Autos];

    //------HARCODEO ------------
    Error=inicializaVector(Propietario,TAM_Prop);
    Error=init_hark(Propietario,TAM_Prop);
    eAutomovil_initHardcode(Autos);
    flag=1;
    //-------------------------

        do
        {
            menu("1- Alta de propietario\n"
                 "2- Modificación de propietario\n"
                 "3- Baja de propietario\n"
                 "4- Mostrar Propietarios\n"
                 "5- Ingreso Auto\n"
                 "6- Muestra Autos X Propietario\n"
                 "7- Egreso Auto\n"
                 );

            scanf("%d",&opcion);
            switch(opcion)
            {
                case 1:
                    Error=Alta(Propietario,TAM_Prop);
                    flag=1;
                    break;
                case 2:
                    if(flag==1)
                    {
                        Error=muestra_Propietario(Propietario,TAM_Prop);
                        if(Error==0)
                        {
                            Error= eGen_modificacion(Propietario ,TAM_Prop, get_int_Rango("Ingrese ID de Propietario a modificar: ",0,TAM_Prop-1));
                        }//FIN if(Error==0)
                    }//hay algo cargado
                    break;
                case 3:
                    if(flag==1)
                    {
                       Error=muestra_Propietario(Propietario,TAM_Prop);
                        if(Error==0)
                        {
                            Error=eGen_Baja(Propietario ,TAM_Prop, get_int_Rango("Ingrese ID de Propietario a dar de baja: ",0,TAM_Prop-1));
                        }//FIN if(Error==0)
                    }
                    break;
                case 4:
                    if(flag==1)
                    {
                        Error=muestra_Propietario(Propietario,TAM_Prop);
                    }
                    break;
                case 5:
                    if(flag==1)
                    {
                       Error=muestra_Propietario(Propietario,TAM_Prop);
                        if(Error==0)
                        {
                            Error=Alta_Auto_propietario(Autos,TAM_Autos,Propietario,TAM_Prop);
                        }//FIN if(Error==0)
                    }
                    break;
                case 6:
                    if(flag==1)
                    {
                       Error= Muestra_propietario_Auto(Autos,TAM_Autos,Propietario,TAM_Prop);
                    }
                    break;
                case 7:  //egreso
                    if(flag==1)
                    {
                       //Error= Muestra_propietario_Auto(Autos,TAM_Autos,Propietario,TAM_Prop);
                       Error= Baja_Auto_propietario(Autos,TAM_Autos,Propietario,TAM_Prop);
                    }
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
