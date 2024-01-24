#ifndef __IMP_RECIBEPEDIDO_H__
#define __IMP_RECIBEPEDIDO_H__
#include <CQSisPedidoMaterial.h>
#include <UIC_H_RecibePedido.h>
#include <TransfiereProducto.h>
class SiscomDatCom;
class SiscomRegistros2Pro;
class QRecibePedido:public RecibePedido
{
 Q_OBJECT
public:
	QRecibePedido(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRecibePedido();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QRecibePedido *InstanciaRecibePedido(void *,char **,void *,const char *,int);
#endif
