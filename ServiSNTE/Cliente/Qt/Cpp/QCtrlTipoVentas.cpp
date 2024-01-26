#include <QCtrlTipoVentas.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlTipoVentas::QCtrlTipoVentas( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegTipoVenta(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlTipoVentas::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBTipoVenta=new QComboBox(this);
	QHBLayout->addWidget(QCBTipoVenta);
	QLETipoVenta=zSiscomQt3::EditAlCombo(QCBTipoVenta,"QLETipoVenta");
	QCBTipoVenta->setAutoCompletion(true);
	QCBTipoVenta->setDuplicatesEnabled(false);
	QCBTipoVenta->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlTipoVentas::MuestraTipoVenta()
{
zSiscomQt3::RegistrosAlCombo(QCBTipoVenta,"nombre",zSisRegTipoVentas);

}
void QCtrlTipoVentas::IniciaControl()
{
	ConsultaTipoVenta();
	MuestraTipoVenta();
}
void QCtrlTipoVentas::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlTipoVentas::ConsultaTipoVenta()
{
zOperacionesServiSNTE lzSisOpTipoVentas(zSisConexion,"TipoVentas");
if((zSisRegTipoVentas=lzSisOpTipoVentas.TipoVentas()))
{
}
else
LogSiscom("NO hay productos aun");
}
void QCtrlTipoVentas::ConectaSlots()
{
connect(QCBTipoVenta,
	SIGNAL(activated(int )),
	SLOT(SlotTipoVenta(int)));
connect(QLETipoVenta,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLETipoVenta,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoTipoVenta(const QString &)));
}
void QCtrlTipoVentas::SlotCapturandoTipoVenta(const QString &pQStrTipoVenta)
{
	if(pQStrTipoVenta.isEmpty())
	emit SignalTipoVentaVacia();
}
void QCtrlTipoVentas::SlotTipoVenta(int pintTipoVenta)
{
  zSisRegTipoVenta=(*zSisRegTipoVentas)[pintTipoVenta];
  SiscomRegistroLog2(zSisRegTipoVenta);
}
void QCtrlTipoVentas::SlotCapturo()
{
if(zSisRegTipoVenta)
{
emit SignalTipoVenta(zSisRegTipoVenta);
zSisRegTipoVenta=0;
}
else
{
LogSiscom("La TipoVenta No existe, se registra");
emit SignalNuevoTipoVenta(QLETipoVenta->text());
}
}
void QCtrlTipoVentas::setFocus()
{
   zSiscomQt3::Foco(QLETipoVenta); 
   QLETipoVenta->selectAll();
}

const char *QCtrlTipoVentas::TipoVenta()
{
return  (const char *)QLETipoVenta->text();
}

void QCtrlTipoVentas::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlTipoVentas::ReIniciaControl()
{
   zSisRegTipoVentas->Libera();
   QCBTipoVenta->clear();
   IniciaControl();
}
