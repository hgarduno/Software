#include <RNCotizaDispositivos.h>
#include <ServidorGeneral.h>
#include <SqlCotizaDispositivos.h>
#include <ComunElectronica.h>
#include <ComunElectronica2.h>
#include <stdlib.h>
#include <string.h>
extern StcSiscomConfiguracion gSSiscomConfiguracionSvr; 


char gchrArrConsultaDispositivos[]="				\n\
SELECT	a.cveProducto,						\n\
	c.DscProducto,						\n\
	b.Existencia,						\n\
	d.exbodegas,						\n\
	a.Precio						\n\
	from precios as a 					\n\
	left outer join existencias as b using (cveProducto)	\n\
	inner join productos as c using(CveProducto)		\n\
	inner join existenciaexpendiobodegas as d on 		\n\
		    (a.CveProducto=d.cveproducto and  		\n\
	             b.idexpendio=d.idexpendio)			\n\
	left outer join productoportipoproducto as e on		\n\
		    (a.CveProducto=e.cveproducto and 		\n\
		     b.idexpendio=d.idexpendio)";

int EliminaTotalOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
LCamposSiscomPro2 *lSLCamposAnterior=0;

	for(;
	     pLCSiscomPro2Dat;
	     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
	{
	   if(!strcmp(SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	   	      "TotalOrden"))
	   {
	     if(!lSLCamposAnterior)
	      return 0;
	      else
	      lSLCamposAnterior->SCP2PtrSig=pLCSiscomPro2Dat->SCP2PtrSig;
	      break;
	   }
	   lSLCamposAnterior=pLCSiscomPro2Dat;

	}
return 1;
}
void EliminaTotalOrden2(LCamposSiscomPro2 *pLCSiscomPro2Dat,
		        char *pchrPtrTotalOrden)
{
LCamposSiscomPro2 *lSLCamposAnterior;

	for(;
	     pLCSiscomPro2Dat;
	     pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)
	{
	   if(!strcmp(SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	   	      "TotalOrden"))
	   {
	      strcpy(pchrPtrTotalOrden,
	      	     SiscomObtenDato(pLCSiscomPro2Dat,"Importe"));
	      lSLCamposAnterior->SCP2PtrSig=pLCSiscomPro2Dat->SCP2PtrSig;
	      break;
	   }
	   lSLCamposAnterior=pLCSiscomPro2Dat;

	}
}
void FormaConsultaDispositivos(LCamposSiscomPro2 *pLCSiscomPro2,
		       char **pchrPtrRegreso)
{
char lchrArrCondicion[2048];
*pchrPtrRegreso=0;
	if(EliminaTotalOrden(pLCSiscomPro2))
	{
	sprintf(lchrArrCondicion,
		"where NmbTipoPrecio='DEFAULT' and \n\
		       b.idExpendio=%s 	       and \n\
		       a.CveProducto in(",
		SiscomObtenDato(pLCSiscomPro2,"IdExpendio"));

	*pchrPtrRegreso=(char *)malloc(strlen(gchrArrConsultaDispositivos) +
				       strlen(lchrArrCondicion)            +
				       5);
	sprintf(*pchrPtrRegreso,
		"%s %s",
		gchrArrConsultaDispositivos,
		lchrArrCondicion);
	/* Se requiere escribir como parte de las 
	 * funciones de soporte, una que permita 
	 * eliminar un nodo de la lista
	 */
	/* Esta funcion elimina de la lista, el registro que en clave del 
	 * producto lleve TotalOrden, ahora se debe generalizar, e integrar
	 * a las funciones para manipular el protocolo
	 */

	for(;
	     pLCSiscomPro2;
	     pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
	{
	    if(pLCSiscomPro2->SCP2PtrSig)
	     sprintf(lchrArrCondicion,
	     	     "'%s',",
		     SiscomObtenDato(pLCSiscomPro2,"CveProducto"));
	     else
	     sprintf(lchrArrCondicion,
	     	     "'%s')",
		     SiscomObtenDato(pLCSiscomPro2,"CveProducto"));
	      *pchrPtrRegreso=(char *)realloc(*pchrPtrRegreso,
	      				       strlen(*pchrPtrRegreso)+
					       strlen(lchrArrCondicion)+
					       5);
	      strcat(*pchrPtrRegreso,lchrArrCondicion);
	}
     }
}
void ConsultaProductosCotiza(int pintNRegistros,
				SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
char *lchrPtrConsulta;
	FormaConsultaDispositivos(pSOpServidor->LCSiscomPro2Dat,&lchrPtrConsulta);
	SiscomLog("%s",lchrPtrConsulta);
	if(lchrPtrConsulta)
	{
	SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
	                         &pSOpServidor->LCSiscomPro2EAct,
				 &pSOpServidor->intNRegistros,
				"ConsultaSQL",
				lchrPtrConsulta);
	}
}
void AjustaImporteTotal(float pfltImpTotal,
		        char *pchrPtrImporteTotal)
{
float lfltEntero;
float lfltFraccion=(float )(pfltImpTotal-(lfltEntero=(int )pfltImpTotal));

	 if(lfltFraccion>0.5)
	  sprintf(pchrPtrImporteTotal,"%.2f",lfltEntero+1);
	 if(lfltFraccion<0.5)
	 sprintf(pchrPtrImporteTotal,"%.2f",lfltEntero);
}

float ObtenPorcentajeDescuentoCajaProducto(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
if(SiscomObtenDatoInt(pLCSiscomPro2Dat,"PorDescuentoCaja"))
return (100.0-SiscomObtenDatoFloat(pLCSiscomPro2Dat,"PorDescuentoCaja"))/100.0;
else
return 1;

}
const char *SePuedeVenderProducto(float pfltExistencia,
				  float pfltTotalSolicitado,
				  float pfltPrecio)
{
   if(pfltExistencia>=pfltTotalSolicitado &&
      pfltPrecio>0)
   return "Si";
   else
   return "No";

}
int EsLaCotizacionPara(LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       const char *pchrPtrPara)
{
   for(;
        pLCSiscomPro2Dat;
	pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig)	
     if(!SiscomComparaCampoChar("TipoCotizacion",pchrPtrPara,pLCSiscomPro2Dat))
     return 1;


return 0;
}

int EsLaCotizacionParaPrecio(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
   return EsLaCotizacionPara(pLCSiscomPro2Dat,"ParaPrecio");
}

int EsLaCotizacionParaAnexarALaOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
   return EsLaCotizacionPara(pLCSiscomPro2Dat,"ALaOrden");
}
void PonPrecioProductoTipoProducto(LCamposSiscomPro2 *pLCSiscomPro2COrden,
				   LCamposSiscomPro2 *pLCSiscomPro2COrdenAct)
{
LCamposSiscomPro2 *lLCSiscomPro2TotalOrden;
lLCSiscomPro2TotalOrden=SiscomUltimoRegistro(pLCSiscomPro2COrden);
SiscomAsignaDatoCampo2("Precio",
			SiscomObtenDato(lLCSiscomPro2TotalOrden,"ImporteCantidad"),
			pLCSiscomPro2COrdenAct);
SiscomAsignaDatoCampo2("ImporteCantidad",
			SiscomObtenDato(lLCSiscomPro2TotalOrden,"ImporteCantidad"),
			pLCSiscomPro2COrdenAct);
pLCSiscomPro2COrdenAct->SCP2PtrSig=lLCSiscomPro2TotalOrden;
}
LCamposSiscomPro2 *AgregandoProductosPrevios(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			       		     LCamposSiscomPro2 *pLCSiscomPro2Kit)
{
int lintContador;
LCamposSiscomPro2 *lLCSiscomPro2Ultimo,
		  *lLCSiscomPro2Dat,
		  *lLCSiscomPro2Anterior,
		  *lLCSiscomPro2Regreso=pLCSiscomPro2Dat;
lLCSiscomPro2Ultimo=SiscomUltimoRegistro(pLCSiscomPro2Dat);
lLCSiscomPro2Ultimo->SCP2PtrSig=pLCSiscomPro2Kit;

for(lLCSiscomPro2Dat=pLCSiscomPro2Dat,
    lintContador=0;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig,
    lintContador++)
{
  lLCSiscomPro2Anterior=lLCSiscomPro2Dat; 
  if(!SiscomComparaCampoChar("IdTipoProducto","2",lLCSiscomPro2Dat))
  {
    if(!lintContador &&lLCSiscomPro2Dat->SCP2PtrSig)
      lLCSiscomPro2Regreso=lLCSiscomPro2Dat->SCP2PtrSig;
    else
    if(lLCSiscomPro2Dat->SCP2PtrSig)
      lLCSiscomPro2Anterior->SCP2PtrSig=lLCSiscomPro2Dat->SCP2PtrSig;
  }
}
return lLCSiscomPro2Regreso;
}
int GeneraSqlDatosBaseRegistrosEntrada(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					char **pchrPtrSql)
{
char lchrArrPaso[256];
int lintTamano,lintContador=0,lintProductosAgregados=0;
*pchrPtrSql=strdup(gchrArrConsultaDispositivos);
sprintf(lchrArrPaso,
	" where NmbTipoPrecio='DEFAULT' and b.IdExpendio=%s and a.cveproducto in(",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"));
*pchrPtrSql=(char *)realloc(*pchrPtrSql,strlen(*pchrPtrSql)+strlen(lchrArrPaso)+1);
strcat(*pchrPtrSql,lchrArrPaso);
   while(pLCSiscomPro2Dat)
   {
	if(pLCSiscomPro2Dat->SCP2PtrSig)
	{
	   if(!lintContador)
	   sprintf(lchrArrPaso,"'%s'",SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto")); 
	   else
	   sprintf(lchrArrPaso,",'%s'",SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto")); 
	   lintProductosAgregados++;
	}
	else
	{
	   if(!SiscomComparaCampoChar("IdTipoProducto","2",pLCSiscomPro2Dat)) 
		sprintf(lchrArrPaso,")");
	   else
	   {
	  	sprintf(lchrArrPaso,"'%s')",SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
		lintProductosAgregados++;
	   }
	}
 	lintTamano=strlen(*pchrPtrSql)+strlen(lchrArrPaso)+1;	
 	*pchrPtrSql=(char *)realloc(*pchrPtrSql,lintTamano);
	strcat(*pchrPtrSql,lchrArrPaso);
	pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
	lintContador++;
   }
return lintProductosAgregados;
}
void AgregaDatosBaseRegistrosEntrada(SArgsSiscom *pSAgsSiscom,
				     LCamposSiscomPro2 *pLCSiscomPro2Dat,
				     LCamposSiscomPro2 *pLCSiscomPro2Base)
{
char *lchrPtrSql;
LCamposSiscomPro2 *lLCSiscomPro2UltimoBase;
if(GeneraSqlDatosBaseRegistrosEntrada(pLCSiscomPro2Dat,&lchrPtrSql))
{
SqlDatosBaseRegistroEntrada(SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"),
			    lchrPtrSql,
			    pSAgsSiscom);
lLCSiscomPro2UltimoBase=SiscomUltimoRegistro(pLCSiscomPro2Base);
lLCSiscomPro2UltimoBase->SCP2PtrSig=SiscomArgumentoOperacionPrim("SqlProductosEntrada",pSAgsSiscom);
}
}
				    
/* Queretaro Martes 17 de Noviembre del 2015 
 * Se integra la cotizacion del TipoProducto a kit o practica ...
 */

void CotizaOrden(LCamposSiscomPro2 *pLCSiscomPro2Ent,
		 LCamposSiscomPro2 *pLCSiscomPro2Base,
		 float pfltPorDescuento,
		 float pfltPorDescuentoCajaOrden,
		 LCamposSiscomPro2 **pLCSiscomPro2COrden,
		 int *pintPtrNRegRegreso,
		 SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Ent=0,
		  *lLCSiscomPro2Base=0,
		  *lLCSiscomPro2Orden=0,
		  *lLCSiscomPro2COrdenAct=0;
int lintNRegistrosKit=0;
const char *lchrPtrCveKit;
if(pSAgsSiscom && SiscomArgumentosNumeroRegistros("SqlTipoProducto",pSAgsSiscom))
{
   SiscomPonPrimerRegistroArgumento("SqlTipoProducto",pSAgsSiscom);
   if(EsLaCotizacionParaPrecio(pLCSiscomPro2Ent))
   {
   lchrPtrCveKit=SiscomObtenDato(pLCSiscomPro2Ent,"CveProducto");
   lLCSiscomPro2Ent=0;
   lLCSiscomPro2Base=pLCSiscomPro2Base;
   *pintPtrNRegRegreso=0;
   FormaCotizacionTipoProducto(pSAgsSiscom,
   			       pLCSiscomPro2Ent->SCSiscomPro2,
   			       &lLCSiscomPro2Ent,
			       &lLCSiscomPro2Base,
			       &lintNRegistrosKit);
    CotizandoOrden(lLCSiscomPro2Ent,
	       	   lLCSiscomPro2Base,
	       	   pfltPorDescuento,
	       	   pfltPorDescuentoCajaOrden,
	       	   &lLCSiscomPro2Orden,
	       	   &lintNRegistrosKit,
		   pSAgsSiscom);
    ArmaRespuestaVentaTipoProducto(pLCSiscomPro2Ent,
    				   lchrPtrCveKit,
				   SiscomObtenCampoArgumento("SqlTipoProducto","idproducto",pSAgsSiscom),
    				   pLCSiscomPro2COrden,
				   &lLCSiscomPro2COrdenAct,
				   pintPtrNRegRegreso);
    PonPrecioProductoTipoProducto(lLCSiscomPro2Orden,
    				  *pLCSiscomPro2COrden);
    (*pintPtrNRegRegreso)++;
  }
   if(EsLaCotizacionParaAnexarALaOrden(pLCSiscomPro2Ent))
  {
   lLCSiscomPro2Ent=0;
   lLCSiscomPro2Base=pLCSiscomPro2Base;
   *pintPtrNRegRegreso=0;
   FormaCotizacionTipoProducto(pSAgsSiscom,
   			       pLCSiscomPro2Ent->SCSiscomPro2,
   			       &lLCSiscomPro2Ent,
			       &lLCSiscomPro2Base,
			       &lintNRegistrosKit);
   AgregaDatosBaseRegistrosEntrada(pSAgsSiscom,pLCSiscomPro2Ent,lLCSiscomPro2Base); 
   pLCSiscomPro2Ent=AgregandoProductosPrevios(pLCSiscomPro2Ent,lLCSiscomPro2Ent);
   *pintPtrNRegRegreso=lintNRegistrosKit;
    CotizandoOrden(pLCSiscomPro2Ent,
 	     	   lLCSiscomPro2Base,
	     	   pfltPorDescuento,
	     	   pfltPorDescuentoCajaOrden,
	      	   pLCSiscomPro2COrden,
	           pintPtrNRegRegreso,
		   pSAgsSiscom);
  }
}
else
{
 CotizandoOrden(pLCSiscomPro2Ent,
 	     pLCSiscomPro2Base,
	     pfltPorDescuento,
	     pfltPorDescuentoCajaOrden,
	     pLCSiscomPro2COrden,
	     pintPtrNRegRegreso,
	     pSAgsSiscom);
}
SiscomContenidoProtocoloVertical(*pLCSiscomPro2COrden); 
} 
void ObtenDatosTipoProducto(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    const char **pchrPtrClaveKit,
			    const char **pchrPtrIdProductoKit,
			    const char **pchrPtrImporteKit,
			    const char **pchrPtrEsKit)
{

*pchrPtrClaveKit=SiscomObtenDato(pLCSiscomPro2Dat,"ClaveKit");
*pchrPtrIdProductoKit=SiscomObtenDato(pLCSiscomPro2Dat,"IdProductoKit");
*pchrPtrImporteKit="";
*pchrPtrEsKit="Si";
}
void CotizandoOrden(LCamposSiscomPro2 *pLCSiscomPro2Ent,
		 LCamposSiscomPro2 *pLCSiscomPro2Base,
		 float pfltPorDescuento,
		 float pfltPorDescuentoCajaOrden,
		 LCamposSiscomPro2 **pLCSiscomPro2COrden,
		 int *pintPtrNRegRegreso,
		 SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Base=pLCSiscomPro2Base;
LCamposSiscomPro2 *lLCSiscomPro2COrden=0;
char lchrArrImpTotal[25],
     lchrArrImpUnitario[25],
     lchrArrCantidad[25],
     lchrArrPorDescuento[10],
     lchrArrEsClienteFrecuente[5],
     lchrArrPorDescuentoCaja[12],
     lchrArrPorDescuentoCajaOrden[12];
const char *lchrPtrClaveKit="",
     *lchrPtrIdProductoKit="",
     *lchrPtrImporteKit="",
     *lchrPtrEsKit="";
float lfltImpTotal=0,
      lfltImpUnitario=0,
      lfltCantidad,
      lfltNumJuegos,
      lfltTotalSolicitado,
      lfltExistencia,
      lfltPorDescuentoCaja=1.0;
	*pintPtrNRegRegreso=0;
for(;
    pLCSiscomPro2Ent;
    pLCSiscomPro2Ent=pLCSiscomPro2Ent->SCP2PtrSig)
  for(lLCSiscomPro2Base=pLCSiscomPro2Base;
      lLCSiscomPro2Base;
      lLCSiscomPro2Base=lLCSiscomPro2Base->SCP2PtrSig)
  {
		if(!strcmp(SiscomObtenDato(pLCSiscomPro2Ent,"CveProducto"),
			   SiscomObtenDato(lLCSiscomPro2Base,"cveproducto")))
		{
		  if(!strcmp(SiscomObtenDato(pLCSiscomPro2Ent,"EsKit"),"Si"))
		   ObtenDatosTipoProducto(pLCSiscomPro2Ent,
		   			 &lchrPtrClaveKit,
					 &lchrPtrIdProductoKit,
					 &lchrPtrImporteKit,
					 &lchrPtrEsKit);
		  /* Queretaro a 3 de diciembre del 2015 
		   * Se integra el modulo de faltantes 
		   * Cuando se detecte que la existencia en el expendio y la bodega
		   * es 0, se debera realizar la insercion a la tabla de faltantes 
		   * para que se lleve el registro ....
		   */
		  /*
		  RegistrandoFaltantes(lLCSiscomPro2Base,pSAgsSiscom);
		  */
		  lfltNumJuegos=atof(SiscomObtenDato(pLCSiscomPro2Ent,"NumJuegos"));
		  lfltCantidad=atof(SiscomObtenDato(pLCSiscomPro2Ent,"Cantidad"));
		  lfltExistencia=atof(SiscomObtenDato(lLCSiscomPro2Base,"existencia"));
		  /* Lunes 17 de Septiembre 2012
		   * Se agrega la posibilidad de asignar un descuento por producto
		   */
		  lfltPorDescuentoCaja=ObtenPorcentajeDescuentoCajaProducto(pLCSiscomPro2Ent);
		  lfltImpUnitario=atof(SiscomObtenDato(lLCSiscomPro2Base,"precio"))*
		  		  lfltCantidad					   *
				  lfltNumJuegos					   *
				  pfltPorDescuento				   *
				  lfltPorDescuentoCaja				   *
				  pfltPorDescuentoCajaOrden;
		  lfltTotalSolicitado=lfltNumJuegos*
		  		      lfltCantidad;
		  if(lfltExistencia>=lfltTotalSolicitado)		      
		  lfltImpTotal+=lfltImpUnitario;
		  sprintf(lchrArrImpTotal,"%.2f",lfltImpTotal);
		  sprintf(lchrArrImpUnitario,"%.2f",lfltImpUnitario);
		  sprintf(lchrArrPorDescuentoCaja,"%.2f",lfltPorDescuentoCaja);
		  sprintf(lchrArrPorDescuentoCajaOrden,"%.2f",pfltPorDescuentoCajaOrden);
		  SiscomLog("El importe:%s",lchrArrImpUnitario);
		  SiscomAnexaRegistroPro2(
		      	pLCSiscomPro2COrden,
		      	&lLCSiscomPro2COrden,
		      	pintPtrNRegRegreso,
		      	"CveProducto, 		\
		       	Descripcion,		\
			Cantidad, 		\
			Existencia,		\
			ExisBodega,		\
			Precio,			\
			NmbTipoPrecio,		\
			IdExpendio,		\
			ImporteCantidad,	\
			ImporteTotal,		\
			SePuedeVender,		\
			NumJuegos,      	\
			IdCliente,		\
			IdPractica,		\
			EdoRegistro,		\
			ClienteFrecuente,	\
			PorDescuento,		\
			RFC,			\
			IdCaja,			\
			PorDescuentoCaja,	\
			PorDescuentoCajaOrden,	\
			OrdenACaja,		\
			CantidadValida,		\
			OrigenCompra,		\
			EsKit,			\
			CveKit,			\
			IdProductoKit,		\
			CantidadKit,		\
			IdTipoProducto",
			SiscomObtenDato(pLCSiscomPro2Ent,"CveProducto"),
			SiscomObtenDato(lLCSiscomPro2Base,"dscproducto"),
			SiscomObtenDato(pLCSiscomPro2Ent,"Cantidad"),
			SiscomObtenDato(lLCSiscomPro2Base,"existencia"),
			SiscomObtenDato(lLCSiscomPro2Base,"exbodegas"),
			SiscomObtenDato(lLCSiscomPro2Base,"precio"),
			SiscomObtenDato(pLCSiscomPro2Ent,"NmbPrecio"),
			SiscomObtenDato(pLCSiscomPro2Ent,"IdExpendio"),
			lchrArrImpUnitario,
			"",
			/*
			lfltExistencia >= lfltTotalSolicitado ? "Si" : "No",
			*/
			SePuedeVenderProducto(lfltExistencia,lfltTotalSolicitado,lfltImpUnitario),
			SiscomObtenDato(pLCSiscomPro2Ent,"NumJuegos"),
			SiscomObtenDato(pLCSiscomPro2Ent,"IdCliente"),
			SiscomObtenDato(pLCSiscomPro2Ent,"IdPractica"),
			SiscomObtenDato(pLCSiscomPro2Ent,"EdoRegistro"),
			pfltPorDescuento!=1.0 ? "Si" : "",
			"",
			SiscomObtenDato(pLCSiscomPro2Ent,"RFC"),
			"0",
			SiscomObtenDato(pLCSiscomPro2Ent,"PorDescuentoCaja"),
			SiscomObtenDato(pLCSiscomPro2Ent,"PorDescuentoCajaOrden"),
			"0",
			!lfltCantidad ? "No" : "Si",
			"",
			SiscomObtenDato(pLCSiscomPro2Ent,"EsKit"),
			SiscomObtenDato(pLCSiscomPro2Ent,"ClaveKit"),
			SiscomObtenDato(pLCSiscomPro2Ent,"IdProductoKit"),
			SiscomObtenDato(pLCSiscomPro2Ent,"CantidadKit"),
			SiscomObtenDato(lLCSiscomPro2Base,"idtipoproducto"));
		 break;
		}

	}
	if(lfltPorDescuentoCaja!=1.0)
	AjustaImporteTotal(lfltImpTotal,lchrArrImpTotal);
	if(pfltPorDescuentoCajaOrden!=1.0)
	AjustaImporteTotal(lfltImpTotal,lchrArrImpTotal);

	if(pfltPorDescuento!=1.0)
	{
	AjustaImporteTotal(lfltImpTotal,lchrArrImpTotal);
	sprintf(lchrArrPorDescuento,"%.2f",(1-pfltPorDescuento)*100);
	strcpy(lchrArrEsClienteFrecuente,"Si");
	}
	else
	{
	  lchrArrPorDescuento[0]=0;
	strcpy(lchrArrEsClienteFrecuente,"No");

	}
	SiscomAnexaRegistroPro2(pLCSiscomPro2COrden,
		  			  &lLCSiscomPro2COrden,
					  pintPtrNRegRegreso,
					  "CveProducto, 		\
					   Descripcion,			\
					   Cantidad, 			\
					   Existencia,			\
					   ExisBodega,			\
					   Precio,			\
					   NmbTipoPrecio,		\
					   IdExpendio,			\
					   ImporteCantidad,		\
					   ImporteTotal,		\
					   SePuedeVender,		\
					   NumJuegos,			\
					   IdCliente,			\
					   IdPractica,			\
					   EdoRegistro,			\
					   ClienteFrecuente,		\
					   PorDescuento,		\
					   RFC				\
					   IdCaja,			\
					   PorDescuentoCaja,    	\
					   PorDescuentoCajaOrden,	\
					   CantidadValida,		\
					   OrigenCompra,		\
					   EsKit,			\
					   ClaveKit,			\
					   IdProductoKit,		\
					   ImporteKit,			\
					   IdTipoProducto",
					   "TotalOrden",
					   "",
					   "",
					   "",
					   "",
					   "",
					   "",
					   "",
					   lchrArrImpTotal,
					   lchrArrImpTotal,
					   "",
					   "",
					   "",
					   "",
					   "",
					   lchrArrEsClienteFrecuente,
					   lchrArrPorDescuento,
					   "",
					   "-1",
					   "0",
					   "0",
					   "0",
					   "Cantidad Muy Valida",
					   "OrigenCompra",
					   lchrPtrEsKit,
					   lchrPtrClaveKit,
					   lchrPtrIdProductoKit);




}
void ObtenLimitesClienteFrecuente(int pintPtoCom,
				  const char *pchrPtrDirIpSvr,
				  const char *pchrPtrIdExpendio,
				  LCamposSiscomPro2 **pLCSiscomPro2)
{
char *lchrPtrEdoConexion=0,
     *lchrPtrOperacion=0;
int lintSocketCliente,
	lintNRegistros;

	SiscomConsultaBaseDeDatos("select * from clientefrecuente",
				   pchrPtrDirIpSvr,
				   pintPtoCom,
				   &lchrPtrEdoConexion,
				   &lintSocketCliente,
				   &lintNRegistros,
				   &lchrPtrOperacion,
				   pLCSiscomPro2);


}
int ObtenImporteComprasCliente(int pintPtoCom,
			        const char *pchrPtrDirIpSvr,
				LCamposSiscomPro2 *pLCSiscomPro2,
				const char *pchrPtrIdCliente,
				float *pfltPtrImporte)
{
int lintDia,
    lintMes,
    lintAno;
char lchrArrCadenaConsulta[256];
char *lchrPtrEdoConexion=0,
     *lchrPtrOperacion=0;
int lintSocketCliente,
	lintNRegistros,
	lintNDiasCalculo=atoi(SiscomObtenDato(pLCSiscomPro2,"numdias")),
	lintDiasAtras;
LCamposSiscomPro2 *lLCSiscomPro2=0;
    	SiscomObtenFechaHoyINT(&lintDia,&lintMes,&lintAno);
	
	SiscomLog("Num Dias Calculo %d, Dia Hoy %d",
			  lintNDiasCalculo,
			  lintDia);
	lintDiasAtras=(lintDia-lintNDiasCalculo) > 0 ?
		      lintDia-lintNDiasCalculo : 1 ;
	sprintf(lchrArrCadenaConsulta,
		"select sum(importe) as TotalCliente					\
		 from ventas 								\
		 where cliente=%s and 							\
		 	idexpendio= %s and						\
			cast(fechahora as date)>='%04d-%02d-%02d' and 			\
			cast(fechahora as date)<='%04d-%02d-%02d'",	
		pchrPtrIdCliente,
		SiscomObtenDato(pLCSiscomPro2,"idexpendio"),
		lintAno,
		lintMes,
		lintDiasAtras,
		lintAno,
		lintMes,
		lintDia);
	
	SiscomConsultaBaseDeDatos(lchrArrCadenaConsulta,
				   pchrPtrDirIpSvr,
				   pintPtoCom,
				   &lchrPtrEdoConexion,
				   &lintSocketCliente,
				   &lintNRegistros,
				   &lchrPtrOperacion,
				   &lLCSiscomPro2);
	if(SiscomObtenDato(lLCSiscomPro2,"totalcliente")[0])
	{
	*pfltPtrImporte=atof(SiscomObtenDato(lLCSiscomPro2,"totalcliente"));
	return 1;
	}
	else
	{
	*pfltPtrImporte=0.0;
	return 0;
	}

}
int ImporteEnElLimite(LCamposSiscomPro2 *pLCSiscomPro2Dat,
		      float pfltImporte,
		      float *pfltPtrPorDescuento)
{
float lfltLimiteSuperior=atof(SiscomObtenDato(pLCSiscomPro2Dat,
					      "limitesuperior")),
      lfltLimiteInferior=atof(SiscomObtenDato(pLCSiscomPro2Dat,
      					      "limiteinferior"));
	*pfltPtrPorDescuento=1.0;
	if(pfltImporte>=lfltLimiteInferior &&
	   pfltImporte<=lfltLimiteSuperior )
	{
	 *pfltPtrPorDescuento=0.01*(100.00-atof(SiscomObtenDato(pLCSiscomPro2Dat,"descuento")));
	 return 1;
	}
	return 0;
}
void ObtenDatosClienteFrecuente(SiscomOperacionesServidor pSOpServidor,
			        float *pfltPtrDescuento)
{
float lfltImporte,
	lfltPorDescuento=1.0;
LCamposSiscomPro2 *lLCSiscomPro2LCFrec=0;
float lfltDescuentoMaximo,
      lfltImporteMaximo;


	ObtenLimitesClienteFrecuente(pSOpServidor.intPtoCom,
				     pSOpServidor.chrPtrDirIpSvr,
				     SiscomObtenDato(pSOpServidor.LCSiscomPro2Dat,"IdExpendio"),
				     &lLCSiscomPro2LCFrec);
	if(ObtenImporteComprasCliente(pSOpServidor.intPtoCom,
				   pSOpServidor.chrPtrDirIpSvr,
				   lLCSiscomPro2LCFrec,
				   SiscomObtenDato(pSOpServidor.LCSiscomPro2Dat,"IdCliente"),
				   &lfltImporte))
	for(;
		lLCSiscomPro2LCFrec;
	    lLCSiscomPro2LCFrec=lLCSiscomPro2LCFrec->SCP2PtrSig)
	 {
	    lfltDescuentoMaximo=atof(SiscomObtenDato(lLCSiscomPro2LCFrec,"descuento"));
	    lfltImporteMaximo=atof(SiscomObtenDato(lLCSiscomPro2LCFrec,"limitesuperior"));
	    if(ImporteEnElLimite(lLCSiscomPro2LCFrec,
	    			 lfltImporte,
				 pfltPtrDescuento))
		return;
	 }
	 if(lfltImporte>=lfltImporteMaximo)
	 *pfltPtrDescuento=0.01*(100-lfltDescuentoMaximo);
}
int VeSiSeHaceElCalculoClienteFrecuente(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
const char *lchrPtrIdCliente=SiscomObtenDato(pLCSiscomPro2Dat,"IdCliente");
const char *lchrPtrRFC=SiscomObtenDato(pLCSiscomPro2Dat,"RFC");

	if(lchrPtrIdCliente &&
	   lchrPtrRFC)
	if(lchrPtrIdCliente 					&&
	   lchrPtrRFC						&&
	   lchrPtrIdCliente[0]					&&
	   lchrPtrRFC[0] 					&&
	   strcmp(lchrPtrRFC,"GENERAL")				&&
	   strcmp(lchrPtrRFC,"No Se Encontro El Campo")		&&
	   gSSiscomConfiguracionSvr.chrPtrClienteFrecuente	&&
	   !strcmp(gSSiscomConfiguracionSvr.chrPtrClienteFrecuente,"Si"))
	  return 1;
	 else
	 return 0;


}
/* Lunes 17 de septiembre del 2012 
 * Se agrega la asignacion de un descuento por producto y orden en la caja
 */

float ObtenPorcentajeDescuentoOrdenCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
if(SiscomObtenDatoInt(pLCSiscomPro2Dat,"PorDescuentoCajaOrden"))
 return (100.0-SiscomObtenDatoFloat(pLCSiscomPro2Dat,"PorDescuentoCajaOrden"))/100.0;
 else
 return 1.0;
}
void CotizaDispositivos(int pintSocket,
		        int pintNRegistros)
{
SArgsSiscom *lSArgsSiscom=0,
	    lSArgsSiscomPaso;
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;
LCamposSiscomPro2 *lLCSiscomPro2Orden=0;
int lintNRegRegreso;
float lfltDescuento=1.0;
float lfltPorDescuentoCajaOrden=1.0;
	lSOpServidor.EjecutaProcesoAntes=0;

/* Queretaro 17 de Noviembre del 2015 
 * Se Agrega el soporte para tipo de producto
 */
memset(&lSArgsSiscomPaso,0,sizeof(SArgsSiscom));
SiscomLog("--------------------------------------------");
ComunicacionExpendioConsulta(&lSArgsSiscomPaso);
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);

/* Tepotzotlan Mexico a 16 de noviembre del 2015
 * Con la integracion del concepto de Kit y practicas 
 * al esquema de trabajo, en el que el kit se toma 
 * como un producto, y se le da una asociacion 
 * de productos que lo forman, se deben realizar
 * las consideraciones en este modulo para que 
 * la identificar que en la peticion llega un 
 * producto kit o practica se agreguen los productos
 */
	lSArgsSiscom=AgregandoProductoPorTipoProducto(lSOpServidor.LCSiscomPro2Dat,&lSArgsSiscomPaso);
	ElectronicaComunicacionExpendio(lSOpServidor.LCSiscomPro2Dat,
					&lSOpServidor.intPtoCom,
					lSOpServidor.chrPtrDirIpSvr);
	ConsultaProductosCotiza(pintNRegistros,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	if(lSOpServidor.intNRegistrosRes)
	SiscomLog("Registros Regreso:%d",lSOpServidor.intNRegistrosRes);
	SiscomLog("----Cotizando ---------");
	SiscomContenidoProtocolo(lSOpServidor.LCSiscomPro2Dat);
	SiscomLog("-----Cotizando------");
	if(lSOpServidor.intNRegistrosRes)
	{
	if(VeSiSeHaceElCalculoClienteFrecuente(lSOpServidor.LCSiscomPro2Dat))
	{
	SiscomLog("Se realiza el calculo cliente frecuente");
	ObtenDatosClienteFrecuente(lSOpServidor,&lfltDescuento);
	}
	if(lSOpServidor.intNRegistrosRes)
	{
        lfltPorDescuentoCajaOrden=ObtenPorcentajeDescuentoOrdenCaja(lSOpServidor.LCSiscomPro2Dat);

	/* Lunes 17 de septiembre se integra el manejo de los descuentos 
	 * en Caja, por producto y por orden
	 */
	/* Queretaro 17 de Noviembre del 2015
	 * Con la integracion del tipo de producto
	 * Se realiza la cotizacion primero del 
	 * kit o practica .... 
	 */
	SiscomLog("El %f",lfltDescuento);
	CotizaOrden(lSOpServidor.LCSiscomPro2Dat,
		    lSOpServidor.LCSiscomPro2,
		    lfltDescuento,
		    lfltPorDescuentoCajaOrden,
		    &lLCSiscomPro2Orden,
		    &lintNRegRegreso,
		    lSArgsSiscom);
	}
	else
	lintNRegRegreso=0;
	SiscomEnviaAlServidor(pintSocket,
			      lintNRegRegreso,
			      "Cotizacion",
			      lLCSiscomPro2Orden);
	
	/*SiscomContenidoProtocoloVertical(lLCSiscomPro2Orden); */
	}
	else
	{
	  SiscomLog("No Se encontro informacion del producto");

	} close(pintSocket);


}

LCamposSiscomPro2 *CualesProductosPorTipoProducto(LCamposSiscomPro2 *pLCSiscomPro2Productos)
{
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgrupaDatos=0,
			   *lLCSiscomPro2AgrupaPaso=0;
SiscomContenidoProtocolo(pLCSiscomPro2Productos);
SiscomAgrupaListaPorCampoPro2("IdTipoProducto",pLCSiscomPro2Productos,&lLCSiscomPro2AgrupaDatos);
for(lLCSiscomPro2AgrupaPaso=lLCSiscomPro2AgrupaDatos;
    lLCSiscomPro2AgrupaPaso;
    lLCSiscomPro2AgrupaPaso=lLCSiscomPro2AgrupaPaso->LCSiscomPro2AgrupaS)
   if(!strcmp(lLCSiscomPro2AgrupaPaso->chrPtrCampo,"2"))
   return lLCSiscomPro2AgrupaPaso->LCSiscomPro2Prim;
if(pLCSiscomPro2Productos->SCP2PtrSig)
return 0;
else
return pLCSiscomPro2Productos;
}


/* Tepotzotlan Mexico a 16 de noviembre del 2015
 * Con la integracion del concepto de Kit y practicas 
 * al esquema de trabajo, en el que el kit se toma 
 * como un producto, y se le da una asociacion 
 * de productos que lo forman, se deben realizar
 * las consideraciones en este modulo para que 
 * la identificar que en la peticion llega un 
 * producto kit o practica se agreguen los productos
 */
SArgsSiscom *AgregandoProductoPorTipoProducto(LCamposSiscomPro2 *pLCSiscomPro2Productos,
				      SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrSql;
const char *lchrPtrIdExpendio;
LCamposSiscomPro2 *lLCSiscomPro2Datos;
if((lLCSiscomPro2Datos=CualesProductosPorTipoProducto(pLCSiscomPro2Productos)))
{
lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2Productos,"IdExpendio");
FormaConsultaTiposProducto(lLCSiscomPro2Datos,lchrPtrIdExpendio,&lchrPtrSql);
ArgumentosTipoProducto(pSAgsSiscom);
SqlDefinicionTipoProducto(lchrPtrIdExpendio,lchrPtrSql,pSAgsSiscom);
return pSAgsSiscom;
}
else
return 0;
}

				    
void AgregandoCondicionTipoProducto(LCamposSiscomPro2 *pLCSiscomPro2Producto,
					    const char *pchrPtrCveProducto,
		        		    char **pchrPtrSql)
{
char lchrArrPaso[128];
int lintTamanoActual=strlen(*pchrPtrSql);
   if(pLCSiscomPro2Producto->SCP2PtrSig)
    sprintf(lchrArrPaso,"'%s',",pchrPtrCveProducto);
    else
    sprintf(lchrArrPaso,"'%s')",pchrPtrCveProducto);
lintTamanoActual+=strlen(lchrArrPaso);
*pchrPtrSql=(char *)realloc(*pchrPtrSql,lintTamanoActual+1);
strcat(*pchrPtrSql,lchrArrPaso);
}
void FormaConsultaTiposProducto(LCamposSiscomPro2 *pLCSiscomPro2Productos,
				const char *pchrPtrIdExpendio,
				char **pchrPtrSql)
{
const char *lchrPtrCveProducto;
char lchrArrSqlExpendio[128];
*pchrPtrSql=strdup("									\n\
	select a.idproducto,								\n\
	       0 as idtipoproducto,							\n\
		a.cveproducto as clave,							\n\
		b.cveproducto,								\n\
		c.dscproducto,								\n\
		d.existencia,								\n\
		d.exbodegas,								\n\
		e.precio,								\n\
		cantidad 								\n\
	from productoportipoproducto as a  inner join 					\n\
	     definiciontiposproducto as b using(idproducto) inner join			\n\
	     productos as c on b.cveproducto=c.cveproducto inner join			\n\
	     existenciaexpendiobodegas as d on b.cveproducto=d.cveproducto inner join	\n\
	     precios as e on b.cveproducto=e.cveproducto				\n\
        where a.cveproducto in(");
while(pLCSiscomPro2Productos)
{
   lchrPtrCveProducto=SiscomObtenDato(pLCSiscomPro2Productos,"CveProducto");	
   AgregandoCondicionTipoProducto(pLCSiscomPro2Productos,lchrPtrCveProducto,pchrPtrSql);
   pLCSiscomPro2Productos=pLCSiscomPro2Productos->SCP2PtrSig;
}
sprintf(lchrArrSqlExpendio," and d.idexpendio=%s",pchrPtrIdExpendio);
*pchrPtrSql=(char *)realloc(*pchrPtrSql,strlen(*pchrPtrSql)+strlen(lchrArrSqlExpendio)+1);
strcat(*pchrPtrSql,lchrArrSqlExpendio);
}

void ArgumentosTipoProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlTipoProducto",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlProductosEntrada",pSAgsSiscom);
}
void AsignaCampoParaCotizar(const char *pchrPtrCampoEntrada,
			    const char *pchrPtrCampoSalida,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    SCampoSiscomPro2 *pSCSiscomPro2Salida)
{
SiscomAsignaDatoCampo(pchrPtrCampoSalida,
		      pSCSiscomPro2Salida->intNumCampos,
		      (char *)SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampoEntrada),
		      pSCSiscomPro2Salida);
}
void CantidadPedidaPorCantidadDispositivo(const char *pchrPtrCantidadKits,
					  LCamposSiscomPro2 *pLCSiscomPro2DatBase,
					  SCampoSiscomPro2 *pSCSiscomPro2Salida)
{
float lfltCantidadSolicitada=atof(pchrPtrCantidadKits),
      lfltCantidadProducto=SiscomObtenDatoFloat(pLCSiscomPro2DatBase,"cantidad"),
      lfltTotal;
char lchrArrCantidadTot[20];
lfltTotal=lfltCantidadSolicitada*lfltCantidadProducto;
sprintf(lchrArrCantidadTot,"%.2f",lfltTotal);
SiscomAsignaDatoCampo2A("Cantidad",lchrArrCantidadTot,pSCSiscomPro2Salida);
}
const char *SiscomObtenCampo(SCampoSiscomPro2 *pSCSiscomPro2,
			     const char *pchrPtrNmbCampo)
{
int lintContador;
int lintNCampos=pSCSiscomPro2->intNumCampos;
for(lintContador=0; lintContador<lintNCampos; lintContador++,pSCSiscomPro2++)
if(!strcmp(pchrPtrNmbCampo,pSCSiscomPro2->chrPtrNmbCampo))
 return pSCSiscomPro2->chrPtrDato;
 return 0;
}
void FormaCotizacionTipoProducto(SArgsSiscom *pSAgsSiscom,
		     SCampoSiscomPro2 *pSCSiscomPro2,
		     LCamposSiscomPro2 **pLCSiscomPro2Ent,
		     LCamposSiscomPro2 **pLCSiscomPro2Base,
		     int *pintPtrNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlTipoProducto",pSAgsSiscom),
		  *lLCSiscomPro2EntAct=0;
SCampoSiscomPro2 *lSCSiscomPro2;
const char *lchrPtrCantidadPedida;
int lintTamanoRegistro;
*pintPtrNRegistros=0;
*pLCSiscomPro2Base=lLCSiscomPro2Dat;
while(lLCSiscomPro2Dat)
{
  lintTamanoRegistro=sizeof(SCampoSiscomPro2)*(pSCSiscomPro2->intNumCampos);
  lSCSiscomPro2=(SCampoSiscomPro2 *)malloc(lintTamanoRegistro);
  memcpy(lSCSiscomPro2,pSCSiscomPro2,lintTamanoRegistro);
  lchrPtrCantidadPedida=SiscomObtenCampo(pSCSiscomPro2,"Cantidad");
  AsignaCampoParaCotizar("cveproducto","CveProducto",lLCSiscomPro2Dat,lSCSiscomPro2);
  CantidadPedidaPorCantidadDispositivo(lchrPtrCantidadPedida,lLCSiscomPro2Dat,lSCSiscomPro2);
  SiscomAsignaDatoCampo("IdTipoProducto",pSCSiscomPro2->intNumCampos,"0",lSCSiscomPro2);
  AsignaCampoParaCotizar("precio","Precio",lLCSiscomPro2Dat,lSCSiscomPro2);
  AsignaCampoParaCotizar("clave","ClaveKit",lLCSiscomPro2Dat,lSCSiscomPro2);
  SiscomCreaListaCamposPro2(lSCSiscomPro2,pLCSiscomPro2Ent,&lLCSiscomPro2EntAct);
  lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
  (*pintPtrNRegistros)++;
}
}
void ArmaRespuestaVentaTipoProducto(LCamposSiscomPro2 *pLCSiscomPro2Ent,
				    const char *pchrPtrCveKit,
				    const char *pchrPtrIdProductoKit,
				    LCamposSiscomPro2 **pLCSiscomPro2COrdenPrim,
				    LCamposSiscomPro2 **pLCSiscomPro2COrdenAct,
				    int *pintPtrNRegRegreso)
{
		  SiscomAnexaRegistroPro2(
		      	pLCSiscomPro2COrdenPrim,
		      	pLCSiscomPro2COrdenAct,
		      	pintPtrNRegRegreso,
		      	"CveProducto, 		\
		       	Descripcion,		\
			Cantidad, 		\
			Existencia,		\
			ExisBodega,		\
			Precio,			\
			NmbTipoPrecio,		\
			IdExpendio,		\
			ImporteCantidad,	\
			ImporteTotal,		\
			SePuedeVender,		\
			NumJuegos,      	\
			IdCliente,		\
			IdPractica,		\
			EdoRegistro,		\
			ClienteFrecuente,	\
			PorDescuento,		\
			RFC,			\
			IdCaja,			\
			PorDescuentoCaja,	\
			PorDescuentoCajaOrden,	\
			OrdenACaja,		\
			CantidadValida,		\
			IdOrigenCompra,		\
			EsKit,			\
			CveKit,			\
			IdProductoKit,		\
			CantidadKit,		\
			ImporteKit,		\
			IdTipoProducto",
			SiscomObtenDato(pLCSiscomPro2Ent,"CveProducto"),
			"Descripcion",
			SiscomObtenDato(pLCSiscomPro2Ent,"Cantidad"),
			"",
			"",
			"",
			SiscomObtenDato(pLCSiscomPro2Ent,"NmbPrecio"),
			SiscomObtenDato(pLCSiscomPro2Ent,"IdExpendio"),
			"",
			"",
			"Si",
			SiscomObtenDato(pLCSiscomPro2Ent,"NumJuegos"),
			SiscomObtenDato(pLCSiscomPro2Ent,"IdCliente"),
			SiscomObtenDato(pLCSiscomPro2Ent,"IdPractica"),
			SiscomObtenDato(pLCSiscomPro2Ent,"EdoRegistro"),
			"",
			"",
			SiscomObtenDato(pLCSiscomPro2Ent,"RFC"),
			"0",
			SiscomObtenDato(pLCSiscomPro2Ent,"PorDescuentoCaja"),
			SiscomObtenDato(pLCSiscomPro2Ent,"PorDescuentoCajaOrden"),
			"0",
			"Si",
			"",
			"Si",
			pchrPtrCveKit,
			pchrPtrIdProductoKit,
			SiscomObtenDato(pLCSiscomPro2Ent,"CantidadKit"),
			SiscomObtenDato(pLCSiscomPro2Ent,"ImporteKit"),
			"2");
}
		  /* Queretaro a 3 de diciembre del 2015 
		   * Se integra el modulo de faltantes 
		   * Cuando se detecte que la existencia en el expendio y la bodega
		   * es 0, se debera realizar la insercion a la tabla de faltantes 
		   * para que se lleve el registro ....
		   */


