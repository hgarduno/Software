#include <QCtrlTipoDocumentos.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlTipoDocumentos::QCtrlTipoDocumentos( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegTipoDocumento(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlTipoDocumentos::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBTipoDocumento=new QComboBox(this);
	QHBLayout->addWidget(QCBTipoDocumento);
	QLETipoDocumento=zSiscomQt3::EditAlCombo(QCBTipoDocumento,"QLETipoDocumento");
	QCBTipoDocumento->setAutoCompletion(true);
	QCBTipoDocumento->setDuplicatesEnabled(false);
	QCBTipoDocumento->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlTipoDocumentos::MuestraTipoDocumento()
{
zSiscomQt3::RegistrosAlCombo(QCBTipoDocumento,"nombre",zSisRegTipoDocumentos);

}
void QCtrlTipoDocumentos::IniciaControl()
{
	ConsultaTipoDocumento();
	MuestraTipoDocumento();
}
void QCtrlTipoDocumentos::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlTipoDocumentos::ConsultaTipoDocumento()
{
zOperacionesServiSNTE lzSisOpTipoDocumentos(zSisConexion,"TipoDocumentos");
if((zSisRegTipoDocumentos=lzSisOpTipoDocumentos.TipoDocumentos()))
SiscomRegistrosLog(zSisRegTipoDocumentos);
else
LogSiscom("NO hay productos aun");
}
void QCtrlTipoDocumentos::ConectaSlots()
{
connect(QCBTipoDocumento,
	SIGNAL(activated(int )),
	SLOT(SlotTipoDocumento(int)));
connect(QLETipoDocumento,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLETipoDocumento,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoTipoDocumento(const QString &)));
}
void QCtrlTipoDocumentos::SlotCapturandoTipoDocumento(const QString &pQStrTipoDocumento)
{
	if(pQStrTipoDocumento.isEmpty())
	emit SignalTipoDocumentoVacia();
}
void QCtrlTipoDocumentos::SlotTipoDocumento(int pintTipoDocumento)
{
  zSisRegTipoDocumento=(*zSisRegTipoDocumentos)[pintTipoDocumento];
  SiscomRegistroLog2(zSisRegTipoDocumento);
}
void QCtrlTipoDocumentos::SlotCapturo()
{
if(zSisRegTipoDocumento)
{
emit SignalTipoDocumento(zSisRegTipoDocumento);
zSisRegTipoDocumento=0;
}
else
{
LogSiscom("La TipoDocumento No existe, se registra");
emit SignalNuevoTipoDocumento(QLETipoDocumento->text());
}
}
void QCtrlTipoDocumentos::setFocus()
{
   zSiscomQt3::Foco(QLETipoDocumento); 
   QLETipoDocumento->selectAll();
}

const char *QCtrlTipoDocumentos::TipoDocumento()
{
return  (const char *)QLETipoDocumento->text();
}

void QCtrlTipoDocumentos::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlTipoDocumentos::ReIniciaControl()
{
   zSisRegTipoDocumentos->Libera();
   QCBTipoDocumento->clear();
   IniciaControl();
}
