#ifndef __FACTURAS_H__
#define __FACTURAS_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *OpFacturasComprasPorFecha();
SiscomOperaciones2 *OpDetalleFactura();
SiscomOperaciones2 *OpActualizaNumeroFactura();
SiscomOperaciones2 *OpBuscaFacturas();
SiscomOperaciones2 *OpAnexaFacturasCompras();
SiscomOperaciones2 *OpRegistraFactura();

void FacturasComprasPeriodo(SArgsSiscom *);
void ActualizaNumeroFactura(SArgsSiscom *);
void RegistrandoFactura(SArgsSiscom *pSAgsSiscom);
void GeneraDatosFactura(SArgsSiscom *pSAgsSiscom);
void ArgumentosFacturas(SArgsSiscom *);
void ArgumentosRegistraFactura(SArgsSiscom *pSAgsSiscom);
void InsercionAPersonaFisicaMoral(SArgsSiscom *pSArgsSiscom);

#endif
