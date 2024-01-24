#include <IMP_TransferenciasExpendioExpendio.h>

#include <SiscomDesarrollo3Qt++.h>
#include <CQSisRastreoProducto.h>

 #include <qlcdnumber.h>
QTransferenciasExpendioExpendio::QTransferenciasExpendioExpendio(
				    CQSisRastreoProducto *pCQSRastreoP,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				TransferenciasExpendioExpendio(pQWParent,pchrPtrName,pWFlags),
				CQSRastreoProducto(pCQSRastreoP)
{
IniciaVariables();
ConectaSlots();
}

QTransferenciasExpendioExpendio::~QTransferenciasExpendioExpendio()
{

}

void QTransferenciasExpendioExpendio::ConectaSlots()
{


}
void QTransferenciasExpendioExpendio::IniciaVariables()
{
const char *lchrPtrCampos[]={"fechahora",
			"origen",
			"destino",
			"cantidad",
			0};
if(!CQSRastreoProducto->EdoConsultaTransExpExp())
{
SiscomDesarrollo3Qt::RegistrosALaTabla(lchrPtrCampos,
			QTDatos,
			CQSRastreoProducto->TransferenciasExpendioExpendio());

SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
QLCDNCantidad->setNumDigits(10);
QLCDNCantidad->display(CQSRastreoProducto->TotalTransExpendioExpendio());
}
}
