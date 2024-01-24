
#ifndef __IMP_REGISTROPRODUCTOSSISCOM_H__
#define __IMP_REGISTROPRODUCTOSSISCOM_H__
#include <UIC_H_RegistroProductosSiscom.h>
class zSiscomConexion;
class SiscomDatCom;
class zSiscomRegistro;
class zProducto;
class zProductoSiscom;
class QRegistroProductosSiscom:public RegistroProductosSiscom
{
 Q_OBJECT
public:
	QRegistroProductosSiscom(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegistroProductosSiscom();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zProductoSiscom *zProdSiscom;

	const char *chrPtrIdCompraProductoSiscom;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraDefinicionProducto();
	void ObteniendoDefinicionProducto();
	void RegistrandoProductoSiscom();
	void ValidandoCompraProductoSiscom();

	void MuestraProductos();
	void MuestraProductosNoAlcanza();
	void FilasDefinicionProductoABlanco();
	void ObteniendoIdCompraProductosSiscom();

	int EsProductoPracticaEtc();
	void HabilitandoBotonRegistro();
	void AsignandoOrigen();
	void AsignandoOrigen(const char *);
private slots:
	void SlotSeleccionoProducto(zSiscomRegistro *);
	void SlotFocoARegistrar();
	void SlotRegistrar();
	void SlotCapturandoCantidad(const QString &);
	void SlotExpendio();
	void SlotBodega();
};
extern "C" QRegistroProductosSiscom *InstanciaRegistroProductosSiscom(void *,char **,void *,const char *,int);
#endif
