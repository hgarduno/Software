#include <QCtrlPlazos.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlPlazos::QCtrlPlazos( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegPlazo(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlPlazos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBPlazo=new QComboBox(this);
	QHBLayout->addWidget(QCBPlazo);
	QLEPlazo=zSiscomQt3::EditAlCombo(QCBPlazo,"QLEPlazo");
	QCBPlazo->setAutoCompletion(true);
	QCBPlazo->setDuplicatesEnabled(false);
	QCBPlazo->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlPlazos::MuestraPlazo()
{
zSiscomQt3::RegistrosAlCombo(QCBPlazo,"nombre",zSisRegPlazos);

}
void QCtrlPlazos::IniciaControl()
{
	ConsultaPlazo();
	MuestraPlazo();
}
void QCtrlPlazos::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlPlazos::ConsultaPlazo()
{
zOperacionesServiSNTE lzSisOpPlazos(zSisConexion,"Plazos");
if((zSisRegPlazos=lzSisOpPlazos.Plazos()))
{

}
else
LogSiscom("NO hay plazos aun");
}
void QCtrlPlazos::ConectaSlots()
{
connect(QCBPlazo,
	SIGNAL(activated(int )),
	SLOT(SlotPlazo(int)));
connect(QLEPlazo,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEPlazo,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoPlazo(const QString &)));
}
void QCtrlPlazos::SlotCapturandoPlazo(const QString &pQStrPlazo)
{
	if(pQStrPlazo.isEmpty())
	emit SignalPlazoVacia();
}
void QCtrlPlazos::SlotPlazo(int pintPlazo)
{
  zSisRegPlazo=(*zSisRegPlazos)[pintPlazo];
  SiscomRegistroLog2(zSisRegPlazo);
}
void QCtrlPlazos::SlotCapturo()
{
if(zSisRegPlazo)
{
emit SignalPlazo(zSisRegPlazo);
zSisRegPlazo=0;
}
else
{
LogSiscom("La Plazo No existe, se registra");
emit SignalNuevoPlazo(QLEPlazo->text());
}
}
void QCtrlPlazos::setFocus()
{
   zSiscomQt3::Foco(QLEPlazo); 
   QLEPlazo->selectAll();
}

const char *QCtrlPlazos::Plazo()
{
return  (const char *)QLEPlazo->text();
}

void QCtrlPlazos::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlPlazos::ReIniciaControl()
{
   zSisRegPlazos->Libera();
   QCBPlazo->clear();
   IniciaControl();
}
