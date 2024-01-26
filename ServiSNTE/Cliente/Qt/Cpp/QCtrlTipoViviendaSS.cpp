#include <QCtrlTipoViviendaSS.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlTipoViviendaSS::QCtrlTipoViviendaSS( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegTipoVivienda(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlTipoViviendaSS::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBTipoVivienda=new QComboBox(this);
	QHBLayout->addWidget(QCBTipoVivienda);
	QLETipoVivienda=zSiscomQt3::EditAlCombo(QCBTipoVivienda,"QLETipoVivienda");
	QCBTipoVivienda->setAutoCompletion(true);
	QCBTipoVivienda->setDuplicatesEnabled(false);
	QCBTipoVivienda->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlTipoViviendaSS::MuestraTipoVivienda()
{
zSiscomQt3::RegistrosAlCombo(QCBTipoVivienda,"nombre",zSisRegTipoViviendaSS);
}
void QCtrlTipoViviendaSS::IniciaControl()
{
	ConsultaTipoVivienda();
	MuestraTipoVivienda();
	emit SignalTipoVivienda(zSisRegTipoVivienda);
}
void QCtrlTipoViviendaSS::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlTipoViviendaSS::ConsultaTipoVivienda()
{
zOperacionesServiSNTE lzSisOpTipoViviendaSS(zSisConexion,"TipoVivienda");
if(zSisRegTipoViviendaSS)
LogSiscom("ya tiene algo");
else
LogSiscom("No tiene nada");
if((zSisRegTipoViviendaSS=lzSisOpTipoViviendaSS.TipoViviendaSS()))
{
SiscomRegistrosLog(zSisRegTipoViviendaSS);
zSisRegTipoVivienda=(*zSisRegTipoViviendaSS)[0];
}
else
LogSiscom("NO hay productos aun");
}
void QCtrlTipoViviendaSS::ConectaSlots()
{
connect(QCBTipoVivienda,
	SIGNAL(activated(int )),
	SLOT(SlotTipoVivienda(int)));
connect(QLETipoVivienda,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLETipoVivienda,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoTipoVivienda(const QString &)));
}
void QCtrlTipoViviendaSS::SlotCapturandoTipoVivienda(const QString &pQStrTipoVivienda)
{
	if(pQStrTipoVivienda.isEmpty())
	emit SignalTipoViviendaVacia();
}
void QCtrlTipoViviendaSS::SlotTipoVivienda(int pintTipoVivienda)
{
  zSisRegTipoVivienda=(*zSisRegTipoViviendaSS)[pintTipoVivienda];
  SiscomRegistroLog2(zSisRegTipoVivienda);
}
void QCtrlTipoViviendaSS::SlotCapturo()
{
if(zSisRegTipoVivienda)
{
emit SignalTipoVivienda(zSisRegTipoVivienda);
zSisRegTipoVivienda=0;
}
else
{
LogSiscom("La TipoVivienda No existe, se registra");
emit SignalNuevoTipoVivienda(QLETipoVivienda->text());
}
}
void QCtrlTipoViviendaSS::setFocus()
{
   zSiscomQt3::Foco(QLETipoVivienda); 
   QLETipoVivienda->selectAll();
}

const char *QCtrlTipoViviendaSS::TipoVivienda()
{
return  (const char *)QLETipoVivienda->text();
}

void QCtrlTipoViviendaSS::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlTipoViviendaSS::ReIniciaControl()
{
   zSisRegTipoViviendaSS->Libera();
   QCBTipoVivienda->clear();
   IniciaControl();
}
