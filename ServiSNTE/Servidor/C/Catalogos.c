#include <Catalogos.h>
#include <SqlCatalogos.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <string.h>

void FrecuenciaTransaccional(int pintSocket,
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
SiscomAgregaOperacion(SqlFrecuenciaTransaccional,&lSiscomProDat);
SiscomAgregaOperacion(EnviaFrecuenciaTransaccional,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void TiposFolio(int pintSocket,
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
SiscomAgregaOperacion(SqlTiposFolio,&lSiscomProDat);
SiscomAgregaOperacion(EnviaTiposFolio,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


void FrecuenciaPagos(int pintSocket,
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
SiscomAgregaOperacion(SqlFrecuenciaPagos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaFrecuenciaPagos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void TipoVivienda(int pintSocket,
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
SiscomAgregaOperacion(SqlTipoVivienda,&lSiscomProDat);
SiscomAgregaOperacion(EnviaTipoVivienda,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ConceptosExistencias(int pintSocket,
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
SiscomAgregaOperacion(SqlConceptosExistencias,&lSiscomProDat);
SiscomAgregaOperacion(EnviaConceptosExistencias,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaConceptosExistencias(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("ConceptosExistencias",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("ConceptosExistencias",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

int EnviaTipoVivienda(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("TipoVivienda",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("TipoVivienda",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

int EnviaFrecuenciaPagos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("FrecuenciaPagos",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("FrecuenciaPagos",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

int EnviaFrecuenciaTransaccional(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("FrecuenciaTransaccional",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("FrecuenciaTransaccional",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}
int EnviaTiposFolio(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("TiposFolio",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("TiposFolio",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void TiendasEntrega(int pintSocket,
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
SiscomAgregaOperacion(SqlTiendasEntrega,&lSiscomProDat);
SiscomAgregaOperacion(EnviaTiendasEntrega,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaTiendasEntrega(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("TiendasEntrega",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("TiendasEntrega",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void Vendedores(int pintSocket,
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
SiscomAgregaOperacion(SqlVendedores,&lSiscomProDat);
SiscomAgregaOperacion(EnviaVendedores,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void PerfilesSS(int pintSocket,
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
SiscomAgregaOperacion(SqlPerfiles,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPerfiles,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}




int EnviaVendedores(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Vendedores",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("Vendedores",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

int EnviaPerfiles(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Perfiles",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("Perfiles",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void Plazos(int pintSocket,
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
SiscomAgregaOperacion(SqlPlazos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPlazos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaPlazos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Plazos",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("Plazos",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void Camiones(int pintSocket,
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
SiscomAgregaOperacion(SqlCamiones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCamiones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaCamiones(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Camiones",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("Camiones",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void Proveedores(int pintSocket,
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
SiscomAgregaOperacion(SqlProveedores,&lSiscomProDat);
SiscomAgregaOperacion(EnviaProveedores,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaProveedores(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Proveedores",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("Proveedores",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void Productos(int pintSocket,
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
SiscomAgregaOperacion(SqlProductos,&lSiscomProDat);
SiscomAgregaOperacion(ConcatenaProductoModelo,&lSiscomProDat);
SiscomAgregaOperacion(EnviaProductos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ProductosCodigoBarras(int pintSocket,
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
SiscomAgregaOperacion(SqlProductosCodigoBarras,&lSiscomProDat);
SiscomAgregaOperacion(EnviaProductos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ProductoCodigoBarras(int pintSocket,
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
SiscomAgregaOperacion(SqlProductoCodigoBarras,&lSiscomProDat);
SiscomAgregaOperacion(EnviaProductos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ProductoProveedor(int pintSocket,
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
SiscomAgregaOperacion(SqlProductoProveedor,&lSiscomProDat);
SiscomAgregaOperacion(EnviaProductos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ProductosCodigoBarrasFechaCompra(int pintSocket,
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
SiscomAgregaOperacion(SqlProductosCodigoBarrasFechaCompra,&lSiscomProDat);
SiscomAgregaOperacion(EnviaProductos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ProductosCodigoBarrasTodos(int pintSocket,
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
SiscomAgregaOperacion(SqlProductosCodigoBarrasTodos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaProductos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int ConcatenaProductoModelo(SiscomOperaciones *pSiscomOpePtrDat)
{
SiscomRegistroProL *lSiscomRegProLPtrProductos;
char lchrArrProductoModelo[256];
lSiscomRegProLPtrProductos=SiscomRegistrosCampoO("Productos",pSiscomOpePtrDat);

for(;
    lSiscomRegProLPtrProductos;
    lSiscomRegProLPtrProductos=SiscomSiguienteNodoRegistroProL(lSiscomRegProLPtrProductos))
{
sprintf(lchrArrProductoModelo,
	"%s (%s)",
	  SiscomObtenCampoRegistroProLChar("nombreproducto",lSiscomRegProLPtrProductos),
	  SiscomObtenCampoRegistroProLChar("modelo",lSiscomRegProLPtrProductos));
/*
LogSiscom("Producto(%s) Modelo(%s) %s",
	  SiscomObtenCampoRegistroProLChar("nombreproducto",lSiscomRegProLPtrProductos),
	  SiscomObtenCampoRegistroProLChar("modelo",lSiscomRegProLPtrProductos),
	  lchrArrProductoModelo);
*/
SiscomAgregaCampoRegistro("ProdModelo",lchrArrProductoModelo,lSiscomRegProLPtrProductos);

}




}

int EnviaProductos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Productos",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("Productos",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void Departamentos(int pintSocket,
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
SiscomAgregaOperacion(SqlDepartamentos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaDepartamentos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaDepartamentos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Departamentos",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("Departamentos",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void TipoDocumentos(int pintSocket,
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
SiscomAgregaOperacion(SqlTipoDocumentos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaTipoDocumentos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaTipoDocumentos(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("TipoDocumentos",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("TipoDocumentos",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void Estados(int pintSocket,
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
SiscomAgregaOperacion(SqlEstados,&lSiscomProDat);
SiscomAgregaOperacion(EnviaEstados,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaEstados(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Estados",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("Estados",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void TipoVentas(int pintSocket,
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
SiscomAgregaOperacion(SqlTipoVentas,&lSiscomProDat);
SiscomAgregaOperacion(EnviaTipoVentas,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaTipoVentas(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("TipoVentas",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("TipoVentas",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void Financiadoras(int pintSocket,
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
SiscomAgregaOperacion(SqlFinanciadoras,&lSiscomProDat);
SiscomAgregaOperacion(EnviaFinanciadoras,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaFinanciadoras(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("Financiadoras",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("Financiadoras",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

void FormasEntrega(int pintSocket,
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
SiscomAgregaOperacion(SqlFormasEntrega,&lSiscomProDat);
SiscomAgregaOperacion(EnviaFormasEntrega,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int EnviaFormasEntrega(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("FormasEntrega",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("FormasEntrega",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}

