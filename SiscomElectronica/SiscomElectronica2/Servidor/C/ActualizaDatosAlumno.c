#include <ActualizaDatosAlumno.h>
#include <ComunElectronica2.h>
#include <SiscomAplicaciones.h>

#include <stdlib.h>
SiscomOperaciones2 *OpActualizaDatosAlumno()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(CopiaGeneralesAlumnoEntrada,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomArgumentosPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomValidaNombreVacio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomNormalizaPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ReAsignaErrorPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SiscomPersonaEnNormalizados,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ActualizaDatosAlumno,lSOpOperaciones);
return lSOpOperaciones;
}

void ReAsignaErrorPersonaEnNormalizados(SArgsSiscom *pSAgsSiscom)
{
    pSAgsSiscom->SiscomError[2]=EjecutaActualizaDatosAlumno; 
}
/*
 * Miercoles 14 De Septiembre 2011 
 *
 * Este sera considerado el caso feliz de la actualizacion de los
 * datos, en el que despues de normalizar la informacion que se
 * actualizara si se encuentra registrado en normalizados 
 * por lo que se procede a actualizar los datos en personas
 * telefonos, etc
 *
 */
void EjecutaActualizaDatosAlumno(SArgsSiscom *pSAgsSiscom)
{
  SiscomLog("Se Actualizan los datos del Alumno");
  SiscomActualizaPersona(pSAgsSiscom);
  SiscomImprimeArgumento("SisSQLPersona",pSAgsSiscom);
}
void ActualizaDatosAlumno(SArgsSiscom *pSAgsSiscom)
{
/*
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
SiscomImprimeArgumento("SisNormalizado",pSAgsSiscom);
SiscomImprimeArgumento("SisRegistrosEnNormalizados",pSAgsSiscom);
SiscomLog("El Regreso:%d",pSAgsSiscom->intCodigoRetorno);
*/
}

void CopiaGeneralesAlumnoEntrada(SArgsSiscom *pSAgsSiscom)
{
 pSAgsSiscom->LCSiscomPro2Dat=SiscomSubRegistroPrim(0,pSAgsSiscom->LCSiscomPro2SREntrada);
}
