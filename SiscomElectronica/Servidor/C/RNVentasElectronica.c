#include <RNVentasElectronica.h>
#include <RNPersonas.h>
#include <RNCotizaDispositivos.h>
#include <ServidorGeneral.h>
#include <ComunElectronica.h>
#include <stdlib.h>
#include <string.h>
#include <SiscomProtocolo2.h>

extern StcSiscomConfiguracion gSSiscomConfiguracionSvr;
StcConsultas gStcCnsVentas[]={ {EsConsultaVentas,FormaConsultaVentas}
			       };
int gintCnsVentas=1;

int EsConsultaVentas(char **pchrPtrEntrada)
{
	return 1;
}
void FormaConsultaVentas(char **pchrPtrEntrada,
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
}
void AnalizaConsultaVentas(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsVentas;
	    lintContador++)
	   if(gStcCnsVentas[lintContador].Consulta(pchrPtrEntrada))
	      gStcCnsVentas[lintContador].FormaConsulta(pchrPtrEntrada,pSOpServidor);
}
void ConsultaVentas(int pintSocket,
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
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	AnalizaConsultaVentas(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);

	close(pintSocket);
}

void AgregaInsercionesCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			   const char *pchrPtrImporteTotal,
			   const char *pchrPtrFecha,
			   LCamposSiscomPro2 **pLCSiscomPro2Ins,
			   LCamposSiscomPro2 **pLCSiscomPro2InsAct,
			   int *pintPtrNRegistros)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into VentasCaja values(%s,%s,%s,%s,%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCaja"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPractica"),
	pchrPtrImporteTotal,
	SiscomObtenDato(pLCSiscomPro2Dat,"Recibi"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Cambio"),
	pchrPtrFecha);
SiscomAnexaRegistroPro2(pLCSiscomPro2Ins,
		       pLCSiscomPro2InsAct,
		       pintPtrNRegistros,
		       "ComandoSQL",
		       lchrArrSql);

}


void AgregaInsercionEscuelaOrden(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			   const char *pchrPtrFecha,
			   LCamposSiscomPro2 **pLCSiscomPro2Ins,
			   LCamposSiscomPro2 **pLCSiscomPro2InsAct,
			   int *pintPtrNRegistros)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into EscuelaOrden values(%s,%s,%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2Dat,"IdPractica"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdEscuela"),
	pchrPtrFecha);
SiscomAnexaRegistroPro2(pLCSiscomPro2Ins,
		       pLCSiscomPro2InsAct,
		       pintPtrNRegistros,
		       "ComandoSQL",
		       lchrArrSql);

}
/*
 * Lunes 1 Agosto 2011 
 * Como parte del manejo de los puntos para clientes siscom
 */
void AgregaActualizacionComprasClientes(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					const char *pchrPtrImporteTotal,
			   		LCamposSiscomPro2 **pLCSiscomPro2Ins,
			   		LCamposSiscomPro2 **pLCSiscomPro2InsAct,
			   		int *pintPtrNRegistros)
{

char lchrArrSql[256];
if(strcmp(SiscomObtenDato(pLCSiscomPro2Dat,"RFC"),"GENERAL"))
{
sprintf(lchrArrSql,
	"update ComprasClientes set total=total+%s \n\
	 where idpersona=%s",
	 pchrPtrImporteTotal,
	SiscomObtenDato(pLCSiscomPro2Dat,"IdCliente"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Ins,
		       pLCSiscomPro2InsAct,
		       pintPtrNRegistros,
		       "ComandoSQL",
		       lchrArrSql);
}


}


/* Domingo 13 De Enero del 2013 
 * Para simplificar el manejo de los datos de la orden (Cliente)
 * al integrar la caja centralizada se agrego la tabla OrdenCliente
 * para almacenar dicha informacion, ya que en la tabla de ventas
 * se tiene la informacion del idcliente, lo cual esta mal.
 */

void AgregaOrdenCliente(const char *pchrPtrIdVenta,
		      const char *pchrPtrIdCliente,
		      LCamposSiscomPro2 **pLCSiscomPro2Prim,
		      LCamposSiscomPro2 **pLCSiscomPro2Act,
		      int *pintPtrNRegistros)
{
char lchrArrSql[128];
sprintf(lchrArrSql,
	"insert into OrdenCliente values(%s,%s);",
	 pchrPtrIdVenta,
	 pchrPtrIdCliente);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL",
			lchrArrSql);
}

