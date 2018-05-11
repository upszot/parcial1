#include "funciones.h"

void menu(char *opciones)
{
    system("cls");
    printf("%s \n",opciones);
    printf("\n0.  Salir \n");
    printf("\n\tIngrese Opcion: ");
}

void sms_error(int mensaje,int Error)
{
    system("cls");
    printf("\n\n");
    switch(mensaje)
    {
        case -1:
            printf("ERROR-COD: %d -- Inicializar listado",Error);
            break;
        case 1:
            printf("ERROR-COD: %d -- Alta",Error);
            break;
        case 2:
            printf("ERROR-COD: %d -- Modificacion",Error);
            break;
        case 3:
            printf("ERROR-COD: %d -- Baja",Error);
            break;
        case 99:
            printf("ERROR-COD: %d -- No Encontro ID ",Error);
            break;
        default:
            printf("Se produjo un Error Inesperado...");
            break;
    }
    printf("\n\n");
    system("pause");
}

int get_int_Rango(char sms[30],int desde,int hasta)
{
    int aux;
    int flag=0;
    do
    {
        if(flag==1)
        {
            printf("\n Valor fuera de Rango Debe ser: (%d< X <%d)  \n",desde-1,hasta+1);
            system("pause");
            system("cls");
        }
        fflush(stdin);
        printf("%s",sms);
        scanf("%d",&aux);
        flag=1;
    }while( (aux<desde) || (aux>hasta) );

    return aux;
}

char *get_char(char sms[],int LongitudCadena)
{
    char *PTexto= (char *) malloc (sizeof(char)*LongitudCadena);

    //Variable temporal donde cargo el texto pedido...
    //es mas larga para de esa forma poder controlar si se exedieron en la longitud
    char TextoLibre[LongitudCadena+4];

    fflush(stdin);
    int flag=0;
    do
    {
        if(flag==1)
        {
            printf("\n La longitud maxima del campo es: %d \n",LongitudCadena);
            system("pause");
            system("cls");
        }
        printf("%s ",sms);
        // fgets lee desde el teclado (stdin) pero solo almacena en la variable
        //la cantidad de caracteres de longitud +3... (trunca todolo lo que se exeda...
        //si lo que ingresa es mas chico que esa longitud.. carga hasta que le das enter..
        //pero carga el retorno de carro en la variable
        fgets(TextoLibre,LongitudCadena+3,stdin);
        flag=1;
    }while(strlen(TextoLibre) >= LongitudCadena);
    //la funcion strtok elimina un caracter de el arreglo... en este caso el retorno de carro...
    strcpy(PTexto,strtok(TextoLibre, "\n"));
    return PTexto;
}


int  inicializaVector(EPropietario lista[],int tam)
{
    int retorno=-1;
    if(tam>0 && lista!=NULL)
    {
        retorno=0;
        for(int i=0; i<tam ;i++)
        {
            lista[i].IdPropietario=0;
            lista[i].estado=0;
        }//fin for(int i=0; i<tam ;i++)
    }
    return retorno;
}

void eAutomovil_initHardcode(eAutomovil listadoAutomoviles[])
{

    //                                 marca   patente     ID  FK estado
    listadoAutomoviles[0] = (eAutomovil){AUDI,"AAA",1,1,1};
    listadoAutomoviles[1] = (eAutomovil){3,"CCC",2,1,1};
    listadoAutomoviles[2] = (eAutomovil){3,"DDD",3,1,1};
    listadoAutomoviles[3] = (eAutomovil){AUDI,"BBB",4,2,1};
    listadoAutomoviles[4] = (eAutomovil){AUDI,"ZZZ",5,3,1};
    listadoAutomoviles[5] = (eAutomovil){AUDI,"III",6,3,1};
    listadoAutomoviles[6] = (eAutomovil){4,"HHH",7,3,1};
    listadoAutomoviles[7] = (eAutomovil){AUDI,"EEE",8,3,1};
    listadoAutomoviles[8] = (eAutomovil){4,"FFF",9,3,1};
    listadoAutomoviles[9] = (eAutomovil){AUDI,"GGG",10,3,1};

    /*
        int marca;
    char patente[10];
	int idAutomovil;
    int idPropietario;
    int estado;
*/
    //int id[]= {1,2,3,4,5,6,7,8,9,10};
    //char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    //int marca[]= {1,3,3,2,2,3,3,4,3,1};
    //int propietario[]= {2,1,2,1,3,3,4,1,4,3};

}

