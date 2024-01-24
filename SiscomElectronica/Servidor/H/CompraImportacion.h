#ifndef __COMPRAIMPORTACION_H__
#define __COMPRAIMPORTACION_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void RegistroParcialCompraImportacionFaltaronProductos(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void ProductoImportadoInf(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

void GuardaCompraImportacionComo(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void GuardaCompraImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

void ConsultaCompraImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);
void ConsultaComprasImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

void CompraImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

void RegistraCompraImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

void ProductosPorFiltroComprasImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

void CompletaProductosImportacion(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct);

int CalculandoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoConsultaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoConsultaComprasImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int RegistrandoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);

int ProductosPorFiltro(SiscomOperaciones *pSiscomOpePtrDato);
int EnviaProductoImportadoInf(SiscomOperaciones *);
int VerificaProductoDuplicado(SiscomOperaciones *);
int ProductoYaEstaEnLaLista(SiscomOperaciones *);
int NoSePuedeCargarImportacion(SiscomOperaciones *);

float ObtenPesoCompra(SiscomRegistroProL *pSisRegProLPtrProductos);
float CostoGramoEnvio(float pfltPesoTotal,SiscomOperaciones *pSiscomOpePtrDato);
void PesoTotalProducto(SiscomRegistroProL *pSisRegProLPtrProducto);
void CostoEnvioProducto(float pfltPtrCostoGramo,SiscomRegistroProL *pSisRegProLPtrProducto);
void CostoTotalDolares(SiscomRegistroProL *pSisRegProLPtrProducto);
void PrecioMasCostoEnvio(SiscomRegistroProL *pSisRegProLPtrProducto);
void CostoFinalPesos(SiscomOperaciones *pSiscomOpePtrDato,SiscomRegistroProL *pSiscomRegProLPtrProducto);
void PonderacionCostoAdministrativo(SiscomOperaciones *pSiscomOpePtrDato);
void CostoFinalMasCostoAdministrativo(SiscomOperaciones *pSiscomOpePtrDato,SiscomRegistroProL *);
void CostoPartida(SiscomRegistroProL *pSiscomRegProLPtrProducto);
int ArgumentoCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaIdCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int AgregaFechaCompraImportacion(SiscomOperaciones *pSiscomOpePtrDato);
int GuardandoCompraImportacion(SiscomOperaciones *pSisComOpePtrDato);
int AsignaIdCompraImportacion(SiscomOperaciones *pSisComOpePtrDato);
int AsignaIdCompraImportacionComo(SiscomOperaciones *pSisComOpePtrDato);
int EnviaCompletaProductosImportacion(SiscomOperaciones *pSisOpePtrDato);
int FormaCondicionClavesProveedores(SiscomOperaciones *pSisOpePtrDato);
int CompletandoDatosProductoImportacion(SiscomOperaciones *pSisOpePtrDato);
void ObtenImporteCompra(SiscomRegistroProL *pSiscomRegProLPtrProductos,SiscomOperaciones *pSiscomOpePtrDato);
#endif