/* Martes 18 de Octubre del 2016 Tepotzotlan
 * Se agrego la insercion del importe de la orden ..
 *
 */
void AgregaImporteOrden(const char *pchrPtrIdVenta,
		      const char *pchrPtrImporteOrden,
		      const char *pchrPtrFechaHora,
		      LCamposSiscomPro2 **pLCSiscomPro2Prim,
		      LCamposSiscomPro2 **pLCSiscomPro2Act,
		      int *pintPtrNRegistros)
{
char lchrArrSql[128];
sprintf(lchrArrSql,
	"insert into ImporteOrden values(%s,%s,'%s');",
	 pchrPtrIdVenta,
	 pchrPtrImporteOrden,
	 pchrPtrFechaHora);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL",
			lchrArrSql);
}

void LaOrdenSeModificoEnLaCajaCentral(const char *pchrPtrIdVenta,
				      LCamposSiscomPro2 **pLCSiscomPro2Prim,
				      LCamposSiscomPro2 **pLCSiscomPro2Act,
				      int *pintPtrNRegistros)
{
char lchrArrSql[128];
 SiscomLog("La venta se modifico en la caja central");
sprintf(lchrArrSql,
	"delete from ventas where idventa=%s",
	 pchrPtrIdVenta);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL",
			lchrArrSql);
}
void ActualizaEstadoOrdenCajaCentral(const char *pchrPtrIdVenta,
		      LCamposSiscomPro2 **pLCSiscomPro2Prim,
		      LCamposSiscomPro2 **pLCSiscomPro2Act,
		      int *pintPtrNRegistros)
{
char lchrArrSql[128];
sprintf(lchrArrSql, 
	"update cajacentral set estado=1 where idventa=%s",
	 pchrPtrIdVenta);
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL",
			lchrArrSql);
}
				    
