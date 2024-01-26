#include <QCtrlFrecuenciaTransaccionalSS.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlFrecuenciaTransaccionalSS::QCtrlFrecuenciaTransaccionalSS( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegFrecuenciaTransaccional(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlFrecuenciaTransaccionalSS::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBFrecuenciaTransaccional=new QComboBox(this);
	QHBLayout->addWidget(QCBFrecuenciaTransaccional);
	QLEFrecuenciaTransaccional=zSiscomQt3::EditAlCombo(QCBFrecuenciaTransaccional,"QLEFrecuenciaTransaccional");
	QCBFrecuenciaTransaccional->setAutoCompletion(true);
	QCBFrecuenciaTransaccional->setDuplicatesEnabled(false);
	QCBFrecuenciaTransaccional->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlFrecuenciaTransaccionalSS::MuestraFrecuenciaTransaccional()
{
zSiscomQt3::RegistrosAlCombo(QCBFrecuenciaTransaccional,"nombre",zSisRegFrecuenciaTransaccionalSS);

}
void QCtrlFrecuenciaTransaccionalSS::IniciaControl()
{
	ConsultaFrecuenciaTransaccional();
	MuestraFrecuenciaTransaccional();
}
void QCtrlFrecuenciaTransaccionalSS::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlFrecuenciaTransaccionalSS::ConsultaFrecuenciaTransaccional()
{
zOperacionesServiSNTE lzSisOpFrecuenciaTransaccionalSS(zSisConexion,"FrecuenciaTransaccionalSS");
if((zSisRegFrecuenciaTransaccionalSS=lzSisOpFrecuenciaTransaccionalSS.FrecuenciaTransaccionalSS()))
SiscomRegistrosLog(zSisRegFrecuenciaTransaccionalSS);
else
LogSiscom("NO hay productos aun");
}
void QCtrlFrecuenciaTransaccionalSS::ConectaSlots()
{
connect(QCBFrecuenciaTransaccional,
	SIGNAL(activated(int )),
	SLOT(SlotFrecuenciaTransaccional(int)));
connect(QLEFrecuenciaTransaccional,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEFrecuenciaTransaccional,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoFrecuenciaTransaccional(const QString &)));
}
void QCtrlFrecuenciaTransaccionalSS::SlotCapturandoFrecuenciaTransaccional(const QString &pQStrFrecuenciaTransaccional)
{
	if(pQStrFrecuenciaTransaccional.isEmpty())
	emit SignalFrecuenciaTransaccionalVacia();
}
void QCtrlFrecuenciaTransaccionalSS::SlotFrecuenciaTransaccional(int pintFrecuenciaTransaccional)
{
  zSisRegFrecuenciaTransaccional=(*zSisRegFrecuenciaTransaccionalSS)[pintFrecuenciaTransaccional];
  SiscomRegistroLog2(zSisRegFrecuenciaTransaccional);
}
void QCtrlFrecuenciaTransaccionalSS::SlotCapturo()
{
if(zSisRegFrecuenciaTransaccional)
{
emit SignalFrecuenciaTransaccional(zSisRegFrecuenciaTransaccional);
zSisRegFrecuenciaTransaccional=0;
}
else
{
LogSiscom("La FrecuenciaTransaccional No existe, se registra");
emit SignalNuevoFrecuenciaTransaccional(QLEFrecuenciaTransaccional->text());
}
}
void QCtrlFrecuenciaTransaccionalSS::setFocus()
{
   zSiscomQt3::Foco(QLEFrecuenciaTransaccional); 
   QLEFrecuenciaTransaccional->selectAll();
}

const char *QCtrlFrecuenciaTransaccionalSS::FrecuenciaTransaccional()
{
return  (const char *)QLEFrecuenciaTransaccional->text();
}

void QCtrlFrecuenciaTransaccionalSS::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlFrecuenciaTransaccionalSS::ReIniciaControl()
{
   zSisRegFrecuenciaTransaccionalSS->Libera();
   QCBFrecuenciaTransaccional->clear();
   IniciaControl();
}