int init_hark(EPropietario lista[],int tam)
{

    int retorno=0;
    lista[0].IdPropietario=1;
    lista[1].IdPropietario=2;
    lista[2].IdPropietario=3;
    lista[3].IdPropietario=4;

    lista[0].estado=1;
    lista[1].estado=1;
    lista[2].estado=1;
    lista[3].estado=1;

    strcpy(lista[0].nombre,"Juan");
    strcpy(lista[1].nombre,"Luis");
    strcpy(lista[2].nombre,"Maria");
    strcpy(lista[3].nombre,"Jose");

    strcpy(lista[0].direccion,"mitre");
    strcpy(lista[1].direccion,"urquiza");
    strcpy(lista[2].direccion,"belgrano");
    strcpy(lista[3].direccion,"alsina");

    strcpy(lista[0].tarjeta,"111-111");
    strcpy(lista[1].tarjeta,"222-222");
    strcpy(lista[2].tarjeta,"333-333");
    strcpy(lista[3].tarjeta,"444-444");
    return retorno;
}

int obtenerEspacioLibre(EPropietario lista[],int cant)
{
    int retorno=-1;//pq no es un valor valida para el subindice de un vector
    if(cant>0&&lista!=NULL)
    {
        retorno=-2;
        for(int i=0; i<cant ;i++)
        {//recorro mi listado de personas
            if(lista[i].estado==0)
            {//Esta libre
                retorno=i;
                break;
            }
        }//for(int i=0; i<cant ;i++)
    }//fin if(cant>0&&lista!=NULL)
    return retorno;
}

int eGen_siguienteId(EPropietario listado[],int limite)
{
    int retorno = 0;
    if(limite > 0 && listado != NULL)
    {
        for(int i=0; i<limite; i++)
        {
            if(listado[i].estado==1)
            {//ocupado
                    if(listado[i].IdPropietario > retorno)
                    {
                         retorno=listado[i].IdPropietario;
                    }
            }
        }//FIN for(int i=0; i<limite; i++)
    }
    return retorno+1;
}

int eGen_siguienteIdAuto(eAutomovil listado[],int limite)
{
    int retorno = 0;
    if(limite > 0 && listado != NULL)
    {
        for(int i=0; i<limite; i++)
        {
            if(listado[i].estado==1)
            {//ocupado
                    if(listado[i].idAutomovil > retorno)
                    {
                         retorno=listado[i].idAutomovil;
                    }
            }
        }//FIN for(int i=0; i<limite; i++)
    }
    return retorno+1;
}

EPropietario carga_datos()
{
    EPropietario record;
    system("cls");

    strcpy(record.nombre,get_char("\nIngrese Nombre: ",50));
    strcpy(record.direccion,get_char("\nIngrese direccion: ",50));
    strcpy(record.tarjeta,get_char("\nIngrese tarjeta: ",30));
    //record.estado=1;
    return record;
}

void Marca_to_Texto(int codMarca, char textoMarca[])
{
    switch(codMarca)
    {
        case ALPHA_ROMEO:
            strcpy(textoMarca,"ALPHA ROMEO");
            break;
        case FERRARI:
            strcpy(textoMarca,"FERRARI");
            break;
        case AUDI:
            strcpy(textoMarca, "AUDI");
            break;
        case OTROS:
            strcpy(textoMarca, "OTRA MARCA");
            break;
    }
}

