#include <QCtrlCursos.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlayout.h>
#include <qcombobox.h>

extern FILE *gzPtrFleArchivoLog3Qt;

QCtrlCursos::QCtrlCursos( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intCurso(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlCursos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBCursos=new QComboBox(this);
	QHBLayout->addWidget(QCBCursos);
	QLECursos=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBCursos,"QLECursos");
	QCBCursos->setAutoCompletion(true);
	QCBCursos->setDuplicatesEnabled(false);
	QCBCursos->setInsertionPolicy(QComboBox::NoInsertion);

}
void QCtrlCursos::MuestraCursos()
{

SiscomDesarrollo3Qt::RegistrosAlCombo("curso",
				      QCBCursos,
				      &SisReg3LstCursos);

}
void QCtrlCursos::IniciaControl()
{
	ConsultaCursos();
	MuestraCursos();
}
void QCtrlCursos::ConsultaCursos()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
SisReg3LstCursos.clear();
QCBCursos->clear();
lCQS3QtOperaciones.Cursos(&SisReg3LstCursos);
}
void QCtrlCursos::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlCursos::ConectaSlots()
{
	connect(QCBCursos,
		SIGNAL(activated(int)),
		SLOT(SlotCurso(int)));

}
void QCtrlCursos::SlotCurso(int pintNEscuela)
{
	intCurso=pintNEscuela;
	emit SignalCurso(SisReg3LstCursos[pintNEscuela]);
}
void QCtrlCursos::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLECursos);	
}

void QCtrlCursos::Limpia()
{
}

SiscomRegistro3 *QCtrlCursos::CursoActual()
{
	return SisReg3LstCursos[intCurso];
}

void QCtrlCursos::keyPressEvent(QKeyEvent *pQKPTecla)
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

