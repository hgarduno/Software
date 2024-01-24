#include <SalidaMaterial.h>
#include <ComunElectronica2.h>
#include <SqlMotivosSalidas.h>
#include <SqlSalidaMaterial.h>

#include <stdlib.h>
SiscomOperaciones2 *OpMotivosSalidas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(
					sizeof(SiscomOperaciones2 )*100
					);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosMotivosSalidas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlMotivosSalidas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaMotivosSalidas,lSOpOperaciones);

return lSOpOperaciones;
}

SiscomOperaciones2 *OpRegistraSalidaMaterial()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(
					sizeof(SiscomOperaciones2 )*100
					);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosSalidaMaterial,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(IniciaArgumentoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraSalidaMaterial,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlRegistraDetalleSalidaMaterial,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaInventario,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaRegistroSalidaMaterial,lSOpOperaciones);

return lSOpOperaciones;
}


void EnviaMotivosSalidas(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("==============");
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
SiscomLog("==============");
SiscomImprimeArgumento("SqlMotivosSalidas",pSAgsSiscom);

SiscomEnviaArgumentoCliente("SqlMotivosSalidas",
			    pSAgsSiscom);
}

void EnviaRegistroSalidaMaterial(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRegreso=0;

SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlSalidaMaterial",
				 &lLCSiscomPro2Reg,
				 &lintNRegRegreso);

SiscomLog("==============");
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
SiscomImprimeArgumento("DatosSalidaMaterial",pSAgsSiscom);
SiscomLog("==============");
SiscomImprimeArgumento("SqlSalidaMaterial",pSAgsSiscom);
}
void ArgumentosMotivosSalidas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(5,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlMotivosSalidas",pSAgsSiscom);
}

void ArgumentosSalidaMaterial(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(5,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlSalidaMaterial",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"DatosSalidaMaterial",pSAgsSiscom);
}

void IniciaArgumentoDatos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2PrimDat=0,
		  *lLCSiscomPro2ActDat=0;
int lintNRegistros=0;
char lchrArrIdSalida[28];
char lchrArrFechaHoy[52];
SiscomObtenNumeroUnicoChar(lchrArrIdSalida);
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
SiscomAnexaRegistroPro2(&lLCSiscomPro2PrimDat,
			&lLCSiscomPro2ActDat,
			&lintNRegistros,
			"IdRegistro,	\
			 Fecha",
			 lchrArrIdSalida,
			 lchrArrFechaHoy);
SiscomAsignaInformacionArgumento("DatosSalidaMaterial",
				 pSAgsSiscom,
				 lLCSiscomPro2PrimDat,
				 lLCSiscomPro2ActDat,
				 lintNRegistros);
}
