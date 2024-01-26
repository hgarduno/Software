#include <QtImpRepProveedores.h>
#include <QtImprimiendoRepProveedores.h>
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
#include <zProveedores.h>
#include <zImpresionProveedores.h>

#include <qpushbutton.h>
#include <qtextedit.h>
#include <qlineedit.h>
QtImpRepProveedores::QtImpRepProveedores(QWidget *pQWParent,
					       const char *pchrPtrName):
					   RepProveedores(pQWParent,pchrPtrName),
					   zSisRegProveedor(0)
{
	
	Conexion((zSiscomConexion *)gzSiscomConexion);
	IniciaVariables();
	ConectaSlots();
}
void QtImpRepProveedores::IniciaVariables()
{
QCtrProveedores->Servidor(zSisConexion);
QCtrProveedores->IniciaControl();
zSiscomQt3::Foco(QCtrProveedores);
}
void QtImpRepProveedores::Conexion(zSiscomConexion *pzSisConexion)
{
	zSisConexion=pzSisConexion;
}
void QtImpRepProveedores::ConectaSlots()
{
	connect(QPBConsultar,
		SIGNAL(clicked()),
		SLOT(SlotConsultar()));
	connect(QPBImprimir,
		SIGNAL(clicked()),
		SLOT(SlotImprimir()));
}
void QtImpRepProveedores::SlotImprimir()
{
zImpresionProveedores *lzImpProveedores=new zImpresionProveedores(zPrvDatos);
QtImprimiendoRepProveedores *lQtImpProveedores=new QtImprimiendoRepProveedores(zSisConexion,
					    lzImpProveedores);
}
void QtImpRepProveedores::SlotConsultar()
{
	Consultando();
	Consulta();
	Muestra();
}
void QtImpRepProveedores::Consultando()
{
Consulta();
Muestra();
}
void QtImpRepProveedores::Consulta()
{
zReportesServiSNTE lzRepServiSNTE(zSisConexion,"RepProveedores");
zPrvDatos=lzRepServiSNTE.Proveedores(zSisRegProveedor);
zPrvDatos->Inicia();
}
void QtImpRepProveedores::Muestra()
{
const char *lchrPtrCampos[]={"idempresa",
			"razonsocial"  ,
			"contacto",
			0};
zSiscomQt3::LlenaTabla(lchrPtrCampos,zPrvDatos,QTProveedores);
}
