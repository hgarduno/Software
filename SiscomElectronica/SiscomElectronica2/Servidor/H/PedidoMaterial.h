#ifndef __PEDIDOMATERIAL_H___
#define __PEDIDOMATERIAL_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OpRecibePedidoMaterial();
SiscomOperaciones2 *OpRegistraPedidoMaterial();
SiscomOperaciones2 *OpPedidosExpendios();
SiscomOperaciones2 *OpActualizaEstadoPedido();
SiscomOperaciones2 *OpActualizaCantidadProductoPedido();
SiscomOperaciones2 *OpImprimePedido();
SiscomOperaciones2 *OpValidaExistenciaExpendio();
void RegistraRecibePedido(SArgsSiscom *pSAgsSiscom);
SiscomOperaciones2 *OpPedidosPendientesPorEnviarAMatriz();
SiscomOperaciones2 *OpDetallePedidoPendientePorEnviarAMatriz();
SiscomOperaciones2 *OpEnviaPedidoPendientePorEnviarAMatriz();


void RegistraPedidoMaterialExpendio(SArgsSiscom *pSAgsSiscom);
void RegistraPedidoMaterialMatriz(SArgsSiscom *pSAgsSiscom);
void ArgumentosRecibePedido(SArgsSiscom *pSAgsSiscom);
void ArgumentosPedidoMaterial(SArgsSiscom *pSAgsSiscom);
void ArgumentosPedidosExpendios(SArgsSiscom *pSAgsSiscom);
void ArgumentosActualizaEstado(SArgsSiscom *pSAgsSiscom);
void ArgumentosImprimePedido(SArgsSiscom *pSAgsSiscom);
void ArgumentosPedidosPendientes(SArgsSiscom *pSAgsSiscom);
void GeneraIdPedidoMaterial(SArgsSiscom *pSAgsSiscom);
void DatosRecibePedidoEstadoPedido(SArgsSiscom *pSAgsSiscom);
void EnviaPedidosExpendios(SArgsSiscom *pSAgsSiscom);
void EnviaActualizaEstadoPedido(SArgsSiscom *pSAgsSiscom);
void EnviaActualizaCantidadProductoPedido(SArgsSiscom *pSAgsSiscom);
void ImprimePedido(SArgsSiscom *pSAgsSiscom);
void ValidaExistenciaExpendio(SArgsSiscom *pSAgsSiscom);
void FormaInsercionesPedidoPendientePorEnviarAMatriz(SArgsSiscom *pSAgsSiscom);
void RegistraPedidoPendienteMatriz(SArgsSiscom *pSAgsSiscom);
void EncabezadoImprimePedido(SArgsSiscom *pSAgsSiscom,
		char *pchrPtrTexto);
void ArchivoTemporalImprimePedido(const char *pchrPtrNoOrden,
		     const char *pchrPtrTexto,
		     char *pchrPtrArchivo);
char *TextoImpresionPedido(SArgsSiscom *pSAgsSiscom,
		     int *pintPtrTamBuffer);
void EjecutaComandoImpresionPedido(const char *pchrPtrNoOrden,
			     const char *pchrPtrTexto,
			     int pintTamBuffer);

void EnviaEstadoConexionALaMatriz(const char *pchrPtrEstado,
				  const char *pchrPtrMensaje,
				  SArgsSiscom *pSAgsSiscom);
void ActualizaEstadoPedido(const char *pchrPtrIdEstado,
			   SArgsSiscom *pSAgsSiscom);
#endif
