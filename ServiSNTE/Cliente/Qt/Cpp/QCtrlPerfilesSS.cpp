#include <QCtrlPerfilesSS.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

typedef enum {Perfil, Chofer} tipoPersona;

QCtrlPerfilesSS::QCtrlPerfilesSS( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegPerfil(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlPerfilesSS::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBPerfil=new QComboBox(this);
	QHBLayout->addWidget(QCBPerfil);
	QLEPerfil=zSiscomQt3::EditAlCombo(QCBPerfil,"QLEPerfil");
	QCBPerfil->setAutoCompletion(true);
	QCBPerfil->setDuplicatesEnabled(false);
	QCBPerfil->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlPerfilesSS::MuestraPerfil()
{
zSiscomQt3::RegistrosAlCombo(QCBPerfil,"tipopersona",zSisRegPerfilesSS);

}
void QCtrlPerfilesSS::IniciaControl()
{
        ConsultaPerfil();
	MuestraPerfil();
}
void QCtrlPerfilesSS::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlPerfilesSS::ConsultaPerfil()
{
zOperacionesServiSNTE lzSisOpPerfilesSS(zSisConexion,"PerfilesSS");
if((zSisRegPerfilesSS=lzSisOpPerfilesSS.PerfilesSS(lchrArrTipoPersona)))
{

}
else
LogSiscom("NO hay %s",lchrArrTipoPersona);
}
void QCtrlPerfilesSS::ConectaSlots()
{
connect(QCBPerfil,
	SIGNAL(activated(int )),
	SLOT(SlotPerfil(int)));
connect(QLEPerfil,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEPerfil,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoPerfil(const QString &)));
}
void QCtrlPerfilesSS::SlotCapturandoPerfil(const QString &pQStrPerfil)
{
	if(pQStrPerfil.isEmpty())
	emit SignalPerfilVacia();
}
void QCtrlPerfilesSS::SlotPerfil(int pintPerfil)
{
  zSisRegPerfil=(*zSisRegPerfilesSS)[pintPerfil];
}
void QCtrlPerfilesSS::SlotCapturo()
{
if(zSisRegPerfil)
{
emit SignalPerfil(zSisRegPerfil);
zSisRegPerfil=0;
}
else
{
LogSiscom("La Perfil No existe, se registra");
emit SignalNuevoPerfil(QLEPerfil->text());
}
}
void QCtrlPerfilesSS::setFocus()
{
   zSiscomQt3::Foco(QLEPerfil); 
   QLEPerfil->selectAll();
}

const char *QCtrlPerfilesSS::Perfil()
{
return  (const char *)QLEPerfil->text();
}

void QCtrlPerfilesSS::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlPerfilesSS::ReIniciaControl()
{
   zSisRegPerfilesSS->Libera();
   QCBPerfil->clear();
   IniciaControl();
}
