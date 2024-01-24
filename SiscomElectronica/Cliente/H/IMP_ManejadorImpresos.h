
#ifndef __IMP_MANEJADORIMPRESOS_H__
#define __IMP_MANEJADORIMPRESOS_H__
#include <UIC_H_ManejadorImpresos.h>
class zSiscomConexion;
class SiscomDatCom;
class zSiscomRegistro;
class zSiscomRegistros;
class QManejadorImpresos:public ManejadorImpresos
{
 Q_OBJECT
public:
	QManejadorImpresos(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QManejadorImpresos();
private:
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegEdoImpresos;
	zSiscomRegistro *zSisRegImpreso;
	zSiscomRegistros *zSisRegsEdoFecha;

private:
	void ConectaSlots();
	void IniciaVariables();
	int Consultando();
	int Consulta();
	void Muestra();

	int Actualizando();
private slots:
	void SlotFocoAFechaFin();
	void SlotFocoAEstadosImpresos();
	void SlotFocoAConsulta(zSiscomRegistro *);
	void SlotConsultar();
	void SlotSeleccionaImpreso(int pintImpreso,int,int,const QPoint &);
	void SlotActualiza();
};
extern "C" QManejadorImpresos *InstanciaManejadorImpresos(void *,char **,void *,const char *,int);
#endif
