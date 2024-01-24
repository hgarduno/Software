#include <Bodegas.h>
#include <SqlBodegas.h>
#include <ComunElectronica2.h>
#include <stdlib.h>

SiscomOperaciones2 *OPBodegas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlBodegas,lSOpOperaciones);
return lSOpOperaciones;
}


SiscomOperaciones2 *OPExistenciaProductoBodega()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlExistenciaProductoBodega,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPTransfiereBodegaExpendio()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosBodegas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaMaterialBodega,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaBodegaAExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaExistenciaExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(TransfiereBodegaExpendio,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OPInventarioBodega()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosInventarioBodegas,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaInventarioBodega,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaExistenciaBodega,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(InventarioBodega,lSOpOperaciones);
return lSOpOperaciones;
}

void ArgumentosBodegas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlBodegas",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlExpendio",pSAgsSiscom);
}

void ArgumentosInventarioBodegas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlInventarioBodega",pSAgsSiscom);
}
int ActualizandoExpendio(int pintPtoComAd,
			  const char *pchrPtrDirIpSvrAd,
			  SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrRegreso;
int lintNRegRegreso=0;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
if(!(lchrPtrRegreso=SiscomEjecutaRegistroInformacion2(
			pintPtoComAd,
			pchrPtrDirIpSvrAd,
			pSAgsSiscom,
			"SqlExpendio",
			&lLCSiscomPro2Reg,
			&lintNRegRegreso)))
{
SiscomLog("Actualizacion en el expedio Exitosa");
return 0;
}
else
{
SiscomLog("NO se pudo realizar la actualizacion en el expendio:%s (%d)",
	  lchrPtrRegreso,
	  lintNRegRegreso);
SiscomContenidoProtocolo(lLCSiscomPro2Reg);
return 1;
}
}
void ActualizandoBodega(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRegreso=0;
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlBodegas",
				 &lLCSiscomPro2Reg,
				 &lintNRegRegreso);
SiscomContenidoProtocolo(lLCSiscomPro2Reg);
}
void TransfiereBodegaExpendio(SArgsSiscom *pSAgsSiscom)
{
int lintPtoCom;
char lchrArrDirIpSvr[25];
char lchrArrBaseDatos[256];
SiscomComunicacionExpendio2(SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"idempresa"),
			    &lintPtoCom,
			    lchrArrDirIpSvr,
			    lchrArrBaseDatos);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomLog("El material se transfiere a: (%d,%s)",lintPtoCom,lchrArrDirIpSvr);
SiscomImprimeArgumento("SqlBodegas",pSAgsSiscom);
SiscomImprimeArgumento("SqlExpendio",pSAgsSiscom);
if(!ActualizandoExpendio(lintPtoCom,
			lchrArrDirIpSvr,
			pSAgsSiscom))
{
  ActualizandoBodega(pSAgsSiscom); 
RespondeEstadoOperacion(pSAgsSiscom,"0","Traspaso Existoso");
}
else
RespondeEstadoOperacion(pSAgsSiscom,"1","No se pudo establecer la comunicacion con el expendio");
}

void InventarioBodega(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintNRegRegreso=0;
SiscomEjecutaRegistroInformacion(pSAgsSiscom,
				 "SqlInventarioBodega",
				 &lLCSiscomPro2Reg,
				 &lintNRegRegreso);
RespondeEstadoOperacion(pSAgsSiscom,"0","Registro Exitoso");
/*SiscomContenidoProtocolo(lLCSiscomPro2Reg); */
}

void RespondeEstadoOperacion(SArgsSiscom *pSAgsSiscom,
			     const char *pchrPtrEdoOperacion,
			     const char *pchrPtrMensaje)
{
 SiscomAnexaRegistroRegreso(pSAgsSiscom,
 			    "Error,	\
			     Mensaje",
			     pchrPtrEdoOperacion,
			     pchrPtrMensaje);
SiscomEnviaRegreso(pSAgsSiscom);
}
