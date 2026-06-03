
#ifndef __IMP_EXISTENCIAS_H__
#define __IMP_EXISTENCIAS_H__
#include <QtExistencias.h>
class SiscomDatCom;

class zSiscomConexion;
class zSiscomRegistro;


class QExistencias:public QtExistencias
{
 Q_OBJECT
public:
	QExistencias(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QExistencias();
private:
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void PedidoExistenciaMinima();
	void RegistraPedidoExistenciaMinima();
private slots:

};
extern "C" QExistencias *InstanciaExistencias(void *,char **,void *,const char *,int);
#endif
