#include <SincronizaExpendio.h>
#include <ComunElectronica2.h>
SiscomOperaciones2 *OpSincronizaExpendio()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SincronizaExpendio,lSOpOperaciones2);
return lSOpOperaciones2;
}

void SincronizaExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
}

void ProductosMatriz(const char *pchrPtrIp,
		     int pintPuerto,
		     LCamposSiscomPro2 **pLCSiscomPro2Reg)
{



}
