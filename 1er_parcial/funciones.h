
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//constantes
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

typedef struct
{
    int IdPropietario;
    char nombre[50];
    char direccion[50];
    char tarjeta[30];
    int estado;
}EPropietario;

typedef struct
{
    int marca;
    char patente[10];
	int idAutomovil;
    int idPropietario;
    int estado;
}eAutomovil;

int devolverHorasEstadia();

void eAutomovil_initHardcode(eAutomovil listadoAutomoviles[]);
int init_hark(EPropietario lista[],int tam);

void menu(char *opciones);
void sms_error(int mensaje,int Error);
char *get_char(char sms[],int LongitudCadena);

int get_int_Rango(char sms[30],int desde,int hasta);


/** \brief inicializo los estados en 0
 *
 * \param lista[] EPropietario
 * \param tam int
 * \return int
 *
 */
int  inicializaVector(EPropietario lista[],int tam);

int eGen_siguienteId(EPropietario listado[],int limite);
int obtenerEspacioLibre(EPropietario lista[],int cant);
EPropietario carga_datos();
int Alta(EPropietario lista[],int cant);

int eGen_buscarPorId_Auto(eAutomovil listado[] ,int limite, int id);

int eGen_buscarPorId(EPropietario listado[] ,int limite, int id);
int eGen_modificacion(EPropietario listado[] ,int limite, int id);


void muestra_datos_Propietario(EPropietario lista, int Nro);
int muestra_Propietario(EPropietario lista[],int cant);
int eGen_Baja(EPropietario listado[] ,int limite, int id);


int eGen_buscarPorId_prop(EPropietario listado[] ,int limite, int id);
void Marca_to_Texto(int codMarca, char textoMarca[]);
int Alta_Auto_propietario(eAutomovil Autos[],int cant_autos,EPropietario propietarios[],int Cant_Propietarios);


int Muestra_propietario_Auto(eAutomovil Autos[],int cant_autos,EPropietario propietarios[],int Cant_Propietarios);
void muestra_datos_Propietario_Autos(EPropietario lista, eAutomovil Autos);

int Baja_Auto_propietario(eAutomovil Autos[],int cant_autos,EPropietario propietarios[],int Cant_Propietarios);
