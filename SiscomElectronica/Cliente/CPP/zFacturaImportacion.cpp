#include <zFacturaImportacion.h>

#include <zProductoImportado.h>
#include <zProductosImportados.h>

#include <zSiscomDesarrollo4.h>
zFacturaImportacion::zFacturaImportacion(const char *pchrPtrArchivo,
					 const char *pchrPtrIdProveedor):
					chrPtrArchivo(pchrPtrArchivo),
					chrPtrIdProveedor(pchrPtrIdProveedor)
{
   Inicia();
   if(AbreArchivo())
    ProductosImportados();

SiscomRegistrosLog(Productos());
}
int zFacturaImportacion::AbreArchivo()
{
  if((FlePtrArchivo=fopen(chrPtrArchivo,"r")))
    return 1;
  else
  return 0;
}

void zFacturaImportacion::ProductosImportados()
{
zProductoImportado *lzProdImp;
    while(!LeeLinea(&lzProdImp))
      (*zProdsImps) << lzProdImp;
}
void zFacturaImportacion::ProductoImportado(const char *pchrPtrLinea,
					    zProductoImportado **pzProdImp)
{
char **lchrPtrCampos;
char lchrArrPrecioS[15];
	*pzProdImp=new zProductoImportado;
	zSiscomDesarrollo4::CadenasPorSeparador(pchrPtrLinea,'\t',&lchrPtrCampos);
        ObtenPrecio(*(lchrPtrCampos+5),lchrArrPrecioS);
	/*
	LogSiscom("El Producto del proveedor (%s)  Cantidad(%s) Precio(%s)",
		  *(lchrPtrCampos+2),
		  *(lchrPtrCampos+4),
		  *(lchrPtrCampos+5));
	*/
	(*pzProdImp)->CveProveedor(*(lchrPtrCampos+2));
	(*pzProdImp)->Cantidad(*(lchrPtrCampos+4));
	(*pzProdImp)->CostoUnitarioDolares(lchrArrPrecioS);
	(*pzProdImp)->IdProveedor(chrPtrIdProveedor);
}
			
int zFacturaImportacion::LeeLinea(zProductoImportado **pzProdImportado)
{
char lchrArrLinea[512];
int lintRegreso;
   if(!(lintRegreso=zSiscomDesarrollo4::LeeLinea(FlePtrArchivo,lchrArrLinea)))
	ProductoImportado(lchrArrLinea,pzProdImportado);
return lintRegreso;
}
void zFacturaImportacion::ObtenPrecio(const char *pchrPtrPrecioE,
				      char *pchrPtrPrecioS)
{
  zSiscomDesarrollo4::CadenaHastaDelimitador(pchrPtrPrecioE,'$',pchrPtrPrecioS);
}
void zFacturaImportacion::Inicia()
{
   zProdsImps=new zProductosImportados;
}
zProductosImportados *zFacturaImportacion::Productos()
{
	return zProdsImps;
}
