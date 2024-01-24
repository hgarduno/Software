
#ifndef __IMP_SELECCIONACLIENTE_H__
#define __IMP_SELECCIONACLIENTE_H__
#include <UIC_H_SeleccionaCliente.h>
class SiscomDatCom;
class SiscomRegistro3;
class QSeleccionaCliente:public SeleccionaCliente
{
 Q_OBJECT
public:
	QSeleccionaCliente(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QSeleccionaCliente();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SReg3Cliente;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraContactos();
private slots:
	void SlotMoral(SiscomRegistro3 *);
	void SlotFisica(SiscomRegistro3 *);

};
#endif
