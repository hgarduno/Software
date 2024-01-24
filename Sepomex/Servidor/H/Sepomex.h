#ifndef __SEPOMEX_H__
#define __SEPOMEX_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>
void ConsultaSepomex(int,int);
void RegistraSepomex(int,int);


int EsConsultaEstados(char **);
void FormaConsultaEstados(char **,SiscomOperacionesServidor *);

int EsConsultaMunicipios(char **);
void FormaConsultaMunicipios(char **,SiscomOperacionesServidor *);

int EsConsultaTAsentamientos(char **);
void FormaConsultaTAsentamientos(char **,SiscomOperacionesServidor *);

int EsConsultaAsentamientos(char **);
void FormaConsultaAsentamientos(char **,SiscomOperacionesServidor *);


SiscomOperaciones2 *SepomexEstados();
SiscomOperaciones2 *SepomexMunicipios();
SiscomOperaciones2 *SepomexAsentamientos();
/*!
 * Se declara el apuntador a funcion ComunicacionAccesoDatosSepomex <br>
 * debido a que en la aplicacion de las rutinas de este modulo no se <br>
 * llenaba las variables de direccion ip y puerto del servidor de acceso a datos <br>
 * esto se observo en la aplicacion del modulo en el sistema SISCOMElectronica <br>
 * con lo que en el modulo de consultas del sistema se inicia este apuntador a funcion <br>
 * 
 */
extern void (*ComunicacionAccesoDatosSepomex)(SArgsSiscom *);
#endif
