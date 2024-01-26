#include <QtImpRepStockProveedorCosto.h>
#include <QtImprimiendoRepStockProveedorCosto.h>
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
#include <zImpresionStockProveedorCosto.h>
#include <zExistenciaProveedor.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qtable.h>
QtImpRepStockProveedorCosto::QtImpRepStockProveedorCosto(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RepStockProveedorCosto(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRepStockProveedorCosto::IniciaVariables()
{
	QCtrProveedores->Servidor(zSisConexion);
	QCtrProveedores->IniciaControl();
	zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpRepStockProveedorCosto::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRepStockProveedorCosto::ConectaSlots()
{
	connect(QCtrProveedores,
		SIGNAL(SignalProveedor(zSiscomRegistro *)),
		SLOT(SlotProveedor(zSiscomRegistro *)));
	connect(QPBConsulta,
		SIGNAL(clicked()),
		SLOT(SlotConsulta()));
	connect(QPBImprimir,
		SIGNAL(clicked()),
		SLOT(SlotImprimir()));
}
void QtImpRepStockProveedorCosto::SlotImprimir()
{
zImpresionStockProveedorCosto *lzImpStockProveedorCosto=new zImpresionStockProveedorCosto((zStockProveedorCosto *)zExiProveedor);
QtImprimiendoRepStockProveedorCosto lQtImpRepPreciosProd(zSisConexion,
						     lzImpStockProveedorCosto);
}
void QtImpRepStockProveedorCosto::SlotConsulta()
{
	Consultando();
}
void QtImpRepStockProveedorCosto::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
	zSisRegProveedor=pzSisRegProveedor;
	zSiscomQt3::Foco(QPBConsulta);
	SiscomRegistroLog2(pzSisRegProveedor);	
	LogSiscom("el id del proveedor es %s",(*pzSisRegProveedor)["idempresa"]);
	LogSiscom("el nombre del proveedor es %s",(*pzSisRegProveedor)["razonsocial"]);
}
void QtImpRepStockProveedorCosto::Consultando()
{
QTExistenciaProveedor->setNumCols(5);
Consulta();
Muestra();
}
void QtImpRepStockProveedorCosto::Consulta()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,
				  "ExistenciasProveedor");
zExiProveedor=lzRepServiSNTE.ExistenciaProveedor(zSisRegProveedor);
}
void QtImpRepStockProveedorCosto::Muestra()
{
int lintContador=1;
if(zExiProveedor->PrimerProducto())
{
AgregaColumnasTiendas();
	do 
	{
	  QTExistenciaProveedor->setNumRows(lintContador);
	  QTExistenciaProveedor->setText(lintContador-1,0,zExiProveedor->NumeroProducto());
	  QTExistenciaProveedor->setText(lintContador-1,1,zExiProveedor->NombreProducto());
	  QTExistenciaProveedor->setText(lintContador-1,2,zExiProveedor->Modelo());
	  QTExistenciaProveedor->setText(lintContador-1,3,zExiProveedor->CostoTotal());
	  QTExistenciaProveedor->setText(lintContador-1,4,zExiProveedor->TotalStock());
	  MuestraStockPorTienda(lintContador-1);
	  lintContador++;
	}while(zExiProveedor->SiguienteProducto());

}
zSiscomQt3::AjustaColumnasTabla(QTExistenciaProveedor);
}
void QtImpRepStockProveedorCosto::AgregaColumnasTiendas()
{
int lintContador;
QTExistenciaProveedor->setNumCols(QTExistenciaProveedor->numCols()+
				 zExiProveedor->NTiendas()); 

int lintColumna=5;
if(zExiProveedor->PrimerTienda())
{
      do
      {
	  QTExistenciaProveedor->horizontalHeader()->setLabel(lintColumna,zExiProveedor->Siglas());
	  lintColumna++;
      }while(zExiProveedor->SiguienteTienda());
}
}
void QtImpRepStockProveedorCosto::MuestraStockPorTienda(int pintContador)
{
int lintColumna=5;
if(zExiProveedor->PrimerTienda())
{
      do
      {
	  QTExistenciaProveedor->setText(pintContador,
	  				 lintColumna, 
					 zExiProveedor->Stock());
	  lintColumna++;
      }while(zExiProveedor->SiguienteTienda());
}
}
