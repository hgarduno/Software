#ifndef __ORDENESVENDIDAS_H__
#define __ORDENESVENDIDAS_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

typedef struct ConsultandoOrdenes
{
	const char *chrPtrTipoConsulta;
	int (*Consulta)(SiscomOperaciones *);

}StcConsultandoOrdenes;

typedef int (*InformacionPorTipoOrden)(SiscomRegistroProL *,SiscomOperaciones *);

int InformacionVenta(SiscomRegistroProL *pSiscomRegProLOrdenes,SiscomOperaciones *pSiscomOpePtrDatos);
int InformacionPedido(SiscomRegistroProL *pSiscomRegProLOrdenes,SiscomOperaciones *pSiscomOpePtrDatos);
int InformacionApartado(SiscomRegistroProL *pSiscomRegProLOrdenes,SiscomOperaciones *pSiscomOpePtrDatos);
int InformacionCotizacion(SiscomRegistroProL *pSiscomRegProLOrdenes,SiscomOperaciones *pSiscomOpePtrDatos);
int InformacionCancelacion(SiscomRegistroProL *pSiscomRegProLOrdenes,SiscomOperaciones *pSiscomOpePtrDatos);
int InformacionPagoTransferencia(SiscomRegistroProL *pSiscomRegProLOrdenes,SiscomOperaciones *pSiscomOpePtrDatos);

void OrdenesVendidas2(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);
void OrdenesVendidas(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void OrdenesParaFacturar(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);


void OrdenParaFacturar(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void OrdenesApartados(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void ProductoEnApartados(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

void ConsultaOrdenVendida(int pintSocket,
		SiscomRegistroProL *pSiscomRegProLPtrPrim,
		SiscomRegistroProL *pSiscomRegProLPtrAct);

int EnviandoOrdenesVendidas(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoOrdenesVendidas2(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoApartados(SiscomOperaciones *pSiscomOpePtrDato);
int EnviandoOrden(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoCotizaciones(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoPedidos(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoApartados(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoAbonosApartados(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoVentas(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoDatosEscuela(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoCondicionVentas(SiscomOperaciones *pSiscomOpePtrDato);

int SeEncontroLaOrden(SiscomOperaciones *pSiscomOpePtrDato);
int NOSeEncontroOrden(SiscomOperaciones *pSiscomOpePtrDato);

int CondicionConsultaOrdenes(SiscomOperaciones *);
int CondicionConsultaPorDescripcion(SiscomOperaciones *pSiscomOpePtrDato);
int ConsultandoDatosPorTipoOrden(SiscomOperaciones *pSiscomOpePtrDato);
int ComoHagoLaConsultaOrdenes(SiscomOperaciones *pSiscomOpePtrDato);
SiscomRegistroProL *AgrupaOrdenesVendidas(SiscomOperaciones *pSiscomOpePtrDato);
SiscomRegistroProL *AgrupaOrdenesVendidas2(SiscomOperaciones *pSiscomOpePtrDato);
SiscomRegistroProL *AgrupaAbonosApartados(SiscomOperaciones *pSiscomOpePtrDato);



int CondicionConsultaPorRangoFechas(SiscomOperaciones *pSiscomOpePtrDato,int,int);

void ActualizaArgumentoCondicion(const char *pchrPtrCondicion,
				 SiscomOperaciones *pSiscomOpePtrDato);




int PorRangoFechas(SiscomOperaciones *);
int PorHoraEntrega(SiscomOperaciones *pSiscomOpePtrDato);
#endif

