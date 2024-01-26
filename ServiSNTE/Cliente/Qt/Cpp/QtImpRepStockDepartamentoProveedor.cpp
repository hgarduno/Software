#include <QtImpRepStockDepartamentoProveedor.h>
#include <QtImprimiendoRepStockDepartamentoProveedor.h>
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

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpRepStockDepartamentoProveedor::QtImpRepStockDepartamentoProveedor(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RepStockDepartamentoProveedor(pQWParent,pchrPtrName),
					   zSisRegProveedor(0)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRepStockDepartamentoProveedor::IniciaVariables()
{
QCtrTiendas->Servidor(zSisConexion);
QCtrProveedor->Servidor(zSisConexion);
QCtrTiendas->IniciaControl();
QCtrProveedor->IniciaControl();
zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpRepStockDepartamentoProveedor::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRepStockDepartamentoProveedor::ConectaSlots()
{
    connect(QCtrTiendas,
    	    SIGNAL(SignalTienda(zSiscomRegistro *)),
	    SLOT(SlotTienda(zSiscomRegistro *)));
    connect(QCtrProveedor,
    	    SIGNAL(SignalProveedor(zSiscomRegistro *)),
	    SLOT(SlotProveedor(zSiscomRegistro *)));
    connect(QPBImprimir,
    	    SIGNAL(clicked()),
	    SLOT(SlotImprimir()));
    connect(QPBConsulta,
	    SIGNAL(clicked()),
	    SLOT(SlotConsulta()));
}
void QtImpRepStockDepartamentoProveedor::SlotImprimir()
{
QtImprimiendoRepStockDepartamentoProveedor lQtImpRepStockDepProv(zSisConexion,zSisRegsStockProveedor);
}
void QtImpRepStockDepartamentoProveedor::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
  zSisRegProveedor=pzSisRegProveedor;
  zSiscomQt3::Foco(QPBConsulta);
}
void QtImpRepStockDepartamentoProveedor::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
   zSisRegTienda=pzSisRegTienda;
   zSiscomQt3::Foco(QCtrProveedor);
}
void QtImpRepStockDepartamentoProveedor::SlotConsulta()
{
  Consultando();
  zSisRegProveedor=0;
  zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpRepStockDepartamentoProveedor::Consultando()
{
 Consulta();
 Muestra();
}
void QtImpRepStockDepartamentoProveedor::Consulta()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"StockDepartamentoProveedor");
if((zSisRegsStockProveedor=lzRepServiSNTE.StockDepartamentoProveedor(zSisRegTienda,
								     0,
								    zSisRegProveedor)))
{


}
}
void QtImpRepStockDepartamentoProveedor::Muestra()
{
const char *lchrPtrCampos[]={"numproducto",
		       "nombreproducto",
		       "modelo",
		       "stock",
		       "costoneto",
		       "costototal",
		       "preciogeneral",
		       "totalventa",
		       "margen",
		       0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zSisRegsStockProveedor,QTReporte);
}
