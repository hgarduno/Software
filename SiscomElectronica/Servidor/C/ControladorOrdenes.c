#include<ControladorOrdenes.h>
#include <stdlib.h>
#include <string.h>
/* Martes 15 de enero del 2013
 *  Para integrar la carga de los productos en la ventana
 *  de cotizacion de orden en la caja central se agrego 
 *  la consulta
 */
StcConsultaSvrSiscom2 gStcCnsControladorOrdenes[]=
{
  {EsConsultaControladorOrdenes, FormaConsultaControladorOrdenes},
  {EsConsultaGeneraIdOrden, FormaConsultaGeneraIdOrden},
  {EsConsultaProductosCotizacion, FormaConsultaProductosCotizacion},
  {EsConsultaProductosOrdenVendida, FormaConsultaProductosOrdenVendida},
  {EsConsultaProductosOrdenCajaCentral, FormaConsultaProductosOrdenCajaCentral},
  {EsConsultaOrdenesPorFechas, FormaConsultaOrdenesPorFechas},
  {EsConsultaProductosOrdenes, FormaConsultaProductosOrdenes},
};
int gintCnsControladorOrdenes=6;



/* OJO          
 *
 * En este modulo falta considerar, la busqueda de la
 * direccion ip del expendio.
 *
 * Revisar el modulo RNReportesVentas.c 
 */
int EsConsultaProductosOrdenes(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ProductosDeLasOrdenes");
}
/*
 * 12 Julio 2007 
 * Queretaro 
 *
 * Para el caso de SISCOM Electronica, la clave del producto
 * es suficiente para poder saber de que se esta hablando, pero
 * si la clave se utiliza un codigo de barras, se debera consi-
 * derar en la consulta de esta funcion integrar la descripcion
 * del producto
 *
 */

