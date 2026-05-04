
#include <QtCuentaCortesS.h>
#include <QtCuentaCortesImp.h>
#include <IMP_SelExpendios.h>

#include <qpushbutton.h> 

QtCuentaCortesS::QtCuentaCortesS(QWidget *pQWParent,
				 const char *pchrPtrName,
				 WFlags pWFlags):
				CuentaCortes(pQWParent,pchrPtrName,pWFlags)
{
QtCCortes->setNumRows(10);
QtCCortes->setNumCols(20);
QtCCortes->Fila(2);
QtCCortes->Columna(0);
QtCCortes->IniciaVariables();

ConectaSlots();
}


void QtCuentaCortesS::SlotExpendio()
{
SeleccionaExpendio();
}
void QtCuentaCortesS::ConectaSlots()
{

connect(QPBExpendio,SIGNAL(clicked()),SLOT(SlotExpendio()));

}

void QtCuentaCortesS::SeleccionaExpendio()
{

}
