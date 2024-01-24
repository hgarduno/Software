#include <GastosExpendio.h>
#include <SqlGastosExpendio.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <ComunSiscomElectronica4.h>
#include <SqlProductosSE.h>

#include <string.h>


void GastosSiscom(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlGastosSiscom,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoGastosSiscom,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviandoGastosSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];

SiscomEnviaAsociadoRespuestaCliente("Gastos",
				    lchrArrBuffer,
				    pSiscomOpePtrDato);
return 0;
}