void FormaConsultaProductosOrdenes(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
char lchrArrPaso[128];
int lintContador;

	sprintf(lchrArrConsulta,
		"select idventa,		\
			cantidad,		\
			cveproducto,		\
			precio			\
		  from ventas			\
		  where idventa in(");
	for(lintContador=1;
	    pchrPtrEntrada[lintContador];
	    lintContador++)
	{
	  if(pchrPtrEntrada[lintContador+1])
	  sprintf(lchrArrPaso,
	  	  "%s,",
		  pchrPtrEntrada[lintContador]);
	  else
	  sprintf(lchrArrPaso,
	  	  "%s)",
		  pchrPtrEntrada[lintContador]);
	  strcat(lchrArrConsulta,lchrArrPaso);

	}
	strcat(lchrArrConsulta," order by idventa");
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=RealizaCalculosProductosOrdenes;
}
int ObtenIndiceOrden(StcListaGeneral **pLGenOrdenes,
		     const char *pchrPtrCveProducto)
{
int lintContador=0;
SProductoOrden *lSPOrden;
	for(lintContador=0;
            pLGenOrdenes[lintContador];
	    lintContador++)
	{
	 lSPOrden=(SProductoOrden *)pLGenOrdenes[lintContador]->vidInformacion;
	 if(!strcmp(lSPOrden->chrArrCveProducto,
	 	    pchrPtrCveProducto))
	 {
	  return lintContador;
	 }
	}

	  return lintContador;
}
void CopiaDatosProductoOrden(LCamposSiscomPro2 *pLCSiscomPro2,
			     SProductoOrden *pSPOrden)
{
	strcpy(pSPOrden->chrArrIdVenta,SiscomObtenDato(pLCSiscomPro2,"idventa"));
	pSPOrden->fltCantidad=atof(SiscomObtenDato(pLCSiscomPro2,"cantidad"));
	strcpy(pSPOrden->chrArrCveProducto,SiscomObtenDato(pLCSiscomPro2,"cveproducto"));
	pSPOrden->fltPrecioU=atof(SiscomObtenDato(pLCSiscomPro2,"precio"));
	pSPOrden->fltPrecioTotal=pSPOrden->fltCantidad*pSPOrden->fltPrecioU;
}
void AsignaMemoriaListaProductos(int pintNDatos,
				 StcListaGeneral ***pSLGeneral)
{
int lintContador;
	if(!(*pSLGeneral=(StcListaGeneral **)malloc(sizeof(StcListaGeneral *)*(pintNDatos+1))))
	{

	}
	else
	{
	  for(lintContador=0;lintContador<pintNDatos;lintContador++)
	   (*pSLGeneral)[lintContador]=0;
	}
}
void GeneraInformacionProducto(StcListaGeneral *pLGenPrimOrden,
			       SiscomOperacionesServidor *pSOpServidor,
			       LCamposSiscomPro2 **pLCSiscomPro2Act,
			       float *pfltPtrImporteTotal)
{
SProductoOrden *lSPOrdenDat;
float lfltCantidad=0.0;
float lfltImporte=0.0;
float lfltImporteParcial;
char lchrArrImporte[10];
char lchrArrCantidad[10];
char lchrArrCveProducto[50];
char lchrArrPrecio[10];

	    lSPOrdenDat=(SProductoOrden *)pLGenPrimOrden->vidInformacion;
	    strcpy(lchrArrCveProducto,
	    	   lSPOrdenDat->chrArrCveProducto);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Calculando:%s",
			  lchrArrCveProducto);

	for(;
	     pLGenPrimOrden;
	     pLGenPrimOrden=pLGenPrimOrden->LGenSig)
	{
	    lSPOrdenDat=(SProductoOrden *)pLGenPrimOrden->vidInformacion;
	    lfltCantidad+=lSPOrdenDat->fltCantidad;
	    lfltImporte+=lSPOrdenDat->fltCantidad*
	    		 lSPOrdenDat->fltPrecioU;
	}
	sprintf(lchrArrImporte,"%.2f",lfltImporte);
	sprintf(lchrArrCantidad,"%.2f",lfltCantidad);
	/*
	 * 17 Julio 2007
	 * Queretaro
	 *
	 * En este punto no se toma el precio directamente de la 
	 * informacion en la base de datos, debido al que en 
	 * el proceso de facturacion, y al realizarse este para
	 * varias ordenes que pudieron tomarse durante un periodo
	 * de tiempo, en el que el precio pudo haber variado, por 
	 * este motivo el precio final de la facturacion se obtiene
	 * dividiendo el importe total de los productos entre la
	 * cantidad de productos vendidos en todas las ordenes
	 */
	sprintf(lchrArrPrecio,"%.2f",lfltImporte/lfltCantidad);
	*pfltPtrImporteTotal+=lfltImporte;
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
				pLCSiscomPro2Act,
				&pSOpServidor->intNRegistrosRes,
				"cveproducto,		\
				precio,			\
				cantidad,		\
				importe,		\
				idventa",
				lchrArrCveProducto,
				lchrArrPrecio,
				lchrArrCantidad,
				lchrArrImporte,
				"");


				

}
void GeneraRespuestaOrdenes(StcListaGeneral **pLGenPrimOrden,
			    SiscomOperacionesServidor *pSOpServidor)
{
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
float lfltImporteTotal=0.0;
char lchrArrImporteTotal[10];
int lintContador;
	pSOpServidor->intNRegistrosRes=0;
	pSOpServidor->LCSiscomPro2=0;
SiscomMensajesLog(gPtrFleArchivoLog,
		  "Cuentas Ordenes:");

	for(lintContador=0;
	    pLGenPrimOrden[lintContador];
	    lintContador++)
	  GeneraInformacionProducto(pLGenPrimOrden[lintContador],
	  			    pSOpServidor,
	  			    &lLCSiscomPro2Act,
				    &lfltImporteTotal);
	sprintf(lchrArrImporteTotal,"%.2f",lfltImporteTotal);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
				&lLCSiscomPro2Act,
				&pSOpServidor->intNRegistrosRes,
				"cveproducto,		\
				precio,			\
				cantidad,		\
				importe,		\
				idventa",
				"Total",
				"",
				"",
				lchrArrImporteTotal,
				"");

	sprintf(lchrArrImporteTotal,"%.2f",lfltImporteTotal*1.15);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
				&lLCSiscomPro2Act,
				&pSOpServidor->intNRegistrosRes,
				"cveproducto,		\
				precio,			\
				cantidad,		\
				importe,		\
				idventa",
				"Total Mas IVA",
				"",
				"",
				lchrArrImporteTotal,
				"");


}
void RealizaCalculosProductosOrdenes(SiscomOperacionesServidor *pSOpServidor)
{
StcListaGeneral **lLGenPrimOrden,
	     **lLGenOrdenActual,
	     *lLGenDatos=0;
int lintIndice=0;
LCamposSiscomPro2 *lLCSiscomPro2Dat;
SProductoOrden lSPOrden;
SProductoOrden *lSPOrdenDat;
int lintContador;
	AsignaMemoriaListaProductos(100,&lLGenPrimOrden);
	AsignaMemoriaListaProductos(100,&lLGenOrdenActual);
	SiscomImprimeContenidoProtocolo("",
					gPtrFleArchivoLog,
					pSOpServidor->LCSiscomPro2);

	for(lLCSiscomPro2Dat=pSOpServidor->LCSiscomPro2;
	    lLCSiscomPro2Dat;
	    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
	{
	   lintIndice=ObtenIndiceOrden(lLGenPrimOrden,
	   			       SiscomObtenDato(lLCSiscomPro2Dat,"cveproducto"));
	   CopiaDatosProductoOrden(lLCSiscomPro2Dat,&lSPOrden);
	   SiscomCreaNodoListaGeneral((void *)&lSPOrden,
	   			      (void (*)(void *,StcListaGeneral **))CreaNodoProductoOrden,
				      &lLGenPrimOrden[lintIndice],
				      &lLGenOrdenActual[lintIndice]);
	}
	SiscomMensajesLog(gPtrFleArchivoLog,"Los datos por orden");
	for(lintContador=0;
	    lLGenPrimOrden[lintContador];
	    lintContador++)
	{
	   lSPOrdenDat=(SProductoOrden *)lLGenPrimOrden[lintContador]->vidInformacion;
	   SiscomMensajesLog(gPtrFleArchivoLog,
	   		     "%s",
			     lSPOrdenDat->chrArrCveProducto);
	  for(lLGenDatos=lLGenPrimOrden[lintContador];
	      lLGenDatos;
	      lLGenDatos=lLGenDatos->LGenSig)
	  {
	     lSPOrdenDat=(SProductoOrden *)lLGenDatos->vidInformacion;
	    SiscomMensajesLog(gPtrFleArchivoLog,
	    		      "\t%s\t%s\t%f\t%f",
			      lSPOrdenDat->chrArrIdVenta,
			      lSPOrdenDat->chrArrCveProducto,
			      lSPOrdenDat->fltCantidad,
			      lSPOrdenDat->fltPrecioU);
	  }
	}
	GeneraRespuestaOrdenes(lLGenPrimOrden,pSOpServidor);
}

void CreaNodoProductoOrden(SProductoOrden *pSProdOrden,
			   StcListaGeneral **pSLisGeneral)
{

	*pSLisGeneral=(StcListaGeneral *)malloc(sizeof(StcListaGeneral));
	(*pSLisGeneral)->vidInformacion=malloc(sizeof(SProductoOrden));
	*(SProductoOrden *)(*pSLisGeneral)->vidInformacion=*pSProdOrden;
	(*pSLisGeneral)->LGenSig=0;
}


int EsConsultaOrdenesPorFechas(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"OrdenesPorFecha");
}
void FormaConsultaOrdenesPorFechas(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta,
	"select sum(importe) as Total,					\
	        fechahora::date,					\
	        idventa,						\
		cliente,						\
		nombre,							\
		apaterno,						\
		amaterno						\
	from ventas inner join 						\
	     personas as a on idpersona=cliente				\
	where fechahora::date>='%s' and					\
	      fechahora::date<='%s' and					\
	      edoventa=0						\
	group by fechahora::date,					\
		idventa,						\
		cliente,						\
		nombre,							\
		apaterno,						\
		amaterno",
	 pchrPtrEntrada[2],
	 pchrPtrEntrada[3]);

SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=RealizaCalculosOrdenesFecha;
}


void RealizaCalculosOrdenesFecha(SiscomOperacionesServidor *pSOpServidor)
{

LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
		  *lLCSiscomPro2Act=0,
		  *lLCSiscomPro2Rec;
const char *lchrPtrTotal;
char lchrArrImporteIva[20],
     lchrArrImporteTotal[20];
float lfltImporteIva,
      lfltImporte;
float lfltImporteTotal=0.0,
      lfltImporteTotalIva=0.0;
SiscomMensajesLog(gPtrFleArchivoLog,
		  "RealizaCalculosOrdenesFecha:%d",
		  pSOpServidor->intNRegistrosRes);
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,pSOpServidor->LCSiscomPro2);

 pSOpServidor->intNRegistrosRes=0;
 for(lLCSiscomPro2Rec=pSOpServidor->LCSiscomPro2;
     lLCSiscomPro2Rec;
     lLCSiscomPro2Rec=lLCSiscomPro2Rec->SCP2PtrSig)
 {
	lfltImporte=atof((lchrPtrTotal=SiscomObtenDato(lLCSiscomPro2Rec,"total")));
	lfltImporteIva=1.15*lfltImporte;
	lfltImporteTotalIva+=lfltImporteIva;
	lfltImporteTotal+=lfltImporte;
	sprintf(lchrArrImporteIva,"%.2f",lfltImporteIva);
	SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
				&lLCSiscomPro2Act,
				&pSOpServidor->intNRegistrosRes,
				"NumOrden,		\
				 ImporteTotal,		\
				 ImporteIVA,		\
				 Fecha,			\
				 IdCliente,		\
				 Nombre,		\
				 APaterno,		\
				 AMaterno",
				 SiscomObtenDato(lLCSiscomPro2Rec,"idventa"),
				 lchrPtrTotal,
				 lchrArrImporteIva,
				 SiscomObtenDato(lLCSiscomPro2Rec,"fechahora"),
				 SiscomObtenDato(lLCSiscomPro2Rec,"cliente"),
				 SiscomObtenDato(lLCSiscomPro2Rec,"nombre"),
				 SiscomObtenDato(lLCSiscomPro2Rec,"apaterno"),
				 SiscomObtenDato(lLCSiscomPro2Rec,"amaterno"));
 }