void AgregaOrdenACaja(const char *pchrPtrIdVenta,
		      const char *pchrPtrIdExpendio,
		      const char *pchrPtrIdCaja,
		      const char *pchrPtrImporteTotal,
		      LCamposSiscomPro2 **pLCSiscomPro2Prim,
		      LCamposSiscomPro2 **pLCSiscomPro2Act,
		      int *pintPtrNRegistros)
{
char lchrArrSql[128];
char lchrArrSqlIdCajaCentral[128];
/* Queretaro 13 de agosto 2013 
 * En la revision de la integracion de las ordenes
 * a caja se habia cambiado a la forma de identificar
 * la caja con la direccion ip de la maquina, y no 
 * se integro esta funcionalidad al registro de la
 * orden en la caja, por tal motivo se agrega 
 */
sprintf(lchrArrSqlIdCajaCentral,
	"select idcaja from cajas where direccionip='%s'",
	gchrArrDirIpCliente);
SiscomLog("Agregando la orden %s A la caja centralizada",pchrPtrIdVenta);

sprintf(lchrArrSql,
	"insert into CajaCentral values(%s,%s,(%s),%s,%s);",
	 pchrPtrIdVenta,
	 pchrPtrIdExpendio,
	 lchrArrSqlIdCajaCentral,
	 pchrPtrImporteTotal,
	 "0");
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL",
			lchrArrSql);
}
void AgregaVentasPorTipoProducto(LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 const char *pchrPtrIdVenta,
				 const char *pchrPtrImporte,
				 LCamposSiscomPro2 **pLCSiscomPro2Ins,
				 LCamposSiscomPro2 **pLCSiscomPro2InsAct,
				 int *pintPtrNRegistros)
{
char lchrArrSql[256];
LCamposSiscomPro2Agrupados *lLCSiscomPro2AgTipoProducto;
SiscomAgrupaListaPorCampoPro2("ClaveKit",pLCSiscomPro2Dat,&lLCSiscomPro2AgTipoProducto);
SiscomContenidoAgrupadosPro2(lLCSiscomPro2AgTipoProducto);
for(;
    lLCSiscomPro2AgTipoProducto;
    lLCSiscomPro2AgTipoProducto=lLCSiscomPro2AgTipoProducto->LCSiscomPro2AgrupaS)
{
sprintf(lchrArrSql,
	"insert into VentasPorTipoProducto values(%s,%s,%s,0);",
	pchrPtrIdVenta,
	SiscomObtenDato(lLCSiscomPro2AgTipoProducto->LCSiscomPro2Prim,"IdProductoKit"),
	SiscomObtenDato(lLCSiscomPro2AgTipoProducto->LCSiscomPro2Prim,"CantidadKit"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Ins,
			pLCSiscomPro2InsAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
sprintf(lchrArrSql,
	"update existencias set existencia=existencia-%s where cveproducto='%s' and idexpendio=%s;",
	SiscomObtenDato(lLCSiscomPro2AgTipoProducto->LCSiscomPro2Prim,"CantidadKit"),
	SiscomObtenDato(lLCSiscomPro2AgTipoProducto->LCSiscomPro2Prim,"ClaveKit"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Ins,
			pLCSiscomPro2InsAct,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");

}
}

void RegistrandoVentas(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
char lchrArrFechaHora[52],
	lchrArrCantidad[12];
const char *lchrPtrIdVendedor;
int lintNRegistros=0,
    lintSocketAD;
int lintIdVenta=SiscomObtenNumeroUnico();
int lintPtoComAD;
char lchrArrDirIpAD[35];
int lintNRegRespuesta;

const char *lchrPtrIdVenta;
const char *lchrPtrEdoVenta;
const char *lchrPtrOrdenACaja;
const char *lchrPtrIdExpendio;
const char *lchrPtrIdCaja;
char lchrArrImporteTotal[20];
SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);

SiscomLog("------------------- RegistraVentas --------------");
SiscomContenidoProtocoloVertical(lLCSiscomPro2);
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
	EliminaTotalOrden2(lLCSiscomPro2,lchrArrImporteTotal);
	lchrPtrIdVendedor= SiscomObtenDato(lLCSiscomPro2,"IdUnidad"); 
	lchrPtrIdVenta=SiscomObtenDato(lLCSiscomPro2,"IdPractica");
	lchrPtrIdCaja=SiscomObtenDato(lLCSiscomPro2,"IdCaja");
	SiscomContenidoProtocolo(lLCSiscomPro2);
	/* Sabado 12 de enero del 2013
	 */  
	lchrPtrIdExpendio=SiscomObtenDato(lLCSiscomPro2,"IdExpendio");
	ElectronicaComunicacionExpendio2(
		SiscomObtenDato(lLCSiscomPro2,"IdExpendio"),
		&lintPtoComAD,
		lchrArrDirIpAD,
		0);
/*
 * 2007-06-06 
 * Siguiendo con las modificaciones, del codigo para el 
 * manejo de la facturacion, registro de cotizaciones, etc.
 *
 * Se anexo a la tabla venta un campo, edoVenta, el cual 
 * puede tomar los siguientes valores:
 *
 * 0 Venta
 * 1 Cotizacion
 * Tepotzotlan 3 de Enero del 2013
 * 3 Orden A Caja Centralizada
 *
 * Ademas, en el campo Proveedor se copio enviara el valor 
 * del campo edoVenta, esto para no agregar un campo mas.
 *
 * El campo se coloco solo en el primer producto.
 *
 * Modificacion 2
 *
 */

/* Queretaro 12 Julio 2007
 * En la fase de pruebas de este modulo se identico 
 * la siguiente problematica:
 * Al registrar una cotizacion, tambien se realiza la 
 * actualizacion en la tabla de existencias, para lo que
 * se agrega la validacion del campo Proveedor, que es
 * donde se pasa el valor de edoVenta, para ver si trae
 * el valor de 1 entonces corresponde a una cotizacion
 * para lo que no se anexara la cadena de actualizacion
 * de la tabla de existencias
 */
	lchrPtrEdoVenta=SiscomObtenDato(lLCSiscomPro2,"Proveedor");
/* Tepotzotlan 3 de Enero del 2012
 * Se agrega la integracion con la caja centralizada
 */
       lchrPtrOrdenACaja=SiscomObtenDato(lLCSiscomPro2,"OrdenACaja");
       SiscomLog("La Orden a Caja:%s",lchrPtrOrdenACaja);
/*
 * Tepotzotlan 18 Septiembre del 2009
 *
 * La siguiente funcion se agrega para generar las sentencias
 * Sql, del proceso de insercion de la informacion de Cajas
 */

  if(!strcmp(lchrPtrOrdenACaja,"0") &&
     !strcmp(lchrPtrEdoVenta,"0")) 
  AgregaInsercionesCaja(lLCSiscomPro2,
  			lchrArrImporteTotal,
			lchrArrFechaHora,
  			&lLCSiscomPro2Ins,
			&lLCSiscomPro2InsAct,
			&lintNRegistros);

/*
 * Queretaro 24 Agosto 2010
 * Con la paniqueada del negocio que sera nuestra competencia
 * apartir de estos dias, se procedio a llevar el control de
 * los clientes que nos visitan y de que escuela
 */

  if(!strcmp(lchrPtrOrdenACaja,"0") &&
     !strcmp(lchrPtrEdoVenta,"0"))
AgregaInsercionEscuelaOrden(lLCSiscomPro2,
			    lchrArrFechaHora,
			    &lLCSiscomPro2Ins,
			    &lLCSiscomPro2InsAct,
			    &lintNRegistros);
/* Martes 18 Octubre 2016 se agrego el importe de la orden
 * 
 */

  if(!strcmp(lchrPtrOrdenACaja,"0") &&
     !strcmp(lchrPtrEdoVenta,"0"))
AgregaImporteOrden(lchrPtrIdVenta,
		   lchrArrImporteTotal,
		   lchrArrFechaHora,
		   &lLCSiscomPro2Ins,
		   &lLCSiscomPro2InsAct,
		   &lintNRegistros);
/*
 * Tepotzotlan 1 De Agosto del 2011 
 * Se agrego como parte del manejo de puntos
 * siscom, la insercion a la tabla que lleva 
 * el total de compras por un cliente 
 */
  if(!strcmp(lchrPtrOrdenACaja,"0") &&
     !strcmp(lchrPtrEdoVenta,"0"))
  AgregaActualizacionComprasClientes(lLCSiscomPro2,
  			lchrArrImporteTotal,
  			&lLCSiscomPro2Ins,
			&lLCSiscomPro2InsAct,
			&lintNRegistros);
/* Queretaro a 19 de Noviembre del 2015 
 * Se Agrega el manejo de los productos por tipo de producto
 * para esta caso es en la venta 
 * OJOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo
 * Hay que revisar, el caso de cuando se realice una
 * cotizacion y esta se almacene
 */
  if(!strcmp(lchrPtrOrdenACaja,"0") &&
     !strcmp(lchrPtrEdoVenta,"0"))
  AgregaVentasPorTipoProducto(
  			lLCSiscomPro2,
			lchrPtrIdVenta,
  			lchrArrImporteTotal,
  			&lLCSiscomPro2Ins,
			&lLCSiscomPro2InsAct,
			&lintNRegistros);

/*
 * Tepotzotlan 3 Enero del 2013
 * Se agrego la integracion de la caja 
 */


 if(!strcmp(lchrPtrOrdenACaja,"1"))
 {
 AgregaOrdenACaja(lchrPtrIdVenta,
 		  lchrPtrIdExpendio,
		  lchrPtrIdCaja,
 		  lchrArrImporteTotal,
  		  &lLCSiscomPro2Ins,
		  &lLCSiscomPro2InsAct,
		  &lintNRegistros);
AgregaInsercionEscuelaOrden(lLCSiscomPro2,
			    lchrArrFechaHora,
			    &lLCSiscomPro2Ins,
			    &lLCSiscomPro2InsAct,
			    &lintNRegistros);
AgregaOrdenCliente(lchrPtrIdVenta,
		  SiscomObtenDato(lLCSiscomPro2,"IdCliente"),
		  &lLCSiscomPro2Ins,
		  &lLCSiscomPro2InsAct,
		  &lintNRegistros);
 }
/* Viernes 18 Enero del 2013 
 * Si la orden se modifico de la caja se envia 
 * en el estado de la venta 4, con lo que se 
 * deberan eliminar los registros de la tabla 
 * ventas para volverse a insertar con los  
 * nuevos valores 
 */
if(!strcmp(lchrPtrEdoVenta,"4"))
{
LaOrdenSeModificoEnLaCajaCentral(lchrPtrIdVenta,
				 &lLCSiscomPro2Ins,
				 &lLCSiscomPro2InsAct,
				 &lintNRegistros);
ActualizaEstadoOrdenCajaCentral(lchrPtrIdVenta,
				 &lLCSiscomPro2Ins,
				 &lLCSiscomPro2InsAct,
				 &lintNRegistros);

AgregaInsercionesCaja(lLCSiscomPro2,
  		      lchrArrImporteTotal,
		      lchrArrFechaHora,
  		      &lLCSiscomPro2Ins,
		      &lLCSiscomPro2InsAct,
		      &lintNRegistros);
lchrPtrEdoVenta="0";
}
  for(;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
  {
  	sprintf(lchrArrCantidad,
		"%f",
		atof(SiscomObtenDato(lLCSiscomPro2,"NumJuegos"))*	
		atof(SiscomObtenDato(lLCSiscomPro2,"Cantidad")));
	/*
	 * 2007-06-06 
	 * Para la integracion del proceso de facturacion se
	 * cambio, la generacion del IdVenta, ahora la interfaz
	 * solicita este identificador, y lo pasa al modulo de 
	 * ventas, con lo que este dato se envia de la interfaz
	 * y no se requiere que se genere en este punto
	 */
	 /* Tepotzotlan  a 21 de Noviembre del 2015 
	  * Se agrega la insercion del IdProducto de tipo de producto
	  */
	 if(!SiscomComparaCampoChar("EsKit","Si",lLCSiscomPro2))
	 sprintf(lchrArrActualiza,
	 	 "insert into ventas values(%s,%s,'%s','%s',%s,%s,%s,%s,%s,%s,%s);",
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"),
		 lchrPtrIdVenta,
		 lchrArrFechaHora,
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		 /*
		  * Error reportado el dia 2-02-2007 
		  * cuando el usuario selecciona en la 
		  * interfaz el numero de juegos, no se 
		  * considera para la actualizacion de 
		  * la base de datos, por lo que siempre
		  * se tomaba lo de un juego.
		  *
		 SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		 */
		 lchrArrCantidad,
		 SiscomObtenDato(lLCSiscomPro2,"Importe"),
		 SiscomObtenDato(lLCSiscomPro2,"Precio"),
		 lchrPtrIdVendedor,
		 SiscomObtenDato(lLCSiscomPro2,"IdCliente"),
		 /* Modificacion 2
		  *
		  *
		  */
		 lchrPtrEdoVenta,
		 /* Tepotzotlan Mexico 21 De Noviembre del 2015 
		  * Se agrega la insercion por Tipo Producto
		  */
		 SiscomObtenDato(lLCSiscomPro2,"IdProductoKit"));
	   else
	 sprintf(lchrArrActualiza,
	 	 "insert into ventas values(%s,%s,'%s','%s',%s,%s,%s,%s,%s,%s);",
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"),
		 lchrPtrIdVenta,
		 lchrArrFechaHora,
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		 /*
		  * Error reportado el dia 2-02-2007 
		  * cuando el usuario selecciona en la 
		  * interfaz el numero de juegos, no se 
		  * considera para la actualizacion de 
		  * la base de datos, por lo que siempre
		  * se tomaba lo de un juego.
		  *
		 SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		 */
		 lchrArrCantidad,
		 SiscomObtenDato(lLCSiscomPro2,"Importe"),
		 SiscomObtenDato(lLCSiscomPro2,"Precio"),
		 lchrPtrIdVendedor,
		 SiscomObtenDato(lLCSiscomPro2,"IdCliente"),
		 /* Modificacion 2
		  *
		  *
		  */
		 lchrPtrEdoVenta
		 /* Tepotzotlan Mexico 21 De Noviembre del 2015 
		  * Se agrega la insercion por Tipo Producto
		  * En esta condicion el producto no es parte de un kit
		  */);

	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	/* Queretaro 12 De Julio 2007
	 *
	 * Validacion requerida para no actualizar el
	 * la tabla de existencias en caso de que se
	 * haya seleccionado registrar una cotizacion
	 * Si el campo EdoVenta trae el valor de cero
	 * entonces es una venta
	 */
	/* Queretaro 20 de Agosto del 2013 
	 * REVISAR porque no esta llegando el campo 
	 * de orden a caja, esto origino en esta 
	 * condicion que no generara las actualizaciones
	 * de la base de datos  para el inventario
	 * por la forma en la que se puso la condicion
	 * Este problema se da debido a que llega en el 
	 * campo "No se encontro campo"
	 * REVISARRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
	 */
	if(!strcmp(lchrPtrOrdenACaja,"0")&&
	   !strcmp(lchrPtrEdoVenta,"0"))
	{
	sprintf(lchrArrActualiza,
		"update existencias set Existencia=Existencia-%s \
		 where CveProducto='%s' and			 \
		       idExpendio=%s",
		 /*
		  * Problema de la actualizacion y el numero de juegos
		  * SiscomObtenDato(lLCSiscomPro2,"Cantidad"),
		  */
		 lchrArrCantidad,
		 SiscomObtenDato(lLCSiscomPro2,"CveProducto"),
		 SiscomObtenDato(lLCSiscomPro2,"IdExpendio"));
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
	}

  }
  SiscomContenidoProtocolo(lLCSiscomPro2Ins);
	SiscomInformacionServidor(lintPtoComAD,
	                          lchrArrDirIpAD,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomLog("Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
	
/*
 * Tepotzotlan
 * Domingo 18 De Septiembre 2011 
 * Al momento de enviar la informacion 
 * al servidor de Acceso a datos, este 
 * intenta regresar la respuesta al no 
 * haber considerado la rutina para recibir
 * la informacion, se envia un SIGPIPE
 * por lo cual se procede a integrar la rutina 
 * para leer el regreso de informacion
 * del servidor
 */
SiscomLeeInformacionRespuesta(lintSocketAD,
			      &lintNRegRespuesta,
			      &lLCSiscomPro2Reg);
SiscomContenidoProtocolo(lLCSiscomPro2Reg);
}

void RegistraVentas(int pintSocket,
			int pintNRegistros)
{
  SiscomLog("----------------------------------------------------------------");
   	RegistrandoVentas(pintSocket,pintNRegistros); 
  SiscomLog("----------------------------------------------------------------");
}
