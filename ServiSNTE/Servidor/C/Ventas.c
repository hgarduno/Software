#include <Ventas.h>
#include <SqlVentas.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void RegistraVenta(int pintSocket,
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
SiscomAgregaOperacion(GeneraIdVenta,&lSiscomProDat);
SiscomAgregaOperacion(GeneraIdTelefonoCliente,&lSiscomProDat);
SiscomAgregaOperacion(GeneraFechaVenta,&lSiscomProDat);
SiscomAgregaOperacion(OrdenVenta,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraVenta,&lSiscomProDat);
SiscomAgregaOperacion(SqlDatosTiendaVenta,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdVentaRegistrada,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int GeneraIdVenta(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdVenta",pSiscomOpePtrDato);
}
int GeneraIdTelefonoCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
  SiscomIdARegistrosAsociadosEntrada("Envio","IdTelefono",pSiscomOpePtrDato);
}

void AgregandoTiendaVenta(SiscomRegistroProL *pSiscomRegProLPtrRegreso,
			  SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrTienda;
lSiscomRegProLPtrTienda=SiscomRegistrosAsociadoRespuestaOperacion("TiendaVenta",
								pSiscomOpePtrDato);
SiscomRegistrosAlCampo("Tienda",
			lSiscomRegProLPtrTienda,
			0,
			pSiscomRegProLPtrRegreso);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrTienda);
}
int EnviaIdVentaRegistrada(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0,
		   *lSiscomRegProLPtrOrden,
		   *lSiscomRegProLPtrProductos;
char lchrArrBuffer[512];
const char *lchrPtrIdVenta,
 	   *lchrPtrFecha;
char lchrArrAnio[5],
	lchrArrMes[3],
	lchrArrDia[3];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSiscomOpePtrDato);
lchrPtrIdVenta=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdVenta",
						     pSiscomOpePtrDato);

lchrPtrFecha=SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato);
DatosFecha(lchrPtrFecha,lchrArrAnio,lchrArrMes,lchrArrDia);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdVenta,Mensajes,Fecha,Dia,Mes,Anio,Tienda,",
		       lchrPtrIdVenta,
		       "Registro Exitoso",
		       lchrPtrFecha,
		       lchrArrDia,
		       lchrArrMes,
		       lchrArrAnio,
		       (const char *)0);

AgregandoTiendaVenta(lSiscomRegProLPtrPrim,pSiscomOpePtrDato);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
lSiscomRegProLPtrOrden=SiscomRegistrosAsociadosCampoEntrada("Envio",
							    "Orden",
							    pSiscomOpePtrDato);

lSiscomRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",lSiscomRegProLPtrOrden);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrOrden);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProductos);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);

SiscomAsociadosArgumentoLog("SqlInsertaVenta",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
}

int GeneraFechaVenta(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAsignaFechaHoraAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
}

int OrdenVenta(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrOrden,
		   *lSiscomRegProLPtrProductosPrim=0,
		   *lSiscomRegProLPtrProductosAct=0;
char lchrArrBuffer[256];
lSiscomRegProLPtrOrden=SiscomRegistrosAsociadosCampoEntrada("Envio",
							    "Orden",
							    pSiscomOpePtrDato);
/*
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrOrden);
*/
lSiscomRegProLPtrProductosPrim=SiscomObtenRegistrosCampoProL("Productos",lSiscomRegProLPtrOrden);
SiscomAgregaArgumentoOperacion("ProductosOrden",
			       lSiscomRegProLPtrProductosPrim,
			       lSiscomRegProLPtrProductosAct,
			       pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProductosPrim);
}

