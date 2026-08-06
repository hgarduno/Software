#include <ZInventarioExpendio.h> 


ZInventarioExpendio::ZInventarioExpendio(const char *pchrPtrArchivo,
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

void ZInventarioExpendio::AgregandoProducto(const  char *pchrPtrCveProducto,
					    const char *pchrPtrCantidad,
					    const char *pchrPtrIdExpendio,
					    const char *pchrPtrIdInventario)
{
  AnexaProducto(Producto(pchrPtrCveProducto,
  			 pchrPtrCantidad,
			 pchrPtrIdExpendio,
			 pchrPtrIdInventario));
}
