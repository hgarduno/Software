#include <QtImprimeRepExistenciaTiendaProveedor.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionExistenciaTiendaProveedor.h>
#include <zExistenciaTiendaProveedor.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRepExistenciaTiendaProveedor::QtImprimeRepExistenciaTiendaProveedor(zSiscomConexion *pzSisConexion,
							 zImpresionExistenciaTiendaProveedor *pzImpExistenciaTiendaProveedor,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpExistenciaTiendaProveedor,
									pQWParent,
									pchrPtrName),
							zImpExistenciaTiendaProveedor(pzImpExistenciaTiendaProveedor),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeRepExistenciaTiendaProveedor::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeRepExistenciaTiendaProveedor::Reporte()
{
/*zExistenciaTiendaProveedor *lzExistenciaTiendaProveedor=zImpExistenciaTiendaProveedor->ExistenciaTiendaProveedor();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProveedor);
int lintDesplazamientoY=0;
if(lzExistenciaTiendaProveedor->PrimerProveedor())
{
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzExistenciaTiendaProveedor->Proveedor()))
    {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
    }
    lintDesplazamientoY=MuestraProductos(lintDesplazamientoY,lzExistenciaTiendaProveedor);
    lintDesplazamientoY+=2*intIncrementoY;
  }while(lzExistenciaTiendaProveedor->SiguienteProveedor());

}*/
}
/*int QtImprimeRepExistenciaTiendaProveedor::SeImprimeElCampo(zSiscomRegistro *pzSisRegPosicion)
{
   if(pzSisRegPosicion->EsElValorCampo("campo","preciogeneral"))
   	  return zImpExistenciaTiendaProveedor->ImprimePrecio();
    if(pzSisRegPosicion->EsElValorCampo("campo","importeventa"))
         return zImpExistenciaTiendaProveedor->ImprimeImporteVenta();
    else
    return 1;

}
int QtImprimeRepExistenciaTiendaProveedor::Producto(int pintDesplazamiento,
				       zSiscomRegistros *pzSisRegsCampos,
				       zSiscomRegistro *pzSisRegProducto)
{
zSiscomRegistro *lzSisRegPosicion;
int lintRegreso;
for(lzSisRegPosicion=pzSisRegsCampos->Primer();
    lzSisRegPosicion;
    lzSisRegPosicion=pzSisRegsCampos->Siguiente())
   if(SeImprimeElCampo(lzSisRegPosicion))
   lintRegreso=Texto(lzSisRegPosicion->CampoInt("x"),
    		     lzSisRegPosicion->CampoInt("y")+pintDesplazamiento,
		     lzSisRegPosicion->CampoInt("anchox"),
		     lzSisRegPosicion->CampoInt("anchoy"),
		     (const char *)(*pzSisRegProducto)[(const char *)lzSisRegPosicion->Campo("campo")]);

return lintRegreso;
}
int QtImprimeRepExistenciaTiendaProveedor::MuestraProductos(int pintDesplazamiento,
						  zExistenciaTiendaProveedor *pzExistenciaTiendaProveedor)
{
*int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[14];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");
 if(pzExistenciaTiendaProveedor->PrimerProducto())
 {
	do
	{
	   if(SeAgregaALaLista(pzExistenciaTiendaProveedor))
	   {
	   if(Producto(lintDesplazamientoY,lzSisRegsProductos,pzExistenciaTiendaProveedor->Producto()))
	   {
		NumeroPagina(&lintDesplazamientoY);
		lintDesplazamientoY=0;
	   } 
	   lintDesplazamientoY+=intIncrementoY;
	   }
		
	}while(pzExistenciaTiendaProveedor->SiguienteProducto());

 }
 lintDesplazamientoY=MuestraTotalProveedor(lintDesplazamientoY,lzSisRegsProductos,pzExistenciaTiendaProveedor);
return lintDesplazamientoY;
}
int QtImprimeRepExistenciaTiendaProveedor::MuestraTotalProveedor(int pintDesplazamiento,
						   zSiscomRegistros *pzSisRegsPosiciones,	
						    zExistenciaTiendaProveedor *pzExistenciaTiendaProveedor)
{
int lintDesplazamientoY=pintDesplazamiento;
    Texto(lintDesplazamientoY,
    	  pzSisRegsPosiciones,
	  "campo",
	  "stock",
	  "Total Proveedor");

    Texto(lintDesplazamientoY,
    	  pzSisRegsPosiciones,
	  "campo",
	  "importecosto",
	  pzExistenciaTiendaProveedor->TotalProveedor());
return lintDesplazamientoY+intIncrementoY;
}*/
void QtImprimeRepExistenciaTiendaProveedor::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesExistenciaTiendaProveedor");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionExistenciaTiendaProveedor();
}
void QtImprimeRepExistenciaTiendaProveedor::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpExistenciaTiendaProveedor);

}

/*int QtImprimeRepExistenciaTiendaProveedor::SeAgregaALaLista(zExistenciaTiendaProveedor *pzLstPrecios)
{
	return strcmp(pzLstPrecios->Stock(),"0");
}*/
