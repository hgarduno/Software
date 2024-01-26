#include <QtImprimeSoporteTransferencias.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionSoporteTransferencias.h>
#include <zSoporteTransferencias.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeSoporteTransferencias::QtImprimeSoporteTransferencias(zSiscomConexion *pzSisConexion,
							 zImpresionSoporteTransferencias *pzImpSoporteTransferencias,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpSoporteTransferencias,
									pQWParent,
									pchrPtrName),
							zImpSoporteTransferencias(pzImpSoporteTransferencias),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeSoporteTransferencias::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeSoporteTransferencias::Reporte()
{
/*zSoporteTransferencias *lzSoporteTransferencias=zImpSoporteTransferencias->SoporteTransferencias();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProveedor);
int lintDesplazamientoY=0;
if(lzSoporteTransferencias->PrimerProveedor())
{
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzSoporteTransferencias->Proveedor()))
    {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
    }
    lintDesplazamientoY=MuestraProductos(lintDesplazamientoY,lzSoporteTransferencias);
    lintDesplazamientoY+=2*intIncrementoY;
  }while(lzSoporteTransferencias->SiguienteProveedor());

}*/
}
/*int QtImprimeSoporteTransferencias::SeImprimeElCampo(zSiscomRegistro *pzSisRegPosicion)
{
   if(pzSisRegPosicion->EsElValorCampo("campo","preciogeneral"))
   	  return zImpSoporteTransferencias->ImprimePrecio();
    if(pzSisRegPosicion->EsElValorCampo("campo","importeventa"))
         return zImpSoporteTransferencias->ImprimeImporteVenta();
    else
    return 1;

}
int QtImprimeSoporteTransferencias::Producto(int pintDesplazamiento,
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
int QtImprimeSoporteTransferencias::MuestraProductos(int pintDesplazamiento,
						  zSoporteTransferencias *pzSoporteTransferencias)
{
*int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[14];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");
 if(pzSoporteTransferencias->PrimerProducto())
 {
	do
	{
	   if(SeAgregaALaLista(pzSoporteTransferencias))
	   {
	   if(Producto(lintDesplazamientoY,lzSisRegsProductos,pzSoporteTransferencias->Producto()))
	   {
		NumeroPagina(&lintDesplazamientoY);
		lintDesplazamientoY=0;
	   } 
	   lintDesplazamientoY+=intIncrementoY;
	   }
		
	}while(pzSoporteTransferencias->SiguienteProducto());

 }
 lintDesplazamientoY=MuestraTotalProveedor(lintDesplazamientoY,lzSisRegsProductos,pzSoporteTransferencias);
return lintDesplazamientoY;
}
int QtImprimeSoporteTransferencias::MuestraTotalProveedor(int pintDesplazamiento,
						   zSiscomRegistros *pzSisRegsPosiciones,	
						    zSoporteTransferencias *pzSoporteTransferencias)
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
	  pzSoporteTransferencias->TotalProveedor());
return lintDesplazamientoY+intIncrementoY;
}*/
void QtImprimeSoporteTransferencias::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesSoporteTransferencias");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionSoporteTransferencias();
}
void QtImprimeSoporteTransferencias::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpSoporteTransferencias);

}

/*int QtImprimeSoporteTransferencias::SeAgregaALaLista(zSoporteTransferencias *pzLstPrecios)
{
	return strcmp(pzLstPrecios->Stock(),"0");
}*/
