#include <zSiscomCampo.h>
#include <zSiscomRegistros.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <zSiscomDesarrollo4.h>
zSiscomCampo::zSiscomCampo():
		chrPtrNombre(0),
		chrPtrDato(0),
		zSisRegsAsociados(0)

{

}
zSiscomCampo::zSiscomCampo(const char *pchrPtrNombre,
			   const unsigned  char *pchrPtrDato):
			   zSisRegsAsociados(0)
{
 chrPtrNombre=strdup(pchrPtrNombre);
 chrPtrDato=pchrPtrDato ? 
 	    (const unsigned char *)strdup((const  char *)pchrPtrDato):
	    (const unsigned char *)0;
} 
zSiscomCampo::zSiscomCampo(zSiscomCampo *pzSisCamCampo):
				zSisRegsAsociados(0)
{
const unsigned char *lchrPtrDato=pzSisCamCampo->Dato();
    chrPtrNombre=strdup(pzSisCamCampo->Nombre());
    chrPtrDato=lchrPtrDato ? 
    		(const unsigned char *)strdup((const char *)lchrPtrDato):
		(const unsigned char *)0;
}
zSiscomCampo::zSiscomCampo(const char *pchrPtrNombre):
			   zSisRegsAsociados(0)
{
  chrPtrNombre=strdup(pchrPtrNombre);
  chrPtrDato=(const unsigned char *)0;
}
zSiscomCampo::zSiscomCampo(const char *pchrPtrNombre,
			   zSiscomRegistro *pzSisRegDato):
			   zSisRegsAsociados(0)
{
  chrPtrNombre=strdup(pchrPtrNombre);
  chrPtrDato=(const unsigned char *)0;
  if(!zSisRegsAsociados)
  {
	 zSisRegsAsociados=new zSiscomRegistros;
	 (*zSisRegsAsociados)<< pzSisRegDato;
  }
  else
  	(*zSisRegsAsociados) << pzSisRegDato;
}

zSiscomCampo::zSiscomCampo(const char *pchrPtrNombre,
			   zSiscomRegistros *pzSisRegsDatos):
			   zSisRegsAsociados(0)
{
chrPtrNombre=strdup(pchrPtrNombre);
  chrPtrDato=(const unsigned char *)0;
Asociados(pzSisRegsDatos);
}
void zSiscomCampo::Asociados(zSiscomRegistros *pzSisRegistros)
{
   zSisRegsAsociados=pzSisRegistros;
}
zSiscomRegistros *zSiscomCampo::Asociados()
{
 return zSisRegsAsociados;
}
const char *zSiscomCampo::Nombre()
{
return chrPtrNombre;
}
const unsigned char *zSiscomCampo::Dato()
{
return chrPtrDato ? chrPtrDato : (const unsigned char *)0;
}
int zSiscomCampo::DatoInt()
{
const char *lchrPtrDato=(const char *)Dato();
  if(lchrPtrDato)
  return atoi(lchrPtrDato);
  else
  return -65000;
}
float zSiscomCampo::DatoFloat()
{
const char *lchrPtrDato=(const char *)Dato();
  if(lchrPtrDato)
  return atof(lchrPtrDato);
  else
  return -65000.00;
}

bool zSiscomCampo::operator==(zSiscomCampo &pzSisCampo)
{
return !strcmp(Nombre(),pzSisCampo.Nombre());
}
/* Lunes 15 de Diciembre del 2014
 * Cuando los datos del campo se obtienen 
 * mediante alguna funcion que regresa 
 * el apuntador via malloc, se debe de 
 * llamar a estas funciones
 * El caso de la clase zSiscomRecibe es un
 * ejemplo de esta condicion
 */
void zSiscomCampo::Nombre(const char *pchrPtrNombre)
{
    chrPtrNombre=pchrPtrNombre;
}
void zSiscomCampo::Dato(const unsigned char *pchrPtrDato)
{
   if(chrPtrDato)
    free((void *)chrPtrDato);
    
     chrPtrDato=pchrPtrDato ? 
 	    (const unsigned char *)strdup((const  char *)pchrPtrDato):
	    (const unsigned char *)0;
}
void zSiscomCampo::Dato(zSiscomRegistro *pzSisRegDato)
{
if(zSisRegsAsociados &&
   zSisRegsAsociados->NNodos()==1)
   delete zSisRegsAsociados;
 zSisRegsAsociados=new zSiscomRegistros;
 (*zSisRegsAsociados) << pzSisRegDato;
}
void zSiscomCampo::Dato(zSiscomRegistros *pzSisRegsDatos)
{
if(zSisRegsAsociados)
   delete zSisRegsAsociados;
 zSisRegsAsociados=pzSisRegsDatos;
}

