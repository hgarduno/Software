#ifndef __IMP_CLAVESPROVEEDOR4_H__
#define __IMP_CLAVESPROVEEDOR4_H__
#include <UIC_H_ClavesProveedor4.h>
#include <zClavesProveedor.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;

class zClaveProveedor;
class QClavesProveedor4:public ClavesProveedor4
{
 Q_OBJECT
public:
	QClavesProveedor4(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QClavesProveedor4();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	zSiscomRegistro *zSisRegProveedor;
	
	zClavesProveedor zClavsProveedor;
	zClaveProveedor *zClavProveedor;

	int intActualizando;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraProducto(zSiscomRegistro *);
	void Anexando();
	void Muestra();
	zClaveProveedor *ClaveProveedor();
	void AnexaClaveProveedor();
	void MuestraClaveProveedor();
	void Registrando();
	int ValidaClaveRegistrada(zClaveProveedor **);
	void AnalizaProductoSeleccionado();
	void MuestraProductoRegistrado(zClaveProveedor *);
	void HabilitaAnexar();
	void HabilitaRegistrar();
	void ReIniciaRegistra();

	void SeleccionandoClave(int);
	void Actualiza();
	void MuestraProductos();
	void ReIniciaActualizacion();
	void HabilitaDesHabilitaClaveDescripcionProveedor(bool);
	void HabilitandoParaActualizar();
	void ActualizandoClaveRegistrada();
	void ActualizaDatosClaveProveedor();
	void ActualizaClaveRegistrada();
	void NoEstaLaClaveProveedor();

private slots:
	void SlotProducto(zSiscomRegistro *);
	void SlotProveedor(zSiscomRegistro *);
	void SlotFocoADescripcionP();
	void SlotAnexar();
	void SlotRegistra();
	void SlotCapturandoClaveP(const QString &);
	void SlotCapturandoDescripcionP();
	void SlotClave(int,int,int,const QPoint &);
	void SlotActualizar();
};
extern "C" QClavesProveedor4 *InstanciaClavesProveedor4(void *,char **,void *,const char *,int);
#endif