int Alta_Auto_propietario(eAutomovil Autos[],int cant_autos,EPropietario propietarios[],int Cant_Propietarios)
{
    int retorno=-1;
    int ID_Prop;
    int PosID_Prop;
    int PosID_Auto;

    if(cant_autos > 0 && Autos != NULL && Cant_Propietarios >0 && propietarios !=NULL)
    {
        retorno = -2;

        ID_Prop=get_int_Rango("\nIngrese su ID de propietario: ",0,Cant_Propietarios);
        PosID_Prop=eGen_buscarPorId_prop(propietarios,Cant_Propietarios,ID_Prop);
        if(PosID_Prop>=0)
        {// existe
            retorno=-3;

                PosID_Auto=eGen_siguienteIdAuto(Autos,cant_autos);
                if(PosID_Auto>=0)
                {
                    retorno=0;

                    Autos[PosID_Auto].estado=1;
                    Autos[PosID_Auto].idPropietario=ID_Prop;
                    Autos[PosID_Auto].idAutomovil=PosID_Auto;
                    Autos[PosID_Auto].marca=get_int_Rango("Ingrese Marca 1.ALPHA ROMEO, 2.FERRARI, 3.AUDI, 4.OTRA MARCA: ",1,4);
                    strcpy(Autos[PosID_Auto].patente,get_char("\n Ingrese Patente: ",10));
                }
                else
                {
                    retorno = -5;
                }//FIN if(PosID_Auto>=0)

        }//FIN if(PosID_Prop>=0)
    }//    if(cant_autos > 0 && Autos != NULL && Cant_Propietarios >0 && propietarios !=NULL)
    return retorno;
}

int Alta(EPropietario lista[],int cant)
{
    int retorno=-1;
    int Pos_libre;
    //int Next_ID;
    if(cant>0&&lista!=NULL)
    {
        retorno=-2;

        Pos_libre= obtenerEspacioLibre(lista,cant);
        if(Pos_libre>=0)
        {//Encontre una posicion libre
            retorno=0;

            system("cls");
            lista[Pos_libre].IdPropietario=eGen_siguienteId(lista,cant);
            strcpy(lista[Pos_libre].nombre,get_char("\nIngrese Nombre: ",50));
            strcpy(lista[Pos_libre].direccion,get_char("\nIngrese direccion: ",50));
            strcpy(lista[Pos_libre].tarjeta,get_char("\nIngrese tarjeta: ",30));
            lista[Pos_libre].estado=1;
            //lista[Pos_libre]=carga_datos();
        }
        else
        {
            printf("\n No hay espacio libre..");
        }
    }//if(cant>0&&personas!=NULL)
    return retorno;
}

