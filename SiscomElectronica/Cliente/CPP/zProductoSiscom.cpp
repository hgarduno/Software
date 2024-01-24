#include <zProductoSiscom.h>
#include <zSiscomCampo.h>

#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>
zProductoSiscom::zProductoSiscom(zSiscomRegistro *pzSisRegistro):
			zProducto(pzSisRegistro),
			intNoAlcanza(0)
{
 (*this)				<< 
 new zSiscomCampo("CantidadAComprar") 	<< 
 new zSiscomCampo("IdCompra");
}
void zProductoSiscom::CantidadAComprar(const char *pchrPtrCantidadAComprar)
{
 ActualizaCampo("CantidadAComprar",(const unsigned char *)pchrPtrCantidadAComprar);
}
void zProductoSiscom::IdCompra(const char *pchrPtrIdCompra)
{
 ActualizaCampo("IdCompra",(const unsigned char *)pchrPtrIdCompra);
}
void zProductoSiscom::ActualizaProductos(zSiscomRegistros *pzSisRegsProductos)
{
    ActualizaCampo("Productos",pzSisRegsProductos);
}
void zProductoSiscom::NoAlcanza(int pintNoAlcanza)
{
 intNoAlcanza=pintNoAlcanza;
}
int zProductoSiscom::NoAlcanza()
{
   return intNoAlcanza;
}
int zProductoSiscom::SiAlcanzaProdDefinicion()
{
zSiscomRegistro *lzSisRegNoAlcanza;
lzSisRegNoAlcanza=zSisRegProdDefActual->AsociadoDelCampo("NoAlcanza");
   return zSisRegProdDefActual->EstaElCampoEnElRegistro("NoAlcanza");
}

int zProductoSiscom::PrimerProdDefinicion()
{
     zSisRegProdDefActual=DefinicionProducto()->Primer();
     return zSisRegProdDefActual ? 1 : 0;
}
int zProductoSiscom::SiguienteProdDefinicion()
{
     zSisRegProdDefActual=DefinicionProducto()->Siguiente();
     SiscomRegistroLog2(zSisRegProdDefActual);
     return zSisRegProdDefActual ? 1 :0 ;
}
const char *zProductoSiscom::NoAlcanzaAComprar()
{
zSiscomRegistro *lzSisRegProducto;
 if((lzSisRegProducto=zSisRegProdDefActual->AsociadoDelCampo("NoAlcanza")))
    return (const char *)lzSisRegProducto->Campo("AComprar");
 else
    return 0;
}

const char *zProductoSiscom::NoAlcanzaExistencia()
{
zSiscomRegistro *lzSisRegProducto;
 if((lzSisRegProducto=zSisRegProdDefActual->AsociadoDelCampo("NoAlcanza")))
    return (const char *)lzSisRegProducto->Campo("Existencia");
 else
    return 0;
}
const char *zProductoSiscom::ClaveProdDef()
{
	return (const char *)zSisRegProdDefActual->Campo("cveproducto");
}

const char *zProductoSiscom::CantidadProdDef()
{
	return (const char *)zSisRegProdDefActual->Campo("cantidad");
}

void zProductoSiscom::AgregaOrigenDefinicion()
{
zSiscomRegistro *lzSisRegProductoDef;
for(lzSisRegProductoDef=DefinicionProducto()->Primer();
    lzSisRegProductoDef;
    lzSisRegProductoDef=DefinicionProducto()->Siguiente())
  (*lzSisRegProductoDef) << 
  new zSiscomCampo("Origen",(const unsigned char *)"Bodega");
}

void ProductoSiscom(const char *pchrPtrArchivo,
                    const char *pchrPtrFuncion,
                    int pintNoLinea,
                    zProductoSiscom *pzProdSiscom)
{
zSiscomRegistro *lzSisRegProducto;
zSiscomRegistros *lzSisRegsDefProducto;
zSiscomDesarrollo4::Log(pchrPtrArchivo,pchrPtrFuncion,pintNoLinea,"%s",pzProdSiscom->Clave());
lzSisRegsDefProducto=pzProdSiscom->AsociadosDelCampo("Productos");
for(lzSisRegProducto=lzSisRegsDefProducto->Primer();
    lzSisRegProducto;
    lzSisRegProducto=lzSisRegsDefProducto->Siguiente())
{
  
}
}
