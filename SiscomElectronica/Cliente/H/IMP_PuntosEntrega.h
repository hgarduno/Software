
#ifndef __IMP_PUNTOSENTREGA_H__
#define __IMP_PUNTOSENTREGA_H__
#include <UIC_H_PuntosEntrega.h>
#include <QtPuntosEntrega.h>
class SiscomDatCom;
class zSiscomConexion;
class zPuntoEntrega;
class zDireccion;

class QPuntosEntrega:public QtPuntosEntrega
{
 Q_OBJECT
public:
	QPuntosEntrega(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPuntosEntrega();
	void Registrar();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zPuntoEntrega *zPEntrega;
	zDireccion *DireccionPEntrega();
private:
	zPuntoEntrega *PuntoEntrega();
	zDireccion *zDirPEntrega;
private slots:
	void SlotRegistrar();
};
extern "C" QPuntosEntrega *InstanciaPuntosEntrega(void *,char **,void *,const char *,int);
#endif
