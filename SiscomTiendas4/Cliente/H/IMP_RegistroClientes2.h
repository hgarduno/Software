
#ifndef __IMP_REGISTROCLIENTES2_H__
#define __IMP_REGISTROCLIENTES2_H__
#include <UIC_H_RegistroClientes2.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;


class CQSisCliente;
class QRegistroClientes2:public RegistroClientes2
{
 Q_OBJECT
public:
	QRegistroClientes2(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroClientes2();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisCliente *CQSCliente;
	SiscomRegistro3Lst SisReg3LstDirecciones;
	const char *chrPtrIdPersona;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisCliente *Cliente();
	void RegistraG();
	void ConsultaDirecciones();
	void ConsultandoDirecciones();
	void MuestraDirecciones();
	void AnexarDireccion();

private slots:
	void SlotPasaFocoAPaterno();
	void SlotPasaFocoAMaterno();
	void SlotPasaFocoRFC();
	void SlotPasaFocoRegistraGenerales();
	void SlotRegistraG();
	void SlotAnexarDireccion();
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QRegistroClientes2 *InstanciaRegistroClientes2(void *,char **,void *,const char *,int);
#endif
