
#ifndef __IMP_MUESTRAEXISTENCIAEXPENDIOS_H__
#define __IMP_MUESTRAEXISTENCIAEXPENDIOS_H__
#include <UIC_H_MuestraExistenciaExpendios.h>
#include <zExistenciaExpendios.h>
#include <zProductos.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;
class zExistenciaExpendio;
class QMuestraExistenciaExpendios:public MuestraExistenciaExpendios
{
 Q_OBJECT
public:
	QMuestraExistenciaExpendios(zSiscomRegistro *pzSisRegProducto,
		QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QMuestraExistenciaExpendios();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	zProductos zProdsRegreso;
	zExistenciaExpendios zExExpendios;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando(zProductos *pzProductos);
	void Consulta(zProductos *pzProductos);
	void Muestra();
	int MuestraExistenciaExpendio(int,zExistenciaExpendio *);
	void reject();
private slots:
	void SlotCancelar();
};
#endif
