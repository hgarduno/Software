#ifndef __REGISTRAORDEN_H__
#define __REGISTRAORDEN_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

typedef struct CerrandoApartado
{
   int (*AdelantoApartado)(SiscomOperaciones *);
   int (*PagoCierreApartado)(SiscomOperaciones *);
}SiscomCerrandoApartado;

void FormandoComoPago(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);


void RegistraOrden(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);

void PagarApartado(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);

void ActualizaDescripcionCotizacion(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);


void VerificaConCuantoPago(int pintSocket,
		   SiscomRegistroProL *pSiscomRegProLPtrPrim,
		   SiscomRegistroProL *pSiscomRegProLPtrAct);


int RegistrandoOrden(SiscomOperaciones *pSiscomOpePtrDato);
int ArgumentoOrden(SiscomOperaciones *pSiscomOpePtrDato);
int CamposCierraApartadoOtroDia(SiscomOperaciones *);
int VerificandoConCuantoPago(SiscomOperaciones *);


int CalculandoComoPago(SiscomOperaciones *);


int EsOrdenVentaPagaEfectivo(SiscomOperaciones *);
int ValidandoFechaPedido(SiscomOperaciones *pSiscomOpePtrDato);
int SePagoConTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
int SePagoCombinandoMetodosPago(SiscomOperaciones *);
int SePagoConTarjeta(SiscomOperaciones *pSiscomOpePtrDato);

int FormaPagoCombinada(SiscomOperaciones *pSisOpePtrDato);
int SePagoCombinado(SiscomOperaciones *pSisOpePtrDatos);

int SePagoUnaParteEjectivo(SiscomOperaciones *pSisOpePtrDato);
SiscomRegistroProL *InformacionTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
const char *InformacionTransferenciaObservaciones(SiscomOperaciones *pSisOpePtrDato);
const char *InformacionTransferenciaSeReflejo(SiscomOperaciones *pSisOpePtrDato);
const char *InformacionTransferenciaImporte(SiscomOperaciones *pSisOpePtrDato);
const char *InformacionTransferenciaTelefono(SiscomOperaciones *pSisOpePtrDato);


SiscomRegistroProL *InformacionTarjeta(SiscomOperaciones *pSiscomOpePtrDato);
const char *InformacionTarjetaObservaciones(SiscomOperaciones *pSisOpePtrDato);
const char *InformacionTarjetaImporte(SiscomOperaciones *pSisOpePtrDato);

SiscomRegistroProL *InformacionRegistroApartado(SiscomOperaciones *);
const char *InformacionApartadoPorPagar(SiscomOperaciones *);

const char *InformacionOrdenConCuantoPaga(SiscomOperaciones *);

SiscomRegistroProL *OrdenCompraEnvio(SiscomOperaciones *);
SiscomRegistroProL *FormaPagoEnvio(SiscomOperaciones *);

const char *ValorValidoFormaPagoTarjeta(SiscomOperaciones *pSisOpePtrDato,
				 const char *pchrPtrCampo,
				 const char *pchrPtrQPongo);

const char *ValorValidoFormaPagoTransferencia(SiscomOperaciones *pSisOpePtrDato,
				 const char *pchrPtrCampo,
				 const char *pchrPtrQPongo);

int SePagaraConTransferencia(SiscomOperaciones *pSiscomOpePtrDato);
int SePagaraConTarjeta(SiscomOperaciones *pSiscomOpePtrDato);
int SePagaraConEfectivo(SiscomOperaciones *pSiscomOpePtrDato);

int PagoApartadoEfectivo(SiscomOperaciones *pSiscomOpePtrDato);

int CerrandoApartado(SiscomOperaciones *pSisOpePtrDatos);

int AdelantoPagadoEfectivo(SiscomOperaciones *pSIsOpePtrDato);
int PagandoCierreConEfectivo(SiscomOperaciones *pSisOpePtrDato);


#endif
