#ifndef __IMP_MANEJADORKITS_H__
#define __IMP_MANEJADORKITS_H__
#include <UIC_H_ManejadorKits.h>
#include <CQSisProductoPorTipo.h>
class zSiscomConexion;
class SiscomDatCom;
class QLineEdit;
class QManProductos;
class ProductoE;
class zSiscomRegistro;
class QManejadorKits:public ManejadorKits
{
 Q_OBJECT
public:
	QManejadorKits(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QManejadorKits();
private:
	zSiscomConexion *zSisConexion;
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QLineEdit *QLECProductos;
	QManProductos *QMProductos;
	ProductoE *ProdSeleccionado;
	CQSisProductoPorTipo CQSProductoPorTipo;
	const char *chrPtrIdProducto;
	zSiscomRegistro *zSisRegTipoProducto;

private:
	void ConectaSlots();
	void IniciaVariables();
	ProductoE *RegistraKit();
	void MuestraProductoAsignado(ProductoE *pProdATipoProducto);
	void Anexar();
	void MuestraProductosDelProducto();
	void HabilitaEliminaRegistra();
	void RegistraProductos();

	void ReIniciandoRegistro();
private slots:
	void S_Producto(ProductoE *);
	void S_RegistraKit();
	void S_Anexar();
	void S_FocoAAnexar();
	void S_RegistraProductos();
	void S_SeleccionoTipoProducto(zSiscomRegistro *);
	void S_Producto(int,int,int,const QPoint &);
	void S_CambiaCantidad(int,int,int,const QPoint &);
	void S_FocoACantidad();
	void S_EliminaProducto();
};
extern "C" QManejadorKits *InstanciaManejadorKits(void *,char **,void *,const char *,int);
#endif
