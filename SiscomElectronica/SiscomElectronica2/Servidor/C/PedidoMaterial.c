#include <PedidoMaterial.h>
#include <SqlPedidoMaterial.h>
#include <ComunElectronica2.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
#include <string.h>
#include <cups/cups.h>

SiscomOperaciones2 *OpRecibePedidoMaterial()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*10);
memset(lSOpOperaciones,0,sizeof(SiscomOperaciones2)*10); 
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosRecibePedido,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(DatosRecibePedidoEstadoPedido,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(SqlRegistraRecibePedido,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(SqlActualizaExistenciasPorEntregaPedido,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(SqlRegistraEstadosPedidoRecibioEnExpendio,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(RegistraRecibePedido,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OpRegistraPedidoMaterial()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*12);
memset(lSOpOperaciones,0,sizeof(SiscomOperaciones2 )*11);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendio3,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosPedidoMaterial,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(GeneraIdPedidoMaterial,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlRegistraPedidoMaterial,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlRegistraDetallePedidoMaterial,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlRegistraEstadosPedidoMaterial,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlRegistraUltimoEstadoPedido,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(RegistraPedidoMaterialExpendio,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraPedidoMaterialMatriz,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OpPedidosExpendios()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*7);
memset(lSOpOperaciones,0,sizeof(SiscomOperaciones2)*7); 
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOpSubRegistros,lSOpOperaciones);
<<<<<<< HEAD
SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones);   
=======
/*SiscomAnexaOperacionAlArreglo2(SiscomComunicacionMatriz,lSOpOperaciones);    */
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
>>>>>>> f3a89418aee067f7aaa90b83aeeb94e34411ca0a
SiscomAnexaOperacionAlArreglo2(ArgumentosPedidosExpendios,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlPedidosExpendios,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlDetallePedidoExpendio,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(EnviaPedidosExpendios,lSOpOperaciones); 
return lSOpOperaciones;
}

SiscomOperaciones2 *OpActualizaEstadoPedido()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosActualizaEstado,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlActualizaEstadoPedido,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(EnviaActualizaEstadoPedido,lSOpOperaciones); 
return lSOpOperaciones;
}

SiscomOperaciones2 *OpActualizaCantidadProductoPedido()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosActualizaEstado,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlActualizaCantidadProductoPedido,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(EnviaActualizaCantidadProductoPedido,lSOpOperaciones); 
return lSOpOperaciones;
}

SiscomOperaciones2 *OpImprimePedido()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*200);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosImprimePedido,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlImprimePedido,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ImprimePedido,lSOpOperaciones); 
return lSOpOperaciones;
}

SiscomOperaciones2 *OpValidaExistenciaExpendio()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*7);
memset(lSOpOperaciones,0,sizeof(SiscomOperaciones2)*7);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosPedidoMaterial,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(SqlExistenciaExpendio,lSOpOperaciones); 
SiscomAnexaOperacionAlArreglo2(ValidaExistenciaExpendio,lSOpOperaciones); 
return lSOpOperaciones;
}
SiscomOperaciones2 *OpPedidosPendientesPorEnviarAMatriz()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*7);
memset(lSOpOperaciones,0,sizeof(SiscomOperaciones2)*7);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(SqlPedidosPendientesPorEnviarAMatriz,lSOpOperaciones); 
return lSOpOperaciones;
}

void ArgumentosRecibePedido(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlRecibePedido",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"Operacion",pSAgsSiscom);
}
SiscomOperaciones2 *OpDetallePedidoPendientePorEnviarAMatriz()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*7);
memset(lSOpOperaciones,0,sizeof(SiscomOperaciones2)*7);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(SqlDetallePedidoPendientePorEnviarAMatriz,lSOpOperaciones); 
return lSOpOperaciones;
}


