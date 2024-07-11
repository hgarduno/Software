#include <CorteCaja.h>

#include <SqlCorteCajaSucursal.h>


#include <ComunSiscomElectronica4.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomMacrosInsercionesSql.h>
#include <SiscomFuncionesComunes.h>
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

void CambiosCaja(int pintSocket,
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
SiscomAgregaOperacion(SqlCambiosCaja,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCambiosCaja,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConsultaCambioCaja(int pintSocket,
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
SiscomAgregaOperacion(SqlCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(AcondicionandoParaMostrar,&lSiscomProDat);
SiscomAgregaOperacion(EnviandoCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void RegistraCambioCaja(int pintSocket,
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
SiscomAgregaOperacion(ArgumentoCorteCaja,&lSiscomProDat);
SiscomAgregaOperacion(AgregaArgumentoCajaCambio,&lSiscomProDat);
SiscomAgregaOperacion(AgregaArgumentoDatosCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(YaHayCajaConCambio,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroCambioCaja,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoCambio,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int RegistrandoCambio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadosArgumentoLog("SqlCorteCaja",
                            "SentenciasSql",
                             lchrArrBuffer,
                           pSisOpePtrDato);
return 0;
}

int EnviandoCalculoCorteCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
MultiplicandoSumandoCajas(pSisOpePtrDato);
SiscomEnviaAsociadoEntradaCliente("Envio",lchrArrBuffer,pSisOpePtrDato);
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

int ArgumentoCorteCaja(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlCorteCaja",
                                  pSiscomOpePtrDato->chrArrBaseDatos,
                                  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
                                  lchrArrBuffer,
                                  pSiscomOpePtrDato);
return 0;
}
int AgregaArgumentoCajaCambio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrCajaCambio;
lSisRegProLPtrCajaCambio=CajaDeCambio(pSisOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrCajaCambio);
SiscomAgregaArgumentoOperacion("CajaCambio",
			       lSisRegProLPtrCajaCambio,
			       lSisRegProLPtrCajaCambio,
			       pSisOpePtrDato);
			      
return 0;
}
int AgregaArgumentoDatosCambioCaja(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
	lchrArrIdCambioCaja[28],
	lchrArrFecha[28];;


SiscomRegistroProL *lSisRegProLPtrPrim=0,
		   *lSisRegProLPtrAct=0;

SiscomObtenNumeroUnicoChar(lchrArrIdCambioCaja);
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);

SiscomAnexaRegistroPro(&lSisRegProLPtrPrim,
		       &lSisRegProLPtrAct,
		       lchrArrBuffer,
		       "IdCambioCaja,Fecha,",
		       lchrArrIdCambioCaja,
		       lchrArrFecha);
SiscomAgregaArgumentoOperacion("DCorteCaja",
			       lSisRegProLPtrPrim,
			       lSisRegProLPtrAct,
			       pSisOpePtrDato);

return 0;
}
SiscomRegistroProL *CajaDeCambio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrCajas;
lSisRegProLPtrCajas=SiscomObtenRegistrosCampoEntrada("Envio",pSisOpePtrDato);
return SiscomBuscaRegistroLista("Nombre","Cambio",lSisRegProLPtrCajas);
}
SiscomRegistroProL *EfectivoCambioCaja(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrCCaja;

if((lSisRegProLPtrCCaja=CajaDeCambio(pSisOpePtrDato)))
return SiscomObtenRegistrosCampoProL("Dinero",lSisRegProLPtrCCaja);
}
int YaHayCajaConCambio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrIdCajaCambio[128];
   if(SqlCajaConCambio(pSisOpePtrDato,lchrArrIdCajaCambio))
   {
	SiscomActualizaCampoArgumento2("DCorteCaja",
				       "IdCambioCaja",
				       lchrArrIdCajaCambio,
				       pSisOpePtrDato);
	SqlActualizaCambioCaja(pSisOpePtrDato);

   }
   else
	SqlRegistraCambioCaja(pSisOpePtrDato);
}

int EnviandoCambiosCaja(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[256];
SiscomEnviaAsociadoRespuestaCliente("CambiosCaja",lchrArrBuffer,pSisOpePtrDatos);
return 0;
}
char *CampoAcondicionado(const char *pchrPtrCampo,
			      SiscomRegistroProL *pSisRegProLPtrReg)
{
char lchrArrRegreso[12];
sprintf(lchrArrRegreso,
	 "%.0f",
	 SiscomObtenCampoRegistroProLFloat(pchrPtrCampo,pSisRegProLPtrReg));
return strdup(lchrArrRegreso);;
}
void AcondicionaRegistro(SiscomRegistroProL *pSisRegProLPtrReg)
{

SiscomActualizaCampoRegistroActual("cantidad",
				  CampoAcondicionado("cantidad",pSisRegProLPtrReg),
				  pSisRegProLPtrReg);


SiscomActualizaCampoRegistroActual("importe",
				  CampoAcondicionado("importe",pSisRegProLPtrReg),
				  pSisRegProLPtrReg);


if(!SiscomComparaCadenaCampoRegistroProL("0.500","valor",pSisRegProLPtrReg))
SiscomActualizaCampoRegistroActual("valor",
				  "0.50",
				  pSisRegProLPtrReg);
else
SiscomActualizaCampoRegistroActual("valor",
				  CampoAcondicionado("valor",pSisRegProLPtrReg),
				  pSisRegProLPtrReg);
				   
}
int AcondicionandoParaMostrar(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[128],
	lchrArrCantidad[12],
	lchrArrImporte[12],
	lchrArrValor[12];
SiscomRegistroProL *lSisRegProLPtrRegreso;
lSisRegProLPtrRegreso=SiscomRegistrosAsociadoRespuestaOperacion("CambioCaja",
							pSisOpePtrDatos);
for(;
	lSisRegProLPtrRegreso;
	lSisRegProLPtrRegreso=lSisRegProLPtrRegreso->SiscomRegProLPtrSig)
  AcondicionaRegistro(lSisRegProLPtrRegreso);

return 0;
}
int EnviandoCambioCaja(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[256];
SiscomEnviaAsociadoRespuestaCliente("CambioCaja",lchrArrBuffer,pSisOpePtrDatos);
return 0;
}
