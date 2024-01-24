
#ifndef __IMP_ACTUALIZAPRODUCTOIMPORTADO_H__
#define __IMP_ACTUALIZAPRODUCTOIMPORTADO_H__
#include <UIC_H_ActualizaProductoImportado.h>
class zProductoImportado;
class zSiscomConexion;
class QActualizaProductoImportado:public ActualizaProductoImportado
{
 Q_OBJECT
public:
	QActualizaProductoImportado(zProductoImportado *pzProdImportado,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QActualizaProductoImportado();
	int Aceptar();
private:
	zProductoImportado *zProdImportado;
	int intAceptar;
	int intCambioPeso;
	zSiscomConexion *zSisConexion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraProducto();
	void Actualiza();
	void ActualizaPeso();
	void ActualizandoPeso();
private slots:
	void SlotAceptar();
	void SlotFocoACostoUnitario();
	void SlotFocoAPeso();
	void SlotFocoAAceptar();
	void SlotCambiandoPeso(const QString &);
};
#endif
