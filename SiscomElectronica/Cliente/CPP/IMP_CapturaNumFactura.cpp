#include <IMP_CapturaNumFactura.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <CQSisFacturas.h>
#include <qlineedit.h>
#include <qpushbutton.h>

QCapturaNumFactura::QCapturaNumFactura(SiscomRegistro3 *pSisReg3Factura,
				    SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CapturaNumFactura(pQWParent,
						  pchrPtrName,
						  pbModal,
						  pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos),
				SisReg3Factura(pSisReg3Factura)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCapturaNumFactura::~QCapturaNumFactura()
{

}

void QCapturaNumFactura::ConectaSlots()
{
connect(QLENumFactura,
	SIGNAL(returnPressed()),
	SLOT(SlotPasaFocoAceptar()));
connect(QPBAceptar,
	SIGNAL(clicked()),
	SLOT(SlotAceptar()));

}
void QCapturaNumFactura::SlotPasaFocoAceptar()
{
SisReg3Factura->SiscomActualizaCampo(
		 "numfactura",
		 SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLENumFactura));
SiscomDesarrollo3Qt::PasaFocoControl(QPBAceptar);
}
void QCapturaNumFactura::SlotAceptar()
{
ActualizaNumeroFactura();
}
void QCapturaNumFactura::IniciaVariables()
{
QLENumFactura->setText((*SisReg3Factura)["numfactura"]);
SiscomDesarrollo3Qt::PasaFocoControl(QLENumFactura);
}
void QCapturaNumFactura::ActualizaNumeroFactura()
{
CQSisFacturando lCQSFacturando(SisDatCom);
lCQSFacturando.ActualizaNumeroFactura(SisReg3Factura);
}