SiscomOperaciones2 *OpEnviaPedidoPendientePorEnviarAMatriz()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*7);
memset(lSOpOperaciones,0,sizeof(SiscomOperaciones2)*7);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(ArgumentosPedidosPendientes,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(SqlDetallePedidoPendientePorEnviarAMatriz2,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(FormaInsercionesPedidoPendientePorEnviarAMatriz,lSOpOperaciones);   
SiscomAnexaOperacionAlArreglo2(RegistraPedidoPendienteMatriz,lSOpOperaciones);   
return lSOpOperaciones;
}


void ArgumentosPedidoMaterial(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlPedidoMaterial",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"Operacion",pSAgsSiscom);
}
void ArgumentosPedidosPendientes(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(4,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlPedidosPendientes",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlDetallePedidoPendiente",pSAgsSiscom);
}

void ArgumentosPedidosExpendios(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(3,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlPedidosExpendios",pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(1,"SqlDetallePedidoExpendio",pSAgsSiscom);
}
void ArgumentosImprimePedido(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlImprimePedido",pSAgsSiscom);
}

void ArgumentosActualizaEstado(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlActualizaEstado",pSAgsSiscom);
}

void EnviaPedidosExpendios(SArgsSiscom *pSAgsSiscom)
{
int lintContador=0;
LCamposSiscomPro2 *lLCSiscomPro2Pedidos,
		  *lLCSiscomPro2Detalle,
		  *lLCSiscomPro2PedidosRegPrim=0,
		  *lLCSiscomPro2PedidosRegAct=0;
lLCSiscomPro2Pedidos=SiscomArgumentoOperacionPrim("SqlPedidosExpendios",pSAgsSiscom);
lLCSiscomPro2Detalle=SiscomArgumentoOperacionPrim("SqlDetallePedidoExpendio",pSAgsSiscom);
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
for(; 
    lLCSiscomPro2Pedidos;
    lLCSiscomPro2Pedidos=lLCSiscomPro2Pedidos->SCP2PtrSig,
    lintContador++)
{
SiscomCreaListaCamposPro2(lLCSiscomPro2Pedidos->SCSiscomPro2,
			  &lLCSiscomPro2PedidosRegPrim,
			  &lLCSiscomPro2PedidosRegAct);
for(lLCSiscomPro2Detalle=SiscomArgumentoOperacionPrim("SqlDetallePedidoExpendio",pSAgsSiscom); 
     lLCSiscomPro2Detalle;
     lLCSiscomPro2Detalle=lLCSiscomPro2Detalle->SCP2PtrSig)
{
    if(!SiscomComparaCampo(lLCSiscomPro2Pedidos,lLCSiscomPro2Detalle,"idpedido"))
    {
	lintContador++;
	SiscomCreaListaCamposPro2(lLCSiscomPro2Detalle->SCSiscomPro2,
			  	  &lLCSiscomPro2PedidosRegPrim,
			  	  &lLCSiscomPro2PedidosRegAct);
    }
}
}
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      lintContador,
		      "Respuesta",
		      lLCSiscomPro2PedidosRegPrim);
SiscomLog("Se envio todo");
}
void RegistraPedidoMaterialExpendio(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaArgumentoParaRegistro("SqlPedidoMaterial",pSAgsSiscom);
}

void EnviaActualizaEstadoPedido(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlActualizaEstado",pSAgsSiscom);
SiscomEnviaArgumentoParaRegistro("SqlActualizaEstado",pSAgsSiscom);
}
void EnviaActualizaCantidadProductoPedido(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("---------------------------------------------------");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlActualizaEstado",pSAgsSiscom);
SiscomEnviaArgumentoParaRegistro("SqlActualizaEstado",pSAgsSiscom);
}


void ActualizaEstadoPedido(const char *pchrPtrIdEstado,
			   SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256],
	lchrArrSqlUltimoEstado[256];
char lchrArrFechaHoy[26];
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"insert into EstadosPedidoMaterial values(%s,%s,'%s');",
	pchrPtrIdEstado,
	SiscomObtenCampoArgumento("Operacion","IdPedidoMaterial",pSAgsSiscom),
	lchrArrFechaHoy);
