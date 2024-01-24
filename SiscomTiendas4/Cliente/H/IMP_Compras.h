
#ifndef __IMP_COMPRAS_H__
#define __IMP_COMPRAS_H__
#include <UIC_H_Compras.h>
#include <CQSisCompras.h>
class SiscomDatCom;
class CQSisProducto;
class CQSisEmpresa;
class CQSisContacto;
class CQSisFormaPago;
class QCompras:public Compras
{
 Q_OBJECT
public:
	QCompras(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCompras();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisProducto *CQSProducto;
	CQSisEmpresa *CQSEProveedor;
	CQSisContacto *CQSContacto;
	CQSisFormaPago *CQSFPago;
	CQSisLstCompra CQSLCompra;
	CQSisLstCompra CQSLUCompra;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisCompra *FormaCompra();
	void AnexaCompra();
	void Registra();
	void ReIniciaCompra();
	void UltimaCompra();
	void MuestraUltimaCompra();
	void EjecutaUltimaCompra();
	void HabilitaRegistrar();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotProducto(CQSisProducto *);
	void SlotEmpresa(CQSisEmpresa *);
	void SlotContacto(CQSisContacto *);
	void SlotFormaPago(CQSisFormaPago *);
	void SlotPasaFocoAnexarCompra();
	void SlotPasaFocoPrecioCompra();
	void SlotPasaFocoNFactura();
	void SlotAnexar();
	void SlotRegistra();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QCompras *InstanciaCompras(void *,char **,void *,const char *,int);
#endif
