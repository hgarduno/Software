#include <IMP_TotalComprasProducto.h>
#include <SiscomDesarrollo3Qt++.h>

#include <CQSisRastreoProducto.h>
 #include <qlcdnumber.h>
QTotalComprasProducto::QTotalComprasProducto(
				    CQSisRastreoProducto *pCQSRastreoP,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				TotalComprasProducto(pQWParent,pchrPtrName,pWFlags),
				CQSRastreoProducto(pCQSRastreoP)
{
IniciaVariables();
ConectaSlots();
}

QTotalComprasProducto::~QTotalComprasProducto()
{

}

void QTotalComprasProducto::ConectaSlots()
{


}
void QTotalComprasProducto::IniciaVariables()
{
const char *lchrPtrCampos[]={"fecha","cantidad","razonsocial",0};
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
				       QTDatos,
				       CQSRastreoProducto->ComprasProducto());

SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
QLCDNCantidad->setNumDigits(10);
QLCDNCantidad->display(CQSRastreoProducto->TotalCompras());
}
