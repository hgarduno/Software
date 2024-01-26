#include <QtImpRepPreciosProducto.h>
#include <QtImprimiendoRepPreciosProducto.h>
#include <zReportesServiSNTE.h>
#include <QCtrlTiendasEntrega.h>
#include <QCtrlProveedoresSS.h>
#include <QCtrlDepartamentosSS.h>

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
#include <zListaPrecios.h>
#include <zImpresionListaPrecios.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qmessagebox.h>
QtImpRepPreciosProducto::QtImpRepPreciosProducto(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RepPreciosProducto(pQWParent,pchrPtrName),
					   zSisRegProveedor(0)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRepPreciosProducto::IniciaVariables()
{
	QCtrTiendas->Servidor(zSisConexion);
        QCtrProveedores->Servidor(zSisConexion);
	QCtrDepartamentos->Servidor(zSisConexion);
	QCtrTiendas->IniciaControl();
        QCtrProveedores->IniciaControl();
	QCtrDepartamentos->IniciaControl();
	zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpRepPreciosProducto::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRepPreciosProducto::ConectaSlots()
{
        connect(QCtrTiendas,
            SIGNAL(SignalTienda(zSiscomRegistro *)),
            SLOT(SlotTienda(zSiscomRegistro *)));
	connect(QCtrDepartamentos,
		SIGNAL(SignalDepartamento(zSiscomRegistro *)),
		SLOT(SlotDepartamento(zSiscomRegistro *)));
        connect(QCtrProveedores,
            SIGNAL(SignalProveedor(zSiscomRegistro *)),
            SLOT(SlotProveedor(zSiscomRegistro *)));
        connect(QPBConsulta,
            SIGNAL(clicked()),
            SLOT(SlotConsulta()));
	connect(QPBImprimir,
	 	SIGNAL(clicked()),
		SLOT(SlotImprime()));
}
void QtImpRepPreciosProducto::SlotDepartamento(zSiscomRegistro *pzSisRegDepartamento)
{
     zSisRegDepartamento=pzSisRegDepartamento;
     zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpRepPreciosProducto::SlotImprime()
{
zImpresionListaPrecios *lzImpListaPrecios=new zImpresionListaPrecios(zLstPrecios,
								     "Productos Por Tienda Por Proveedor");
QtImprimiendoRepPreciosProducto lQtImpRepPreciosProd(zSisConexion,
						     lzImpListaPrecios);
}
void QtImpRepPreciosProducto::SlotConsulta()
{
	Consultando();
	zSisRegProveedor=0;	
	zSiscomQt3::Foco(QCtrTiendas);
}
void QtImpRepPreciosProducto::SlotTienda(zSiscomRegistro *pzSisRegTienda)
{
	zSisRegTienda=pzSisRegTienda;
	zSiscomQt3::Foco(QCtrDepartamentos);
}
void QtImpRepPreciosProducto::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
	zSisRegProveedor=pzSisRegProveedor;
	zSiscomQt3::Foco(QPBConsulta);
}
void QtImpRepPreciosProducto::Consultando()
{
 Consulta();
 if(zLstPrecios)
 Muestra();
 else
 QMessageBox::information(this,"Aviso del Sistema",chrPtrMensaje);
}

void QtImpRepPreciosProducto::Consulta()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"PreciosProductos");
zLstPrecios=lzRepServiSNTE.ListaPrecios(zSisRegTienda,zSisRegProveedor,&chrPtrMensaje);
}

void QtImpRepPreciosProducto::Muestra()
{
int lintContador=1;
if(zLstPrecios->PrimerDepartamento())
{
  do
  {
	QTListaPrecios->setNumRows(lintContador);
	QTListaPrecios->setText(lintContador-1,0,zLstPrecios->IdDepartamento());
	QTListaPrecios->setText(lintContador-1,1,zLstPrecios->NombreDepartamento());
	lintContador=MuestraProductosProveedor(lintContador); 
	lintContador++;
  }while(zLstPrecios->SiguienteDepartamento());
}
zSiscomQt3::AjustaColumnasTabla(QTListaPrecios);
}
int QtImpRepPreciosProducto::SeAgregaALaLista(zListaPrecios *pzLstPrecios)
{
	return strcmp(pzLstPrecios->Stock(),"0");
}
int QtImpRepPreciosProducto::MuestraProductosProveedor(int pintContador)
		
{
int lintContador=pintContador+1;
  if(zLstPrecios->PrimerProducto())
  {
	 do
	 {	
    		QTListaPrecios->setNumRows(lintContador);
		if(SeAgregaALaLista(zLstPrecios))
		{
		QTListaPrecios->setText(lintContador-1,2,zLstPrecios->Numero());
		QTListaPrecios->setText(lintContador-1,3,zLstPrecios->Nombre());
		QTListaPrecios->setText(lintContador-1,4,zLstPrecios->Modelo());
		QTListaPrecios->setText(lintContador-1,5,zLstPrecios->Stock());
		QTListaPrecios->setText(lintContador-1,6,zLstPrecios->PrecioGeneral());
	        lintContador++; 
		}
	 }while(zLstPrecios->SiguienteProducto());
  }
return lintContador-1;
}
