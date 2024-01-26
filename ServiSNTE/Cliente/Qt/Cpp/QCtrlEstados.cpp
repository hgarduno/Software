#include <QCtrlEstados.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlEstados::QCtrlEstados( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegEstado(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlEstados::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBEstado=new QComboBox(this);
	QHBLayout->addWidget(QCBEstado);
	QLEEstado=zSiscomQt3::EditAlCombo(QCBEstado,"QLEEstado");
	QCBEstado->setAutoCompletion(true);
	QCBEstado->setDuplicatesEnabled(false);
	QCBEstado->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlEstados::MuestraEstado()
{
zSiscomQt3::RegistrosAlCombo(QCBEstado,"nombre",zSisRegEstados);

}
void QCtrlEstados::IniciaControl()
{
	ConsultaEstado();
	MuestraEstado();
}
void QCtrlEstados::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlEstados::ConsultaEstado()
{
zOperacionesServiSNTE lzSisOpEstados(zSisConexion,"Estados");
if((zSisRegEstados=lzSisOpEstados.Estados()))
SiscomRegistrosLog(zSisRegEstados);
else
LogSiscom("NO hay productos aun");
}
void QCtrlEstados::ConectaSlots()
{
connect(QCBEstado,
	SIGNAL(activated(int )),
	SLOT(SlotEstado(int)));
connect(QLEEstado,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEEstado,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoEstado(const QString &)));
}
void QCtrlEstados::SlotCapturandoEstado(const QString &pQStrEstado)
{
	if(pQStrEstado.isEmpty())
	emit SignalEstadoVacia();
}
void QCtrlEstados::SlotEstado(int pintEstado)
{
  zSisRegEstado=(*zSisRegEstados)[pintEstado];
  SiscomRegistroLog2(zSisRegEstado);
}
void QCtrlEstados::SlotCapturo()
{
if(zSisRegEstado)
{
emit SignalEstado(zSisRegEstado);
zSisRegEstado=0;
}
else
{
LogSiscom("La Estado No existe, se registra");
emit SignalNuevoEstado(QLEEstado->text());
}
}
void QCtrlEstados::setFocus()
{
   zSiscomQt3::Foco(QLEEstado); 
   QLEEstado->selectAll();
}

const char *QCtrlEstados::Estado()
{
return  (const char *)QLEEstado->text();
}

void QCtrlEstados::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlEstados::ReIniciaControl()
{
   zSisRegEstados->Libera();
   QCBEstado->clear();
   IniciaControl();
}
