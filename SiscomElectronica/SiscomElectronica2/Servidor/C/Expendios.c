#include <Expendios.h>
#include <SqlExpendios.h>
#include <ComunElectronica2.h>

#include <stdlib.h>

SiscomOperaciones2 *OPExpendios()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlExpendios,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OpRegistraExpendio()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosExpendios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(GeneraIdExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraExpendio,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OpActualizaDatosExpendio()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosExpendios,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaEmpresa,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ActualizaDatosExpendio,lSOpOperaciones);
return lSOpOperaciones;
}
void GeneraIdExpendio(SArgsSiscom *pSAgsSiscom)
{
int lintIdExpendio=SiscomObtenNumeroUnico();

SiscomAsignaDatoCampoInt2(pSAgsSiscom->LCSiscomPro2Dat,
			  "ExpendioId",
			  -lintIdExpendio);
}
void RegistraExpendio(SArgsSiscom *pSArgsSiscom)
{
SiscomContenidoProtocolo(pSArgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlExpendios",pSArgsSiscom);
SiscomEnviaServidorArgumento(pSArgsSiscom,"SqlExpendios");
}


void ActualizaDatosExpendio(SArgsSiscom *pSArgsSiscom)
{
SiscomContenidoProtocolo(pSArgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlExpendios",pSArgsSiscom);
SiscomEnviaServidorArgumento(pSArgsSiscom,"SqlExpendios"); 
}
void ArgumentosExpendios(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlExpendios",pSAgsSiscom);
}
