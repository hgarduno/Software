#include <QCtrlFrecuenciaPagosSS.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlFrecuenciaPagosSS::QCtrlFrecuenciaPagosSS( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegFrecunciaPago(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlFrecuenciaPagosSS::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBFrecunciaPago=new QComboBox(this);
	QHBLayout->addWidget(QCBFrecunciaPago);
	QLEFrecunciaPago=zSiscomQt3::EditAlCombo(QCBFrecunciaPago,"QLEFrecunciaPago");
	QCBFrecunciaPago->setAutoCompletion(true);
	QCBFrecunciaPago->setDuplicatesEnabled(false);
	QCBFrecunciaPago->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlFrecuenciaPagosSS::MuestraFrecunciaPago()
{
zSiscomQt3::RegistrosAlCombo(QCBFrecunciaPago,"nombre",zSisRegFrecuenciaPagosSS);

}
void QCtrlFrecuenciaPagosSS::IniciaControl()
{
	ConsultaFrecunciaPago();
	MuestraFrecunciaPago();
}
void QCtrlFrecuenciaPagosSS::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlFrecuenciaPagosSS::ConsultaFrecunciaPago()
{
zOperacionesServiSNTE lzSisOpFrecuenciaPagosSS(zSisConexion,"FrecuenciaPagos");
if((zSisRegFrecuenciaPagosSS=lzSisOpFrecuenciaPagosSS.FrecuenciaPagosSS()))
SiscomRegistrosLog(zSisRegFrecuenciaPagosSS);
else
LogSiscom("NO hay productos aun");
}
void QCtrlFrecuenciaPagosSS::ConectaSlots()
{
connect(QCBFrecunciaPago,
	SIGNAL(activated(int )),
	SLOT(SlotFrecunciaPago(int)));
connect(QLEFrecunciaPago,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEFrecunciaPago,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoFrecunciaPago(const QString &)));
}
void QCtrlFrecuenciaPagosSS::SlotCapturandoFrecunciaPago(const QString &pQStrFrecunciaPago)
{
	if(pQStrFrecunciaPago.isEmpty())
	emit SignalFrecunciaPagoVacia();
}
void QCtrlFrecuenciaPagosSS::SlotFrecunciaPago(int pintFrecunciaPago)
{
  zSisRegFrecunciaPago=(*zSisRegFrecuenciaPagosSS)[pintFrecunciaPago];
  SiscomRegistroLog2(zSisRegFrecunciaPago);
}
void QCtrlFrecuenciaPagosSS::SlotCapturo()
{
if(zSisRegFrecunciaPago)
{
emit SignalFrecunciaPago(zSisRegFrecunciaPago);
zSisRegFrecunciaPago=0;
}
else
{
LogSiscom("La FrecunciaPago No existe, se registra");
emit SignalNuevoFrecunciaPago(QLEFrecunciaPago->text());
}
}
void QCtrlFrecuenciaPagosSS::setFocus()
{
   zSiscomQt3::Foco(QLEFrecunciaPago); 
   QLEFrecunciaPago->selectAll();
}

const char *QCtrlFrecuenciaPagosSS::FrecunciaPago()
{
return  (const char *)QLEFrecunciaPago->text();
}

void QCtrlFrecuenciaPagosSS::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlFrecuenciaPagosSS::ReIniciaControl()
{
   zSisRegFrecuenciaPagosSS->Libera();
   QCBFrecunciaPago->clear();
   IniciaControl();
}
