#include <CorteCaja.h>




#include <ComunSiscomElectronica4.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomMacrosInsercionesSql.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>


#include <string.h>
void CalculaCorteCaja(int pintSocket,
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
SiscomAgregaOperacion(MultiplicaSumaDenominaciones,&lSiscomProDat);
SiscomAgregaOperacion(SumaGastosCaja,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCalculoCorteCaja,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviandoCalculoCorteCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
MultiplicandoSumandoCajas(pSisOpePtrDato);
SiscomEnviaAsociadoEntradaCliente("Envio",lchrArrBuffer,pSisOpePtrDato);
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
return 0;
}
float RealizaSumatoriaGastosCaja(SiscomRegistroProL *pSisRegProLPtrGastos)
{

}
int SumaGastosCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
float lfltTotalGastos;
SiscomRegistroProL *lSisRegProLPtrGastos;
if((lSisRegProLPtrGastos=SiscomRegistrosAsociadosCampoEntrada("Envio",
							     "Gastos",
							     pSisOpePtrDato)))
{
lfltTotalGastos=SiscomObtenSumatoriaRegistros("Importe",lSisRegProLPtrGastos); 
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrGastos);
SiscomActualizaCampoAsociadoEntradaFloat("Envio",
					 "TotalGastos",
					 lfltTotalGastos,
					 pSisOpePtrDato);
}
return 0;
}
void MultiplicandoSumandoCajas(SiscomOperaciones *pSisOpePtrDato)
{
float lfltTotal;
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrCajas,*lSisRegProLPtrCajas1;
lSisRegProLPtrCajas1=lSisRegProLPtrCajas=SiscomObtenRegistrosCampoEntrada("Envio",pSisOpePtrDato);
for(;
    lSisRegProLPtrCajas;
    lSisRegProLPtrCajas=lSisRegProLPtrCajas->SiscomRegProLPtrSig)
{
lfltTotal=MultiplicaSumaCaja(SiscomObtenRegistrosCampoProL("Dinero",lSisRegProLPtrCajas));
SiscomActualizaCampoFloatRegistroActual("Total","%.2f",lfltTotal,lSisRegProLPtrCajas);
}
/*
SiscomRegistroProtocoloLog(lchrArrBuffer,
			   SiscomObtenRegistrosCampoProL("Dinero",lSisRegProLPtrCajas1));
*/
}

float MultiplicaSumaCaja(SiscomRegistroProL *pSisRegProLPtrDeno)
{
float lfltTotal=0.0;
for(;
    pSisRegProLPtrDeno;
    pSisRegProLPtrDeno=pSisRegProLPtrDeno->SiscomRegProLPtrSig)
{
SiscomMultiplicaCamposACampo("Valor","Cantidad","Importe","%.2f",pSisRegProLPtrDeno); 
lfltTotal+=SiscomObtenCampoRegistroProLFloat("Importe",pSisRegProLPtrDeno);
}
return lfltTotal;
}

int MultiplicaSumaDenominaciones(SiscomOperaciones *pSisOpePtrDato)
{
float lfltTotal;
SiscomRegistroProL *lSisRegProLPtrDeno;
lSisRegProLPtrDeno=SiscomRegistrosAsociadosCampoEntrada("Envio",	
						        "Dinero",
							pSisOpePtrDato);
lfltTotal=MultiplicaSumaCaja(lSisRegProLPtrDeno);
return 0;
}