sprintf(lchrArrSqlUltimoEstado,
	"update ultimoestadopedido set idestado=%s where idpedido=%s;",
	pchrPtrIdEstado,
	SiscomObtenCampoArgumento("Operacion","IdPedidoMaterial",pSAgsSiscom));
SiscomCadenaInsercionSql(pSAgsSiscom,"%s%s",lchrArrSql,lchrArrSqlUltimoEstado);
}
void RegistraElPedidoRecibidoEnExpendio(SArgsSiscom *pSAgsSiscom)
{


}


void RegistraPedidoMaterialMatriz(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdMatriz[20];
SiscomDatosComunicacionMatriz2(0,0,0,lchrArrIdMatriz);
SiscomImprimeArgumento("SqlPedidoMaterial",pSAgsSiscom); 
if(!SqlEnviaSentenciasArgumento(lchrArrIdMatriz,"SqlPedidoMaterial",pSAgsSiscom))
{
  SiscomLog("Se Registro el pedido");
  ActualizaEstadoPedido("1",pSAgsSiscom);
 EnviaEstadoConexionALaMatriz("1","Registro Exitoso del Pedido",pSAgsSiscom);
}
else
{
 SiscomLog("Error la enviar");
  ActualizaEstadoPedido("4",pSAgsSiscom); 
 EnviaEstadoConexionALaMatriz("0","Conexion No Disponible a la matriz\nSe Coloca el pedido como pendiente\npor enviar ....",pSAgsSiscom);
}
}
void DatosRecibePedidoEstadoPedido(SArgsSiscom *pSAgsSiscom)
{
char lchrArrFechaHoy[26];
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
  SiscomAnexaRegistroArgumento(
  	"Operacion",
  	pSAgsSiscom,
	"IdPedidoMaterial,Fecha,EstadoPedido",
	SiscomCampoRegistroPrincipal(pSAgsSiscom->LCSiscomPro2SREntrada,"IdPedido"),
	lchrArrFechaHoy,
	"4");
/* Sabado 14 de noviembre se actualiza como Recibido en expendio */

}
void RegistraPedidoPendienteMatriz(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdMatriz[20];
SiscomLog("---- ");
SiscomDatosComunicacionMatriz2(0,0,0,lchrArrIdMatriz);
SiscomImprimeArgumento("SqlDetallePedidoPendiente",pSAgsSiscom); 
if(!SqlEnviaSentenciasArgumento(lchrArrIdMatriz,"SqlDetallePedidoPendiente",pSAgsSiscom))
{
  SiscomLog("Se Registro el pedido");
  ActualizaEstadoPedido("1",pSAgsSiscom);
 EnviaEstadoConexionALaMatriz("1","Registro Exitoso del Pedido",pSAgsSiscom);
}
else
{
 SiscomLog("Error la enviar");
 EnviaEstadoConexionALaMatriz("0","Conexion No Disponible a la matriz\nSe Coloca el pedido como pendiente\npor enviar ....",pSAgsSiscom);
}

}
void EnviaEstadoConexionALaMatriz(const char *pchrPtrEstado,
				  const char *pchrPtrMensaje,
				 SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2PrimReg=0,
		  *lLCSiscomPro2ActReg=0;
int lintNRegRegreso=0;

SiscomAnexaRegistroPro2(&lLCSiscomPro2PrimReg,
			&lLCSiscomPro2ActReg,
			&lintNRegRegreso,
			"EstadoRegistro,Mensaje",
			pchrPtrEstado,
			pchrPtrMensaje);
SiscomEnviaAlServidor(pSAgsSiscom->intSocketCliente,
		      lintNRegRegreso,
		      "NoHayConexionMatriz",
		      lLCSiscomPro2PrimReg);
}
void GeneraIdPedidoMaterial(SArgsSiscom *pSAgsSiscom)
{
char lchrArrIdPedidoMaterial[26],
     lchrArrFechaHoy[26];
  SiscomObtenNumeroUnicoChar(lchrArrIdPedidoMaterial);
  SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
  SiscomAnexaRegistroArgumento("Operacion",
  				pSAgsSiscom,
				"IdPedidoMaterial,Fecha,EstadoPedido",
				lchrArrIdPedidoMaterial,
				lchrArrFechaHoy,
				"0");
}
void ImprimePedido(SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrImpresion;
int lintTamBuffer;
SiscomLog("");
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlImprimePedido",pSAgsSiscom);  
lchrPtrImpresion=TextoImpresionPedido(pSAgsSiscom,&lintTamBuffer); 
SiscomLog("%s %dBytes",lchrPtrImpresion,strlen(lchrPtrImpresion));
EjecutaComandoImpresionPedido(SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPedido"),
			      lchrPtrImpresion,
			      lintTamBuffer);
SiscomLog("%s",lchrPtrImpresion);
}

