
#ifndef __IMP_ACTUALIZAPRECIOS_H__
#define __IMP_ACTUALIZAPRECIOS_H__
#include <UIC_H_ActualizaPrecios.h>
#include <SiscomRegistros4.h>
class SiscomDatCom;
class CQSisFamilia;
class QActualizaPrecios:public ActualizaPrecios
{
 Q_OBJECT
public:
	QActualizaPrecios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QActualizaPrecios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisFamilia *CQSFamilia;
	SiscomRegistro4 SisReg4Productos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoProductos();
	void ConsultaProductos();
	void MuestraProductos();

	void MuestraColumna(SiscomRegistro4 *,const char *,int,int,int,int);
	void MuestraColumnasPrecios(SiscomRegistro3Lst *,int );
private slots:
	void SlotFamilia(CQSisFamilia *);
	void SlotConsulta();
};
extern "C" QActualizaPrecios *InstanciaActualizaPrecios(void *,char **,void *,const char *,int);
#endif