sprintf(lchrArrImporteIva,"%.2f",lfltImporteTotalIva);
sprintf(lchrArrImporteTotal,"%.2f",lfltImporteTotal);
SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
				&lLCSiscomPro2Act,
				&pSOpServidor->intNRegistrosRes,
				"NumOrden,		\
				 ImporteTotal,		\
				 ImporteIVA,		\
				 Fecha,			\
				 IdCliente,		\
				 Nombre,		\
				 APaterno,		\
				 AMaterno",
				 "",
				 lchrArrImporteTotal,
				 lchrArrImporteIva,
				 "",
				 "",
				 "",
				 "",
				 "");

 pSOpServidor->LCSiscomPro2=lLCSiscomPro2Prim;
 SiscomMensajesLog(gPtrFleArchivoLog,
 		   "Numero Registros:%d",
		   pSOpServidor->intNRegistrosRes);
SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,pSOpServidor->LCSiscomPro2);
}


int EsConsultaProductosOrdenVendida(char **pchrPtrEntrada)
{
	SiscomLog("");
	return !strcmp(pchrPtrEntrada[0],"ProductosOrdenVendida");
}
void FormaConsultaProductosOrdenVendida(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta,
	"select * 		\
	 from ventas		\
	 where idventa=%s and 	\
	 edoventa=0",
	 pchrPtrEntrada[1]);
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=0;
}

int EsConsultaProductosOrdenCajaCentral(char **pchrPtrEntrada)
{
	SiscomLog("");
	return !strcmp(pchrPtrEntrada[0],"ProductosOrdenCajaCentral");
}
void FormaConsultaProductosOrdenCajaCentral(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta,
	"select * 		\
	 from ventas		\
	 where idventa=%s and 	\
	 edoventa=3",
	 pchrPtrEntrada[1]);
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=0;
}


int EsConsultaProductosCotizacion(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ProductosCotizacion");
}
void FormaConsultaProductosCotizacion(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta,
	"select * 		\
	 from ventas		\
	 where idventa=%s and 	\
	 edoventa=1",
	 pchrPtrEntrada[1]);
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=0;
}

