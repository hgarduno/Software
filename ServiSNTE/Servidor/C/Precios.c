#include <Precios.h>
#include <SqlPrecios.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void RegistraPrecio(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdCostoGeneral,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdCostoBruto,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdCostoForaneo,&lSiscomProDat);
SiscomAgregaOperacion(FechaPrecioGeneral,&lSiscomProDat);
SiscomAgregaOperacion(FechaPrecioForaneo,&lSiscomProDat);
SiscomAgregaOperacion(FechaPrecioBruto,&lSiscomProDat);
/* Tepotzotlan Mexico
 *  En la revision del punto de venta para el contrato de beneficios
 *  integrales, me di cuenta que el precio general se usa en las
 *  tiendas foraneas, por lo que hasta que no se revise esto, 
 *  agrego la funcion que replica el precio general y el foraneo
 *  a las tiendas
SiscomAgregaOperacion(SqlRegistraPrecioGeneral,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraPrecioForaneo,&lSiscomProDat);

*/
SiscomAgregaOperacion(SqlRegistraPreciosCostosDescuentos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdPrecioRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int GeneraIdCostoGeneral(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadosCampoEntrada("Envio","CostoGeneral","idpreciogeneral",pSiscomOpePtrDato);
return 0;
}

int GeneraIdCostoBruto(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadosCampoEntrada("Envio","CostoBruto","idcostobruto",pSiscomOpePtrDato);
return 0;
}

int GeneraIdCostoForaneo(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomIdAsociadosCampoEntrada("Envio","CostoForaneo","idprecioforaneo",pSiscomOpePtrDato);
return 0;
}
int EnviaIdPrecioRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
/*
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
const char *lchrPtrIdPrecio;
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
lchrPtrIdPrecio=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdCosto",
						     pSiscomOpePtrDato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdPrecio,Mensajes,",
		       lchrPtrIdPrecio,
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomAsociadosArgumentoLog("SqlInsertaPrecio",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
*/
SiscomRegistroProL *lSisRegProLPtrPrecioGeneral;
SiscomRegistroProL *lSisRegProLPtrPrecioForaneo;



return 0;
}

int FechaPrecioGeneral(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrDatos;
char lchrArrBuffer[128];

lSisRegProLPtrDatos=SiscomRegistrosAsociadosCampo("Envio",
						 "CostoGeneral",
						 pSiscomOpePtrDato->SiscomRegProLPtrPrimEnt);
for(;
    lSisRegProLPtrDatos;
    lSisRegProLPtrDatos=lSisRegProLPtrDatos->SiscomRegProLPtrSig)
{
  if(SiscomCampoRegistroProLCharEsVacio("fecha",lSisRegProLPtrDatos)==1)
	SiscomAsignaFechaCampo("fecha",lSisRegProLPtrDatos);
}
return 0;
}

int FechaPrecioBruto(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomFechaAsociadosCampoEntrada("Envio","CostoBruto","fecha",pSiscomOpePtrDato);
return 0;
}
int FechaPrecioForaneo(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrDatos;
char lchrArrBuffer[128];
lSisRegProLPtrDatos=SiscomRegistrosAsociadosCampo("Envio",
						 "CostoForaneo",
						 pSiscomOpePtrDato->SiscomRegProLPtrPrimEnt);

for(;
    lSisRegProLPtrDatos;
    lSisRegProLPtrDatos=lSisRegProLPtrDatos->SiscomRegProLPtrSig)
{
  if(SiscomCampoRegistroProLCharEsVacio("fecha",lSisRegProLPtrDatos)==1)
	SiscomAsignaFechaCampo("fecha",lSisRegProLPtrDatos);
}
return 0;
}
int OrdenPrecio(SiscomOperaciones *pSiscomOpePtrDato)
{
/*
SiscomRegistroProL *lSiscomRegProLPtrOrden,
		   *lSiscomRegProLPtrProductos;
char lchrArrBuffer[256];
lSiscomRegProLPtrOrden=SiscomRegistrosAsociadosCampoEntrada("Envio",
							    "Orden",
							    pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrOrden);
lSiscomRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",lSiscomRegProLPtrOrden);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProductos);
*/
return 0;
}
