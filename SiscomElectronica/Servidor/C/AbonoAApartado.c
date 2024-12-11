#include <AbonoAApartado.h>

#include <SqlAbonoAApartado.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>


#include <string.h>
#include <stdlib.h>
void AbonoAApartado(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoAbonoAApartado,&lSiscomProDat);
SiscomAgregaOperacion(AgregaFechaAbonoAApartado,&lSiscomProDat);
SiscomAgregaOperacion(SqlAbonoAApartado,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraAbonoAApartado,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoAbonoAApartado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviandoAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");


return 0;


}


int ArgumentoAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlAbonoAApartado",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}


int AgregaFechaAbonoAApartado(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAsignaFechaHoraAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
return 0;
}