int eGen_buscarPorId_prop(EPropietario listado[] ,int limite, int id)
{
    int retorno = -1;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(int i=0;i<limite;i++)
        {
            if(listado[i].estado == 1 && listado[i].IdPropietario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eGen_buscarPorId_Auto(eAutomovil listado[] ,int limite, int id)
{
    int retorno = -1;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(int i=0;i<limite;i++)
        {
            if(listado[i].estado == 1 && listado[i].idAutomovil == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));
    horas = (rand()%24)+1;
    return horas ;

}

void muestra_datos_Propietario(EPropietario lista, int Nro)
{// impreme los datos
    //printf("\n Nro de persona: %d",Nro);
    printf(" ID: %d",lista.IdPropietario);
    printf("\t Nombre: %s",lista.nombre);
    printf("\t Direccion: %s",lista.direccion);
    printf("\t Tarjeta: %s",lista.tarjeta);
    printf("\n\n");
}

void muestra_datos_Propietario_Autos(EPropietario lista, eAutomovil Autos)
{// impreme los datos
    //printf("\n Nro de persona: %d",Nro);
    printf(" ID: %d",lista.IdPropietario);
    printf("\t Nombre: %s",lista.nombre);
    printf("\t --- ID Auto: %d",Autos.idAutomovil);
    printf("\t Patente: %s",Autos.patente);

    char marca[10];

    Marca_to_Texto(Autos.marca,marca);
    printf("\t Marca: %s",marca);


    printf("\n\n");
}

int Muestra_propietario_Auto(eAutomovil Autos[],int cant_autos,EPropietario propietarios[],int Cant_Propietarios)
{
    int retorno=-1;

    if(cant_autos > 0 && Autos != NULL && Cant_Propietarios >0 && propietarios !=NULL)
    {
        retorno = -2;
        for(int j=0;j<Cant_Propietarios;j++)
        {
            if(propietarios[j].estado==1)
            {//propietario activo
                for(int i=0;i<cant_autos;i++)
                {
                    if( Autos[i].estado==1)
                    {//el propietario tiene un auto
                        retorno=0;
                        if(Autos[i].idPropietario==propietarios[j].IdPropietario)
                        {
                            muestra_datos_Propietario_Autos(propietarios[j], Autos[i]);
                        }

                    }
                }//for(int i=0;i<cant_autos;i++)
            }//if(propietarios[j].estado==1)
        }
    }//    if(cant_autos > 0 && Autos != NULL && Cant_Propietarios >0 && propietarios !=NULL)
    if(retorno==0)
    {
        system("pause");
    }
    return retorno;
}



int Baja_Auto_propietario(eAutomovil Autos[],int cant_autos,EPropietario propietarios[],int Cant_Propietarios)
{
    int retorno=-1;
    int Cobrar;
    int PosID_Auto;
    int PosID_Prop;
    int ID_Auto;
    int ID_Prop;

    if(cant_autos > 0 && Autos != NULL && Cant_Propietarios >0 && propietarios !=NULL)
    {
        retorno = -2;
        for(int j=0;j<Cant_Propietarios;j++)
        {
            if(propietarios[j].estado==1)
            {//propietario activo
                for(int i=0;i<cant_autos;i++)
                {
                    if( Autos[i].estado==1)
                    {//el propietario tiene un auto
                        retorno=0;
                        if(Autos[i].idPropietario==propietarios[j].IdPropietario)
                        {
                            muestra_datos_Propietario_Autos(propietarios[j], Autos[i]);
                        }

                    }
                }//for(int i=0;i<cant_autos;i++)
            }//if(propietarios[j].estado==1)
        }

         ID_Prop=get_int_Rango("\n\nIngrese ID Propietario: ",0,Cant_Propietarios);
         PosID_Prop=eGen_buscarPorId(propietarios ,Cant_Propietarios,ID_Prop);


        if(PosID_Prop>=0)
        {//exite el propietario

            ID_Auto=get_int_Rango("\nIngrese ID Auto a dar de baja: ",0, eGen_siguienteIdAuto(Autos,cant_autos));
            PosID_Auto=eGen_buscarPorId_Auto(Autos ,cant_autos,ID_Auto );
            if(PosID_Auto>=0)
            {//existe el auto

                Cobrar=devolverHorasEstadia();
                Autos[PosID_Auto].estado=0;

                printf("\n\nCosto: %d\n",Cobrar);
                system("pause");

            }
            else
            {
                retorno=-4;
            }
        }
        else
        {
            retorno =-3;
        }



    }//    if(cant_autos > 0 && Autos != NULL && Cant_Propietarios >0 && propietarios !=NULL)
    if(retorno==0)
    {
        system("pause");
    }
    return retorno;
}



int muestra_Propietario(EPropietario lista[],int cant)
{
    int retorno=-1;
    system("cls");
    if(cant>0&&lista!=NULL)
    {
        retorno=-2;
        for(int i=0;i<cant;i++)
        {//recorro e imprimo
            if(lista[i].estado==1)
            {
                muestra_datos_Propietario(lista[i],i);
                retorno=0;
            }
        }
        if(retorno==0)
        {
            system("pause");
        }
    }//FIN if(cant>0&&personas!=NULL)
    return retorno;
}


int eGen_buscarPorId(EPropietario listado[] ,int limite, int id)
{
    int retorno = -1;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(int i=0;i<limite;i++)
        {
            if(listado[i].estado == 1 && listado[i].IdPropietario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eGen_modificacion(EPropietario listado[] ,int limite, int id)
{
    int retorno = -1;
    int PosID;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        PosID=eGen_buscarPorId(listado,limite,id);
        if(PosID >= 0)
        {
            retorno = 0;
            strcpy(listado[PosID].tarjeta,get_char("\n Ingrese Tarjeta: ",30));
            listado[PosID].estado = 1;
        }
        else
        {//en este caso PosID va a tener el codigo de error...
            retorno = -3;
            sms_error(99,PosID);
        }

    }
    return retorno;
}


int eGen_Baja(EPropietario listado[] ,int limite, int id)
{
    int retorno = -1;
    int PosID;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        PosID=eGen_buscarPorId(listado,limite,id);
        if(PosID >= 0)
        {
            retorno = 0;
            listado[PosID].estado = 0;
        }
        else
        {//en este caso PosID va a tener el codigo de error...
            retorno = -3;
            sms_error(99,PosID);
        }

    }
    return retorno;
}
