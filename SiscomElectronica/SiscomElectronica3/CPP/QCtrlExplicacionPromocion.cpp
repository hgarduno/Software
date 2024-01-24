#include <QCtrlExplicacionPromocion.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlayout.h>
#include <qcombobox.h>

extern FILE *gzPtrFleArchivoLog3Qt;

QCtrlExplicacionPromocion::QCtrlExplicacionPromocion( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intExplicacionPromocion(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlExplicacionPromocion::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBExplicacionPromocion=new QComboBox(this);
	QHBLayout->addWidget(QCBExplicacionPromocion);
	QLEExplicacionPromocion=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBExplicacionPromocion,"QLEExplicacionPromocion");
	QCBExplicacionPromocion->setAutoCompletion(true);
	QCBExplicacionPromocion->setDuplicatesEnabled(false);
	QCBExplicacionPromocion->setInsertionPolicy(QComboBox::NoInsertion);

}
void QCtrlExplicacionPromocion::MuestraExplicacionPromocion()
{

SiscomDesarrollo3Qt::RegistrosAlCombo("explicacion",
				      QCBExplicacionPromocion,
				      &SisReg3LstExplicacionPromocion);

}
void QCtrlExplicacionPromocion::IniciaControl()
{
	QCBExplicacionPromocion->clear();
	ConsultaExplicacionPromocion();
	MuestraExplicacionPromocion();
}
void QCtrlExplicacionPromocion::ConsultaExplicacionPromocion()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
SisReg3LstExplicacionPromocion.clear();
QCBExplicacionPromocion->clear();
lCQS3QtOperaciones.ExplicacionPromocion(&SisReg3LstExplicacionPromocion);
}
void QCtrlExplicacionPromocion::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlExplicacionPromocion::ConectaSlots()
{
	connect(QCBExplicacionPromocion,
		SIGNAL(activated(int)),
		SLOT(SlotExplicacionPromocion(int)));

}
void QCtrlExplicacionPromocion::SlotExplicacionPromocion(int pintNEscuela)
{
	intExplicacionPromocion=pintNEscuela;
	emit SignalExplicacionPromocion(SisReg3LstExplicacionPromocion[pintNEscuela]);
}
void QCtrlExplicacionPromocion::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEExplicacionPromocion);	
}

void QCtrlExplicacionPromocion::Limpia()
{
}

SiscomRegistro3 *QCtrlExplicacionPromocion::ExplicacionPromocionActual()
{
	return SisReg3LstExplicacionPromocion[intExplicacionPromocion];
}

void QCtrlExplicacionPromocion::keyPressEvent(QKeyEvent *pQKPTecla)
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

