#include <QtImpRepStockTienda.h>
#include <QtImprimiendoRepStockTienda.h>
#include <zReportesServiSNTE.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlProveedoresSS.h>

#include <zSiscomConexion.h>
#include <zSiscomOperaciones.h>
#include <zSiscomConexion.h>
#include <zSiscomRegistros.h>
#include <zSiscomRegistro.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomEnviaArchivo.h>
#include <zSiscomRecibeArchivo.h>
#include <zSiscomQt3.h>
#include <zSiscomCampo.h>

#include <zStockTienda.h>
#include <zImpresionStockTienda.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qradiobutton.h>
QtImpRepStockTienda::QtImpRepStockTienda(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RepStockTienda(pQWParent,pchrPtrName),
					   zSisRegProveedor(0)
{
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRepStockTienda::IniciaVariables()
{
QCtrTiendas->Servidor(zSisConexion);
QCtrTiendas->IniciaControl();
QCtrProveedores->Servidor(zSisConexion);
QCtrProveedores->IniciaControl();
zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpRepStockTienda::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRepStockTienda::ConectaSlots()
{
   connect(QCtrTiendas,
   	   SIGNAL(SignalTienda(zSiscomRegistro *)),
	   SLOT(SlotTienda(zSiscomRegistro *)));
   connect(QPBConsulta,
    	    SIGNAL(clicked()),
	    SLOT(SlotConsulta()));
   connect(QCtrProveedores,
	   SIGNAL(SignalProveedor(zSiscomRegistro *)),
	   SLOT(SlotProveedor(zSiscomRegistro *)));
   connect(QPBImprimir,
   	   SIGNAL(clicked()),
	   SLOT(SlotImprimir()));
  
}
void QtImpRepStockTienda::SlotImprimir()
{
zImpresionStockTienda *lzImpStockTienda=new zImpresionStockTienda(zLstStock);
lzImpStockTienda->ImprimePrecio(QRBPrecio->isChecked());
lzImpStockTienda->ImprimeImporteVenta(QRBImporteVenta->isChecked());
QtImprimiendoRepStockTienda lQtImpRepStocktTienda(zSisConexion,
						 lzImpStockTienda);
}
void QtImpRepStockTienda::SlotConsulta()
{
	Consultando();
	zSisRegProveedor=0;
	zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpRepStockTienda::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
   	zSisRegTienda=pzSisRegTienda;
	zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpRepStockTienda::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
   	zSisRegProveedor=pzSisRegProveedor;
	zSiscomQt3::Foco(QPBConsulta);
}
void QtImpRepStockTienda::Consultando()
{
 Consulta();
 if(zLstStock)
 Muestra();
}
void QtImpRepStockTienda::Consulta()
{
	zReportesServiSNTE lzRepServiSNTE(zSisConexion,"StockTienda");
	zLstStock=lzRepServiSNTE.StockTienda(zSisRegTienda,zSisRegProveedor );
	zLstStock->Tienda(zSisRegTienda);
}
void QtImpRepStockTienda::Muestra()
{
int lintContador=1;
if(zLstStock->PrimerProveedor())
{
  do
  {
        QTListaStock->setNumRows(lintContador);
        QTListaStock->setText(lintContador-1,0,zLstStock->NumeroProveedor());
        QTListaStock->setText(lintContador-1,1,zLstStock->RazonSocial());
        lintContador=MuestraProductosProveedor(lintContador);
	lintContador=MuestraTotalProveedor(lintContador);
        lintContador++;
  }while(zLstStock->SiguienteProveedor());

zSiscomQt3::AjustaColumnasTabla(QTListaStock);
}
}
int QtImpRepStockTienda::MuestraProductosProveedor(int pintContador)
{
int lintContador=pintContador+1;
  if(zLstStock->PrimerProducto())
 {
         do
         {
                QTListaStock->setNumRows(lintContador);
                QTListaStock->setText(lintContador-1,2,zLstStock->Numero());
                QTListaStock->setText(lintContador-1,3,zLstStock->Nombre());
                QTListaStock->setText(lintContador-1,4,zLstStock->Modelo());
		QTListaStock->setText(lintContador-1,5,zLstStock->Stock());
                QTListaStock->setText(lintContador-1,6,zLstStock->CostoNeto());
		QTListaStock->setText(lintContador-1,7,zLstStock->ImporteCosto());
		if(QRBPrecio->isChecked())
		QTListaStock->setText(lintContador-1,8,zLstStock->Precio());
		if(QRBImporteVenta->isChecked())
		QTListaStock->setText(lintContador-1,9,zLstStock->ImporteVenta());
                lintContador++;
         }while(zLstStock->SiguienteProducto());
  }
return lintContador-1;
}
int QtImpRepStockTienda::MuestraTotalProveedor(int pintContador)
{
int lintContador=pintContador+1;
	 QTListaStock->setNumRows(lintContador);
	 QTListaStock->setText(lintContador-1,5,"Total Proveedor");
	 QTListaStock->setText(lintContador-1,7,zLstStock->TotalProveedor());
return lintContador;
}

