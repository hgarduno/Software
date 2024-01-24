#ifndef __PRODUCTOS_H__
#define __PRODUCTOS_H__
#include <SiscomDesarrollo2.h>
SiscomOperaciones2 *OperacionesProductos();
SiscomOperaciones2 *ProductosRegistrados();
SiscomOperaciones2 *OperacionesActualizaProductos();

void RegistraProducto(SArgsSiscom *);
void CambiaMayusculasClave(SArgsSiscom *);
void ArgumentosProductos(SArgsSiscom *);
void GeneraIdProducto(SArgsSiscom *);

#endif
