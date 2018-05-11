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
        default:
            printf("Se produjo un Error Inesperado...");
            break;
    }
    printf("\n\n");
    system("pause");
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
            lista[i].estado=0;
        }//fin for(int i=0; i<tam ;i++)
    }
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

EPropietario carga_datos()
{
    EPropietario record;
    system("cls");
    strcpy(record.nombre,get_char("\nIngrese Nombre: ",50));
    strcpy(record.nombre,get_char("\nIngrese direccion: ",50));
    strcpy(record.nombre,get_char("\nIngrese tarjeta: ",30));
    record.estado=1;
    return record;
}


int Alta(EPropietario lista[],int cant)
{
    int retorno=-1;
    int Pos_libre;
    if(cant>0&&lista!=NULL)
    {
        retorno=-2;
        Pos_libre= obtenerEspacioLibre(lista,cant);
        if(Pos_libre>=0)
        {//Encontre una posicion libre
            retorno=0;
            lista[Pos_libre]=carga_datos();
        }
        else
        {
            printf("\n No hay espacio libre..");
        }
    }//if(cant>0&&personas!=NULL)
    return retorno;
}
