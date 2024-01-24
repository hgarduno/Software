#include <SeguridadCajas.h>
#include <SqlSeguridadCajas.h>
#include <ComunElectronica2.h>
#include <ServidorGeneral.h>
SiscomOperaciones2 *OpCajasYControles()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlCajasYControles,lSOpOperaciones2);
return lSOpOperaciones2;
}
SiscomOperaciones2 *OpControlesCaja()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(DireccionIpCaja,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlControlesCaja,lSOpOperaciones2);
return lSOpOperaciones2;
}
SiscomOperaciones2 *OpActualizaEdoControlCaja()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosEdoControlCaja,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlActualizaEdoControl,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ActualizaEdoControlCaja,lSOpOperaciones2);
return lSOpOperaciones2;
}

void DireccionIpCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("La direccion ip de la caja %s: el argumento de consulta(2) %s",
	  gchrArrDirIpCliente,
	  pSAgsSiscom->chrPtrArgConsulta[2]);
pSAgsSiscom->chrPtrArgConsulta[2]=strdup(gchrArrDirIpCliente);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);

}
void ActualizaEdoControlCaja(SArgsSiscom *pSArgsSiscom)
{
SiscomContenidoProtocolo(pSArgsSiscom->LCSiscomPro2Dat);
SiscomEnviaServidorArgumento(pSArgsSiscom,"SqlActualizaEdoControl");
}
void ArgumentosEdoControlCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlActualizaEdoControl",pSAgsSiscom);
}
