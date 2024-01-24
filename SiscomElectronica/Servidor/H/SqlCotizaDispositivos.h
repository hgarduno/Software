#ifndef __SQLCOTIZADISPOSITIVOS_H__
#define __SQLCOTIZADISPOSITIVOS_H__
#include <SiscomDesarrollo2.h>
/* Lunes 16 de Noviembre del 2015
 * Con la integracion de los Tipos de producto
 * se agrego la manejo de la informacion 
 * mediante el manejo de la version 2, en la 
 * cotizacion de los productos
 */

void SqlDefinicionTipoProducto(const char *pchrPtrIdExpendio,
			       const char *pchrPtrSql,
			       SArgsSiscom *pSAgsSiscom);
void SqlDatosBaseRegistroEntrada(const char *pchrPtrIdExpendio,
				 const char *pchrPtrSql,
				 SArgsSiscom *pSAgsSiscom);

void SqlDefinicionProductoSiscom(const char *pchrPtrCveProducto,
			 	SArgsSiscom *pSAgsSiscom);
void SqlRegistraFaltante(SArgsSiscom *pSAgsSiscom);
void SqlInsertandoDetalleFaltante(SArgsSiscom *pSAgsSiscom);
void SqlIncrementaVecesPedido(SArgsSiscom *pSAgsSiscom);

void SqlInsertIntoFaltantes(SArgsSiscom *pSAgsSiscom,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    char *pchrPtrSql);
void SqlInsertIntoDetalleFaltante(SArgsSiscom *pSAgsSiscom,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    char *pchrPtrSql);
void SqlUpdateVecesFaltantes(SArgsSiscom *pSAgsSiscom,
			    LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    char *pchrPtrSql);

void SqlFaltanteProducto(const char *pchrPtrCveProducto,SArgsSiscom *pSAgsSiscom);
#endif
