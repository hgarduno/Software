#ifndef __ZPRODUCTOSINVENTARIO_H__
#define __ZPRODUCTOSINVENTARIO_H__
#include <stdio.h>
#include <ProductosE.h>
#include <SiscomRegistros3.h>

class CQSisInventarioBodega;
class ProductoE;
class ZProductosInventario:public ProductosE,public SiscomRegistro3Lst
{
public:
	ZProductosInventario(const char *pchrPtrArchivo,
			     const char *pchrPtrIdExpendio,
			     const char *pchrPtrIdInventario,
			     const char *pchrPtrIdBodega);

	ProductoE *Producto(const char *pchrPtrCveProducto,
			   const char *pchrPttCantidad,
			   const char *pchrPtrIdExpendio,
			   const char *pchrPtrIdInventario);

	CQSisInventarioBodega *Producto(const char *pchrPtrIdExpendio,
			       		const char *pchrPtrIdEmpleado,
					const char *pchrPtrCantidad,
					const char *pchrPtrCveProducto,
					const char *pchrPtrIdBodega);
	void AnexaProducto(ProductoE *);
	void AnexaProducto(CQSisInventarioBodega *);


	void AbreArchivo();
	void LineasProducto();
	const char *IdBodega();
private:
	FILE *FlePtrArchivo;
	const char *chrPtrArchivo;
	const char *chrPtrIdExpendio;
	const char *chrPtrIdInventario;
	const char *chrPtrIdBodega;

	int intNProductosInventariados;

private:
	void IniciaProductos();
	int LineaProducto(const char *);
	void DatosProducto(const char *,char ***);
	int SiCantidadInventario(const char *);
	int DatosInventario(const char *,
			     char **pchrPtrCveProducto,
			     char **pchrPtrCantidad);
	void Inicia();

	char *Cantidad(char **);
	char *CveProducto(char **);

	virtual void AgregandoProducto(const char *pchrPtrCveProducto,
					const char *pchrPtrCantidad,
					const char *pchrPtrIdExpendio,
					const char *pchrPtrIdEmpleado);

};
#endif
