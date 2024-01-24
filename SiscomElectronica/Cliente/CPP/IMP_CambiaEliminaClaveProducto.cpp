#include <IMP_CambiaEliminaClaveProducto.h>

#include <CQSis3QtComunes.h>
#include <SiscomDesarrollo3Qt++.h>
#include <SiscomRegistros3.h>
#include <QCtrlProdSiscomElectronica.h>

#include <qtextedit.h>
#include <qlineedit.h>
#include <qpushbutton.h>
QCambiaEliminaClaveProducto::QCambiaEliminaClaveProducto(SiscomDatCom *pSisDatCom, 
			            char **pchrPtrArgumentos, 
				    QWidget *pQWParent,       
				    const char *pchrPtrName,
				    bool pbModal,
				    WFlags pWFlags):	      
				CambiaEliminaClaveProducto(pQWParent,
							   pchrPtrName,
							   pbModal,
							   pWFlags),
				SisDatCom(pSisDatCom),
				chrPtrArgumentos(pchrPtrArgumentos)
{
IniciaVariables();
ConectaSlots();
exec();
}

QCambiaEliminaClaveProducto::~QCambiaEliminaClaveProducto()
{

}

void QCambiaEliminaClaveProducto::ConectaSlots()
{

	connect(QCtrProdSiscom,
		SIGNAL(SignalSelecciono(SiscomRegistro3 *)),
		SLOT(SlotProducto(SiscomRegistro3 *)));
	connect(QLECveNueva,
		SIGNAL(returnPressed()),
		SLOT(SlotPasaFocoCambiaClave()));
	connect(QPBCClave,
		SIGNAL(clicked()),
		SLOT(SlotCambiaClave()));
	connect(QPBEProducto,
		SIGNAL(clicked()),
		SLOT(SlotEliminaProducto()));
}
void QCambiaEliminaClaveProducto::SlotEliminaProducto()
{
SiscomRegistro3Lst lSisReg3LstRegreso;
CQSis3QtComunes lCQS3QtCClave(SisDatCom);
lCQS3QtCClave.EliminaProducto(chrPtrArgumentos[0],
			  SisReg3Producto,
			  &lSisReg3LstRegreso);
QCtrProdSiscom->setFocus();

}
void QCambiaEliminaClaveProducto::SlotPasaFocoCambiaClave()
{
  SiscomDesarrollo3Qt::PasaFocoControl(QPBCClave);
}
void QCambiaEliminaClaveProducto::SlotCambiaClave()
{
SiscomRegistro3Lst lSisReg3LstRegreso;
CQSis3QtComunes lCQS3QtCClave(SisDatCom);
lCQS3QtCClave.CambiaClave(chrPtrArgumentos[0],
			  SiscomDesarrollo3Qt::ObtenInformacionDelEdit(QLECveNueva),
			  SisReg3Producto,
			  &lSisReg3LstRegreso);
QCtrProdSiscom->setFocus();
}
void QCambiaEliminaClaveProducto::SlotProducto(SiscomRegistro3 *pSisReg3Producto)
{
	QTEDescripcion->setText((*pSisReg3Producto)["dscproducto"]);	
	QLECveNueva->setText((*pSisReg3Producto)["cveproducto"]);
	SiscomDesarrollo3Qt::PasaFocoControl(QLECveNueva);
	SisReg3Producto=pSisReg3Producto;
}
void QCambiaEliminaClaveProducto::IniciaVariables()
{
 QCtrProdSiscom->Servidor(SisDatCom);
 QCtrProdSiscom->IdExpendio(*chrPtrArgumentos);
 QCtrProdSiscom->IniciaControl();
}
