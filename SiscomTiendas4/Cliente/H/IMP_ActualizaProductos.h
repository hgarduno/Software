
#ifndef __IMP_ACTUALIZAPRODUCTOS_H__
#define __IMP_ACTUALIZAPRODUCTOS_H__
#include <UIC_H_ActualizaProductos.h>
class SiscomDatCom;
class CQSisProducto;
class CQSisFamilia;
class CQSisPrecio;
class QActualizaProductos:public ActualizaProductos
{
 Q_OBJECT
public:
	QActualizaProductos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QActualizaProductos();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisProducto *CQSProducto;
	CQSisFamilia *CQSFamilia;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDatosProducto();
	void PasaAFamilias();
	void ValidaInformacion();
	CQSisProducto *FormaProducto();
	void ActualizaProducto(CQSisProducto *);
private slots:
	void SlotProducto(CQSisProducto *);
	void SlotFamilia(CQSisFamilia *);
	void SlotCambiandoClave(const QString &);
	void SlotCambiandoDescripcion();
	void SlotPasaFocoDsc();
	void SlotActualiza();
	void closeEvent(QCloseEvent *);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QActualizaProductos *InstanciaActualizaProductos(void *,char **,void *,const char *,int);
#endif
