#include <QCtrlDepartamentosSS.h>

#include <zOperacionesServiSNTE.h>
#include <zSiscomQt3.h>
#include <zSiscomConexion.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomRegistro.h>
#include <zSiscomRegistros.h>
#include <qlayout.h>
#include <qcombobox.h>
#include <qlineedit.h>


QCtrlDepartamentosSS::QCtrlDepartamentosSS( QWidget *parent, const char *name )
    : QWidget( parent, name ),
    zSisRegDepartamento(0)

{
	IniciaVariables();
	ConectaSlots();
}
void QCtrlDepartamentosSS::IniciaVariables()
{
	QHBLayout=new QHBoxLayout(this);
	QHBLayout->setMargin(0);
	QCBDepartamento=new QComboBox(this);
	QHBLayout->addWidget(QCBDepartamento);
	QLEDepartamento=zSiscomQt3::EditAlCombo(QCBDepartamento,"QLEDepartamento");
	QCBDepartamento->setAutoCompletion(true);
	QCBDepartamento->setDuplicatesEnabled(false);
	QCBDepartamento->setInsertionPolicy(QComboBox::NoInsertion);
}
void QCtrlDepartamentosSS::MuestraDepartamento()
{
zSiscomQt3::RegistrosAlCombo(QCBDepartamento,"nombredepto",zSisRegDepartamentosSS);

}
void QCtrlDepartamentosSS::IniciaControl()
{
	ConsultaDepartamento();
	MuestraDepartamento();
}
void QCtrlDepartamentosSS::Servidor(zSiscomConexion *pzSisConexion)
{
 zSisConexion=pzSisConexion;
}
void QCtrlDepartamentosSS::ConsultaDepartamento()
{
zOperacionesServiSNTE lzSisOpDepartamentosSS(zSisConexion,"Departamentos");
if((zSisRegDepartamentosSS=lzSisOpDepartamentosSS.DepartamentosSS()))
SiscomRegistrosLog(zSisRegDepartamentosSS);
else
LogSiscom("NO hay productos aun");
}
void QCtrlDepartamentosSS::ConectaSlots()
{
connect(QCBDepartamento,
	SIGNAL(activated(int )),
	SLOT(SlotDepartamento(int)));
connect(QLEDepartamento,
	SIGNAL(returnPressed()),
	SLOT(SlotCapturo()));
connect(QLEDepartamento,
	SIGNAL(textChanged(const QString &)),
	SLOT(SlotCapturandoDepartamento(const QString &)));
}
void QCtrlDepartamentosSS::SlotCapturandoDepartamento(const QString &pQStrDepartamento)
{
	if(pQStrDepartamento.isEmpty())
	emit SignalDepartamentoVacia();
}
void QCtrlDepartamentosSS::SlotDepartamento(int pintDepartamento)
{
  zSisRegDepartamento=(*zSisRegDepartamentosSS)[pintDepartamento];
  SiscomRegistroLog2(zSisRegDepartamento);
}
void QCtrlDepartamentosSS::SlotCapturo()
{
if(zSisRegDepartamento)
{
emit SignalDepartamento(zSisRegDepartamento);
zSisRegDepartamento=0;
}
else
{
LogSiscom("La Departamento No existe, se registra");
emit SignalNuevoDepartamento(QLEDepartamento->text());
}
}
void QCtrlDepartamentosSS::setFocus()
{
   zSiscomQt3::Foco(QLEDepartamento); 
   QLEDepartamento->selectAll();
}

const char *QCtrlDepartamentosSS::Departamento()
{
return  (const char *)QLEDepartamento->text();
}

void QCtrlDepartamentosSS::keyPressEvent(QKeyEvent *pQKPTecla)
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

void QCtrlDepartamentosSS::ReIniciaControl()
{
   zSisRegDepartamentosSS->Libera();
   QCBDepartamento->clear();
   IniciaControl();
}
