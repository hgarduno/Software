#include <QCtrlTiendasEntrega.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlTiendasEntrega::QCtrlTiendasEntrega( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegTienda(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlTiendasEntrega::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBTienda=new QComboBox(this);
	QHBLayout->addWidget(QCBTienda);
	QLETienda=zSiscomQt3::EditAlCombo(QCBTienda,"QLETienda");
	QCBTienda->setAutoCompletion(true);
	QCBTienda->setDuplicatesEnabled(false);
	QCBTienda->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlTiendasEntrega::MuestraTienda()
{
zSiscomQt3::RegistrosAlCombo(QCBTienda,"nombre",zSisRegTiendasEntrega);

}
void QCtrlTiendasEntrega::IniciaControl()
{
	ConsultaTienda();
	MuestraTienda();
}
void QCtrlTiendasEntrega::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlTiendasEntrega::ConsultaTienda()
{
zOperacionesServiSNTE lzSisOpTiendasEntrega(zSisConexion,"TiendasEntrega");
if((zSisRegTiendasEntrega=lzSisOpTiendasEntrega.TiendasEntrega()))
{

}
else
LogSiscom("NO hay productos aun");
}
void QCtrlTiendasEntrega::ConectaSlots()
{
connect(QCBTienda,
	SIGNAL(activated(int )),
	SLOT(SlotTienda(int)));
connect(QLETienda,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLETienda,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoTienda(const QString &)));
}
void QCtrlTiendasEntrega::SlotCapturandoTienda(const QString &pQStrTienda)
{
	if(pQStrTienda.isEmpty())
	emit SignalTiendaVacia();
}
void QCtrlTiendasEntrega::SlotTienda(int pintTienda)
{
  zSisRegTienda=(*zSisRegTiendasEntrega)[pintTienda];
}
void QCtrlTiendasEntrega::SlotCapturo()
{
if(zSisRegTienda)
{
emit SignalTienda(zSisRegTienda);
zSisRegTienda=0;
}
else
{
LogSiscom("La Tienda No existe, se registra");
emit SignalNuevoTienda(QLETienda->text());
}
}
void QCtrlTiendasEntrega::setFocus()
{
   zSiscomQt3::Foco(QLETienda); 
   QLETienda->selectAll();
}

const char *QCtrlTiendasEntrega::Tienda()
{
return  (const char *)QLETienda->text();
}

void QCtrlTiendasEntrega::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlTiendasEntrega::ReIniciaControl()
{
   zSisRegTiendasEntrega->Libera();
   QCBTienda->clear();
   IniciaControl();
}
