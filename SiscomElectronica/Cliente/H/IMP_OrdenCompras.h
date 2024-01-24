
#ifndef __IMP_ORDENCOMPRAS_H__
#define __IMP_ORDENCOMPRAS_H__
#include <UIC_H_OrdenCompras.h>
#include <CQSisOrdenCompra.h>
#include <zOrdenCompra.h>
class SiscomDatCom;
class QLineEdit;
class ProductoE;
class QManProductos;

class zSiscomConexion;
class QOrdenCompras:public OrdenCompras
{
 Q_OBJECT
public:
	QOrdenCompras(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QOrdenCompras();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QLineEdit *QLECProductos;
	ProductoE *ProdSeleccionado;
	QManProductos *QMProductos;
	CQSisComprasProducto CQSComprasProducto;
	CQSisOrdenCompra2 CQSOrdenCompra;
	zSiscomConexion *zSisConexion;
	zOrdenCompra zOrdCompra;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ComprasProducto();
	void ConsultaComprasProducto();
	void MuestraComprasProducto();
	void SeleccionoProducto(int pintProducto);
	void AgregaProductoALaOrden(int pintProducto);
	void MuestraOrdenCompra();
private slots:
	void S_Producto(ProductoE *pProductoE);
	void S_SeleccionaProducto(int,int,int,const QPoint &);
	void SlotProductosFaltantes();
};
extern "C" QOrdenCompras *InstanciaOrdenCompras(void *,char **,void *,const char *,int);
#endif
