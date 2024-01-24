
#ifndef __IMP_PEDIDOS_H__
#define __IMP_PEDIDOS_H__
#include <UIC_H_Pedidos.h>
#include <CQSisProdCotiza.h>
class SiscomDatCom;
class SiscomRegistrosPro2;
class CQSisFormaPago;
class CQSisCliente;
class CQSisPrecio;
class CQSisProducto;
class CQSisProdCotiza;
class CQSisContacto;
class QPedidos:public Pedidos
{
 Q_OBJECT
public:
	QPedidos(SiscomDatCom *,
	    char **,
	    SiscomRegistrosPro2 *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	QPedidos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);

	~QPedidos();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistrosPro2 *SRegistrosPro2;
	CQSisLstProdCotiza CQSLProdCPedidoA;
	CQSisLstProdCotiza CQSLProdCotizar;
	CQSisProdCotiza *CQSPCotizado;
	CQSisCliente *CQSCliente;
private:
	void ConectaSlots();
	void IniciaVariablesPedidoAnterior();
	void IniciaVariablesPedidoNuevo();
	void MuestraPedidoAnterior();
	void CotizaPedido();
	void MuestraPedido();
	void CotizandoPedido();
	void RegistraVenta();
	void GeneraIdPedido();
	void RegistraPedido();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotCotizando(CQSisCliente *,
			    CQSisFormaPago *,
			    CQSisPrecio *,
			    CQSisProducto *,
			    CQSisProdCotiza *,
			    CQSisContacto *);
	void SlotAnexar();
	void SlotRegistrar();
	void SlotClienteFisica(CQSisCliente *);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QPedidos *InstanciaPedidos(void *,char **,void *,const char *,int);
#endif
