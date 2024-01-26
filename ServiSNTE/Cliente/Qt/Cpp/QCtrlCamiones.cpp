#include <QCtrlCamiones.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlCamiones::QCtrlCamiones( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegCamion(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlCamiones::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBCamion=new QComboBox(this);
	QHBLayout->addWidget(QCBCamion);
	QLECamion=zSiscomQt3::EditAlCombo(QCBCamion,"QLECamion");
	QCBCamion->setAutoCompletion(true);
	QCBCamion->setDuplicatesEnabled(false);
	QCBCamion->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlCamiones::MuestraCamion()
{
zSiscomQt3::RegistrosAlCombo(QCBCamion,"nombre",zSisRegCamiones);

}
void QCtrlCamiones::IniciaControl()
{
	ConsultaCamion();
	MuestraCamion();
}
void QCtrlCamiones::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlCamiones::ConsultaCamion()
{
zOperacionesServiSNTE lzSisOpCamiones(zSisConexion,"Camiones");
if((zSisRegCamiones=lzSisOpCamiones.Camiones()))
{
}
else
LogSiscom("NO hay plazos aun");
}
void QCtrlCamiones::ConectaSlots()
{
connect(QCBCamion,
	SIGNAL(activated(int )),
	SLOT(SlotCamion(int)));
connect(QLECamion,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLECamion,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoCamion(const QString &)));
}
void QCtrlCamiones::SlotCapturandoCamion(const QString &pQStrCamion)
{
	if(pQStrCamion.isEmpty())
	emit SignalCamionVacia();
}
void QCtrlCamiones::SlotCamion(int pintCamion)
{
  zSisRegCamion=(*zSisRegCamiones)[pintCamion];
  SiscomRegistroLog2(zSisRegCamion);
}
void QCtrlCamiones::SlotCapturo()
{
if(zSisRegCamion)
{
emit SignalCamion(zSisRegCamion);
zSisRegCamion=0;
}
else
{
LogSiscom("La Camion No existe, se registra");
emit SignalNuevoCamion(QLECamion->text());
}
}
void QCtrlCamiones::setFocus()
{
   zSiscomQt3::Foco(QLECamion); 
   QLECamion->selectAll();
}

const char *QCtrlCamiones::Camion()
{
return  (const char *)QLECamion->text();
}

void QCtrlCamiones::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlCamiones::ReIniciaControl()
{
   zSisRegCamiones->Libera();
   QCBCamion->clear();
   IniciaControl();
}