int EsConsultaControladorOrdenes(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ControladorOrdenes");
}
void FormaConsultaControladorOrdenes(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta,"select * from ??? ");
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
pSOpServidor->EjecutaProcesoDespues=0;
}
int EsConsultaGeneraIdOrden(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"GeneraIdentificador");
}
void FormaConsultaGeneraIdOrden(char **pchrPtrEntrada,
		     SiscomOperacionesServidor *pSOpServidor)
{
/*
char lchrArrConsulta[1024];
sprintf(lchrArrConsulta,"select * from ??? ");
SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
			&pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);
*/
pSOpServidor->EjecutaProcesoDespues=GeneraIdOrden;
}

void GeneraIdOrden(SiscomOperacionesServidor *pSOpServidor)
{
long llngIdOrden;
char lchrArrIdOrden[20];
LCamposSiscomPro2 *lLCSiscomPro2Act=0;
	llngIdOrden=SiscomObtenNumeroUnico();
	sprintf(lchrArrIdOrden,
		 "%ld",llngIdOrden);
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "GenerandoIdOrden:{%s}",
			  lchrArrIdOrden);
	SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2,
			  	&lLCSiscomPro2Act,
				&pSOpServidor->intNRegistrosRes,
				"IdOrden",
				lchrArrIdOrden);
}

void AnalizaConsultaControladorOrdenes(char **pchrPtrEntrada, 
			SiscomOperacionesServidor *pSOpServidor)
{ 
int lintContador;
for(lintContador=0;
    lintContador<gintCnsControladorOrdenes;
    lintContador++)
{
if(gStcCnsControladorOrdenes[lintContador].Consulta(pchrPtrEntrada))
gStcCnsControladorOrdenes[lintContador].FormaConsulta(pchrPtrEntrada,pSOpServidor);
}
}
void ConsultaControladorOrdenes(int pintSocket,int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada;
lSOpServidor.EjecutaProcesoAntes=0;
SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			   gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			   &lSOpServidor);
SiscomLeeInformacionProtocolo(pintSocket,
		     pintNRegistros,
		     &lSOpServidor.LCSiscomPro2Dat);
SiscomContenidoProtocolo(lSOpServidor.LCSiscomPro2Dat);
SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
				  pintNRegistros,
				  "Parametro",
				  &lchrPtrEntrada);
AnalizaConsultaControladorOrdenes(lchrPtrEntrada,&lSOpServidor); 
SiscomOperacionesServidores(&lSOpServidor);
SiscomEnviaAlServidor(pintSocket,
		      lSOpServidor.intNRegistrosRes,
		      "Respuesta",
		      lSOpServidor.LCSiscomPro2);
SiscomContenidoProtocolo(lSOpServidor.LCSiscomPro2);
close(pintSocket);
}
int CreaCadenaComandoControladorOrdenesSql(LCamposSiscomPro2 *pLCSiscomPro2, 
			 char *pchrPtrCadena)
{
	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 return 1;
	}
  return 0;
}
void RegistraControladorOrdenes(int pintSocket,int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
		  *lLCSiscomPro2InsAct=0;
char lchrArrInsercion[1024];
int lintNRegistros=0;
int lintSocketAD;
char *lchrPtrEdoConexion=0;
SiscomLeeInformacionProtocolo(pintSocket,pintNRegistros,&lLCSiscomPro2);
SiscomImprimeContenidoProtocolo("??",gPtrFleArchivoLog,lLCSiscomPro2);
for(;		
	lLCSiscomPro2;
    lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
if(CreaCadenaComandoControladorOrdenesSql(lLCSiscomPro2,lchrArrInsercion))
SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
			&lLCSiscomPro2InsAct,
			&lintNRegistros,
			"ComandoSQL",
			lchrArrInsercion);
SiscomInformacionServidor(
	gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
	"Inserciones",
	lintNRegistros,
	lLCSiscomPro2Ins,
	&lchrPtrEdoConexion,
	&lintSocketAD);
if(lchrPtrEdoConexion)
SiscomMensajesLog(gPtrFleArchivoLog,"Error al Envia:ControladorOrdenes",lchrPtrEdoConexion);
}

