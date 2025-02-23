#include <OrdenesAFacturar.h>
#include <SqlOrdenesAFacturar.h>
#include <ComunElectronica2.h>
#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OpOrdenesAFacturar()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlProductosOrdenes,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(OrdenesParaFacturar,lSOpOperaciones);
return lSOpOperaciones;

}
void OrdenesParaFacturar(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2Agrupados *lLCSisPro2AgruFact=0;
LCamposSiscomPro2 *lLCSiscomPro2ProdFact=0;
LCamposSiscomPro2 *lLCSiscomPro2ProdOrden=0;
int lintNProdOrden;
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
SiscomAgrupaListaPorCampoPro2("cveproducto",
			      pSAgsSiscom->LCSiscomPro2Regreso,
			      &lLCSisPro2AgruFact);
CalculaFactura(pSAgsSiscom,lLCSisPro2AgruFact); 
SiscomContenidoAgrupadosPro2(lLCSisPro2AgruFact);
pSAgsSiscom->LCSiscomPro2Regreso=0;
RespuestaTotalFacturacion(lLCSisPro2AgruFact,
 	       &pSAgsSiscom->LCSiscomPro2Regreso,
	       &pSAgsSiscom->intNumRegRegreso);
CalculaTotalesFacturacion(pSAgsSiscom->LCSiscomPro2Regreso);
SiscomEnviaRegreso(pSAgsSiscom);	
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
}
void ProdParaFacturarProdOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			       LCamposSiscomPro2 **pLCSiscomPro2ProdFact,
			       LCamposSiscomPro2 **pLCSiscomPro2ProdOrden,
			       int *pintPtrNProdOrden)
{
LCamposSiscomPro2 *lLCSiscomPro2ProdFacAct=0;
LCamposSiscomPro2 *lLCSiscomPro2ProdOrdenAct=0;
const char *lchrPtrDato;
*pintPtrNProdOrden=0;
while(pLCSiscomPro2Dat)
{
  lchrPtrDato=SiscomObtenDato(pLCSiscomPro2Dat,"Dato");
  if(!strcmp(lchrPtrDato,"ProductosAFacturar"))
  SiscomCreaListaCamposPro2(pLCSiscomPro2Dat->SCSiscomPro2,
  		      pLCSiscomPro2ProdFact,
		      &lLCSiscomPro2ProdFacAct);
  if(!strcmp(lchrPtrDato,"ProductosOrden"))
  {
  SiscomCreaListaCamposPro2(pLCSiscomPro2Dat->SCSiscomPro2,
  		      pLCSiscomPro2ProdOrden,
		      &lLCSiscomPro2ProdOrdenAct);
  (*pintPtrNProdOrden)++;
  }
 pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
}
}
void CalculaFactura(SArgsSiscom *pSAgsSiscom,
		    LCamposSiscomPro2Agrupados *pLCSisPro2AgruFact)
{
    while(pLCSisPro2AgruFact)
    {
       TotalesPorProducto(pLCSisPro2AgruFact);
       pLCSisPro2AgruFact=pLCSisPro2AgruFact->LCSiscomPro2AgrupaS;
    }
}

void TotalesPorProducto(LCamposSiscomPro2Agrupados *pLCSisPro2AgruFact)
{
float lfltCantidad=0;
float lfltImporteTotal=0;
float lfltCantidad1;
LCamposSiscomPro2 *lLCSisPro2Dat=pLCSisPro2AgruFact->LCSiscomPro2Prim;
	while(lLCSisPro2Dat)
	{
	  lfltCantidad1=atof(SiscomObtenDato(lLCSisPro2Dat,"cantidad"));
	  lfltCantidad+=lfltCantidad1;
	  lfltImporteTotal+=lfltCantidad1*atof(SiscomObtenDato(lLCSisPro2Dat,"precio"));
	 lLCSisPro2Dat=lLCSisPro2Dat->SCP2PtrSig;
	}
SiscomAsignaDatoCampoFloat2(pLCSisPro2AgruFact->LCSiscomPro2Prim,
			   "CantidadTotal",
			   lfltCantidad);
SiscomAsignaDatoCampoFloat2(pLCSisPro2AgruFact->LCSiscomPro2Prim,
			   "ImporteTotal",
			    lfltImporteTotal);
}

void RespuestaTotalFacturacion(LCamposSiscomPro2Agrupados *pLCSisPro2AgruFact,
		    LCamposSiscomPro2 **pLCSiscomPro2Reg,
		    int *pintPtrNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
	*pintPtrNRegistros=0;
    while(pLCSisPro2AgruFact)
    {
       SiscomCreaListaCamposPro2(
             pLCSisPro2AgruFact->LCSiscomPro2Prim->SCSiscomPro2,
             pLCSiscomPro2Reg,
	     &lLCSiscomPro2Act);
       pLCSisPro2AgruFact=pLCSisPro2AgruFact->LCSiscomPro2AgrupaS;
       (*pintPtrNRegistros)++;
    }

}
void CalculaTotalesFacturacion(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
float lfltImporte=0.0;
float lfltImporteMIva;
char lchrArrImporteMIva[128];
char lchrArrImporteConLetra[256];
LCamposSiscomPro2 *lLCSiscomPro2DatPrim=pLCSiscomPro2Dat;
     while(pLCSiscomPro2Dat)
     {
	lfltImporte+=atof(SiscomObtenDato(pLCSiscomPro2Dat,"ImporteTotal"));	
	pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
     }
SiscomAsignaDatoCampoFloat2(lLCSiscomPro2DatPrim,
			    "Total",
			    lfltImporte);
SiscomAsignaDatoCampoFloat2(lLCSiscomPro2DatPrim,
			    "IVA",
			    lfltImporte*0.16);
lfltImporteMIva=lfltImporte*1.16;
SiscomAsignaDatoCampoFloat2(lLCSiscomPro2DatPrim,
			    "TotalMIVA",
			    lfltImporteMIva);
sprintf(lchrArrImporteMIva,"%.2f",lfltImporteMIva);
/*SiscomLog("%s",lchrArrImporteMIva);*/
SiscomTransformaImporteALetra(lchrArrImporteMIva,lchrArrImporteConLetra);
SiscomAsignaDatoCampo2("ImporteConLetra",
		      lchrArrImporteConLetra,
		      lLCSiscomPro2DatPrim);
}
void AgregaProductosOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			  int pintNProdOrden,
			  SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoProtocolo(pLCSiscomPro2Dat);
 SiscomSumaListaCampos(&pSAgsSiscom->LCSiscomPro2Regreso,
                  pLCSiscomPro2Dat);

SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
 pSAgsSiscom->intNumRegRegreso+=pintNProdOrden;

}
