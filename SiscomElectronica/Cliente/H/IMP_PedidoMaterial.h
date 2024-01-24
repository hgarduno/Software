
#ifndef __IMP_PEDIDOMATERIAL_H__
#define __IMP_PEDIDOMATERIAL_H__
#include <UIC_H_PedidoMaterial.h>
#include <CQSisPedidoMaterial.h>
class SiscomDatCom;
class QLEdita;
class QManProductos;
class ProductoE;
class QPedidoMaterial:public PedidoMaterial
{
 Q_OBJECT
public:
	QPedidoMaterial(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPedidoMaterial();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QLineEdit *QLECProductos;
	QManProductos *QMProductos;
	ProductoE *ProdSeleccionado;
	CQSisPedidoMaterial CQSPedidoMaterial;
	int intProductoSeleccionado;
private:
	void ConectaSlots();
	void IniciaVariables();
	void AnexarProducto();
	void MuestraProductos();
	SiscomRegistro3 *RegistraPedidoMaterial();
	void ReIniciaVentana();
	void CapturaObservacionProducto(int pintNProducto);
	void EliminaProducto();
private slots:
	void S_Producto(ProductoE *);
	void S_Anexar();
	void S_FocoAAnexar();
	void S_RegistraPedidoMaterial();
	void S_SeleccionoTabla(int,int,int,const QPoint &);
	void S_EliminaProducto(int,int,int,const QPoint &);
	void S_EliminaProducto();
	void S_PedidosPendientes();
};
extern "C" QPedidoMaterial *InstanciaPedidoMaterial(void *,char **,void *,const char *,int);
#endif
