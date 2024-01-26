#include <QtImpRepExistenciaProveedor.h>
#include <QtImprimiendoRepExistenciaProveedor.h>
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
#include <zExistenciaProveedor.h>
#include <zImpresionExistenciaProveedor.h>

#include <zOperacionesServiSNTE.h>
#include <qpushbutton.h>
#include <qtable.h>
QtImpRepExistenciaProveedor::QtImpRepExistenciaProveedor(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RepExistenciaProveedor(pQWParent,pchrPtrName)
{
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRepExistenciaProveedor::IniciaVariables()
{
QCtrProveedores->Servidor(zSisConexion);
QCtrProveedores->IniciaControl();

zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpRepExistenciaProveedor::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRepExistenciaProveedor::ConectaSlots()
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
void QtImpRepExistenciaProveedor::SlotImprimir()
{
zImpresionExistenciaProveedor *lzImpExiProveedor=new zImpresionExistenciaProveedor(zExiProveedor);
QtImprimiendoRepExistenciaProveedor *lQtImpRepExistenciaProveedor;
lQtImpRepExistenciaProveedor=new QtImprimiendoRepExistenciaProveedor(zSisConexion,lzImpExiProveedor);
}
void QtImpRepExistenciaProveedor::SlotConsulta()
{
Consultando();
}
void QtImpRepExistenciaProveedor::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
	zSisRegProveedor=pzSisRegProveedor;
	zSiscomQt3::Foco(QPBConsulta);	
}
void QtImpRepExistenciaProveedor::Consultando()
{
  Consulta();
  Muestra();
  zSiscomQt3::AjustaColumnasTabla(QTExistenciaProveedor);
}
void QtImpRepExistenciaProveedor::Consulta()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,
				  "ExistenciasProveedor");
zExiProveedor=lzRepServiSNTE.ExistenciaProveedor(zSisRegProveedor);
zExiProveedor->Proveedor(zSisRegProveedor);
}
void QtImpRepExistenciaProveedor::Muestra()
{
int lintContador=1;
if(zExiProveedor->PrimerProducto())
{
	do 
	{
	  QTExistenciaProveedor->setNumRows(lintContador);
	  QTExistenciaProveedor->setText(lintContador-1,0,zExiProveedor->NumeroProducto());
	  QTExistenciaProveedor->setText(lintContador-1,1,zExiProveedor->NombreProducto());
	  QTExistenciaProveedor->setText(lintContador-1,2,zExiProveedor->Modelo());
	  lintContador=MuestraExistenciaTienda(lintContador); 
	  lintContador=MuestraTotalExistencia(lintContador); 
	  lintContador++;
	}while(zExiProveedor->SiguienteProducto());

}
}
int QtImpRepExistenciaProveedor::MuestraExistenciaTienda(int pintContador)
{
int lintContador=pintContador+1;
 if(zExiProveedor->PrimerTienda())
 {
	do
	{	
		QTExistenciaProveedor->setNumRows(lintContador);
		QTExistenciaProveedor->setText(lintContador-1,3,zExiProveedor->IdTienda());
		QTExistenciaProveedor->setText(lintContador-1,4,zExiProveedor->Nombre());
		QTExistenciaProveedor->setText(lintContador-1,5,zExiProveedor->Stock());
		QTExistenciaProveedor->setText(lintContador-1,6,zExiProveedor->Existencia());
		lintContador++;
	}while(zExiProveedor->SiguienteTienda());
 }
return lintContador-1;
}
int QtImpRepExistenciaProveedor::MuestraStockExistencia(int pintContador)
{
       	QTExistenciaProveedor->setNumRows(pintContador);
	QTExistenciaProveedor->setText(pintContador,5,zExiProveedor->Stock());
	QTExistenciaProveedor->setText(pintContador,6,zExiProveedor->Existencia());
	return pintContador+1;
}
int QtImpRepExistenciaProveedor::MuestraTotalExistencia(int pintContador)
{
       	QTExistenciaProveedor->setNumRows(pintContador+1);
	QTExistenciaProveedor->setText(pintContador,4,"Total Producto");
	QTExistenciaProveedor->setText(pintContador,5,zExiProveedor->TotalStock());
	QTExistenciaProveedor->setText(pintContador,6,zExiProveedor->TotalExistencia());
	return pintContador+1;
}
