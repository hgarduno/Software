#include <IMP_TransferenciasBodegasExpendio.h>
#include <SiscomDesarrollo3Qt++.h>

#include <CQSisRastreoProducto.h>

#include <qlcdnumber.h>
QTransferenciasBodegasExpendio::QTransferenciasBodegasExpendio(
				    CQSisRastreoProducto *pCQSRastreoP,
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    WFlags pWFlags):	      
				TransferenciasBodegasExpendio(pQWParent,pchrPtrName,pWFlags),	
				CQSRastreoProducto(pCQSRastreoP)
{
IniciaVariables();
ConectaSlots();
}

QTransferenciasBodegasExpendio::~QTransferenciasBodegasExpendio()
{

}

void QTransferenciasBodegasExpendio::ConectaSlots()
{


}
void QTransferenciasBodegasExpendio::IniciaVariables()
{
const char *lchrPtrCampos[]={"idbodega",
			"razonsocial",
			"fecha",
			"cantidad",
			0};
SiscomDesarrollo3Qt::RegistrosALaTabla(
		lchrPtrCampos,
		QTDatos,
		CQSRastreoProducto->TransferenciasBodegasExpendio());
SiscomDesarrollo3Qt::AjustaColumnas(QTDatos);
QLCDNCantidad->setNumDigits(10);
QLCDNCantidad->display(CQSRastreoProducto->TotalTransBodegaExpendio());
}
