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
/* Siscom Zacatenco 
 * Viernes 30 de Enero 2026 
 * llenando la tienda, rompi una racha de bicleta de muchos meses 
 * sera que 2 dias , si importan ?/
 *
 */

/* 
 * Una vez que se obtienen las ordenes de pago electronico de todos los expendios
 * se debera recibir del servidor un reporte que de alguna informacion sobre 
 * el estado de esas orenes, para posteriorme realizar la factura de publico 
 * en general por pagos electronicos
 *
 */
connect(QPBOrdsPElectronico,SIGNAL(clicked()),SLOT(SlotOrdenesPagoElectronico()));


connect(QPBFacturaPGPE,SIGNAL(clicked()),SLOT(SlotFacturaPGPE()));
}

void QtContabilidadSiscom::SlotFacturaPGPE()
{
 FacturaPublicoEnGeneralPE();
}
void QtContabilidadSiscom::SlotOrdenesPagoElectronico()
{
  OrdenesPagoElectronico();
}
void QtContabilidadSiscom::OrdenesPagoElectronico()
{

}
void QtContabilidadSiscom::FacturaPublicoEnGeneralPE()
{

}
void QtContabilidadSiscom::IniciaVariables()
{
QCtrFechaInicio->ColocaFechaHoy();
QCtrFechaFin->ColocaFechaHoy();
}
