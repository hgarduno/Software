#include <QCtrlVendedores.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>

typedef enum {Vendedor, Chofer} tipoPersona;

QCtrlVendedores::QCtrlVendedores( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegVendedor(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlVendedores::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBVendedor=new QComboBox(this);
	QHBLayout->addWidget(QCBVendedor);
	QLEVendedor=zSiscomQt3::EditAlCombo(QCBVendedor,"QLEVendedor");
	QCBVendedor->setAutoCompletion(true);
	QCBVendedor->setDuplicatesEnabled(false);
	QCBVendedor->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlVendedores::MuestraVendedor()
{
zSiscomQt3::RegistrosAlCombo(QCBVendedor,"nombre",zSisRegVendedores);

}
void QCtrlVendedores::IniciaControl(const char *pchrArrTipoPersona)
{
	strcpy(lchrArrTipoPersona,pchrArrTipoPersona);
    ConsultaVendedor();
	MuestraVendedor();
}
void QCtrlVendedores::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlVendedores::ConsultaVendedor()
{
zOperacionesServiSNTE lzSisOpVendedores(zSisConexion,"Vendedores");
if((zSisRegVendedores=lzSisOpVendedores.Vendedores(lchrArrTipoPersona)))
{

}
else
LogSiscom("NO hay %s",lchrArrTipoPersona);
}
void QCtrlVendedores::ConectaSlots()
{
connect(QCBVendedor,
	SIGNAL(activated(int )),
	SLOT(SlotVendedor(int)));
connect(QLEVendedor,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEVendedor,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoVendedor(const QString &)));
}
void QCtrlVendedores::SlotCapturandoVendedor(const QString &pQStrVendedor)
{
	if(pQStrVendedor.isEmpty())
	emit SignalVendedorVacia();
}
void QCtrlVendedores::SlotVendedor(int pintVendedor)
{
  zSisRegVendedor=(*zSisRegVendedores)[pintVendedor];
}
void QCtrlVendedores::SlotCapturo()
{
if(zSisRegVendedor)
{
emit SignalVendedor(zSisRegVendedor);
zSisRegVendedor=0;
}
else
{
LogSiscom("La Vendedor No existe, se registra");
emit SignalNuevoVendedor(QLEVendedor->text());
}
}
void QCtrlVendedores::setFocus()
{
   zSiscomQt3::Foco(QLEVendedor); 
   QLEVendedor->selectAll();
}

const char *QCtrlVendedores::Vendedor()
{
return  (const char *)QLEVendedor->text();
}

void QCtrlVendedores::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlVendedores::ReIniciaControl()
{
   zSisRegVendedores->Libera();
   QCBVendedor->clear();
   IniciaControl(lchrArrTipoPersona);
}
