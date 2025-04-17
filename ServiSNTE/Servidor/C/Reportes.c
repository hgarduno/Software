#include <Reportes.h>
#include <SqlReportes.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomReplicacion.h>
#include <string.h>
#include <stdlib.h>

void VentasCliente(int pintSocket,
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
SiscomAgregaOperacion(CambiaRFCAMayusculas,&lSiscomProDat);
SiscomAgregaOperacion(SqlVentasCliente,&lSiscomProDat);
SiscomAgregaOperacion(EnviaVentasCliente,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void ConsultaFoliosCancelados(int pintSocket,
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
SiscomAgregaOperacion(SqlConsultaFoliosCancelados,&lSiscomProDat);
SiscomAgregaOperacion(EnviaFoliosCancelados,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}



void ReporteVentas(int pintSocket,
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
SiscomAgregaOperacion(ObtenRangoFecha,&lSiscomProDat);
SiscomAgregaOperacion(SqlReporteVentas,&lSiscomProDat);
SiscomAgregaOperacion(EnviaReporteVentas,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ExistenciasTienda(int pintSocket,
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
SiscomAgregaOperacion(SqlExistenciasTienda,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciasTienda,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ExistenciasAlmacen(int pintSocket,
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
SiscomAgregaOperacion(SqlExistenciasAlmacen,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciasAlmacen,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ExistenciasAlmacenProveedor(int pintSocket,
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
SiscomAgregaOperacion(SqlExistenciasAlmacenProveedor,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciasAlmacen,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ExistenciasAlmacenListaProductos(int pintSocket,
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
SiscomAgregaOperacion(SqlExistenciasAlmacenListaProductos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciasAlmacen,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ExistenciasTiendaProveedor(int pintSocket,
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
SiscomAgregaOperacion(SqlExistenciasTiendaProveedor,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciasTienda,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ExistenciasTiendaListaProductos(int pintSocket,
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
SiscomAgregaOperacion(SqlExistenciasTiendaListaProductos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciasTienda,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ReporteCompras(int pintSocket,
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
SiscomAgregaOperacion(ObtenRangoFecha,&lSiscomProDat);
SiscomAgregaOperacion(SqlReporteCompras,&lSiscomProDat);
SiscomAgregaOperacion(EnviaReporteCompras,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ReporteDetalleCompra(int pintSocket,
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
SiscomAgregaOperacion(SqlReporteDetalleCompra,&lSiscomProDat);
SiscomAgregaOperacion(EnviaReporteDetalleCompra,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void ExistenciasProductoTienda(int pintSocket,
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
SiscomAgregaOperacion(SqlExistenciasProductoTienda,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciasTienda,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ExistenciasProductoAlmacen(int pintSocket,
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
SiscomAgregaOperacion(SqlExistenciasProductoAlmacen,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciasAlmacen,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RepDatosCompra(int pintSocket,
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
SiscomAgregaOperacion(SqlDatosCompra,&lSiscomProDat);
SiscomAgregaOperacion(EnviaDatosCompra,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void RepProveedores(int pintSocket,
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
SiscomAgregaOperacion(SqlRepProveedores,&lSiscomProDat);
SiscomAgregaOperacion(EnviaRepProveedores,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}




void SiscomObtenFechasRango(const char *pchrPtrRango,
			    char *pchrPtrFechaIni,
			    char *pchrPtrFechaFin)
{
strncpy(pchrPtrFechaIni,pchrPtrRango,10);
*(pchrPtrFechaIni+10)=0;
strcpy(pchrPtrFechaFin,pchrPtrRango+11);

}


int ObtenRangoFecha(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[128],
     lchrArrFechaIni[12],
     lchrArrFechaFin[12];
const char *lchrPtrRangoFechas;

lchrPtrRangoFechas=SiscomCampoAsociadoEntradaOperacion("Envio",
						       "RangoFechas",
						       pSiscomOpePtrDat);
SiscomObtenFechasRango(lchrPtrRangoFechas,lchrArrFechaIni,lchrArrFechaFin);
SiscomAgregaCampoAsociadoEntrada("FechaIni",
				lchrArrFechaIni,
				"Envio",
				pSiscomOpePtrDat);

SiscomAgregaCampoAsociadoEntrada("FechaFin",
				lchrArrFechaFin,
				"Envio",
				pSiscomOpePtrDat);
LogSiscom("El Rango de Fechas:%s (%s,%s)",
	  lchrPtrRangoFechas,
	  lchrArrFechaIni,
	  lchrArrFechaFin);
}

int EnviaReporteVentas(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("ReporteVentas",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("ReporteVentas",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);

}

int EnviaExistenciasTienda(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[256];
if(SiscomObtenRegistrosCampoRespuesta("ExistenciasTienda",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("ExistenciasTienda",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

int EnviaReporteCompras(SiscomOperaciones *pSiscomOpePtrDato)
{
return EnviaConsultaReporte("ReporteCompras",pSiscomOpePtrDato);

}
int EnviaReporteDetalleCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
return EnviaConsultaReporte("ReporteDetalleCompras",pSiscomOpePtrDato);

}
int EnviaExistenciasAlmacen(SiscomOperaciones *pSiscomOpePtrDat)
{
return EnviaConsultaReporte("ExistenciasAlmacen",pSiscomOpePtrDat);
}


int EnviaConsultaReporte(const char *pchrPtrAsociado,
			SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta(pchrPtrAsociado,pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO(pchrPtrAsociado,pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void FormaCondicionConsultaListaProductos(SiscomOperaciones *pSiscomOpePtrDatos,
					 char **pchrPtrCondicion)
{
char lchrArrBuffer[128];
char lchrArrPaso[128];
SiscomRegistroProL *lSiscomRegProLPtrProductos;
int lintTamano;
lSiscomRegProLPtrProductos=SiscomRegistrosAsociadoEntradaOperacion("Envio",
								   pSiscomOpePtrDatos);
*pchrPtrCondicion=strdup("where codigobarras in(");
while(lSiscomRegProLPtrProductos)
{
  if(lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
  sprintf(lchrArrPaso, "'%s',", SiscomObtenCampoRegistroProLChar("Producto",lSiscomRegProLPtrProductos));
  else
  sprintf(lchrArrPaso,"'%s'",SiscomObtenCampoRegistroProLChar("Producto",lSiscomRegProLPtrProductos));
  lintTamano=strlen(*pchrPtrCondicion)+
  	     strlen(lchrArrPaso);
  *pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,lintTamano+2); 
  strcat(*pchrPtrCondicion,lchrArrPaso);
  lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig;
}
strcat(*pchrPtrCondicion,")");
}

void FormaCondicionConsultaListaProductosTienda(SiscomOperaciones *pSiscomOpePtrDatos,
					 char **pchrPtrCondicion)
{
char lchrArrBuffer[128];
char lchrArrPaso[128];
SiscomRegistroProL *lSiscomRegProLPtrProductos;
int lintTamano;
lSiscomRegProLPtrProductos=SiscomRegistrosAsociadosCampoEntrada("Envio",
								"Productos",
								pSiscomOpePtrDatos);
*pchrPtrCondicion=strdup("where codigobarras in(");
while(lSiscomRegProLPtrProductos)
{
  if(lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
  sprintf(lchrArrPaso, "'%s',", SiscomObtenCampoRegistroProLChar("Producto",lSiscomRegProLPtrProductos));
  else
  sprintf(lchrArrPaso,"'%s'",SiscomObtenCampoRegistroProLChar("Producto",lSiscomRegProLPtrProductos));
  lintTamano=strlen(*pchrPtrCondicion)+
  	     strlen(lchrArrPaso);
  *pchrPtrCondicion=(char *)realloc(*pchrPtrCondicion,lintTamano+2); 
  strcat(*pchrPtrCondicion,lchrArrPaso);
  lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig;
}
strcat(*pchrPtrCondicion,")");
}

int EnviaVentasCliente(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[128];
if(SiscomObtenRegistrosCampoRespuesta("VentasCliente",pSiscomOpePtrDat))
{
LogSiscom("Si Se encontro algo");
SiscomEnviaRegistroSocket(pSiscomOpePtrDat->intSocket,
			  lchrArrBuffer,
			  pSiscomOpePtrDat->SiscomRegProLPtrPrimRes);
}
else
{
LogSiscom("RFC Sin Compras");
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}
}
int CambiaRFCAMayusculas(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomCambiaAMayusculasCampoAsociadoEntrada("Envio","RFC",pSiscomOpePtrDato);
}

int EnviaFoliosCancelados(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[128];
if(SiscomObtenRegistrosCampoRespuesta("FoliosCancelados",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("FoliosCancelados",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void StockDepartamentoProveedor(int pintSocket,
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
SiscomAgregaOperacion(SqlStockDepartamentoProveedor,&lSiscomProDat);
SiscomAgregaOperacion(EnviaStockDepartamentoProveedor,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PreciosProductos(int pintSocket,
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
SiscomAgregaOperacion(SqlPreciosProductos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPreciosProductos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PreciosProductosComprador(int pintSocket,
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
SiscomAgregaOperacion(SqlPreciosProductosComprador,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPreciosProductosComprador,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void StockTienda(int pintSocket,
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
SiscomAgregaOperacion(SqlStockTienda,&lSiscomProDat);
SiscomAgregaOperacion(EnviaStockTienda,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ExistenciasProveedor(int pintSocket,
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
SiscomAgregaOperacion(SqlExistenciasProveedor,&lSiscomProDat);
SiscomAgregaOperacion(SqlProductosServiSNTE,&lSiscomProDat);
SiscomAgregaOperacion(EnviaExistenciasProveedor,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaStockDepartamentoProveedor(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[128];
if(SiscomObtenRegistrosCampoRespuesta("StockDepartamentoProveedor",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("StockDepartamentoProveedor",pSiscomOpePtrDat));
else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

int EnviaPreciosProductos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
char *lchrPtrCamposProveedor[]={"iddepartamento","nombredepto",0};
char *lchrPtrCamposProductos[]={"idprecio",
				"idproducto",
				"numproducto",
				"nombreproducto",
				"modelo",
				"preciogeneral",
				"stock",
				0};
SiscomRegistroProL *lSiscomRegProLPtrPrimDatos=0,
		   *lSiscomRegProLPtrActDatos=0,
		   *lSiscomRegProLPtrDatos;
if((lSiscomRegProLPtrDatos=SiscomObtenRegistrosCampoRespuesta("ListaPrecios",pSiscomOpePtrDat)))
{
 SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrDatos);
 SiscomAgrupaPorCampo("iddepartamento",
 		      "Productos",
		      lchrPtrCamposProveedor,
		      lchrPtrCamposProductos,
		      lSiscomRegProLPtrDatos,
		      &lSiscomRegProLPtrPrimDatos,
		      &lSiscomRegProLPtrActDatos);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,lchrArrBuffer,lSiscomRegProLPtrPrimDatos);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrimDatos);
}
else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

int EnviaPreciosProductosComprador(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
char *lchrPtrCamposProveedor[]={"iddepartamento","nombredepto",0};
char *lchrPtrCamposProductos[]={"idprecio",
				"idproducto",
				"numproducto",
				"nombreproducto",
				"modelo",
				"preciogeneral",
				0};
SiscomRegistroProL *lSiscomRegProLPtrPrimDatos=0,
		   *lSiscomRegProLPtrActDatos=0,
		   *lSiscomRegProLPtrDatos;
if((lSiscomRegProLPtrDatos=SiscomObtenRegistrosCampoRespuesta("ListaPreciosComprador",pSiscomOpePtrDat)))
{
 SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrDatos);
 SiscomAgrupaPorCampo("iddepartamento",
 		      "Productos",
		      lchrPtrCamposProveedor,
		      lchrPtrCamposProductos,
		      lSiscomRegProLPtrDatos,
		      &lSiscomRegProLPtrPrimDatos,
		      &lSiscomRegProLPtrActDatos);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,lchrArrBuffer,lSiscomRegProLPtrPrimDatos);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrimDatos);
}
else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void ImporteTotalPorProveedor(SiscomRegistroProL *pSiscomRegProLPtrDatos)
{
SiscomRegistroProL *lSiscomRegProLPtrProveedor,
		   *lSiscomRegProLPtrProductos;
char lchrArrBuffer[128];
float lfltTotalProveedor,
	lfltImporteTotalTienda=0;
char lchrArrTotalProveedor[24];
for(lSiscomRegProLPtrProveedor=pSiscomRegProLPtrDatos;
    lSiscomRegProLPtrProveedor;
    lSiscomRegProLPtrProveedor=lSiscomRegProLPtrProveedor->SiscomRegProLPtrSig)
{
   lSiscomRegProLPtrProductos=SiscomObtenRegistrosCampoProL("Productos",lSiscomRegProLPtrProveedor); 
   lfltTotalProveedor=SiscomObtenSumatoriaRegistros("importecosto",lSiscomRegProLPtrProductos);
   sprintf(lchrArrTotalProveedor,"%.2f",lfltTotalProveedor);
   SiscomAgregaCampoRegistro("TotalProveedor",lchrArrTotalProveedor,lSiscomRegProLPtrProveedor);
   lfltImporteTotalTienda+=lfltTotalProveedor;
}
}

int EnviaStockTienda(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[512];
char *lchrPtrCamposProveedor[]={"idempresa","razonsocial",0};
char *lchrPtrCamposProductos[]={"idprecio",
				"idproducto",
				"numproducto",
				"nombreproducto",
				"modelo",
				"costobruto",
				"costoneto",
				"stock",
				"importecosto",
				"idempresa",
				"preciogeneral",
				"importeventa",
				0};
SiscomRegistroProL *lSiscomRegProLPtrPrimDatos=0,
		   *lSiscomRegProLPtrActDatos=0,
		   *lSiscomRegProLPtrDatos;
if((lSiscomRegProLPtrDatos=SiscomObtenRegistrosCampoRespuesta("StockTienda",pSiscomOpePtrDat)))
{
 SiscomAgrupaPorCampo("idempresa",
 		      "Productos",
		      lchrPtrCamposProveedor,
		      lchrPtrCamposProductos,
		      lSiscomRegProLPtrDatos,
		      &lSiscomRegProLPtrPrimDatos,
		      &lSiscomRegProLPtrActDatos);
ImporteTotalPorProveedor(lSiscomRegProLPtrPrimDatos);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,lchrArrBuffer,lSiscomRegProLPtrPrimDatos);
}
else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}





SiscomRegistroProL *ObtenExistenciasPorTienda(SiscomRegistroProL *pSiscomRegProLPtrTienda,
					      SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrInfoTienda,
		   *lSiscomRegProLPtrExistenciasTienda;
const char *lchrPtrSiglas=SiscomObtenCampoRegistroProLChar("siglas",
							   pSiscomRegProLPtrTienda);
lSiscomRegProLPtrInfoTienda=SiscomObtenRegistrosCampoProL(lchrPtrSiglas,
					pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);

lSiscomRegProLPtrExistenciasTienda=SiscomObtenRegistrosCampoProL("ExistenciasProveedor",
								lSiscomRegProLPtrInfoTienda);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrExistenciasTienda);
}

SiscomRegistroProL *SiscomRegistrosMaquinaConsulta(const char *pchrPtrDatoConsultar,
						   const char *pchrPtrNombreConsulta,
						   SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrRegreso,
		   *lSiscomRegProLPtrInformacion;
const char *lchrPtrCampo;
char lchrArrBuffer[128];
if(pSiscomOpePtrDato->SiscomRegProLPtrPrimRes)
{
  lSiscomRegProLPtrInformacion=SiscomObtenRegistrosCampoProL(pchrPtrDatoConsultar,
  							     pSiscomOpePtrDato->SiscomRegProLPtrPrimRes);
  lSiscomRegProLPtrRegreso=SiscomObtenRegistrosCampoProL(pchrPtrNombreConsulta,lSiscomRegProLPtrInformacion);
  return lSiscomRegProLPtrRegreso;
}
}
SiscomRegistroProL *ExistenciasProductosTiendaProveedor(SiscomRegistroProL *pSiscomRegProLPtrMaquina,
					       SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrSiglas;
SiscomRegistroProL *lSiscomRegProLPtrExistencias;
lchrPtrSiglas=SiscomObtenCampoRegistroProLChar("siglas",pSiscomRegProLPtrMaquina);
lSiscomRegProLPtrExistencias=SiscomRegistrosMaquinaConsulta(lchrPtrSiglas,
							    "ExistenciasProveedor",
							    pSiscomOpePtrDato);

return lSiscomRegProLPtrExistencias;
}
void FormaProductoExistenciasTiendas(SiscomRegistroProL *pSiscomRegProLPtrProducto,
				     SiscomRegistroProL **pSiscomRegProLPtrExistenciaProdPrim,
				     SiscomRegistroProL **pSiscomRegProLPtrExistenciaProdAct)
{
/*
  SiscomAnexaRegistroPro2(pSiscomRegProLPtrExistenciaProdPrim,
  			  pSiscomRegProLPtrExistenciaProdAct,
			  pSiscomRegProLPtrProducto);
*/
  SiscomAgregaCampoRegistro("DatosExistencia",0,*pSiscomRegProLPtrExistenciaProdAct); 
  LogSiscom("Agregando Productos al regreso");
}
void FormaExistenciaTienda(SiscomRegistroProL *pSiscomRegProLPtrMaquina,
			   SiscomRegistroProL *pSiscomRegProLPtrExistencias,
			   SiscomRegistroProL **pSiscomRegProLPtrExisTiendaPrim,
			   SiscomRegistroProL **pSiscomRegProLPtrExisTiendaAct)
{
/*
SiscomAnexaRegistroPro2(pSiscomRegProLPtrExisTiendaPrim,
			pSiscomRegProLPtrExisTiendaAct,
			pSiscomRegProLPtrMaquina);
*/
SiscomAgregaCampoRegistro("Existencia",
			  pSiscomRegProLPtrExistencias ? 
			  SiscomObtenCampoRegistroProLChar("existencia",pSiscomRegProLPtrExistencias):0,
			   *pSiscomRegProLPtrExisTiendaAct);
SiscomAgregaCampoRegistro("Stock",
			  pSiscomRegProLPtrExistencias ? 
			  SiscomObtenCampoRegistroProLChar("stock",pSiscomRegProLPtrExistencias):0,
			  *pSiscomRegProLPtrExisTiendaAct);
LogSiscom("Agregando la existencia");
}

int ExistenciaProductoTienda(SiscomRegistroProL *pSiscomRegProLPtrMaquina,
			      SiscomRegistroProL *pSiscomRegProLPtrProdServiSNTE,
			      SiscomOperaciones *pSiscomOpePtrDato,
			      SiscomRegistroProL **pSiscomRegProLPtrProdExiTiendaPrim,
			      SiscomRegistroProL **pSiscomRegProLPtrProdExiTiendaAct)
{
char lchrArrBuffer[256];
const char *lchrPtrNumProducto;
SiscomRegistroProL *lSiscomRegProLPtrProdsTienda;
lchrPtrNumProducto=SiscomObtenCampoRegistroProLChar("numproducto",pSiscomRegProLPtrProdServiSNTE);
lSiscomRegProLPtrProdsTienda=ExistenciasProductosTiendaProveedor(pSiscomRegProLPtrMaquina,pSiscomOpePtrDato);
for(;
     lSiscomRegProLPtrProdsTienda;
     lSiscomRegProLPtrProdsTienda=lSiscomRegProLPtrProdsTienda->SiscomRegProLPtrSig)
{
    if(!SiscomComparaCadenaCampoRegistroProL(lchrPtrNumProducto,
    					     "numproducto",
					     lSiscomRegProLPtrProdsTienda))
    {
    	LogSiscom("\t%s %s",
		  SiscomObtenCampoRegistroProLChar("numproducto",pSiscomRegProLPtrProdServiSNTE),
		  SiscomObtenCampoRegistroProLChar("nombreproducto",pSiscomRegProLPtrProdServiSNTE));
	LogSiscom("\t%s %s",
		  SiscomObtenCampoRegistroProLChar("stock",lSiscomRegProLPtrProdsTienda),
		  SiscomObtenCampoRegistroProLChar("existencia",lSiscomRegProLPtrProdsTienda));
	SiscomAnexaRegistroPro(pSiscomRegProLPtrProdExiTiendaPrim,
			       pSiscomRegProLPtrProdExiTiendaAct,
			      lchrArrBuffer,
			      "idtienda,nombre,siglas,existencia,stock,",
			      SiscomObtenCampoRegistroProLChar("idtienda",pSiscomRegProLPtrMaquina),
			      SiscomObtenCampoRegistroProLChar("nombre",pSiscomRegProLPtrMaquina),
			      SiscomObtenCampoRegistroProLChar("siglas",pSiscomRegProLPtrMaquina),
			      SiscomObtenCampoRegistroProLChar("existencia",lSiscomRegProLPtrProdsTienda),
			      SiscomObtenCampoRegistroProLChar("stock",lSiscomRegProLPtrProdsTienda));
	return 1;
	
    }

}
return 0;
}
void AgregandoExistenciaAlProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto,
				   SiscomRegistroProL *pSiscomRegProLPtrExiTiendasPrim,
				   SiscomRegistroProL *pSiscomRegProLPtrExiTiendasAct,
				   SiscomRegistroProL **pSiscomRegProLPtrExiProveedorTiendasPrim,
				   SiscomRegistroProL **pSiscomRegProLPtrExiProveedorTiendasAct)
{
float lfltExistencia,
	lfltStock,
	lfltCosto;
  if(SiscomObtenCampoRegistroProL("DatosExistencia",pSiscomRegProLPtrProducto))
  {
  /*
	SiscomAnexaRegistroPro2(pSiscomRegProLPtrExiProveedorTiendasPrim,
				pSiscomRegProLPtrExiProveedorTiendasAct,
				pSiscomRegProLPtrProducto);
*/
	lfltStock=SiscomObtenSumatoriaRegistros("stock",pSiscomRegProLPtrExiTiendasPrim);
	lfltExistencia=SiscomObtenSumatoriaRegistros("existencia",pSiscomRegProLPtrExiTiendasPrim);
	lfltCosto=lfltStock*SiscomObtenCampoRegistroProLFloat("costoneto",pSiscomRegProLPtrProducto);
	LogSiscom("Existencia:%f Stock:%f",lfltExistencia,lfltStock);
	SiscomActualizaCampoFloatRegistroActual("Stock","%.0f",lfltStock,pSiscomRegProLPtrProducto);
	SiscomActualizaCampoFloatRegistroActual("Existencia","%.0f",lfltExistencia,pSiscomRegProLPtrProducto);
	SiscomActualizaCampoFloatRegistroActual("Costo","%.2f",lfltCosto,pSiscomRegProLPtrProducto);
	SiscomRegistrosAlCampo("DatosExistencia",
				pSiscomRegProLPtrExiTiendasPrim,
				pSiscomRegProLPtrExiTiendasAct,
				*pSiscomRegProLPtrExiProveedorTiendasAct);
  }
}
SiscomRegistroProL *ProductosParaConsultar(SiscomRegistroProL *pSiscomRegProLPtrProductosServiSNTE,
				       SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrIdProducto;
if(SiscomEstaElCampoAsociado("Envio","IdProducto",pSiscomOpePtrDato))
{
    lchrPtrIdProducto=SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDato);
  LogSiscom("Se busca solo un producto (%s)",lchrPtrIdProducto);
  return SiscomBuscaRegistroLista("idproducto",
  				   lchrPtrIdProducto,
				   pSiscomRegProLPtrProductosServiSNTE);
}
else
return pSiscomRegProLPtrProductosServiSNTE;
}
SiscomRegistroProL *SumaExistenciasProducto(SiscomRegistroProL *pSiscomRegProLPtrMaquinas,
					   SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSiscomRegProLPtrExiProveedorPrim=0,
 		   *lSiscomRegProLPtrExiProveedorAct=0,
		   *lSiscomRegProLPtrExiProveedor;
SiscomRegistroProL *lSiscomRegProLPtrProdServiSNTEProv,
		   *lSiscomRegProLPtrProdServiSNTERecorre;
SiscomRegistroProL *lSiscomRegProLPtrExiProdTiendaPrim=0,
		   *lSiscomRegProLPtrExiProdTiendaAct=0;
SiscomRegistroProL *lSiscomRegProLPtrMaquinas;
lSiscomRegProLPtrProdServiSNTEProv=SiscomObtenRegistrosCampoRespuesta("ProductosServiSNTE",pSiscomOpePtrDato);
lSiscomRegProLPtrProdServiSNTEProv=ProductosParaConsultar(lSiscomRegProLPtrProdServiSNTEProv,pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrProdServiSNTEProv);
 for(lSiscomRegProLPtrProdServiSNTERecorre=lSiscomRegProLPtrProdServiSNTEProv;
     lSiscomRegProLPtrProdServiSNTERecorre;
     lSiscomRegProLPtrProdServiSNTERecorre=lSiscomRegProLPtrProdServiSNTERecorre->SiscomRegProLPtrSig)
{
    	SiscomAgregaCampoRegistro("DatosExistencia",0,lSiscomRegProLPtrProdServiSNTERecorre);
    	SiscomAgregaCampoRegistro("Stock",0,lSiscomRegProLPtrProdServiSNTERecorre);
    	SiscomAgregaCampoRegistro("Existencia",0,lSiscomRegProLPtrProdServiSNTERecorre);
    	SiscomAgregaCampoRegistro("Costo",0,lSiscomRegProLPtrProdServiSNTERecorre);
for(lSiscomRegProLPtrMaquinas=pSiscomRegProLPtrMaquinas;
    lSiscomRegProLPtrMaquinas;
    lSiscomRegProLPtrMaquinas=lSiscomRegProLPtrMaquinas->SiscomRegProLPtrSig)
{
    if(!SiscomComparaCadenaCampoRegistroProL("Servidor","tipoequipo",lSiscomRegProLPtrMaquinas))
    {
    LogSiscom("%s",SiscomObtenCampoRegistroProLChar("siglas",lSiscomRegProLPtrMaquinas));
    ExistenciaProductoTienda(lSiscomRegProLPtrMaquinas,
    			     lSiscomRegProLPtrProdServiSNTERecorre,
			     pSiscomOpePtrDato,
			     &lSiscomRegProLPtrExiProdTiendaPrim,
			     &lSiscomRegProLPtrExiProdTiendaAct);	
    }
 }

AgregandoExistenciaAlProducto(lSiscomRegProLPtrProdServiSNTERecorre,
			      lSiscomRegProLPtrExiProdTiendaPrim,
			      lSiscomRegProLPtrExiProdTiendaAct,
			      &lSiscomRegProLPtrExiProveedorPrim,
			      &lSiscomRegProLPtrExiProveedorAct);
lSiscomRegProLPtrExiProdTiendaPrim=lSiscomRegProLPtrExiProdTiendaAct=0;
}
return lSiscomRegProLPtrExiProveedorPrim;
}

int EnviaExistenciasProveedor(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[256];
const char *lchrPtrSiglas;
SiscomRegistroProL *lSiscomRegProLPtrMaquinas;
SiscomRegistroProL *lSiscomRegProLPtrExistenciasTienda;
lSiscomRegProLPtrMaquinas=SiscomObtenRegistrosCampoProL("Servidores",gSiscomRegProLPtrMemoria);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrMaquinas);
lSiscomRegProLPtrExistenciasTienda=SumaExistenciasProducto(lSiscomRegProLPtrMaquinas,pSiscomOpePtrDat);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrMaquinas);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrExistenciasTienda);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,lchrArrBuffer,lSiscomRegProLPtrExistenciasTienda);
return 0;
}
int EnviaDatosCompra(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
}
SiscomRegistroProL *AgrupaTelefonosProveedores(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
char *lchrPtrCamposProveedor[]={"idempresa",0};
char *lchrPtrCamposTelefonos[]={"telefono",0};
SiscomRegistroProL *lSiscomRegProLPtrTelefonos,
		   *lSiscomRegProLPtrTelefonosPrim=0,
		   *lSiscomRegProLPtrTelefonosAct=0;
if((lSiscomRegProLPtrTelefonos=SiscomObtenRegistrosCampoRespuesta("Telefonos",pSiscomOpePtrDato)))
  SiscomAgrupaPorCampo("idempresa",
  			"Telefonos",
			lchrPtrCamposProveedor,
			lchrPtrCamposTelefonos,
			lSiscomRegProLPtrTelefonos,
			&lSiscomRegProLPtrTelefonosPrim,
			&lSiscomRegProLPtrTelefonosAct);
return lSiscomRegProLPtrTelefonosPrim;
}
void AsignaTelefonosProveedor(SiscomRegistroProL *pSiscomRegProLPtrAgrupados,
			      SiscomRegistroProL *pSiscomRegProLPtrTelefonos,
			      SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrProveedores;
lSiscomRegProLPtrProveedores=SiscomObtenRegistrosCampoRespuesta("Proveedores",
					pSiscomOpePtrDato);
for(;
    lSiscomRegProLPtrProveedores;
    lSiscomRegProLPtrProveedores=lSiscomRegProLPtrProveedores->SiscomRegProLPtrSig)
{
   if(!SiscomComparaCampoRegistrosProL2("idempresa",
   					"idempresa",
					pSiscomRegProLPtrAgrupados,
					lSiscomRegProLPtrProveedores))
	SiscomRegistrosAlCampo("Telefonos",
				pSiscomRegProLPtrTelefonos,
				pSiscomRegProLPtrTelefonos,
				lSiscomRegProLPtrProveedores);
}
}

void AsignaTelefonosProveedores(SiscomRegistroProL *pSiscomRegProLPtrAgrupados,
		     SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrTelefonos;
char lchrArrBuffer[128];
for( ;
    pSiscomRegProLPtrAgrupados;
    pSiscomRegProLPtrAgrupados=pSiscomRegProLPtrAgrupados->SiscomRegProLPtrSig)
{
   if((lSiscomRegProLPtrTelefonos=SiscomObtenRegistrosCampoProL("Telefonos",
   							pSiscomRegProLPtrAgrupados)))
   AsignaTelefonosProveedor(pSiscomRegProLPtrAgrupados,
   			   lSiscomRegProLPtrTelefonos,
			   pSiscomOpePtrDato);
}
}
void AgrupandoTelefonosProveedores(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrAgrupados;
lSiscomRegProLPtrAgrupados=AgrupaTelefonosProveedores(pSiscomOpePtrDato);
AsignaTelefonosProveedores(lSiscomRegProLPtrAgrupados,pSiscomOpePtrDato);
}
void MuestraDatosProveedores(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrRegreso,
		   *lSiscomRegProLPtrTelefonos;
lSiscomRegProLPtrRegreso=SiscomRegistrosAsociadoRespuestaOperacion("Proveedores",pSiscomOpePtrDato);
while(lSiscomRegProLPtrRegreso)
{
 SiscomCamposProtocoloLog2(lSiscomRegProLPtrRegreso);
 if((lSiscomRegProLPtrTelefonos=SiscomObtenRegistrosCampoProL("Telefonos",lSiscomRegProLPtrRegreso)))
 SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrTelefonos);
 lSiscomRegProLPtrRegreso=lSiscomRegProLPtrRegreso->SiscomRegProLPtrSig;
}
}
void AgregaCampoTelefonos(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrRegreso;
lSiscomRegProLPtrRegreso=SiscomObtenRegistrosCampoRespuesta("Proveedores",pSiscomOpePtrDato);
SiscomAgregaCampoRegistros("Telefonos",0,lSiscomRegProLPtrRegreso);
}
int EnviaRepProveedores(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
AgregaCampoTelefonos(pSiscomOpePtrDato);
AgrupandoTelefonosProveedores(pSiscomOpePtrDato);
/*MuestraDatosProveedores(pSiscomOpePtrDato);    */
SiscomEnviaAsociadoRespuestaCliente("Proveedores",lchrArrBuffer,pSiscomOpePtrDato);
}
