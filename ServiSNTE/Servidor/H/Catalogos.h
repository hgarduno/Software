#ifndef __CATALOGOS_H__
#define __CATALOGOS_H__
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <SiscomArchivosIni.h>

void ConceptosExistencias(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void TiendasEntrega(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void Vendedores(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void PerfilesSS(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void Plazos(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void Proveedores(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void Camiones(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void Productos(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ProductosCodigoBarras(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ProductosCodigoBarrasFechaCompra(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void ProductoCodigoBarras(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void Departamentos(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);


void TipoDocumentos(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void TipoEstados(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void TipoVentas(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void TipoFinanciadoras(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);

void TipoFormasEntrega(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct);


int EnviaConceptosExistencias(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaTiendasEntrega(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaVendedores(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaPerfiles(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaPlazos(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaCamiones(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaProveedores(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaProductos(SiscomOperaciones *pSiscomOpePtrDat);
int ConcatenaProductoModelo(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaDepartamentos(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaTipoDocumentos(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaEstados(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaTipoVentas(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaFinanciadoras(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaFormasEntrega(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaTipoVivienda(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaFrecuenciaPagos(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaFrecuenciaTransaccional(SiscomOperaciones *pSiscomOpePtrDat);
int EnviaTiposFolio(SiscomOperaciones *pSiscomOpePtrDat);

#endif
