#ifndef __RNCOMPRAS_H__
#define __RNCOMPRAS_H__
#include <FuncionesComunes.h>



const char *RN_Compras_ObtenFecha(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenCveProducto(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenCantidad(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenImporte(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenProveedor(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenConProveedor(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenResponsable(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenIdExpendio(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenFormaPago(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenNumFactura(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenFechaPago(StcLtaRegComSISCOM *);
const char *RN_Compras_ObtenPrecio(StcLtaRegComSISCOM *);

StcLtaRegComSISCOM *OperacionesCompras(int ,
				     const char *,
				     StcLtaRegComSISCOM *,
				     int *);



int EsRegistroCompras(char **,
			char *,
			StcLtaRegComSISCOM *,
			StcLtaRegComSISCOM **,
			int *);
void RegistraCompras(int,
			const char *,
			const char *,
			StcLtaRegComSISCOM *,
			int ,
			StcLtaRegComSISCOM **,
			int *);
void RespuestaGeneralCompras(int,
				const char *,
				int,
				StcLtaRegComSISCOM *,
				StcLtaRegComSISCOM **,
				int *);
#endif
