#ifndef __SISCOMELECTRONICA_H__
#define __SISCOMELECTRONICA_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>
#include <RNVentasElectronica.h>
#include <RNPersonas.h>
#include <RNProductos.h>
#include <RNCotizaDispositivos.h>
#include <RNEscuelas.h>
#include <RNMaterias.h>
#include <RNPracticas.h>
#include <RNEmpresas.h>
#include <RNEmpleadosExpendio.h>
#include <RNDatosClienteF.h>
#include <RNInventario.h>
#include <RNCompras.h>
#include <RNFamilias.h>
#include <RNUnidades.h>
#include <RNSiscomSeguridad3Prot2.h>
#include <RNReportesVentas.h>
#include <RNTipoPrecios.h>
#include <RNTransfiereProductos.h>
#include <RNIniciaExpendio.h>
#include <VentasPorHora.h>
#include <ControladorOrdenes.h>
#include <Alumnos.h>

void SiscomProtocoloVersion4(int pintSocket);
void OperacionesSistemaGeneral(SSiscomOperaciones **);
void AsignaOperacionesVersion2(int ,
				int,
				SSiscomOperaciones2 **,
				SArgsSiscom *);
void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr);
#endif
