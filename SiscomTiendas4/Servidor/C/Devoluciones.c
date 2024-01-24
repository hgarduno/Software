#include <Devoluciones.h>
#include <SQLDevoluciones.h>
#include <ComunSiscomTiendas4.h>
#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OPTotalADevolver()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegresaTotalADevolver,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPDevolucion()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosDevolucion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdDevolucion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLInventarioDevolucion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLVentasDevolucion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLActualizaTotalVenta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLDevolucion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLDetalleDevolucion,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraDevolucion,lSOpOperaciones);
return lSOpOperaciones;
}
void ArgumentosDevolucion(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SQLDevolucion",pSAgsSiscom);
}
void RegresaTotalADevolver(SArgsSiscom *pSAgsSiscom)
{
float lfltTotal=0.0;
LCamposSiscomPro2 *lLCSiscomPro2Contador;
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
                  *lLCSiscomPro2Act=0;
int lintNRegRes=0;
char lchrArrTotal[20];
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
lfltTotal+=atof(SiscomObtenDato(lLCSiscomPro2Contador,"Precio"))*
	   atof(SiscomObtenDato(lLCSiscomPro2Contador,"Cantidad"));
sprintf(lchrArrTotal,"%.2f",lfltTotal);
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
		    &lLCSiscomPro2Act,
		    &lintNRegRes,
		    "Importe",
		    lchrArrTotal);
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
                      lintNRegRes,
		      "Respuesta",
		      lLCSiscomPro2Prim);
}
void RegistraDevolucion(SArgsSiscom *pSAgsSiscom)
{
EjecutaRegistroInformacion(pSAgsSiscom,"SQLDevolucion");
}
void GeneraIdDevolucion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Contador;
char lchrArrIdDevolucion[20];
   SiscomObtenNumeroUnicoChar(lchrArrIdDevolucion);
for(lLCSiscomPro2Contador=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Contador;
    lLCSiscomPro2Contador=lLCSiscomPro2Contador->SCP2PtrSig)
   SiscomAsignaDatoCampo2("IdDevolucion",lchrArrIdDevolucion,lLCSiscomPro2Contador);
}
