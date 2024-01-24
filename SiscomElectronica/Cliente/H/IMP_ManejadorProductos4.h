
#ifndef __IMP_MANEJADORPRODUCTOS4_H__
#define __IMP_MANEJADORPRODUCTOS4_H__
#include <UIC_H_ManejadorProductos4.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zProductos;
class zProductos;
class QManejadorProductos4:public ManejadorProductos4
{
 Q_OBJECT
public:
	QManejadorProductos4(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QManejadorProductos4();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	zSiscomRegistros *zSisRegsProductosSels;
	zSiscomRegistro *zSisRegCaja;
	zSiscomRegistro *zSisRegEstante;
	zProductos *zProdsSeleccionados;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDescripcion();
	void MuestraUbicacion();
	void MostrandoUbicacion();
	void RegistrarCaja();

	void SeDebeAgregarUbicacion();
	void AsignandoCaja();
	void AsignaCajaAlProducto();
	void AsignaCajaDeDescripcion();
	void MuestraProductos(zProductos *);
	int TieneUbicacion();
	int SinEstante(zSiscomRegistro *);
	int SinCaja(zSiscomRegistro *);
	int SinCajaOSinEstante(const char *,zSiscomRegistro *);
	void AsignandoEstante(zSiscomRegistro *);
	void AsignandoCaja(zSiscomRegistro *);
	void HabilitarAsignarUbicacion();
	void SeleccionoProducto();
	zSiscomRegistro *ProductoComoConsultaBase(zSiscomRegistro *);
	void MuestraProductoActualizado();
private slots:
	void SlotProducto(zSiscomRegistro *);
	void SlotSeleccionados(zProductos *);
	void SlotRegistrarCaja();
	void SlotSeleccionoCaja(zSiscomRegistro *);
	void SlotAsignarUbicacion();
	void SlotAsignaCajaDeDescripcion();
	void SlotEstante(zSiscomRegistro *);
	void SlotProducto(int,int,int,const QPoint &);
};
extern "C" QManejadorProductos4 *InstanciaManejadorProductos4(void *,char **,void *,const char *,int);
#endif
