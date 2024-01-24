#include <QCtrlProgramacionCursos.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlayout.h>
#include <qcombobox.h>

extern FILE *gzPtrFleArchivoLog3Qt;

QCtrlProgramacionCursos::QCtrlProgramacionCursos( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intProgramacionCurso(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlProgramacionCursos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBProgramacionCursos=new QComboBox(this);
	QHBLayout->addWidget(QCBProgramacionCursos);
	QLEProgramacionCursos=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBProgramacionCursos,"QLEProgramacionCursos");
	QCBProgramacionCursos->setAutoCompletion(true);
	QCBProgramacionCursos->setDuplicatesEnabled(false);
	QCBProgramacionCursos->setInsertionPolicy(QComboBox::NoInsertion);

}
void QCtrlProgramacionCursos::MuestraProgramacionCursos()
{

SiscomDesarrollo3Qt::RegistrosAlCombo("programacion",
				      QCBProgramacionCursos,
				      &SisReg3LstProgramacionCursos);

}
void QCtrlProgramacionCursos::IniciaControl()
{
	QCBProgramacionCursos->clear();
	ConsultaProgramacionCursos();
	MuestraProgramacionCursos();
}
void QCtrlProgramacionCursos::ConsultaProgramacionCursos()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
SisReg3LstProgramacionCursos.clear();
QCBProgramacionCursos->clear();
lCQS3QtOperaciones.CursosProgramados(&SisReg3LstProgramacionCursos);
}
void QCtrlProgramacionCursos::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlProgramacionCursos::ConectaSlots()
{
	connect(QCBProgramacionCursos,
		SIGNAL(activated(int)),
		SLOT(SlotProgramacionCurso(int)));

}
void QCtrlProgramacionCursos::SlotProgramacionCurso(int pintNEscuela)
{
	intProgramacionCurso=pintNEscuela;
	emit SignalProgramacionCurso(SisReg3LstProgramacionCursos[pintNEscuela]);
}
void QCtrlProgramacionCursos::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEProgramacionCursos);	
}

void QCtrlProgramacionCursos::Limpia()
{
}

SiscomRegistro3 *QCtrlProgramacionCursos::ProgramacionCursoActual()
{
	return SisReg3LstProgramacionCursos[intProgramacionCurso];
}

void QCtrlProgramacionCursos::keyPressEvent(QKeyEvent *pQKPTecla)
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

