#ifndef __IMP_EXISTENCIAEXPENDIOS_H__
#define __IMP_EXISTENCIAEXPENDIOS_H__
#include <UIC_H_ExistenciaExpendios.h>
#include <zProductos.h>
#include <zExistenciaExpendios.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;


class zExistenciaExpendio;
class QExistenciaExpendios:public ExistenciaExpendios
{
 Q_OBJECT
public:
	QExistenciaExpendios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QExistenciaExpendios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	zExistenciaExpendios zExExpendios;
	zProductos zProdsRegreso;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando(zProductos *pzProductos);
	void Consulta(zProductos *pzProductos);
	void Muestra();
	int MuestraExistenciaExpendio(int ,zExistenciaExpendio *);
private slots:
	void SlotSeleccionoProducto(zSiscomRegistro *);
	void SlotActualizar();
};
extern "C" QExistenciaExpendios *InstanciaExistenciaExpendios(void *,char **,void *,const char *,int);
#endif
