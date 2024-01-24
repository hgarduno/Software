#ifndef __IMP_ADMINISTRADORPEDIDOS_H__
#define __IMP_ADMINISTRADORPEDIDOS_H__
#include <QtAdministradorPedidos.h>
class SiscomDatCom;

class zOrdenes;
class zSiscomConexion;
class QAdministradorPedidos:public QtAdministradorPedidos
{
 Q_OBJECT
public:
	QAdministradorPedidos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QAdministradorPedidos();
	void Consulta();
	void Consultando();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zOrdenes *zOrdsRegistradas;
	zSiscomConexion *zSisConexion;
private:
	void ActualizaEstado();
private slots:
	void SlotConsultar();
	void SlotActualizaEstado();
	void SlotImprimir();
};
extern "C" QAdministradorPedidos *InstanciaAdministradorPedidos(void *,char **,void *,const char *,int);
#endif
