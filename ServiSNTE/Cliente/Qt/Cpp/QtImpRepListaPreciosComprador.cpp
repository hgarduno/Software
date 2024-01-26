#include <QtImpRepListaPreciosComprador.h>
#include <QtImprimiendoRepListaPreciosComprador.h>
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
#include <zImpresionListaPreciosComprador.h>
#include <zListaPreciosComprador.h>
#include <zListaPrecios.h>
#include <qpushbutton.h>
#include <qtextedit.h>
#include <qtable.h>
#include <qmessagebox.h>

QtImpRepListaPreciosComprador::QtImpRepListaPreciosComprador(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RepListaPreciosComprador(pQWParent,pchrPtrName),
					   zSisRegProveedor(0)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRepListaPreciosComprador::IniciaVariables()
{
        QCtrProveedores->Servidor(zSisConexion);
        QCtrProveedores->IniciaControl();
	zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpRepListaPreciosComprador::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRepListaPreciosComprador::ConectaSlots()
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
void QtImpRepListaPreciosComprador::SlotImprimir()
{
zImpresionListaPreciosComprador *lzImpListaPreciosComprador;
lzImpListaPreciosComprador=new zImpresionListaPreciosComprador((zListaPreciosComprador *)zLstPrecios);
QtImprimiendoRepListaPreciosComprador lQtImpRepStocktTienda(zSisConexion,
							    lzImpListaPreciosComprador);
}
void QtImpRepListaPreciosComprador::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
        zSisRegProveedor=pzSisRegProveedor;
        zSiscomQt3::Foco(QPBConsulta);
}

void QtImpRepListaPreciosComprador::SlotConsulta()
{
	Consulta();
	if(zLstPrecios)
	{
	Muestra();
	zSisRegProveedor=0;
	zSiscomQt3::Foco(QCtrProveedores);	
	}
	else
	{
	zSiscomQt3::Foco(QCtrProveedores);
	QMessageBox::information(this,"Aviso del Sistema",chrPtrMensaje);
	}
}

void QtImpRepListaPreciosComprador::Consulta()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"PreciosProductosComprador");
zLstPrecios=lzRepServiSNTE.ListaPreciosComprador(zSisRegProveedor,&chrPtrMensaje);
}

void QtImpRepListaPreciosComprador::Muestra()
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

int QtImpRepListaPreciosComprador::MuestraProductosProveedor(int pintContador)
{
int lintContador=pintContador+1;
  if(zLstPrecios->PrimerProducto())
  {
         do
         {
                QTListaPrecios->setNumRows(lintContador);
                QTListaPrecios->setText(lintContador-1,2,zLstPrecios->Numero());
                QTListaPrecios->setText(lintContador-1,3,zLstPrecios->Nombre());
                QTListaPrecios->setText(lintContador-1,4,zLstPrecios->Modelo());
                QTListaPrecios->setText(lintContador-1,5,zLstPrecios->PrecioGeneral());
                lintContador++;
         }while(zLstPrecios->SiguienteProducto());
  }
return lintContador-1;
}
