#include <QCtrlAlumnos.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlayout.h>
#include <qcombobox.h>

extern FILE *gzPtrFleArchivoLog3Qt;

QCtrlAlumnos::QCtrlAlumnos( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intAlumno(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlAlumnos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBAlumnos=new QComboBox(this);
	QHBLayout->addWidget(QCBAlumnos);
	QLEAlumnos=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBAlumnos,"QLEAlumnos");
	QCBAlumnos->setAutoCompletion(true);
	QCBAlumnos->setDuplicatesEnabled(false);
	QCBAlumnos->setInsertionPolicy(QComboBox::NoInsertion);

}
void QCtrlAlumnos::MuestraAlumnos()
{

SiscomDesarrollo3Qt::RegistrosAlCombo("boleta",
				      QCBAlumnos,
				      &SisReg3LstAlumnos);

}
void QCtrlAlumnos::IniciaControl()
{
	ConsultaAlumnos();
	MuestraAlumnos();
}
void QCtrlAlumnos::ConsultaAlumnos()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
SisReg3LstAlumnos.clear();
QCBAlumnos->clear();
lCQS3QtOperaciones.AlumnosExpendio(chrPtrIdExpendio,
				   &SisReg3LstAlumnos);
}
void QCtrlAlumnos::IdExpendio(const char *pchrPtrIdExpendio)
{
	chrPtrIdExpendio=pchrPtrIdExpendio;
}
void QCtrlAlumnos::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlAlumnos::ConectaSlots()
{
	connect(QCBAlumnos,
		SIGNAL(activated(int)),
		SLOT(SlotAlumno(int)));

}
void QCtrlAlumnos::SlotAlumno(int pintNEscuela)
{
	intAlumno=pintNEscuela;
	emit SignalAlumno(SisReg3LstAlumnos[pintNEscuela]);
}
void QCtrlAlumnos::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEAlumnos);	
}

void QCtrlAlumnos::Limpia()
{
}

SiscomRegistro3 *QCtrlAlumnos::AlumnoActual()
{
	return SisReg3LstAlumnos[intAlumno];
}

void QCtrlAlumnos::keyPressEvent(QKeyEvent *pQKPTecla)
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

