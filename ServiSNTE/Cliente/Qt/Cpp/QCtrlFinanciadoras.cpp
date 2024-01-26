#include <QCtrlFinanciadoras.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlFinanciadoras::QCtrlFinanciadoras( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegFinanciadora(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlFinanciadoras::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBFinanciadora=new QComboBox(this);
	QHBLayout->addWidget(QCBFinanciadora);
	QLEFinanciadora=zSiscomQt3::EditAlCombo(QCBFinanciadora,"QLEFinanciadora");
	QCBFinanciadora->setAutoCompletion(true);
	QCBFinanciadora->setDuplicatesEnabled(false);
	QCBFinanciadora->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlFinanciadoras::MuestraFinanciadora()
{
zSiscomQt3::RegistrosAlCombo(QCBFinanciadora,"nombre",zSisRegFinanciadoras);

}
void QCtrlFinanciadoras::IniciaControl()
{
	ConsultaFinanciadora();
	MuestraFinanciadora();
}
void QCtrlFinanciadoras::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlFinanciadoras::ConsultaFinanciadora()
{
zOperacionesServiSNTE lzSisOpFinanciadoras(zSisConexion,"Financiadoras");
if((zSisRegFinanciadoras=lzSisOpFinanciadoras.Financiadoras()))
{

}
else
LogSiscom("NO hay productos aun");
}
void QCtrlFinanciadoras::ConectaSlots()
{
connect(QCBFinanciadora,
	SIGNAL(activated(int )),
	SLOT(SlotFinanciadora(int)));
connect(QLEFinanciadora,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEFinanciadora,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoFinanciadora(const QString &)));
}
void QCtrlFinanciadoras::SlotCapturandoFinanciadora(const QString &pQStrFinanciadora)
{
	if(pQStrFinanciadora.isEmpty())
	emit SignalFinanciadoraVacia();
}
void QCtrlFinanciadoras::SlotFinanciadora(int pintFinanciadora)
{
  zSisRegFinanciadora=(*zSisRegFinanciadoras)[pintFinanciadora];
  SiscomRegistroLog2(zSisRegFinanciadora);
}
void QCtrlFinanciadoras::SlotCapturo()
{
if(zSisRegFinanciadora)
{
emit SignalFinanciadora(zSisRegFinanciadora);
zSisRegFinanciadora=0;
}
else
{
LogSiscom("La Financiadora No existe, se registra");
emit SignalNuevoFinanciadora(QLEFinanciadora->text());
}
}
void QCtrlFinanciadoras::setFocus()
{
   zSiscomQt3::Foco(QLEFinanciadora); 
   QLEFinanciadora->selectAll();
}

const char *QCtrlFinanciadoras::Financiadora()
{
return  (const char *)QLEFinanciadora->text();
}

void QCtrlFinanciadoras::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlFinanciadoras::ReIniciaControl()
{
   zSisRegFinanciadoras->Libera();
   QCBFinanciadora->clear();
   IniciaControl();
}
