#include <CorteCaja.h>
#include <SqlCorteCaja.h>
#include <ComunElectronica2.h>
SiscomOperaciones2 *OpRegistraCorteCaja()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosCorteCaja,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(GeneraIdCorteCaja,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(CopiaImporteTotalCorte,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlInsertaCorteCaja,lSOpOperaciones2);
/*SiscomAnexaOperacionAlArreglo2(SqlActualizaEstadoCaja,lSOpOperaciones2); */
SiscomAnexaOperacionAlArreglo2(SqlInsertaDetalleCorteCaja,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(RegistraCorteCaja,lSOpOperaciones2);  
return lSOpOperaciones2;
}
void RegistraCorteCaja(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomLog("Y El Sql....");
lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlCorteCaja",pSAgsSiscom);
SiscomContenidoProtocolo(lLCSiscomPro2Dat);
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlCorteCaja");
}
void ArgumentosCorteCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlCorteCaja",pSAgsSiscom);
}
void GeneraIdCorteCaja(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraIdRegistro(pSAgsSiscom,"IdReporte");
}
void CopiaImporteTotalCorte(SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrImporteTotal;
lchrPtrImporteTotal=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2DatUltimo,"Total");
SiscomAsignaDatoCampo2("Total",lchrPtrImporteTotal,pSAgsSiscom->LCSiscomPro2Dat);
}

