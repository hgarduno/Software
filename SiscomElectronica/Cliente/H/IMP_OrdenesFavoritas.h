
#ifndef __IMP_ORDENESFAVORITAS_H__
#define __IMP_ORDENESFAVORITAS_H__
#include <UIC_H_OrdenesFavoritas.h>
#include <zOrdenesFavoritas.h>
class SiscomDatCom;
class zSiscomConexion;
class zOrdenVenta;

class QtSisBotonOrden;
class QOrdenesFavoritas:public OrdenesFavoritas
{
 Q_OBJECT
public:
	QOrdenesFavoritas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QOrdenesFavoritas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zOrdenVenta *zOrdVenta;
	zOrdenesFavoritas zOrdsFavoritas;
	zOrdenesFavoritas zOrdsFavoritasE;
	QtSisBotonOrden *QtSisBtnOrden;
	int intSeleccionandoParaEliminar;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Muestra(zOrdenVenta *);
	void MuestraProductos(zOrdenVenta *);
	void RegistrandoFavoritas();
	void RegistraFavoritas();
	int YaTieneOrden(QtSisBotonOrden *);
	void AgregaOrdenFavorita();
	void EliminaOrdenesFavoritas();
	void PreparaParaEliminarOrdenesFavoritas();
private slots:
	void SlotSelOrden();
	void SlotSeleccionoOrden(zOrdenVenta *);
	void SlotRegistraFavoritas();

	void SlotOrden(QtSisBotonOrden *);
	void SlotMarcaParaEliminar(QtSisBotonOrden *);
	void SlotCapturandoFavorita();
	void SlotAsignaOrdenFavorita();
	void SlotEliminaOrden();
	void SlotAgregaOrdenFavorita();
};
extern "C" QOrdenesFavoritas *InstanciaOrdenesFavoritas(void *,char **,void *,const char *,int);
#endif
