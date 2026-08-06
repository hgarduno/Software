#include <ZProductosInventario.h>
#include <zSiscomDesarrollo4.h>
#include <CQSisInventarioBodega.h>

ZProductosInventario::ZProductosInventario(const char *pchrPtrArchivo,
					  const char *pchrPtrIdExpendio,
					  const char *pchrPtrIdInventario,
					  const char *pchrPtrIdBodega):
					  chrPtrArchivo(pchrPtrArchivo),
					  chrPtrIdExpendio(pchrPtrIdExpendio),
					  chrPtrIdInventario(pchrPtrIdInventario),
					  intNProductosInventariados(0),
					  chrPtrIdBodega(pchrPtrIdBodega)
{
}

void ZProductosInventario::AbreArchivo()
{
if(chrPtrArchivo)
{
 if((FlePtrArchivo=fopen(chrPtrArchivo,"r")))
 {
  
 }
}
else
FlePtrArchivo=stdin;

}
void ZProductosInventario::DatosProducto(const char *pchrPtrLinea,
					char ***pchrPtrDatos)
{
zSiscomDesarrollo4::CadenasPorSeparador(pchrPtrLinea,',',pchrPtrDatos);
}
void ZProductosInventario::AgregandoProducto(const char *pchrPtrCveProducto,
					     const char *pchrPtrCantidad,
					     const char *pchrPtrIdExpendio,
					     const char *pchrPtrIdEmpleado)
{
}
void ZProductosInventario::AnexaProducto(ProductoE *pProductoE)
{
   Anexa(pProductoE);
}
void ZProductosInventario::AnexaProducto(CQSisInventarioBodega *pCQSInventarioB)
{
   Agrega(pCQSInventarioB);
}
void ZProductosInventario::LineasProducto()
{
char lchrArrLinea[128];
char *lchrPtrCveProducto,*lchrPtrCantidad;
IniciaProductos();
	while(!zSiscomDesarrollo4::LeeLinea(FlePtrArchivo,lchrArrLinea) )
	{
	  if(DatosInventario(lchrArrLinea,
	  		     &lchrPtrCveProducto,
			     &lchrPtrCantidad))
	  {
	   AgregandoProducto(lchrPtrCveProducto,
	   		     lchrPtrCantidad,
			     chrPtrIdExpendio,
			     "1386872013");
	   intNProductosInventariados++;
	  }
	}
}
int ZProductosInventario::SiCantidadInventario(const char *pchrPtrCantidad)
{
  return isdigit(*pchrPtrCantidad);
}
int ZProductosInventario::DatosInventario(const char *pchrPtrLinea,
					   char **pchrPtrCveProducto,
					   char **pchrPtrCantidad)
{
char **lchrPtrDatos;
DatosProducto(pchrPtrLinea,&lchrPtrDatos);
*pchrPtrCantidad=Cantidad(lchrPtrDatos);
if(SiCantidadInventario(*pchrPtrCantidad))
{
  *pchrPtrCveProducto=CveProducto(lchrPtrDatos);
  return 1;
  
}
else
return 0;

}
int ZProductosInventario::LineaProducto(const char *pchrPtrLinea)
{
  return strstr(pchrPtrLinea,"cveproducto") ? 1 :0;
 
}
void ZProductosInventario::IniciaProductos()
{
char lchrArrLinea[128];
    while(!zSiscomDesarrollo4::LeeLinea(FlePtrArchivo,lchrArrLinea) &&
         !LineaProducto(lchrArrLinea))
    {
    }
}

char *ZProductosInventario::Cantidad(char **pchrPtrDatos)
{
   return *(pchrPtrDatos+1);
}
char *ZProductosInventario::CveProducto(char **pchrPtrDatos)
{
  return *pchrPtrDatos;
}

void ZProductosInventario::Inicia()
{
 
}
ProductoE *ZProductosInventario::Producto(const char *pchrPtrCveProducto,
					  const char *pchrPtrCantidad,
					  const char *pchrPtrIdExpendio,
					  const char *pchrPtrIdInventario)
{
ProductoE *lProdE=new ProductoE(pchrPtrCveProducto,"","","");
lProdE->SiscomActualizaCampo("Cantidad",pchrPtrCantidad);
lProdE->SiscomActualizaCampo("IdCliente","1386872013"); // IdPersona Heli
lProdE->SiscomActualizaCampo("IdExpendio",pchrPtrIdExpendio); // Siscom Zacatenco
lProdE->SiscomActualizaCampo("NumFactura",pchrPtrIdInventario); // IdInventario 
return lProdE;
}


CQSisInventarioBodega *ZProductosInventario::Producto(
					const char *pchrPtrIdExpendio,
			       		const char *pchrPtrIdEmpleado,
					const char *pchrPtrCantidad,
					const char *pchrPtrCveProducto,
					const char *pchrPtrIdBodega)
{
return new CQSisInventarioBodega(pchrPtrIdExpendio,
				 pchrPtrIdEmpleado,
				 pchrPtrCantidad,
				 pchrPtrCveProducto,
				 pchrPtrCantidad,
				 chrPtrIdBodega);

}
const char *ZProductosInventario::IdBodega()
{
	return chrPtrIdBodega;

}
