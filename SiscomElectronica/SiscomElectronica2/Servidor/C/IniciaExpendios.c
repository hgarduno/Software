#include <IniciaExpendios.h>
#include <SqlIniciaExpendios.h>
#include <ComunElectronica2.h>
#include <string.h>
SiscomOperaciones2 *OpIniciaDatosExpendio()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosIniciaExpendios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlObtenMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlObtenFirmasMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlObtenTiposPersonaMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlObtenTipoPrecio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlObtenPrecios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlObtenControlesCaja,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlObtenEdoControlesCaja,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioMatrizEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioMatrizExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioTiposPersona,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioPersonas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioFirmas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioPublicoEnGeneral,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioTipoPrecio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFamiliasMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlProductosMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlUnidadesMatriz,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaInsertaUnidades,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaInsertaFamilias,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaInsertaProductos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlFormaInsertaExistencias,lSOpOperaciones);

SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioPrecios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioControlesCaja,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendioEdoControlesCaja,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(IniciaDatosExpendio,lSOpOperaciones);
return lSOpOperaciones;
}

void IniciaDatosExpendio(SArgsSiscom *pSArgsSiscom)
{
/*
SiscomContenidoProtocolo(pSArgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlMatriz",pSArgsSiscom);
*/
/*
SiscomImprimeArgumento("SqlFamilias",pSArgsSiscom);
SiscomImprimeArgumento("SqlUnidades",pSArgsSiscom);
*/
/*
SiscomImprimeArgumento("SqlInsertando",pSArgsSiscom); 
*/
EjecutandoRegistro(pSArgsSiscom);
}

void ArgumentosIniciaExpendios(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(12,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlMatriz",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlExpendios",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlFamilias",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(3,"SqlProductos",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(4,"SqlUnidades",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(5,"SqlInsertando",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(6,"SqlTipoPrecio",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(7,"SqlPrecios",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(8,"SqlFirmas",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(9,"SqlTiposPersona",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(10,"SqlControlesCaja",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(11,"SqlEdoControlesCaja",pSAgsSiscom);

}

void EjecutandoRegistro(SArgsSiscom *pSAgsSiscom)
{
char lchrArrDirIp[25];
int lintPuerto;
char *lchrPtrEdoConexion;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRegreso=0;
ObtenComunicacionExpendio(pSAgsSiscom->LCSiscomPro2Dat,
			  lchrArrDirIp,
			  &lintPuerto);

if((lchrPtrEdoConexion=SiscomEjecutaRegistroInformacion2(
			   lintPuerto,
			   lchrArrDirIp,
			   pSAgsSiscom,
			   "SqlInsertando",
			   &lLCSiscomPro2Reg,
			   &lintNRegRegreso)))
{
SiscomLog("%s",lchrPtrEdoConexion);
}
else
SiscomLog("Se realizo la inicializacion del expendio");

}
void ObtenComunicacionExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			       char *pchrPtrDirIp,
			       int *pintPtrPuerto)
{
strcpy(pchrPtrDirIp,
	SiscomObtenDato(pLCSiscomPro2Dat,"diripsvrad"));
*pintPtrPuerto=atoi(SiscomObtenDato(pLCSiscomPro2Dat,"ptocomad"));
}
