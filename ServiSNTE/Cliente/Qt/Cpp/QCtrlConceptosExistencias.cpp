#include <QCtrlConceptosExistencias.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlConceptosExistencias::QCtrlConceptosExistencias( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegConcepto(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlConceptosExistencias::IniciaVariables()
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
void QCtrlConceptosExistencias::MuestraConcepto()
{
zSiscomQt3::RegistrosAlCombo(QCBConcepto,"conceptos",zSisRegConceptosExistencias);

}
void QCtrlConceptosExistencias::IniciaControl()
{
	ConsultaConcepto();
	MuestraConcepto();
}
void QCtrlConceptosExistencias::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlConceptosExistencias::ConsultaConcepto()
{
zOperacionesServiSNTE lzSisOpConceptosExistencias(zSisConexion,"ConceptosExistencias");
if((zSisRegConceptosExistencias=lzSisOpConceptosExistencias.ConceptosExistencias()))
SiscomRegistrosLog(zSisRegConceptosExistencias);
else
LogSiscom("NO hay productos aun");
}
void QCtrlConceptosExistencias::ConectaSlots()
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
void QCtrlConceptosExistencias::SlotCapturandoConcepto(const QString &pQStrConcepto)
{
	if(pQStrConcepto.isEmpty())
	emit SignalConceptoVacia();
}
void QCtrlConceptosExistencias::SlotConcepto(int pintConcepto)
{
  zSisRegConcepto=(*zSisRegConceptosExistencias)[pintConcepto];
  SiscomRegistroLog2(zSisRegConcepto);
}
void QCtrlConceptosExistencias::SlotCapturo()
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
void QCtrlConceptosExistencias::setFocus()
{
   zSiscomQt3::Foco(QLEConcepto); 
   QLEConcepto->selectAll();
}

const char *QCtrlConceptosExistencias::Concepto()
{
return  (const char *)QLEConcepto->text();
}

void QCtrlConceptosExistencias::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlConceptosExistencias::ReIniciaControl()
{
   zSisRegConceptosExistencias->Libera();
   QCBConcepto->clear();
   IniciaControl();
}
