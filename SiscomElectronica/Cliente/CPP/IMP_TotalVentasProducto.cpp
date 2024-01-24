#include <IMP_TotalVentasProducto.h>

#include <SiscomDesarrollo3Qt++.h>
#include <CQSisRastreoProducto.h>
#include <qtable.h>
 #include <qlcdnumber.h>
QTotalVentasProducto::QTotalVentasProducto(CQSisRastreoProducto *pCQSRastreoP,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				TotalVentasProducto(pQWParent,pchrPtrName,pWFlags),
				CQSRastreoProducto(pCQSRastreoP)
{
IniciaVariables();
ConectaSlots();
}

QTotalVentasProducto::~QTotalVentasProducto()
{

}

void QTotalVentasProducto::ConectaSlots()
{


}
void QTotalVentasProducto::IniciaVariables()
{
const char *lchrPtrCampos[]={"fechahora","cantidad","cliente",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTDatos,
				       CQSRastreoProducto->VentasProducto());

SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
QLCDNCantidad->setNumDigits(10);
QLCDNCantidad->display(CQSRastreoProducto->TotalVentas());
}
