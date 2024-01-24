
#ifndef __IMP_IMPRIMEFACTURA_H__
#define __IMP_IMPRIMEFACTURA_H__
#include <qdialog.h>
class QGridLayout;
class QtSisImprimeFactura;
class QPushButton;
class SiscomRegistro3;
class SiscomRegistro3Lst;
class QImprimeFactura:public QDialog
{
 Q_OBJECT
public:
	QImprimeFactura(
		SiscomRegistro3 *pSisRegCliente,
		SiscomRegistro3Lst *pSisReg3LstProductos,
		QWidget *pQWParent=0,
	    	const char *pchrPtrName=0,
	    	bool pbModal=false,
	    	WFlags pWFlags=0);
	~QImprimeFactura();
private:
	QGridLayout *QHBRegilla;
	QPushButton *QPBImprime;
	QtSisImprimeFactura *QtSisImpFactura;
	SiscomRegistro3 *SisReg3Cliente;
	SiscomRegistro3Lst *SisReg3LstProductos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotImprime();
};
#endif
