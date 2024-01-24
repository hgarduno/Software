#include <RNCompras.h>
#include <RNPersonas.h>
#include <RNCotizaDispositivos.h>
#include <ComunElectronica.h>
#include <ServidorGeneral.h>
#include <SqlCotizaDispositivos.h>
#include <ComunElectronica2.h>
#include <stdlib.h>
#include <string.h>
extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsCompras[]={ {EsConsultaCompras,FormaConsultaCompras}
			       };
int gintCnsCompras=1;

int EsConsultaCompras(char **pchrPtrEntrada)
{
	return 1;
}
void FormaConsultaCompras(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[128];

	sprintf(lchrArrConsulta,
		"select *		\
		from empresas 		\
		where idEmpresa<0");
 SiscomInformacionOperaciones("ConsultaSQL","Consultas",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL",
			lchrArrConsulta);

pSOpServidor->EjecutaProcesoDespues=0;
}
void AnalizaConsultaCompras(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsCompras;
	    lintContador++)
	   if(gStcCnsCompras[lintContador].Consulta(pchrPtrEntrada))
	      gStcCnsCompras[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);

	

}
void ConsultaCompras(int pintSocket,
		       int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;

	lSOpServidor.EjecutaProcesoAntes=0;
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	ElectronicaComunicacionExpendio(lSOpServidor.LCSiscomPro2Dat,
					&lSOpServidor.intPtoCom,
					lSOpServidor.chrPtrDirIpSvr);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	AnalizaConsultaCompras(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);

	close(pintSocket);
}

void ValorDelIva(LCamposSiscomPro2 *pLCSiscomPro2,
		 float *pfltPtrPrecio,
		 float *pfltPtrPrecioSinIva)
{
const char *lchrPtrPrecioIva=SiscomObtenDato(pLCSiscomPro2,"PrecioIVA");
const char *lchrPtrPrecio=SiscomObtenDato(pLCSiscomPro2,"Precio");

	if(!strcmp(lchrPtrPrecioIva,"+IVA"))
	{
	   *pfltPtrPrecio=atof(lchrPtrPrecio)*1.16;
	   *pfltPtrPrecioSinIva=atof(lchrPtrPrecio);
	}
	if(!strcmp(lchrPtrPrecioIva,"Con IVA"))
	{
	   *pfltPtrPrecio=atof(lchrPtrPrecio);
	   *pfltPtrPrecioSinIva=(*pfltPtrPrecio)*0.84;
	}
}
/*{ Queretaro a 3 de diciembre del 2015 
 * Se agrega la actualizacion para faltantes
 * en caso, de que el producto este en Faltantes 
 * se actualiza el estado para terminar ahi el 
 * seguimiento
 *
 }*/
void ArgumentosProductosEnFaltantes(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlProductoFaltante",pSAgsSiscom);
}

void ArgumentosProductoFabricadoSiscom(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlFabricadoSiscom",pSAgsSiscom);
}



