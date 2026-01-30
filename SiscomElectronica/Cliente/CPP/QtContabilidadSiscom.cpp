#include <QtContabilidadSiscom.h>
#include <IMP_QControlFecha.h>

#include <qpushbutton.h>

QtContabilidadSiscom::QtContabilidadSiscom(QWidget *pQWParent,
					   const char *pchrPtrName,
					   WFlags pWFlags):
					   ContabilidadSiscom(pQWParent,pchrPtrName,pWFlags)
{
IniciaVariables();
ConectaSlots();
}

QtContabilidadSiscom::~QtContabilidadSiscom()
{

}
void QtContabilidadSiscom::ConectaSlots()
{
connect(QPBOrdsPElectronico,SIGNAL(clicked()),SLOT(SlotOrdenesPagoElectronico()));

}

void QtContabilidadSiscom::SlotOrdenesPagoElectronico()
{
  OrdenesPagoElectronico();
}
void QtContabilidadSiscom::OrdenesPagoElectronico()
{

}
void QtContabilidadSiscom::IniciaVariables()
{
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
}
