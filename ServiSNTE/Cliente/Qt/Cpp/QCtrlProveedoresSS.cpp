#include <QCtrlProveedoresSS.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

#include <stdlib.h>

QCtrlProveedoresSS::QCtrlProveedoresSS( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegProveedor(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlProveedoresSS::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBProveedor=new QComboBox(this);
	QHBLayout->addWidget(QCBProveedor);
	QLEProveedor=zSiscomQt3::EditAlCombo(QCBProveedor,"QLEProveedor");
	QCBProveedor->setAutoCompletion(true);
	QCBProveedor->setDuplicatesEnabled(false);
	QCBProveedor->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlProveedoresSS::MuestraProveedor()
{
zSiscomQt3::RegistrosAlCombo(QCBProveedor,"razonsocial",zSisRegProveedoresSS);
}
void QCtrlProveedoresSS::MuestraProveedorPorClave()
{
zSiscomQt3::RegistrosAlCombo(QCBProveedor,"idempresa",zSisRegProveedoresSS);
}
void QCtrlProveedoresSS::IniciaControlPorRazonSocial()
{
	ConsultaProveedor();
	MuestraProveedor();
}
void QCtrlProveedoresSS::IniciaControl()
{
const char *lchrPtrPorClave=getenv("ProveedorPorClave");
if(lchrPtrPorClave)
IniciaControlPorClave();
else
IniciaControlPorClave();
}
void QCtrlProveedoresSS::IniciaControlPorClave()
{
	ConsultaProveedor();
	MuestraProveedorPorClave();
}

void QCtrlProveedoresSS::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlProveedoresSS::ConsultaProveedor()
{
zOperacionesServiSNTE lzSisOpProveedoresSS(zSisConexion,"Proveedores");
if((zSisRegProveedoresSS=lzSisOpProveedoresSS.ProveedoresSS()))
{

}
else
LogSiscom("NO hay productos aun");
}
void QCtrlProveedoresSS::ConectaSlots()
{
connect(QCBProveedor,
	SIGNAL(activated(int )),
	SLOT(SlotProveedor(int)));
connect(QLEProveedor,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEProveedor,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoProveedor(const QString &)));
}
void QCtrlProveedoresSS::SlotCapturandoProveedor(const QString &pQStrProveedor)
{
	if(pQStrProveedor.isEmpty())
	emit SignalProveedorVacia();
}
void QCtrlProveedoresSS::SlotProveedor(int pintProveedor)
{
  zSisRegProveedor=(*zSisRegProveedoresSS)[pintProveedor];
}
void QCtrlProveedoresSS::SlotCapturo()
{
if(zSisRegProveedor)
{
emit SignalProveedor(zSisRegProveedor);
zSisRegProveedor=0;
}
else
{
LogSiscom("La Proveedor No existe, se registra");
emit SignalNuevoProveedor(QLEProveedor->text());
}
}
void QCtrlProveedoresSS::setFocus()
{
   zSiscomQt3::Foco(QLEProveedor); 
   QLEProveedor->selectAll();
}

const char *QCtrlProveedoresSS::Proveedor()
{
return  (const char *)QLEProveedor->text();
}

void QCtrlProveedoresSS::keyPressEvent(QKeyEvent *pQKPTecla)
{
/* Copiado aqui el Miercoles 17 de diciembre del 2014
 * Domingo 31 Julio del 2011
 * Se buscara integrar una ventana para la busqueda de los
 * alumnos, al momento de presionar F1, ya que si por alguna
 * razon, el nombre que se capturo, tiene alguna variacion 
 * en la busqueda del alumno este no se podra obtener de 
 * manera correcta, la idea de integrarlo en el contro
 * tiene que ver con el hecho de que entodos los lugares
 * en los que se use el control se tenga acceso a esta 
 * funcionalidad
 */
  if(pQKPTecla->key()==Qt::Key_F1)
  {

  }
}

void QCtrlProveedoresSS::ReIniciaControl()
{
   zSisRegProveedoresSS->Libera();
   QCBProveedor->clear();
   IniciaControl();
}
