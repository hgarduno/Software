#include <Devoluciones4.h>

#include <RegistraOrden.h>

#include <SqlDevoluciones.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>


void DevolucionOrden(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoOrden,&lSiscomProDat);
SiscomAgregaOperacion(SqlDevolucionOrden,&lSiscomProDat);
SiscomAgregaOperacion(DevolviendoOrden,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}


int DevolviendoOrden(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrBuffer[256];
 LogSiscom("Devolviendo la orden ");
 SiscomAsociadosArgumentoLog("SqlOrden","SentenciasSql",lchrArrBuffer,pSiscomOpePtrDatos);
}