void EncabezadoImprimePedido(SArgsSiscom *pSAgsSiscom,
		char *pchrPtrTexto)
{
char lchrArrFecha[28];
int lintHora,
	lintMinuto,
	lintSegundo;

SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomObtenHoraActual(&lintHora,&lintMinuto,&lintSegundo);
SiscomPonPrimerRegistroArgumento("SqlImprimePedido",pSAgsSiscom);
sprintf(pchrPtrTexto,
	"\n"
	"SISCOM Electronica\n"
	"A.v. I.P.N. #2085\n"
	"Colonia San Pedro Zacatenco\n"
	"Delegacion Gustavo A. Madero\n"
	"Mexico D.F.\n"
	"Telefono:57540823\n"
	"Fecha %s Hora %02d:%02d:%02d\n"
	"No De Pedido %s\n"
	"Expendio:%s\n"
	"%-26s"	/*Clave Producto */
	"%-5s" /* Cantidad */
	"%-5s" /*Existencia*/
	"%-6s" /*Bodega*/
	"%-4s" /* Estante */
	"%-3s\n", /* Caja*/
	lchrArrFecha,
	lintHora,
	lintMinuto,
	lintSegundo,
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPedido"),
	SiscomObtenCampoArgumento("SqlImprimePedido","razonsocial",pSAgsSiscom),
	"Producto",
	"Can",
	"Ex",
	"Bod",
	"E",
	"C",
	"",
	"");
}

void ArchivoTemporalImprimePedido(const char *pchrPtrNoOrden,
		     const char *pchrPtrTexto,
		     char *pchrPtrArchivo)
{
FILE *lptrFleTemporal;
sprintf(pchrPtrArchivo,
	"%s/ImpresionPedidos/Impresion.SiscomElectronica.%s",
	gSSiscomConfiguracionSvr.chrPtrDirTrabajo,
	pchrPtrNoOrden);
if((lptrFleTemporal=fopen(pchrPtrArchivo,"w")))
{
fprintf(lptrFleTemporal,"%s",pchrPtrTexto);
fclose(lptrFleTemporal);
}
else
SiscomLog("No se pudo crear el archivo:%s",pchrPtrArchivo);

}

