#include <QtImpRepCompras.h>
#include <QtImprimiendoRepDatosCompra.h>
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

#include <zReportesServiSNTE.h>
#include <QCtrlProveedoresSS.h>
#include <QCtrlDepartamentosSS.h>

#include <zDatosCompra.h>
#include <zImpresionDatosCompra.h>
#include <qpushbutton.h>
#include <qtextedit.h>
QtImpRepCompras::QtImpRepCompras(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RepCompras(pQWParent,pchrPtrName)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRepCompras::IniciaVariables()
{
        QCtrProveedores->Servidor(zSisConexion);
        QCtrProveedores->IniciaControl();
	QCtrDepartamentos->Servidor(zSisConexion);
	QCtrDepartamentos->IniciaControl();
        zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpRepCompras::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRepCompras::ConectaSlots()
{
	connect(QCtrProveedores,
		SIGNAL(SignalProveedor(zSiscomRegistro *)),
		SLOT(SlotProveedor(zSiscomRegistro *)));
	connect(QCtrDepartamentos,
		SIGNAL(SignalDepartamento(zSiscomRegistro *)),
		SLOT(SlotDepartamento(zSiscomRegistro *)));
	connect(QPBImprimir,
		SIGNAL(clicked()),
		SLOT(SlotImprimir()));
}
void QtImpRepCompras::SlotImprimir()
{
zImpresionDatosCompra *lzImpDatCompra=new zImpresionDatosCompra(zDatCompra);
lzImpDatCompra->Departamento(zSisRegDepartamento);
QtImprimiendoRepDatosCompra *lQtImpRepDatCompra;
lQtImpRepDatCompra=new QtImprimiendoRepDatosCompra(zSisConexion,
						  lzImpDatCompra);
}
void QtImpRepCompras::SlotProveedor(zSiscomRegistro *pzSisRegProveedor)
{
	zSisRegProveedor=pzSisRegProveedor;
	zSiscomQt3::Foco(QCtrDepartamentos);
}

void QtImpRepCompras::SlotDepartamento(zSiscomRegistro *pzSisRegDepartamento)
{
	zSisRegDepartamento=pzSisRegDepartamento;
	Consultando();
}
void QtImpRepCompras::Consultando()
{
	Consulta();
	Muestra();
}
void QtImpRepCompras::Consulta()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"RepDatosCompra");
zDatCompra=lzRepServiSNTE.DatosCompra(zSisRegProveedor,zSisRegDepartamento);
zDatCompra->IniciaDatos();
}
void QtImpRepCompras::Muestra()
{
const char *lchrPtrCampos[]={"numproducto",
		       "modelo",
		       "nombreproducto",
		       "costobruto",
		       "d1",
		       "d2",
		       "d3",
		       "d4",
		       "iva",
		       "costoneto",
		       "preciogeneral",
		       "margen",
		       0
		       };
zSiscomQt3::LlenaTabla(lchrPtrCampos,zDatCompra->Productos(),QTDatos);

}
