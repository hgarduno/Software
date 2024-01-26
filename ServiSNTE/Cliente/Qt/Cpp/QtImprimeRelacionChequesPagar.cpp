#include <QtImprimeRelacionChequesPagar.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionRelacionChequesPagar.h>
#include <zRelacionChequesPagar.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRelacionChequesPagar::QtImprimeRelacionChequesPagar(zSiscomConexion *pzSisConexion,
							 zImpresionRelacionChequesPagar *pzImpRelacionChequesPagar,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpRelacionChequesPagar,
									pQWParent,
									pchrPtrName),
							zImpRelacionChequesPagar(pzImpRelacionChequesPagar),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeRelacionChequesPagar::Imprimiendo()
{
Cabecera();
//Reporte();
}
void QtImprimeRelacionChequesPagar::Reporte()
{
/*zRelacionChequesPagar *lzRelacionChequesPagar=zImpRelacionChequesPagar->RelacionChequesPagar();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProveedor);
int lintDesplazamientoY=0;
if(lzRelacionChequesPagar->PrimerProveedor())
{
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzRelacionChequesPagar->Proveedor()))
    {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
    }
    lintDesplazamientoY=MuestraProductos(lintDesplazamientoY,lzRelacionChequesPagar);
    lintDesplazamientoY=MuestraTotalProveedor(lintDesplazamientoY,
	   					     lzSisRegsProveedor,
						     lzRelacionChequesPagar);
    lintDesplazamientoY+=2*intIncrementoY;
  }while(lzRelacionChequesPagar->SiguienteProveedor());

}*/
}
/*int QtImprimeRelacionChequesPagar::MuestraProductos(int pintDesplazamiento,
						  zRelacionChequesPagar *pzRelacionChequesPagar)
{
int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[13];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");
 if(pzRelacionChequesPagar->PrimerProducto())
 {
	do
	{
	   if(SeAgregaALaLista(pzRelacionChequesPagar))
	   {
	   if(Texto(lintDesplazamientoY,lzSisRegsProductos,pzRelacionChequesPagar->Producto()))
	   {
		NumeroPagina(&lintDesplazamientoY);
		lintDesplazamientoY=0;
	   }
	   lintDesplazamientoY+=intIncrementoY;
	   }
		
	}while(pzRelacionChequesPagar->SiguienteProducto());

 }
return lintDesplazamientoY;
}
*/
/*int QtImprimeRelacionChequesPagar::MuestraTotalProveedor(int pintDesplazamiento,
						   zSiscomRegistros *pzSisRegsPosiciones,	
						    zRelacionChequesPagar *pzRelacionChequesPagar)
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
	  pzRelacionChequesPagar->TotalProveedor());
return lintDesplazamientoY+intIncrementoY;
}*/
void QtImprimeRelacionChequesPagar::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesRelacionChequesPagar");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionRelacionChequesPagar();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeRelacionChequesPagar::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpRelacionChequesPagar);

}

/*int QtImprimeRelacionChequesPagar::SeAgregaALaLista(zRelacionChequesPagar *pzLstPrecios)
{
	return strcmp(pzLstPrecios->Stock(),"0");
}*/