void GeneraIdFaltante(const char *pchrPtrCveProducto,
		     SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdFaltante[26],
     lchrArrFechaHoy[26];
  SiscomObtenNumeroUnicoChar(lchrArrIdFaltante);
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
  SiscomAnexaRegistroArgumento("IdsFaltantes",
  				pSAgsSiscom,
				"IdFaltante,Fecha,CveProducto",
				lchrArrIdFaltante,
				lchrArrFechaHoy,
				pchrPtrCveProducto);
}
void AsigaCamposFaltanteConSeguimiento(SArgsSiscom *pSAgsSiscom)
{
char lchrArrFechaHoy[26];
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
  SiscomPonPrimerRegistroArgumento("SqlProductoFaltante",pSAgsSiscom); 
  SiscomAnexaRegistroArgumento(
  		"IdsFaltantes",
  		pSAgsSiscom,
		"IdFaltante,Fecha,CveProducto",
		SiscomObtenCampoArgumento("SqlProductoFaltante","idfaltante",pSAgsSiscom),
		lchrArrFechaHoy,
		SiscomObtenCampoArgumento("SqlProductoFaltante","cveproducto",pSAgsSiscom));
}
void ArgumentosFaltantes(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlFaltantes",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"IdsFaltantes",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(2,"SqlProductoFaltante",pSAgsSiscom);
}
int EsProductoFaltante(LCamposSiscomPro2 *pLCSiscomPro2Base)
{

  return !SiscomObtenDatoInt(pLCSiscomPro2Base,"existencia") &&
  	 !SiscomObtenDatoInt(pLCSiscomPro2Base,"exbodegas");
}
void RegistraFaltanteProducto(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlFaltantes");
}
void AgregaEntradaSeguimientoFaltante(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("Agregando seguimiento del faltante");
SqlRegistraFaltante(pSAgsSiscom);
SqlInsertandoDetalleFaltante(pSAgsSiscom);
}
void IncrementaFaltante(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("Incrementando las veces del faltante");
AsigaCamposFaltanteConSeguimiento(pSAgsSiscom);
SqlIncrementaVecesPedido(pSAgsSiscom);
SqlInsertandoDetalleFaltante(pSAgsSiscom);
SiscomImprimeArgumento("SqlFaltantes",pSAgsSiscom);
}
void RegistrandoFaltantes(LCamposSiscomPro2 *pLCSiscomPro2Base,
			  SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrCveProducto;
lchrPtrCveProducto=SiscomObtenDato(pLCSiscomPro2Base,"cveproducto");
if(EsProductoFaltante(pLCSiscomPro2Base))
{
	ArgumentosFaltantes(pSAgsSiscom);
	SqlFaltanteProducto(lchrPtrCveProducto,pSAgsSiscom);
	SiscomImprimeArgumento("SqlProductoFaltante",pSAgsSiscom);
	if(SiscomArgumentoOperacionPrim("SqlProductoFaltante",pSAgsSiscom))
	IncrementaFaltante(pSAgsSiscom);
	else
	{
	GeneraIdFaltante(lchrPtrCveProducto,pSAgsSiscom);
	AgregaEntradaSeguimientoFaltante(pSAgsSiscom);
	}
RegistraFaltanteProducto(pSAgsSiscom); 
}

}
