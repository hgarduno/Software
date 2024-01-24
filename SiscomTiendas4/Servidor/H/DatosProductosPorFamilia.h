#ifndef __DATOSPRODUCTOSPORFAMILIA_H__
#define __DATOSPRODUCTOSPORFAMILIDA_H__
#include <SiscomDesarrollo2.h>

SiscomOperaciones2 *ODatosProductosPorFamilia();
void ArgumentosDatosProductos(SArgsSiscom *pSAgsSiscom);
void FormaInformacionPorProducto(SArgsSiscom *pSAgsSiscom);

void DatosProductosPorFamilia(SArgsSiscom *pSAgsSiscom);
void FormaInformacionPorProducto(SArgsSiscom *pSAgsSiscom);



void AgregaInformacionProducto(LCamposSiscomPro2 *pLCSiscomPro2Informacion,
			   LCamposSiscomPro2 *pLCSiscomPro2Producto,
			   LCamposSiscomPro2 **pLCSiscomPro2InfoProdPrim,
			   LCamposSiscomPro2 **pLCSiscomPro2InfoProdAct);
#endif
