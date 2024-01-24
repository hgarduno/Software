
#ifndef __IMP_INFORMACIONPEDIDO_H__
#define __IMP_INFORMACIONPEDIDO_H__
#include <UIC_H_InformacionPedido.h>
class SiscomDatCom;
class CQSisPedido;
class CQSisEmpleado;
class QInformacionPedido:public InformacionPedido
{
 Q_OBJECT
public:
	QInformacionPedido(const char *,
	    SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QInformacionPedido();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	const char *chrPtrNoPedido;
	CQSisEmpleado *CQSEmpleado;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Registra();
	CQSisPedido *Pedido();
private slots:
	void SlotRegistra();
};
#endif