void ActualizaSiElProductoEstaEnFaltantes(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					  SArgsSiscom *pSAgsSiscom,
					  LCamposSiscomPro2 **pLCSiscomPro2Ins,
					  LCamposSiscomPro2 **pLCSiscomPro2InsAct,
					  int *pintPtrNRegistros)
{
char lchrArrSql[256];
const char *lchrPtrCveProducto;
lchrPtrCveProducto=SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto");
ArgumentosProductosEnFaltantes(pSAgsSiscom);
SqlFaltanteProducto(lchrPtrCveProducto,pSAgsSiscom);
if(SiscomArgumentoOperacionPrim("SqlProductoFaltante",pSAgsSiscom))
{
   SiscomPonPrimerRegistroArgumento("SqlProductoFaltante",pSAgsSiscom);
   sprintf(lchrArrSql,
   	   "update faltantes set idedofaltante=1 where idfaltante=%s",
	    SiscomObtenCampoArgumento("SqlProductoFaltante","idfaltante",pSAgsSiscom));
  SiscomAnexaRegistroPro2(pLCSiscomPro2Ins,
  			  pLCSiscomPro2InsAct,
			  pintPtrNRegistros,
			  "ComandoSQL,EdoRegistro",
			  lchrArrSql,
			  "");
}
}
void ActualizaProductoFabricadoSiscomCompra(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					  SArgsSiscom *pSAgsSiscom,
					  LCamposSiscomPro2 **pLCSiscomPro2Ins,
					  LCamposSiscomPro2 **pLCSiscomPro2InsAct,
					  int *pintPtrNRegistros)
{
float lfltCantidad;
char lchrArrSql[512];
const char *lchrPtrCveProducto;
LCamposSiscomPro2 *lLCSiscomPro2Reg;
lchrPtrCveProducto=SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto");
ArgumentosProductoFabricadoSiscom(pSAgsSiscom);
SqlDefinicionProductoSiscom(lchrPtrCveProducto,pSAgsSiscom);
if((lLCSiscomPro2Reg=SiscomArgumentoOperacionPrim("SqlFabricadoSiscom",pSAgsSiscom)))
{
   SiscomContenidoProtocolo(lLCSiscomPro2Reg); 
   for(;
   	lLCSiscomPro2Reg;
	lLCSiscomPro2Reg=lLCSiscomPro2Reg->SCP2PtrSig)
   {
   lfltCantidad=SiscomObtenDatoFloat(lLCSiscomPro2Reg,"cantidad")*
   		SiscomObtenDatoFloat(pLCSiscomPro2Dat,"Cantidad");
   sprintf(lchrArrSql,
   	   "update existencias set existencia=existencia-%f where cveproducto='%s' and idexpendio=%s;",
	   lfltCantidad,
	   SiscomObtenDato(lLCSiscomPro2Reg,"cveproducto"),
	   SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"));
  SiscomAnexaRegistroPro2(pLCSiscomPro2Ins,
  			  pLCSiscomPro2InsAct,
			  pintPtrNRegistros,
			  "ComandoSQL,EdoRegistro",
			  lchrArrSql,
			  "");
  }
}
}

int EsTipoProductoFabricadoSiscom(LCamposSiscomPro2 *pLCSiscomPro2Producto)
{
const char *lchrPtrIdTipoProducto;
lchrPtrIdTipoProducto=SiscomObtenDato(pLCSiscomPro2Producto,"IdTipoProducto");
if(*lchrPtrIdTipoProducto &&
   !strcmp(lchrPtrIdTipoProducto,"3"))
return 1;
else
return 0;
}
void RegistraCompras(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0,
		  *lLCSiscomPro2Respuesta=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
char lchrArrFechaHora[52];
const char *lchrPtrIdVendedor;
const char *lchrPtrNumFactura=0,
	   *lchrPtrFechaPago=0,
	   *lchrPtrIdExpendio=0,
	   *lchrPtrIdProveedor=0,
	   *lchrPtrIdOrigenCompra;
int lintNRegistros=0,
    lintSocketAD,
    lintNRegistrosRes;
int lintIdVenta=SiscomObtenNumeroUnico();
float lfltImporte,
	lfltImporteCredito=0,
	lfltPrecio,
	lfltPrecioSinIva,
	lfltImporteTotalCompra=0.0;
int lintPtoCom;
char lchrArrDirIpExpendio[40],
     lchrArrIdCompra[25];;
/*{ Queretaro a 3 de diciembre del 2015 
 * Se agrega la valiacion del producto en faltantes 
 * para cambiar el estado  y terminar el seguimiento ....
 }*/
SArgsSiscom lSArgsSiscom;
/* { Tepotzotlan Mexico a 3 Agosto del 2017 
 * Se agrega la funcionalidad para registrar
 * la compra de un producto Fabricado en Siscom
 * para esto, el producto debera estar registrado
 * como kit, y al momento de registrar una compra 
 * de este tipo de producto, cada producto del que 
 * se forma el kit, se descontara del inventario, esto
 * debido a la necesidad de saber que aunque haya 
 * productos como caiman, o cable, si ya se fabrico
 * el producto, este estara como disponible en el 
 * inventario del sistema, pero fisicamente ya se 
 * uso para la fabricacion, por lo que se desarrolla
 * el concepto de producto de fabricacion Siscom y
 * su respectiva compra
 * Para proceder al descuento del material, se toma
 * la consideracion que esta en el expendio,  no 
 * se podra realizar el descuento del producto en 
 * la bodega
 }*/
int lintEsProductoSiscom;

SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
SiscomLog("RegistraCompras");
SiscomContenidoProtocolo(lLCSiscomPro2);
memset(&lSArgsSiscom,0,sizeof(SArgsSiscom));
ComunicacionExpendioConsulta(&lSArgsSiscom);
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
	EliminaTotalOrden(lLCSiscomPro2);
	lchrPtrIdVendedor= SiscomObtenDato(lLCSiscomPro2,"IdUnidad"); 
	lchrPtrIdOrigenCompra=SiscomObtenDato(lLCSiscomPro2,"IdOrigenCompra");
	SiscomObtenNumeroUnicoChar(lchrArrIdCompra);
	ElectronicaComunicacionExpendio(lLCSiscomPro2,
					&lintPtoCom,
					lchrArrDirIpExpendio);

	AgregaRegistroRegistroCompra(&lLCSiscomPro2Ins,
				   &lLCSiscomPro2InsAct,
				   &lintNRegistros,
				   lchrPtrIdOrigenCompra,
				   lchrArrIdCompra,
				   lchrArrFechaHora,
				   lfltImporteTotalCompra);
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {

	lintEsProductoSiscom=EsTipoProductoFabricadoSiscom(lLCSiscomPro2);	
  	ActualizaSiElProductoEstaEnFaltantes(lLCSiscomPro2,
					     &lSArgsSiscom,
					     &lLCSiscomPro2Ins,
					     &lLCSiscomPro2InsAct,
					     &lintNRegistros);
  	ValorDelIva(lLCSiscomPro2,&lfltPrecio,&lfltPrecioSinIva);
  	lfltImporte=atof(SiscomObtenDato(lLCSiscomPro2,"Cantidad"))*
		    lfltPrecio;
	lfltImporteTotalCompra+=lfltImporte;
	 sprintf(lchrArrActualiza,
	 	 "insert into compras values('%s','%s',%s,%f,%s,%s,%s,%s,'%s','%s',%f,%f,%s);",
		 lchrArrFechaHora,
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		 SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		 lfltImporte,
		 SiscomObtenDato(lLCSiscomPro2,"IdProveedor"),
		 "0",
		 lchrPtrIdVendedor,
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"),
		 SiscomObtenDato(lLCSiscomPro2,"NmbPrecio"),
		 SiscomObtenDato(lLCSiscomPro2,"NumFactura"),
		 lfltPrecio,
		 lfltPrecioSinIva,
		 lchrArrIdCompra);
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL,EdoRegistro",
				 lchrArrActualiza,
				 "");
	/* { Miercoles 5 De Diciembre Tepotzotlan Mexico
	 *
	 * Con la integracion del modulo de bodegas a la administracion
	 * de SISCOM, la actualizacion del inventario para las ventas 
	 * se realiza por el traspaso del material de las bodegas al 
	 * expendio.
	 *
	 * En el apartado de compras las compras se almacenan en una
	 * bodega 
	sprintf(lchrArrActualiza,
		"update existencias set Existencia=Existencia+%s \
		 where CveProducto='%s' and			 \
		       idExpendio=%s",
		 SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"));

	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);

	  }*/
	
 	/*if(!lintEsProductoSiscom)	 */
	sprintf(lchrArrActualiza,
		"update precios set Precio=%s \
		 where cveProducto='%s'",
		 SiscomObtenDato(lLCSiscomPro2,"Importe"),
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	SqlMaterialBodega(lLCSiscomPro2,
			  &lLCSiscomPro2Ins,
			  &lLCSiscomPro2InsAct,
			  &lintNRegistros);
	if(!strcmp(SiscomObtenDato(lLCSiscomPro2, "NmbPrecio"), "Credito"))
	{
  	lfltImporteCredito+=atof(SiscomObtenDato(lLCSiscomPro2,"Cantidad"))*
		    	    atof(SiscomObtenDato(lLCSiscomPro2,"Precio"));
	lchrPtrNumFactura=SiscomObtenDato(lLCSiscomPro2,"NumFactura");
	lchrPtrFechaPago=SiscomObtenDato(lLCSiscomPro2,"FechaPago");
	lchrPtrIdExpendio=SiscomObtenDato(lLCSiscomPro2,"IdExpendio");
	lchrPtrIdProveedor=SiscomObtenDato(lLCSiscomPro2,"IdProveedor");
	}

	 /* { Martes 6 de Septiembre del 2016 
	  * Se integra la transferencia, desde la ventana de compras 
	  * se toma la bodega de Zacatenco por default y el expendio 
	  * de Zacatenco
	  }*/
	SqlUpdateMaterialBodegaDescuentaTransferencia(lLCSiscomPro2,
						      &lLCSiscomPro2Ins,
						      &lLCSiscomPro2InsAct,
						      &lintNRegistros);
	SqlInsertBodegaAExpendioTransferencia(lLCSiscomPro2,
					      lchrArrFechaHora,
					      &lLCSiscomPro2Ins,
				     	      &lLCSiscomPro2InsAct,
				     	      &lintNRegistros);
	SqlUpdateExistenciasTransferencia(lLCSiscomPro2,
					  &lLCSiscomPro2Ins,
				     	  &lLCSiscomPro2InsAct,
				     	  &lintNRegistros);
	   if(lintEsProductoSiscom)
	   {
	   SiscomLog("Se genera la actualizacion para un producto fabricado Siscom");
	   ActualizaProductoFabricadoSiscomCompra(lLCSiscomPro2,
	   					  &lSArgsSiscom,
						  &lLCSiscomPro2Ins,
						  &lLCSiscomPro2InsAct,
						  &lintNRegistros);
	   }

        SiscomContenidoProtocolo(lLCSiscomPro2);

  }
  	if(lchrPtrNumFactura)
	{
	  sprintf(lchrArrActualiza,
	  	  "insert into cuentasPorPagar values('%s','%s',%f,%s,%s,'%s',%s);",
		  lchrPtrNumFactura,
		  lchrPtrFechaPago,
		  lfltImporteCredito,
		  lchrPtrIdExpendio,
		  lchrPtrIdVendedor,
		  lchrArrFechaHora,
		  lchrPtrIdProveedor);
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);

	}
	AgregaActualizaImporteCompra(&lLCSiscomPro2Ins,
				     &lLCSiscomPro2InsAct,
				     &lintNRegistros,
				     lchrArrIdCompra,
				     lfltImporteTotalCompra);
	 
					
        SiscomContenidoProtocolo(lLCSiscomPro2Ins);
	/*Tepotzotlan Mexico a 17 de Octubre del 2015
	 * Se cambia la llamada de la funcion , por 
	 * SiscomInformacionServidorConRespuesta, para evitar 
	 * el Sigpipe en el serdidor de AD
	 */
	SiscomInformacionServidorConRespuesta(lintPtoCom,
	                          lchrArrDirIpExpendio,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD,
				  &lLCSiscomPro2Respuesta,
				  &lintNRegistrosRes);
	if(lchrPtrEdoConexion)
	SiscomLog("Error Al Enviar:%s", lchrPtrEdoConexion);
}
/*
 * En el modulo de compras se debera agregar el control
 * para poder seleccionar la bodega en la que se requiere
 * almacenar el material
 *
 * para efectos, del inicio de este desarrollo se toma 
 * la bodega 0, para el expendio
 *
 * Es importante asi mismo considerar que un expendio podra 
 * tener varias bodegas 
 * Martes  
 * Asi mismo sera necesario asignar un idcompra, para al momento de 
 * registrar la compra se pueda identificar el origen del material ?????
 * 
 *
 */
