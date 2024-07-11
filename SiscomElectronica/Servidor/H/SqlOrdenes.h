#ifndef __SQLORDENES_H__
#define __SQLORDENES_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
int SqlPagaConEfectivo(SiscomOperaciones *pSiscomOpePtrDato);
int SqlFormaPagoTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
int SqlRegistraOrden(SiscomOperaciones *pSiscomOpePtrDato);
int SqlImporteOrden(SiscomOperaciones *pSiscomOpePtrDato);
int SqlEscuelaOrden(SiscomOperaciones *pSiscomOpePtrDato);
int SqlVentas(SiscomOperaciones *pSiscomOpePtrDato);
int SqlExistencias(SiscomOperaciones *pSiscomOpePtrDato);
int SqlExistenciasProductosKitPracticaEtc(SiscomOperaciones *pSiscomOpePtrDato);
int SqlOrdenCliente(SiscomOperaciones *pSiscomOpePtrDato);

int SqlApartados(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCotizacion(SiscomOperaciones *pSiscomOpePtrDato);
int SqlCierraApartado(SiscomOperaciones *pSiscomOpePtrDato);
int SqlDatosPedido(SiscomOperaciones *pSiscomOpePtrDato);
int SqlPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato);
int SqlEstadosPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato);
int SqlDireccionEntrega(SiscomOperaciones *pSiscomOpePtrDato);


int SqlMaterialAAreaDiseno(SiscomOperaciones *pSiscomOpePtrDato);
int SqlDonacionMaterial(SiscomOperaciones *pSiscomOpePtrDato);
int SqlActualizaDescripcionCotizacion(SiscomOperaciones *pSisOpePtrDato);

void InsertToMaterialAAreaDiseno(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void InsertToDonacionMaterial(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void InsertToEstadosPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);

void InsertToPedidoCliente(SiscomOperaciones *pSiscomOpePtrDato,
			   SiscomRegistroProL *pSiscomRegProLPtrDato,
			   char *pchrPtrSql);
void InsertToImporteOrden(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void InsertToEscuelaOrden(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void InsertToVentas(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);

void InsertToExistencias(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void InsertToExistenciasKitPracticaEtc(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);

void InsertToOrdenCliente(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void InsertToApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void InsertToEstadoApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);

void InsertToCotizacion(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);

void InsertToDatosPedido(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);

void InsertToImporteOrdenCierreOtroDia(SiscomOperaciones *pSiscomOpePtrDato,
					SiscomRegistroProL *pSiscomRegProLPtrDato,
					char *pchrPtrSql);
void InsertToDireccionEntrega(SiscomOperaciones *pSiscomOpePtrDato,
					SiscomRegistroProL *pSiscomRegProLPtrDato,
					char *pchrPtrSql);

void UpdateToVentasCierraApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void UpdateToImporteOrdenCierraApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);

void UpdateToImporteOrdenCierraApartadoMismoDia(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);

void UpdateToEstadoApartado(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void UpdateToEstadoApartadoADos(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);

void UpdateToVentasCierraApartadoTarjeta(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void UpdateToImporteOrdenCierraApartadoApartoConTarjeta(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);

void UpdateDescripcionCotizacion(SiscomOperaciones *pSisOpePtrDato,
				  SiscomRegistroProL * pSisRegPrOLPtrDato,
				  char *pchrPtrSql);

void DeleteCotizacionModificando(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void DeleteEscuelaOrdenModificando(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void DeleteOrdenClienteModificando(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);
void DeleteVentasModificando(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrSql);


void InsertToPagoTransferencia(SiscomOperaciones *pSisOpePtrDato,
				SiscomRegistroProL *pSisRegProLPtrDato,
				char *pchrPtrSql);

void InsertToPagaCon(SiscomOperaciones *pSisOpePtrDato,
				SiscomRegistroProL *pSisRegProLPtrDato,
				char *pchrPtrSql);
int SeAgreganImportes(SiscomOperaciones *pSiscomOpePtrDato);

int FechaApartadoEntregaHoy(SiscomOperaciones *pSiscomOpePtrDato);
int FechaEntregaProgramada(SiscomOperaciones *pSiscomOpePtrDato);

const char *FormaPagoApartado(SiscomOperaciones *pSiscomOpePtrDato);
const char *FormaPagoOrden(SiscomOperaciones *pSiscomOpePtrDato);

int PagoApartadoEfectivo(SiscomOperaciones *pSiscomOpePtrDato);
int PagoApartadoTarjeta(SiscomOperaciones *pSiscomOpePtrDato);

void CierraApartadoCualquierOtroDia(SiscomOperaciones *pSiscomOpePtrDato);
#endif
