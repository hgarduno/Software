#include <QCtrlTiposFolio.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlTiposFolio::QCtrlTiposFolio( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegFolio(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlTiposFolio::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBFolio=new QComboBox(this);
	QHBLayout->addWidget(QCBFolio);
	QLEFolio=zSiscomQt3::EditAlCombo(QCBFolio,"QLEFolio");
	QCBFolio->setAutoCompletion(true);
	QCBFolio->setDuplicatesEnabled(false);
	QCBFolio->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlTiposFolio::MuestraFolio()
{
zSiscomQt3::RegistrosAlCombo(QCBFolio,"folio",zSisRegTiposFolio);

}
void QCtrlTiposFolio::IniciaControl()
{
	ConsultaFolio();
	MuestraFolio();
}
void QCtrlTiposFolio::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlTiposFolio::ConsultaFolio()
{
zOperacionesServiSNTE lzSisOpTiposFolio(zSisConexion,"TiposFolio");
if((zSisRegTiposFolio=lzSisOpTiposFolio.TiposFolio()))
{

}
else
LogSiscom("NO hay plazos aun");
}
void QCtrlTiposFolio::ConectaSlots()
{
connect(QCBFolio,
	SIGNAL(activated(int )),
	SLOT(SlotFolio(int)));
connect(QLEFolio,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEFolio,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoFolio(const QString &)));
}
void QCtrlTiposFolio::SlotCapturandoFolio(const QString &pQStrFolio)
{
	if(pQStrFolio.isEmpty())
	emit SignalFolioVacia();
}
void QCtrlTiposFolio::SlotFolio(int pintFolio)
{
  zSisRegFolio=(*zSisRegTiposFolio)[pintFolio];
  SiscomRegistroLog2(zSisRegFolio);
}
void QCtrlTiposFolio::SlotCapturo()
{
if(zSisRegFolio)
{
emit SignalFolio(zSisRegFolio);
zSisRegFolio=0;
}
else
{
LogSiscom("La Folio No existe, se registra");
emit SignalNuevoFolio(QLEFolio->text());
}
}
void QCtrlTiposFolio::setFocus()
{
   zSiscomQt3::Foco(QLEFolio); 
   QLEFolio->selectAll();
}

const char *QCtrlTiposFolio::Folio()
{
return  (const char *)QLEFolio->text();
}

void QCtrlTiposFolio::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlTiposFolio::ReIniciaControl()
{
   zSisRegTiposFolio->Libera();
   QCBFolio->clear();
   IniciaControl();
}
