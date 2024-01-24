#ifndef __COTIZANDO4_H__
#define __COTIZANDO4_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>

void CalculaCambioPago(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);
void CotizandoProductos4(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);

void ObtenIdOrden(int pintSocket,
			SiscomRegistroProL *pSiscomRegProLPtrPrim,
			SiscomRegistroProL *pSiscomRegProLPtrAct);


void ArmaCondicionConsultaProductos(SiscomOperaciones *pSiscomOpePtrDato,
				    SiscomRegistroProL *pSiscomRegProLPtrProductos,
			            char **pchrPtrCondicion);

int ArmaRespuestaCotizacion(SiscomOperaciones *pSiscomOpePtrDato);
float CotizandoProductoSiscom4(SiscomOperaciones *pSiscomOpePtrDato,
			       SiscomRegistroProL *pSiscomRegProLPtrProdBase,
		               SiscomRegistroProL *pSiscomRegProLPtrProductos);

void DefinicionTipoProducto(SiscomOperaciones *pSiscomOpePtrDato,
			    SiscomRegistroProL *pSiscomRegProLPtrProducto,
			    int *pintPtrNumKitPracticaEtc,
			    int *pintPtrNumProductos);
int ArgumentoDefinicionProducto(SiscomOperaciones *pSiscomOpePtrDato);

void ActualizaCantidadDefinicion(SiscomRegistroProL *pSiscomRegProLPtrDefinicion,
				 SiscomRegistroProL *pSiscomRegProLPtrProducto);

int ObteniendoIdOrden(SiscomOperaciones *pSiscomOpePtrDato);

void SePuedeVender(SiscomOperaciones *pSiscomOpePtrDato,
		   SiscomRegistroProL *pSiscomRegProLPtrProdBase,
		   SiscomRegistroProL *pSiscomRegProLPtrProducto);

int NoEsProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto);

int EsProductoPractica(SiscomRegistroProL *pSiscomRegProLPtrProducto);
int EsProductoKit(SiscomRegistroProL *pSiscomRegProLPtrProducto);
int EsCircuitoImpreso(SiscomRegistroProL *pSiscomRegProLPtrProducto);
void AjustaImporteTotal(float pfltImpTotal,char *pchrPtrImporteTotal);

void AjustaImporteTotal4(float pfltImpTotal,
		        char *pchrPtrImporteTotal);
int NoJuegosInvalido(SiscomOperaciones *pSiscomOpePtrDato);
int DescuentoInvalido(SiscomOperaciones *pSiscomOpePtrDato);
int ProductoSinPrecioExistencia(SiscomOperaciones *pSiscomOpePtrDato);

int ValidandoDatosCotizacion(SiscomOperaciones *pSiscomOpePtrDato);
int EsProductoSiscom(SiscomRegistroProL *pSiscomRegProLPtrProducto);
int EnviandoCotizacion(SiscomOperaciones *pSiscomOpePtrDato);

int EsOrdenCircuitoImpreso(SiscomOperaciones *pSiscomOpePtrDato);
int CalculandoCambioPago(SiscomOperaciones *pSisOpePtrDato);
int AsignaFechaHoraCotizacion(SiscomOperaciones *pSisOpePtrDato);
const char *SiElClienteEsNuloUsaPublicoGeneral(SiscomOperaciones *pSiscomOpePtrDato);
#endif

