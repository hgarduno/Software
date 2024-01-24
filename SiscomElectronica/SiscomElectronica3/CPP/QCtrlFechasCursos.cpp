#include <QCtrlFechasCursos.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlayout.h>
#include <qcombobox.h>

extern FILE *gzPtrFleArchivoLog3Qt;

QCtrlFechasCursos::QCtrlFechasCursos( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intFechaCurso(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlFechasCursos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBFechasCursos=new QComboBox(this);
	QHBLayout->addWidget(QCBFechasCursos);
	QLEFechasCursos=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBFechasCursos,"QLEFechasCursos");
	QCBFechasCursos->setAutoCompletion(true);
	QCBFechasCursos->setDuplicatesEnabled(false);
	QCBFechasCursos->setInsertionPolicy(QComboBox::NoInsertion);

}
void QCtrlFechasCursos::MuestraFechasCursos()
{

SiscomDesarrollo3Qt::RegistrosAlCombo("fecha",
				      QCBFechasCursos,
				      &SisReg3LstFechasCursos);

}
void QCtrlFechasCursos::IniciaControl()
{
	ConsultaFechasCursos();
	MuestraFechasCursos();
}
void QCtrlFechasCursos::ConsultaFechasCursos()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
SisReg3LstFechasCursos.clear();
QCBFechasCursos->clear();
lCQS3QtOperaciones.FechasCursos(chrPtrIdCurso,
				&SisReg3LstFechasCursos);
}
void QCtrlFechasCursos::IdCurso(const char *pchrPtrIdCurso)
{
	chrPtrIdCurso=pchrPtrIdCurso;
}
void QCtrlFechasCursos::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlFechasCursos::ConectaSlots()
{
	connect(QCBFechasCursos,
		SIGNAL(activated(int)),
		SLOT(SlotFechaCurso(int)));

}
void QCtrlFechasCursos::SlotFechaCurso(int pintNEscuela)
{
	intFechaCurso=pintNEscuela;
	emit SignalFechaCurso(SisReg3LstFechasCursos[pintNEscuela]);
}
void QCtrlFechasCursos::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEFechasCursos);	
}

void QCtrlFechasCursos::Limpia()
{
}

SiscomRegistro3 *QCtrlFechasCursos::FechaCursoActual()
{
	return SisReg3LstFechasCursos[intFechaCurso];
}

void QCtrlFechasCursos::keyPressEvent(QKeyEvent *pQKPTecla)
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

