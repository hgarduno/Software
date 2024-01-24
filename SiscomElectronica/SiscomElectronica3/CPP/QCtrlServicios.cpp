#include <QCtrlServicios.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlayout.h>
#include <qcombobox.h>

extern FILE *gzPtrFleArchivoLog3Qt;

QCtrlServicios::QCtrlServicios( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intCurso(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlServicios::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBServicios=new QComboBox(this);
	QHBLayout->addWidget(QCBServicios);
	QLEServicios=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBServicios,"QLEServicios");
	QCBServicios->setAutoCompletion(true);
	QCBServicios->setDuplicatesEnabled(false);
	QCBServicios->setInsertionPolicy(QComboBox::NoInsertion);

}
void QCtrlServicios::MuestraServicios()
{

SiscomDesarrollo3Qt::RegistrosAlCombo("curso",
				      QCBServicios,
				      &SisReg3LstServicios);

}
void QCtrlServicios::IniciaControl()
{
	ConsultaServicios();
	MuestraServicios();
}
void QCtrlServicios::ConsultaServicios()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
SisReg3LstServicios.clear();
QCBServicios->clear();
lCQS3QtOperaciones.Servicios(&SisReg3LstServicios);
}
void QCtrlServicios::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlServicios::ConectaSlots()
{
	connect(QCBServicios,
		SIGNAL(activated(int)),
		SLOT(SlotCurso(int)));

}
void QCtrlServicios::SlotCurso(int pintNEscuela)
{
	intCurso=pintNEscuela;
	emit SignalCurso(SisReg3LstServicios[pintNEscuela]);
}
void QCtrlServicios::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEServicios);	
}

void QCtrlServicios::Limpia()
{
}

SiscomRegistro3 *QCtrlServicios::CursoActual()
{
	return SisReg3LstServicios[intCurso];
}

void QCtrlServicios::keyPressEvent(QKeyEvent *pQKPTecla)
{
/*
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
  SiscomEscribeLog3Qt("Se presiono F1");
}

