#include <QCtrlFormasEntrega.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlFormasEntrega::QCtrlFormasEntrega( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegFormaEntrega(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlFormasEntrega::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBFormaEntrega=new QComboBox(this);
	QHBLayout->addWidget(QCBFormaEntrega);
	QLEFormaEntrega=zSiscomQt3::EditAlCombo(QCBFormaEntrega,"QLEFormaEntrega");
	QCBFormaEntrega->setAutoCompletion(true);
	QCBFormaEntrega->setDuplicatesEnabled(false);
	QCBFormaEntrega->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlFormasEntrega::MuestraFormaEntrega()
{
zSiscomQt3::RegistrosAlCombo(QCBFormaEntrega,"nombre",zSisRegFormasEntrega);

}
void QCtrlFormasEntrega::IniciaControl()
{
	ConsultaFormaEntrega();
	MuestraFormaEntrega();
}
void QCtrlFormasEntrega::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlFormasEntrega::ConsultaFormaEntrega()
{
zOperacionesServiSNTE lzSisOpFormasEntrega(zSisConexion,"FormasEntrega");
if((zSisRegFormasEntrega=lzSisOpFormasEntrega.FormasEntrega()))
{

}
else
LogSiscom("NO hay productos aun");
}
void QCtrlFormasEntrega::ConectaSlots()
{
connect(QCBFormaEntrega,
	SIGNAL(activated(int )),
	SLOT(SlotFormaEntrega(int)));
connect(QLEFormaEntrega,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEFormaEntrega,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoFormaEntrega(const QString &)));
}
void QCtrlFormasEntrega::SlotCapturandoFormaEntrega(const QString &pQStrFormaEntrega)
{
	if(pQStrFormaEntrega.isEmpty())
	emit SignalFormaEntregaVacia();
}
void QCtrlFormasEntrega::SlotFormaEntrega(int pintFormaEntrega)
{
  zSisRegFormaEntrega=(*zSisRegFormasEntrega)[pintFormaEntrega];
  SiscomRegistroLog2(zSisRegFormaEntrega);
}
void QCtrlFormasEntrega::SlotCapturo()
{
if(zSisRegFormaEntrega)
{
emit SignalFormaEntrega(zSisRegFormaEntrega);
zSisRegFormaEntrega=0;
}
else
{
LogSiscom("La FormaEntrega No existe, se registra");
emit SignalNuevoFormaEntrega(QLEFormaEntrega->text());
}
}
void QCtrlFormasEntrega::setFocus()
{
   zSiscomQt3::Foco(QLEFormaEntrega); 
   QLEFormaEntrega->selectAll();
}

const char *QCtrlFormasEntrega::FormaEntrega()
{
return  (const char *)QLEFormaEntrega->text();
}

void QCtrlFormasEntrega::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlFormasEntrega::ReIniciaControl()
{
   zSisRegFormasEntrega->Libera();
   QCBFormaEntrega->clear();
   IniciaControl();
}
