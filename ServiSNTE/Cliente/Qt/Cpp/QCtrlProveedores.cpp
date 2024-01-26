#include <QCtrlProveedores.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlProveedores::QCtrlProveedores( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegConcepto(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlProveedores::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBConcepto=new QComboBox(this);
	QHBLayout->addWidget(QCBConcepto);
	QLEConcepto=zSiscomQt3::EditAlCombo(QCBConcepto,"QLEConcepto");
	QCBConcepto->setAutoCompletion(true);
	QCBConcepto->setDuplicatesEnabled(false);
	QCBConcepto->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlProveedores::MuestraConcepto()
{
zSiscomQt3::RegistrosAlCombo(QCBConcepto,"razonsocial",zSisRegProveedores);

}
void QCtrlProveedores::IniciaControl()
{
	ConsultaConcepto();
	MuestraConcepto();
}
void QCtrlProveedores::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlProveedores::ConsultaConcepto()
{
zOperacionesServiSNTE lzSisOpProveedores(zSisConexion,"Proveedores");
if((zSisRegProveedores=lzSisOpProveedores.Proveedores()))
SiscomRegistrosLog(zSisRegProveedores);
else
LogSiscom("NO hay productos aun");
}
void QCtrlProveedores::ConectaSlots()
{
connect(QCBConcepto,
	SIGNAL(activated(int )),
	SLOT(SlotConcepto(int)));
connect(QLEConcepto,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEConcepto,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoConcepto(const QString &)));
}
void QCtrlProveedores::SlotCapturandoConcepto(const QString &pQStrConcepto)
{
	if(pQStrConcepto.isEmpty())
	emit SignalConceptoVacia();
}
void QCtrlProveedores::SlotConcepto(int pintConcepto)
{
  zSisRegConcepto=(*zSisRegProveedores)[pintConcepto];
  SiscomRegistroLog2(zSisRegConcepto);
}
void QCtrlProveedores::SlotCapturo()
{
if(zSisRegConcepto)
{
emit SignalConcepto(zSisRegConcepto);
zSisRegConcepto=0;
}
else
{
LogSiscom("La Concepto No existe, se registra");
emit SignalNuevoConcepto(QLEConcepto->text());
}
}
void QCtrlProveedores::setFocus()
{
   zSiscomQt3::Foco(QLEConcepto); 
   QLEConcepto->selectAll();
}

const char *QCtrlProveedores::Concepto()
{
return  (const char *)QLEConcepto->text();
}

void QCtrlProveedores::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlProveedores::ReIniciaControl()
{
   zSisRegProveedores->Libera();
   QCBConcepto->clear();
   IniciaControl();
}
