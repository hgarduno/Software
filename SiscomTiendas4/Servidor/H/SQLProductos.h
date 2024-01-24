#ifndef __SQLPRODUCTOS_H__
#define __SQLPRODUCTOS_H__
#include <SiscomDesarrollo2.h>


void SQLRegistraProductos(SArgsSiscom *);
void SQLRegistraFamiliaProducto(SArgsSiscom *);
void SQLActualizaProductos(SArgsSiscom *);
void SQLActualizaFamiliaProductos(SArgsSiscom *);

void SQLProductosRegistrados(SArgsSiscom *);

void SQLProductosPorFamilia(SArgsSiscom *,char *);
void SQLProductosSemejantesALaClave(SArgsSiscom *,char *);
void SQLProductosConsultaRegistrados(SArgsSiscom *,char *);

#endif
