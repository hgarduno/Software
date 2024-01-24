
#ifndef __IMP_FACTURANDO4_H__
#define __IMP_FACTURANDO4_H__
#include <UIC_H_Facturando4.h>
#include <zOrdenes.h>
#include <zFactura.h>
class SiscomDatCom;
class zSiscomConexion;
class zCliente;
class QFacturando4:public Facturando4
{
 Q_OBJECT
public:
	QFacturando4(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QFacturando4();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zOrdenes zOrdenesF;
	zFactura zFacturaD;
	zSiscomConexion *zSisConexion;
	zCliente *zClienteC;
	int intPersonaFisica;
	void closeEvent(QCloseEvent *);
	int SeLiberaFactura(int pintRegreso);
private:
	void ConectaSlots();
	void IniciaVariables();
	void Calculando();
	void Calcula();
	void Muestra();
	void MuestraCliente();
	int EnviaFactura();
	void Cliente(char *pchrPtrCliente);
	void ImporteLetra();
	void LiberaFacturacion();
private slots:
	void SlotOrdenesFecha();
	void SlotDatosFacturacion();
	void SlotRealizaFactura();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QFacturando4 *InstanciaFacturando4(void *,char **,void *,const char *,int);
#endif
