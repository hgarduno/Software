
#ifndef __IMP_REGISTRAKIT_H__
#define __IMP_REGISTRAKIT_H__
#include <UIC_H_RegistraKit.h>
class SiscomDatCom;
class ProductoE;
class QLineEdit;
class QManProductos;
class QRegistraKit:public RegistraKit
{
 Q_OBJECT
public:
	QRegistraKit(const char *pchrPtrIdTipoProducto,
		SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRegistraKit();
	ProductoE *ProductoAsignado();
	const char *IdProducto();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QLineEdit *QLECProductos;
	QManProductos *QMProductos;
	ProductoE *ProdSeleccionado;
	const char *chrPtrIdProducto;
	const char *chrPtrIdTipoProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Registra();
	void ValidandoRegreso();
private slots:
	void S_Producto(ProductoE *);
	void S_Registra();
};
#endif
