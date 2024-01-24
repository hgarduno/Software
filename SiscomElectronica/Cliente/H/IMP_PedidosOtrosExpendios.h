
#ifndef __IMP_PEDIDOSOTROSEXPENDIOS_H__
#define __IMP_PEDIDOSOTROSEXPENDIOS_H__
#include <UIC_H_PedidosOtrosExpendios.h>
class SiscomDatCom;

class zSiscomRegistro;
class zSiscomRegistros;
class zSiscomConexion;

class QPedidosOtrosExpendios:public PedidosOtrosExpendios
{
 Q_OBJECT
public:
	QPedidosOtrosExpendios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPedidosOtrosExpendios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsProductos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void Imprimiendo();
private slots:
	void SlotActualizar();
	void SlotImprimir();
};
extern "C" QPedidosOtrosExpendios *InstanciaPedidosOtrosExpendios(void *,char **,void *,const char *,int);
#endif
