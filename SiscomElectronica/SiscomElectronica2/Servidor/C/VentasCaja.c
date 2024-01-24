#include <VentasCaja.h>
#include <SqlVentasCaja.h>
#include <ComunElectronica2.h>
#include <stdlib.h>
SiscomOperaciones2 *OpVentasPorCaja()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlVentasPorCaja,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(CalculaTotalEnCaja,lSOpOperaciones2); 
SiscomAnexaOperacionAlArreglo2(SiscomEnviaRegreso,lSOpOperaciones2);
return lSOpOperaciones2;

}
SiscomOperaciones2 *OpVentasPorCajaFecha()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlVentasPorCajaFecha,lSOpOperaciones2);
return lSOpOperaciones2;

}
SiscomOperaciones2 *OpCajasRegistradas()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlCajasRegistradas,lSOpOperaciones2);
return lSOpOperaciones2;

}
SiscomOperaciones2 *OpRegistraImporteCaja()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosCajas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaImporteCaja,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaImporteCaja,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaImporteCajaServidor,lSOpOperaciones);

return lSOpOperaciones;

}
void ArgumentosCajas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlCajas",pSAgsSiscom);
}
int ObtenEstadoReporte(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
return atoi(SiscomObtenDato(pLCSiscomPro2Dat,"edoreporte"));
}
void CalculaTotalEnCaja(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Regreso;
float lfltTotalCorte,
	lfltTotalVentas,
	lfltImporteInicial,
	lfltTotalEnCaja;

for(;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{
    lfltTotalCorte=SiscomObtenCampoAFloat(lLCSiscomPro2Dat,"totalcorte");
    lfltTotalVentas=SiscomObtenCampoAFloat(lLCSiscomPro2Dat,"totalventas");
    lfltImporteInicial=SiscomObtenCampoAFloat(lLCSiscomPro2Dat,"importeinicial");
    lfltTotalEnCaja=(lfltTotalVentas+lfltImporteInicial)-lfltTotalCorte;
    SiscomAsignaDatoCampoFloat2(lLCSiscomPro2Dat,
				 "totalencaja",
				 lfltTotalEnCaja);
}
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
}
void EnviaImporteCajaServidor(SArgsSiscom *pSAgsSiscom)
{
	SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlCajas");
}
