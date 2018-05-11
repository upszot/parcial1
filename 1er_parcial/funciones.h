
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int IdPropietario;
    char nombre[50];
    char direccion[50];
    char tarjeta[30];
    int estado;
}EPropietario;

void menu(char *opciones);
void sms_error(int mensaje,int Error);
char *get_char(char sms[],int LongitudCadena);

/** \brief inicializo los estados en 0
 *
 * \param lista[] EPropietario
 * \param tam int
 * \return int
 *
 */
int  inicializaVector(EPropietario lista[],int tam);


int obtenerEspacioLibre(EPropietario lista[],int cant);
EPropietario carga_datos();
int Alta(EPropietario lista[],int cant);
