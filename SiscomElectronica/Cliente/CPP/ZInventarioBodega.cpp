#include <ZInventarioBodega.h> 
#include <zSiscomDesarrollo4.h>

ZInventarioBodega::ZInventarioBodega(const char *pchrPtrArchivo,
					const char *pchrPtrIdExpendio,
					const char *pchrPtrIdInventario,
					const char *pchrPtrIdBodega):
				 ZProductosInventario(pchrPtrArchivo,
				 		     pchrPtrIdExpendio,
						     pchrPtrIdInventario,
						     pchrPtrIdBodega)
{
AbreArchivo();
LineasProducto();
}

void ZInventarioBodega::AgregandoProducto(const  char *pchrPtrCveProducto,
					    const char *pchrPtrCantidad,
					    const char *pchrPtrIdExpendio,
					    const char *pchrPtrIdInventario)
{
AnexaProducto(Producto(pchrPtrIdExpendio,
                       "1386872013", //Id Heli
                        pchrPtrCantidad,
                        pchrPtrCveProducto,
                        IdBodega()));
}
