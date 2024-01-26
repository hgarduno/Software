#include <QtImprimeRepCuentasPagar.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionCuentasPagar.h>
#include <zCuentasPagar.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRepCuentasPagar::QtImprimeRepCuentasPagar(zSiscomConexion *pzSisConexion,
							 zImpresionCuentasPagar *pzImpCuentasPagar,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpCuentasPagar,
									pQWParent,
									pchrPtrName),
							zImpCuentasPagar(pzImpCuentasPagar),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeRepCuentasPagar::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeRepCuentasPagar::Reporte()
{
/*zCuentasPagar *lzCuentasPagar=zImpCuentasPagar->CuentasPagar();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProveedor);
int lintDesplazamientoY=0;
if(lzCuentasPagar->PrimerProveedor())
{
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzCuentasPagar->Proveedor()))
    {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
    }
    lintDesplazamientoY=MuestraProductos(lintDesplazamientoY,lzCuentasPagar);
    lintDesplazamientoY=MuestraTotalProveedor(lintDesplazamientoY,
	   					     lzSisRegsProveedor,
						     lzCuentasPagar);
    lintDesplazamientoY+=2*intIncrementoY;
  }while(lzCuentasPagar->SiguienteProveedor());

}*/
}
/*int QtImprimeRepCuentasPagar::MuestraProductos(int pintDesplazamiento,
						  zCuentasPagar *pzCuentasPagar)
{
int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");
 if(pzCuentasPagar->PrimerProducto())
 {
	do
	{
	   if(SeAgregaALaLista(pzCuentasPagar))
	   {
	   if(Texto(lintDesplazamientoY,lzSisRegsProductos,pzCuentasPagar->Producto()))
	   {
		NumeroPagina(&lintDesplazamientoY);
		lintDesplazamientoY=0;
	   }
	   lintDesplazamientoY+=intIncrementoY;
	   }
		
	}while(pzCuentasPagar->SiguienteProducto());

 }
return lintDesplazamientoY;
}
int QtImprimeRepCuentasPagar::MuestraTotalProveedor(int pintDesplazamiento,
						   zSiscomRegistros *pzSisRegsPosiciones,	
						    zCuentasPagar *pzCuentasPagar)
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
	  pzCuentasPagar->TotalProveedor());
return lintDesplazamientoY+intIncrementoY;
}*/
void QtImprimeRepCuentasPagar::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesCuentasPagar");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionCuentasPagar();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeRepCuentasPagar::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpCuentasPagar);

}

/*int QtImprimeRepCuentasPagar::SeAgregaALaLista(zCuentasPagar *pzLstPrecios)
{
	return strcmp(pzLstPrecios->Stock(),"0");
}*/
