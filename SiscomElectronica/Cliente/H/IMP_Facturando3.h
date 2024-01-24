
#ifndef __IMP_FACTURANDO3_H__
#define __IMP_FACTURANDO3_H__
#include <UIC_H_Facturando3.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class QImprimeFactura;
class SiscomRegistro3;
class QFacturando3:public Facturando3
{
 Q_OBJECT
public:
	QFacturando3(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QFacturando3();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QImprimeFactura *QIFactura;
	QWidget *QWParent;
	SiscomRegistro3 *SisReg3Cliente;
	SiscomRegistro3Lst SisReg3LstProdAFacturar;
	SiscomRegistro3Lst SisReg3LstOrdenes;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
	void DatosFactura();
	void MuestraDatosCliente(SiscomRegistro3 *);
	void MuestraPersonaFisica(SiscomRegistro3 *);
	void MuestraPersonaMoral(SiscomRegistro3 *);
	void SeleccionaPestana(SiscomRegistro3*);
	int TipoCliente(SiscomRegistro3 *pSisReg3Cliente);
	void MuestraOrdenesAFacturar();
	void MuestraTotales();
private slots:
	void SlotImpFactura();
	void SlotCliente();
	void SlotAnexarOrden();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QFacturando3 *InstanciaFacturando3(void *,char **,void *,const char *,int);
#endif