void SqlMaterialBodega(LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
		       LCamposSiscomPro2 **pLCSiscomPro2DatUlt,
		       int *pintPtrNRegistros)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
	"update materialbodega set existencia=existencia+%s	\n\
	 where idbodega=%s and 					\n\
	      cveproducto='%s'",
	SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdBodega"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatUlt,
			pintPtrNRegistros,
			"ComandoSQL",
			lchrArrSql);
}
/* Martes 6 de Septiembre del 2016
 * Se agrega la cantidad que se transfiere de la bodega al expendio de Zacatenco
 * desde la ventana de compras directo
 * update MaterialBodega set existencia=existencia-2 where idbodega=0 and CveProducto='74LS00'||
 * insert into BodegaAExpendio values(0,-1165857915,'2016-09-07 00:00:03',1173311541,2,'74LS00');||
 *  update existencias set existencia=existencia+2 where cveproducto='74LS00' and idexpendio=-1165857915
 *
 *
 */
int SqlUpdateMaterialBodegaDescuentaTransferencia(
		       LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
		       LCamposSiscomPro2 **pLCSiscomPro2DatUlt,
		       int *pintPtrNRegistros)
{
char lchrArrSql[256];

sprintf(lchrArrSql,
	"update materialbodega set existencia=existencia-%s	\n\
	 where idbodega=%s and 					\n\
	      cveproducto='%s'",
	SiscomObtenDato(pLCSiscomPro2Dat,"CantidadTransfiereZacatenco"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdBodega"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatUlt,
			pintPtrNRegistros,
			"ComandoSQL",
			lchrArrSql);
}

void SqlInsertBodegaAExpendioTransferencia(
		       LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       const char *pchrPtrFecha,
		       LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
		       LCamposSiscomPro2 **pLCSiscomPro2DatUlt,
		       int *pintPtrNRegistros)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into BodegaAExpendio values(0,-1165857915,'%s',1173311541,%s,'%s');",
	pchrPtrFecha,
	SiscomObtenDato(pLCSiscomPro2Dat,"CantidadTransfiereZacatenco"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatUlt,
			pintPtrNRegistros,
			"ComandoSQL",
			lchrArrSql);
}
void SqlUpdateExistenciasTransferencia(
		       LCamposSiscomPro2 *pLCSiscomPro2Dat,
		       LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
		       LCamposSiscomPro2 **pLCSiscomPro2DatUlt,
		       int *pintPtrNRegistros)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"update existencias set existencia=existencia+%s where idexpendio=-1165857915 and cveproducto='%s'",
	SiscomObtenDato(pLCSiscomPro2Dat,"CantidadTransfiereZacatenco"),
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2DatPrim,
			pLCSiscomPro2DatUlt,
			pintPtrNRegistros,
			"ComandoSQL",
			lchrArrSql);

}


void AgregaActualizaImporteCompra(LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
				int *pintPtrNRegistros,
				const char *pchrPtrIdCompra,
				float pfltImporteTotalCompra)

{
char lchrArrSql[256];
sprintf(lchrArrSql,"update RegistroCompra set Importe=%.2f where idCompra=%s;",
	pfltImporteTotalCompra,
	pchrPtrIdCompra);

SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}

void AgregaRegistroRegistroCompra(LCamposSiscomPro2 **pLCSiscomPro2Prim,
				LCamposSiscomPro2 **pLCSiscomPro2Act,
				int *pintPtrNRegistros,
				const char *pchrPtrIdOrigenCompra,
				const char *pchrPtrIdCompra,
				const char *pchrPtrFechaCompra,
				float pfltImporteTotalCompra)
{
char lchrArrSql[256];

sprintf(lchrArrSql,
	"insert into RegistroCompra values(%s,%s,'%s',%.2f);",
	pchrPtrIdCompra,
	pchrPtrIdOrigenCompra,
	pchrPtrFechaCompra,
	pfltImporteTotalCompra);

SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
