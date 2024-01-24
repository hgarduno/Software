#include <Transferencias.h>
#include <ComunElectronica2.h>
#include <SqlTransferencias.h>
#include <stdlib.h>
SiscomOperaciones2 *OpTransferencias()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlTransferencias,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpReEnviaTransferencia()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(200,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ReEnviaTransferencia,lSOpOperaciones);
return lSOpOperaciones;
}
void ReEnviaTransferencia(SArgsSiscom *pSAgsSiscom)
{
int lintPuerto;
char lchrArrDirIp[28],
	lchrArrBaseDatos[128],
	*lchrPtrEdoRegistro;
const char *lchrPtrIdTransferencia;

LCamposSiscomPro2 *lLCSiscomPro2InfTrans=0,
		  *lLCSiscomPro2ProdsATrans=0;
SiscomLog("Re Enviando la Transferencia");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
lchrPtrIdTransferencia=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdTransferencia");
SiscomDatosComunicacionMatriz(&lintPuerto,lchrArrDirIp,lchrArrBaseDatos);
SiscomLog("La Matriz %s:%d",lchrArrDirIp,lintPuerto);
SiscomLog("ReEnviando la transferencia %s",lchrPtrIdTransferencia);

SqlInformacionTransferencia(lintPuerto,
			    lchrArrDirIp,
			    lchrPtrIdTransferencia,
			    &lLCSiscomPro2InfTrans);
SqlProductosATransferir(lintPuerto,
			lchrArrDirIp,
			lchrPtrIdTransferencia,
			&lLCSiscomPro2ProdsATrans);
SiscomContenidoProtocolo(lLCSiscomPro2InfTrans);
SiscomContenidoProtocolo(lLCSiscomPro2ProdsATrans);
if(!(lchrPtrEdoRegistro=SqlInsercionesAlExpendio(lLCSiscomPro2InfTrans,
						lLCSiscomPro2ProdsATrans)))
{
 SiscomLog("Se realizo la actualizacion con exito");
 SqlActualizaTransferenciaExitosa(lintPuerto,lchrArrDirIp,lchrPtrIdTransferencia);
}
}
