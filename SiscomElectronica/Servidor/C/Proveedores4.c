#include <Proveedores4.h>
#include <SqlProveedores4.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>

#include <ComunSiscomElectronica4.h>


#include <string.h>

void Proveedores4(int pintSocket,
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
SiscomAgregaOperacion(SqlProveedores4,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoProveedores4,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviandoProveedores4(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];

SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);

SiscomEnviaAsociadoRespuestaCliente("Proveedores",
                                    lchrArrBuffer,
                                    pSiscomOpePtrDato);

return 0;
}


