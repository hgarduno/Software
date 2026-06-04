#include <QtExistencias.h>
#include <IMP_QControlFecha.h>

#include <zPedidoExistenciaM.h>
#include <zSiscomRegistros.h>

#include <zSiscomQt3.h> 
#include <qpushbutton.h>
#include <qlineedit.h>

QtExistencias::QtExistencias(QWidget *pQWParent,
					   const char *pchrPtrName,
					   WFlags pWFlags):
					   Existencias(pQWParent,pchrPtrName,pWFlags)
{
IniciaVariables();
ConectaSlots();
}

QtExistencias::~QtExistencias()
{

}
void QtExistencias::ConectaSlots()
{
 connect(QPBPedidoEM,SIGNAL(clicked()),SLOT(SlotPedidoEM()));
 connect(QLEPorcentaje,SIGNAL(returnPressed()),SLOT(SlotCapturoPorcentaje()));
 connect(QPBRegistraPEm,SIGNAL(clicked()),SLOT(SlotRegistraPedidoEm()));
}


void QtExistencias::IniciaVariables()
{
IniciaPedidoExistenciaMinima();
}
void QtExistencias::SlotRegistraPedidoEm()
{
RegistraPedidoExistenciaMinima();
}
void QtExistencias::SlotCapturoPorcentaje()
{
 PedidoExistenciaM()->Porcentaje((const char *)QLEPorcentaje->text());
 zSiscomQt3::Foco(QPBPedidoEM);
}
void QtExistencias::SlotPedidoEM()
{
  PedidoExistenciaMinima();
 MuestraProductosMinimos();
}

void QtExistencias::IniciaPedidoExistenciaMinima()
{
zPedidoEm=new zPedidoExistenciaM;
}
zPedidoExistenciaM *QtExistencias::PedidoExistenciaM()
{
  return zPedidoEm;
}
void QtExistencias::PedidoExistenciaMinima()
{

}
void QtExistencias::RegistraPedidoExistenciaMinima()
{


}
void QtExistencias::MuestraProductosMinimos()
{
const char *lchrPtrCampos[]={"Clave",
		       "existencia",
		       "eximinima",
		       "exibodega",
		       "Cantidad",
		       0
		       };

zSiscomQt3::LlenaTabla(lchrPtrCampos,
			(zSiscomRegistros *)PedidoExistenciaM()->Productos(),
			QTDatos);
}