int TamanoBufferImpresionPedido(SArgsSiscom *pSAgsSiscom)
{
/*
 * Cade cantidad representa el numero 
 * de bytes que se asignaran a cada campo
 *
 */
int lintTamRegistro=5	+ /* Cantidad */
  		    5	+ /*Importe   */
		    5	+ /*Num Juegos*/
		    50	+ /*CveProducto*/
		    5	+ /*Precio*/
		    4	+ /*Cliente Frecuente*/
		    5	+ /*No Orden*/
		    20	 /*Nombre Cliente*/ 
		    ;
SiscomLog("(%d) (%d)",
	  lintTamRegistro,
	  SiscomArgumentosNumeroRegistros("SqlImprimePedido",pSAgsSiscom));
return (lintTamRegistro*SiscomArgumentosNumeroRegistros("SqlImprimePedido",pSAgsSiscom))+
	256; /* Domingo 31 De Julio 
	      * Se agrego espacio para la leyenda de puntos 
	      * Siscom Electronica
	      */
}
void FormatoSoloEntero(const char *pchrPtrCadena,
		      char *pchrPtrCadenaS)
{
float lfltNumero=atof(pchrPtrCadena);
sprintf(pchrPtrCadenaS,"%d",(int )lfltNumero);
}
void FormaRegistroImpresionPedido(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    char *pchrPtrRegistro)
{
char lchrArrCantidad[10],
	lchrArrExistencia[10],
	lchrArrBodega[10];

/*SiscomContenidoProtocolo(pLCSiscomPro2Dat); */


FormatoSoloEntero(SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"),lchrArrCantidad);
FormatoSoloEntero(SiscomObtenDato(pLCSiscomPro2Dat,"existencia"),lchrArrExistencia);
FormatoSoloEntero(SiscomObtenDato(pLCSiscomPro2Dat,"exbodegas"),lchrArrBodega);
		

sprintf(pchrPtrRegistro,
	"%-26s%-5s%-5s%-6s%-4s%-3s\n",
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	lchrArrCantidad,
	lchrArrExistencia,
	lchrArrBodega,
	SiscomObtenDato(pLCSiscomPro2Dat,"estante"),
	SiscomObtenDato(pLCSiscomPro2Dat,"caja"));
}
void RegistrosImpresionPedido(SArgsSiscom *pSAgsSiscom,	
			char *pchrPtrTexto)
{
char lchrArrRegistro[256];
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("SqlImprimePedido",pSAgsSiscom);
while(lLCSiscomPro2Dat)
{
  FormaRegistroImpresionPedido(lLCSiscomPro2Dat,lchrArrRegistro);
  strcat(pchrPtrTexto,lchrArrRegistro);
  lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
}
}
char *TextoImpresionPedido(SArgsSiscom *pSAgsSiscom,
		     int *pintPtrTamBuffer)
{
*pintPtrTamBuffer=TamanoBufferImpresionPedido(pSAgsSiscom)+512;
char *lchrPtrImpresion;
lchrPtrImpresion=(char *)malloc(*pintPtrTamBuffer);
EncabezadoImprimePedido(pSAgsSiscom,lchrPtrImpresion);
RegistrosImpresionPedido(pSAgsSiscom,lchrPtrImpresion);
strcat(lchrPtrImpresion,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
return lchrPtrImpresion;
}


void EjecutaComandoImpresionPedido(const char *pchrPtrNoOrden,
			     const char *pchrPtrTexto,
			     int pintTamBuffer)
{
char lchrArrArchivo[256];
char lchrCaracter;
int lintNumDests;;
cups_dest_t *lcupsPtrDestinos,*lcupsPtrDefault;
lintNumDests=cupsGetDests(&lcupsPtrDestinos);
if((lcupsPtrDefault=cupsGetDest(0,0,lintNumDests,lcupsPtrDestinos))) 
{
ArchivoTemporalImprimePedido(pchrPtrNoOrden,pchrPtrTexto,lchrArrArchivo);
cupsPrintFile(lcupsPtrDefault->name,
	      lchrArrArchivo,
		lchrArrArchivo,
		lcupsPtrDefault->num_options,
		lcupsPtrDefault->options);
}
else
SiscomLog("No se ha configurado la impresora por default");
}

void ValidaExistenciaExpendio(SArgsSiscom *pSAgsSiscom)
{
float lfltExTotalEB;
SiscomImprimeArgumento("SqlPedidoMaterial",pSAgsSiscom);
SiscomPonPrimerRegistroArgumento("SqlPedidoMaterial",pSAgsSiscom);
SiscomLog("La Cantidad A Actualizar (%f)  Existencia Disponible (%f)",
	 SiscomCampoDatosEntradaFloat("Cantidad",pSAgsSiscom),
	 SiscomObtenCampoArgumentoFloat("SqlPedidoMaterial","existencia",pSAgsSiscom));

lfltExTotalEB=SiscomObtenCampoArgumentoFloat("SqlPedidoMaterial","existencia",pSAgsSiscom)+
	      SiscomObtenCampoArgumentoFloat("SqlPedidoMaterial","exbodegas",pSAgsSiscom);
if(!SiscomCampoDatosEntradaFloat("Cantidad",pSAgsSiscom))
  SiscomAnexaRegistroRegreso(pSAgsSiscom,
  			     "EdoValidacion,Mensaje",
			     "1",
			     "Cantidad valida");

else
if(lfltExTotalEB < SiscomCampoDatosEntradaFloat("Cantidad",pSAgsSiscom))
{
  SiscomAnexaRegistroRegreso(pSAgsSiscom,
  			     "EdoValidacion,Mensaje",
			     "0",
			     "Cantidad Invalida");
}
else
{
  SiscomAnexaRegistroRegreso(pSAgsSiscom,
  			     "EdoValidacion,Mensaje",
			     "1",
			     "Cantidad valida");
 }
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Regreso);
SiscomEnviaRegreso(pSAgsSiscom);
}

void RegistraRecibePedido(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoSubRegistrosLog(pSAgsSiscom->LCSiscomPro2SREntrada);
SiscomImprimeArgumento("SqlRecibePedido",pSAgsSiscom);
}

void FormaInsercionesPedidoPendientePorEnviarAMatriz(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prods;
char lchrArrSql[1024],
	lchrArrFechaHoy[56];
lLCSiscomPro2Prods=SiscomArgumentoOperacionPrim("SqlPedidosPendientes",pSAgsSiscom);
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
sprintf(lchrArrSql,
	"insert into PedidosMaterial values(%s,'%s','%s',%s);",
	SiscomCampoDatosEntrada("idpedido",pSAgsSiscom),
	lchrArrFechaHoy,
	SiscomCampoDatosEntrada("observaciones",pSAgsSiscom),
	SiscomCampoDatosEntrada("idexpendio",pSAgsSiscom));
 SiscomAnexaRegistroArgumento("SqlDetallePedidoPendiente",
 				pSAgsSiscom,
				"ComandoSQL,EdoRegistro",
				lchrArrSql,
				"");
SiscomLog("%s",lchrArrSql);

SiscomContenidoProtocolo(lLCSiscomPro2Prods);
for( ;
     lLCSiscomPro2Prods;
     lLCSiscomPro2Prods=lLCSiscomPro2Prods->SCP2PtrSig)
{
 SiscomLog("%s",SiscomObtenDato(lLCSiscomPro2Prods,"cveproducto")); 
 sprintf(lchrArrSql,
 	"insert into DetallePedidoMaterial values(%s,'%s','%s','%s');",
	 SiscomObtenDato(lLCSiscomPro2Prods,"idpedido"),
	 SiscomObtenDato(lLCSiscomPro2Prods,"cantidad"),
	 SiscomObtenDato(lLCSiscomPro2Prods,"cveproducto"),
	 SiscomObtenDato(lLCSiscomPro2Prods,"observacion"));
 SiscomAnexaRegistroArgumento("SqlDetallePedidoPendiente",
 				pSAgsSiscom,
				"ComandoSQL,EdoRegistro",
				lchrArrSql,
				"");
}
sprintf(lchrArrSql,
	"insert into EstadosPedidoMaterial values(%s,%s,'%s');",
	"0",
	SiscomCampoDatosEntrada("idpedido",pSAgsSiscom),
	lchrArrFechaHoy);
 SiscomAnexaRegistroArgumento("SqlDetallePedidoPendiente",
 				pSAgsSiscom,
				"ComandoSQL,EdoRegistro",
				lchrArrSql,
				"");
sprintf(lchrArrSql,
	"insert into UltimoEstadoPedido values(%s,%s);",
	SiscomCampoDatosEntrada("idpedido",pSAgsSiscom),
	"0");
 SiscomAnexaRegistroArgumento("SqlDetallePedidoPendiente",
 				pSAgsSiscom,
				"ComandoSQL,EdoRegistro",
				lchrArrSql,
				"");

SiscomPonPrimerRegistroArgumento("SqlDetallePedidoPendiente",pSAgsSiscom);
SiscomImprimeArgumento("SqlDetallePedidoPendiente",pSAgsSiscom);
}
