#include <QtImprimeRepListaPreciosComprador.h>

#include <zOperacionesServiSNTE.h> 

#include <zSiscomDesarrollo4.h>
#include <zImpresionListaPreciosComprador.h>
#include <zListaPreciosComprador.h>
#include <qprinter.h>
#include <qpainter.h>
#include <qmessagebox.h>

QtImprimeRepListaPreciosComprador::QtImprimeRepListaPreciosComprador(zSiscomConexion *pzSisConexion,
							 zImpresionListaPreciosComprador *pzImpListaPreciosComprador,
							 QWidget *pQWParent,
							 const char *pchrPtrName):
							QtImprimeReporte(pzSisConexion,
									pzImpListaPreciosComprador,
									pQWParent,
									pchrPtrName),
							zImpListaPreciosComprador(pzImpListaPreciosComprador),
							intIncrementoY(5)
{
ConsultaPosiciones();

}
void QtImprimeRepListaPreciosComprador::Imprimiendo()
{
Cabecera();
Reporte();
}
void QtImprimeRepListaPreciosComprador::Reporte()
{
zListaPreciosComprador *lzListaPreciosComprador=(zListaPreciosComprador *)zImpListaPreciosComprador->ListaPrecios();
zSiscomRegistro *lzSisRegProveedor=(*zSisRegsPosiciones)[10];
zSiscomRegistros *lzSisRegsProveedor=lzSisRegProveedor->AsociadosDelCampo("registrocampo");
SiscomRegistrosLog(lzSisRegsProveedor);
int lintDesplazamientoY=0;
if(lzListaPreciosComprador->PrimerDepartamento())
{
  do
  {
    if(Texto(lintDesplazamientoY,lzSisRegsProveedor,lzListaPreciosComprador->Departamento()))
    {
	NumeroPagina(&lintDesplazamientoY);
	lintDesplazamientoY=0;
    }
    lintDesplazamientoY=MuestraProductos(lintDesplazamientoY,lzListaPreciosComprador);
    lintDesplazamientoY+=2*intIncrementoY;
  }while(lzListaPreciosComprador->SiguienteDepartamento());

}
}
int QtImprimeRepListaPreciosComprador::MuestraProductos(int pintDesplazamiento,
						  zListaPreciosComprador *pzListaPreciosComprador)
{
int lintDesplazamientoY=pintDesplazamiento;
zSiscomRegistro *lzSisRegProducto=(*zSisRegsPosiciones)[11];
zSiscomRegistros *lzSisRegsProductos=lzSisRegProducto->AsociadosDelCampo("registrocampo");
 if(pzListaPreciosComprador->PrimerProducto())
 {
	do
	{
	   if(Texto(lintDesplazamientoY,lzSisRegsProductos,pzListaPreciosComprador->Producto()))
	   {
		NumeroPagina(&lintDesplazamientoY);
		lintDesplazamientoY=0;
	   }
	   lintDesplazamientoY+=intIncrementoY;
	}while(pzListaPreciosComprador->SiguienteProducto());

 }
return lintDesplazamientoY;
}
void QtImprimeRepListaPreciosComprador::ConsultaPosiciones()
{
zOperacionesServiSNTE lzOpServiSNTE(Conexion(),"PosicionesListaPreciosComprador");
zSisRegsPosiciones=lzOpServiSNTE.CamposImpresionListaPreciosComprador();
SiscomRegistrosLog(zSisRegsPosiciones);
}
void QtImprimeRepListaPreciosComprador::Cabecera()
{
zSiscomRegistro *lzSisRegPosiciones;

for(lzSisRegPosiciones=zSisRegsPosiciones->Primer();
    lzSisRegPosiciones;
    lzSisRegPosiciones=zSisRegsPosiciones->Siguiente())
  Texto(lzSisRegPosiciones,zImpListaPreciosComprador);
}

