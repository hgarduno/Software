
#ifndef __IMP_REGISTROCLIENTES_H__
#define __IMP_REGISTROCLIENTES_H__
#include <UIC_H_RegistroClientes.h>
class SiscomDatCom;
class CQSisCliente;
class QRegistroClientes:public RegistroClientes
{
 Q_OBJECT
public:
	QRegistroClientes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroClientes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisCliente *CQSCliente;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Registra();
	CQSisCliente *Cliente();
	void HabilitaControles(int);
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoRFC();
	void SlotPasaFocoRegistrar();
	void SlotRegistrar();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QRegistroClientes *InstanciaRegistroClientes(void *,char **,void *,const char *,int);
#endif
