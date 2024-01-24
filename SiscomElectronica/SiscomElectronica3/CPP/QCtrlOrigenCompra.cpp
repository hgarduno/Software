#include <QCtrlOrigenCompra.h>
#include <CQSis3QtOperaciones.h>
#include <SiscomDesarrollo3Qt++.h>
#include <qlayout.h>
#include <qcombobox.h>

extern FILE *gzPtrFleArchivoLog3Qt;

QCtrlOrigenCompra::QCtrlOrigenCompra( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    intOrigenCompra(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlOrigenCompra::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBOrigenCompra=new QComboBox(this);
	QHBLayout->addWidget(QCBOrigenCompra);
	QLEOrigenCompra=SiscomDesarrollo3Qt::ColocaEditAlCombo(QCBOrigenCompra,"QLEOrigenCompra");
	QCBOrigenCompra->setAutoCompletion(true);
	QCBOrigenCompra->setDuplicatesEnabled(false);
	QCBOrigenCompra->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlOrigenCompra::MuestraOrigenCompra()
{

SiscomDesarrollo3Qt::RegistrosAlCombo("rfc",
				      QCBOrigenCompra,
				      &SisReg3LstOrigenCompra);

}
void QCtrlOrigenCompra::IniciaControl()
{
	QCBOrigenCompra->clear();
	ConsultaOrigenCompra();
	MuestraOrigenCompra();
}
void QCtrlOrigenCompra::ConsultaOrigenCompra()
{
CQSis3QtOperaciones lCQS3QtOperaciones(SisDatCom);
SisReg3LstOrigenCompra.clear();
QCBOrigenCompra->clear();
lCQS3QtOperaciones.OrigenCompra(&SisReg3LstOrigenCompra);
SiscomRegistro3LstContenido(&SisReg3LstOrigenCompra);
}
void QCtrlOrigenCompra::Servidor(SiscomDatCom *pSisDatCom)
{
	SisDatCom=pSisDatCom;
}
void QCtrlOrigenCompra::ConectaSlots()
{
	connect(QCBOrigenCompra,
		SIGNAL(activated(int)),
		SLOT(SlotOrigenCompra(int)));

}
void QCtrlOrigenCompra::SlotOrigenCompra(int pintNEscuela)
{
	intOrigenCompra=pintNEscuela;
	emit SignalOrigenCompra(SisReg3LstOrigenCompra[pintNEscuela]);
}
void QCtrlOrigenCompra::setFocus()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QLEOrigenCompra);	
}

void QCtrlOrigenCompra::Limpia()
{
}

SiscomRegistro3 *QCtrlOrigenCompra::OrigenCompraActual()
{
	return SisReg3LstOrigenCompra[intOrigenCompra];
}

void QCtrlOrigenCompra::keyPressEvent(QKeyEvent *pQKPTecla)
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

