#ifndef __RNVENTAS_H__
#define __RNVENTAS_H__
#include <FuncionesComunes.h>

#define RN_Venta_IdExpendio			3	
#define RN_Venta_Producto			5
#define RN_Venta_Cantidad			6
#define RN_Venta_Importe			8
#define RN_Venta_Precio				7
#define RN_Venta_Vendedor			1
#define RN_Venta_Cliente			2
#define RN_Venta_ImporteOrden			4
#define RN_Venta_EdoRegistro			9


const char *ObtenEdoRegistroVenta(char **);
const char *ObtenIdExpendioVenta(char **);
const char *ObtenProductoVenta(char **);
const char *ObtenCantidadVenta(char **);
const char *ObtenImporteVenta(char **);
const char *ObtenImporteOrdenVenta(char **);
const char *ObtenPrecioVenta(char **);
const char *ObtenVendedorVenta(char **);
const char *ObtenClienteVenta(char **);

StcLtaRegComSISCOM *RegistraVenta(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ConsultaVenta(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *GeneraRespuestaVenta(int *);


#endif
